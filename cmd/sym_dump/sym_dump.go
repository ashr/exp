package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"

	"github.com/kr/pretty"
	"github.com/mewkiz/pkg/errutil"
	"github.com/sanctuary/exp/sym"
)

func main() {
	flag.Parse()
	for _, path := range flag.Args() {
		if err := parseFile(path); err != nil {
			log.Fatal(err)
		}
	}
}

const (
	KindFuncStart  = 0x8C
	KindFuncEnd    = 0x8E
	KindLocalStart = 0x90
	KindLocalEnd   = 0x92
	KindDef        = 0x94
)

const (
	DefKindLocal        = 0x0001 // local variable definition.
	DefKindGlobalOrFunc = 0x0002 // global variable or function definition.
	DefKind0003         = 0x0003
	DefKind0004         = 0x0004
	DefKind0006         = 0x0006
	DefKind0008         = 0x0008 // structure field definition?
	DefKindParam        = 0x0009 // function parameter definition?
	DefKindStructType   = 0x000A // structure type definition.
	DefKind000B         = 0x000B
	DefKind000C         = 0x000C
	DefKindTypeAlias    = 0x000D // type alias definition.
	DefKindEnumType     = 0x000F // enum type definition.
	DefKind0010         = 0x0010 // enum member definition?
	DefKind0011         = 0x0011
	DefKind0012         = 0x0012
	DefKind0066         = 0x0066 // end of symbol marker?
)

// parseFile parses the given Playstation 1 symbol file.
func parseFile(path string) error {
	syms, err := sym.ParseFile(path)
	if err != nil {
		return errutil.Err(err)
	}
	fs := make(map[string]*FuncDecl)
	globals := make(map[string]*Var)
	types := make(map[string]Type)
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			// Definition.
			switch data.DefKind {
			case DefKindGlobalOrFunc:
				if sym.HasMod(data.Type, sym.ModFunction) {
					f := &FuncDecl{
						Name: data.Name,
						Type: BasicType(data.Type),
					}
					// TODO: Merge decls.
					fs[f.Name] = f
					pretty.Println("function:", f)
				} else {
					global := &Var{Name: data.Name, Type: BasicType(data.Type)}
					// TODO: Merge globals.
					globals[global.Name] = global
					pretty.Println("global:", global)
				}
			case DefKindStructType:
				typ, n := parseStructType(types, syms[i:])
				i += n
				pretty.Println("struct typ:", typ)
				types[typ.TypeName()] = typ
			case DefKindEnumType:
				typ, n := parseEnumType(syms[i:])
				i += n
				pretty.Println("enum typ:", typ)
				types[typ.TypeName()] = typ
			default:
				panic(fmt.Sprintf("definition kind %04X not yet implemented", data.DefKind))
			}
		case *sym.Data96:
			// Definition.
			switch data.DefKind {
			case DefKindTypeAlias:
				fmt.Printf("type alias from %q to %q\n", data.Key, data.Val)
				types[data.Val] = types[data.Key]
			case DefKindGlobalOrFunc:
				t, ok := types[data.Key]
				if !ok {
					panic("pAng!")
				}
				if sym.HasMod(data.Type, sym.ModArray) {
					t = Array{
						Elem:    t,
						Lengths: data.Lengths,
					}
				}
				if sym.HasMod(data.Type, sym.ModFunction) {
					f := &FuncDecl{
						Name: data.Val,
						// TODO: Wrap t to signal that the type is actually a return
						// type of a function.
						Type: t,
					}
					// TODO: Merge decls.
					fs[f.Name] = f
					pretty.Println("function:", f)
				} else {
					global := &Var{Name: data.Val, Type: t}
					// TODO: Merge globals.
					globals[global.Name] = global
					pretty.Println("global:", global)
				}
			}
		case *sym.Data8C:
			// function definition start.
			f, n := parseFunc(types, syms[i:])
			i += n
			pretty.Println("function:", f)
			// TODO: Merge decls.
			fs[f.Name] = f
		}
	}
	return nil
}

type StructType struct {
	Name   string
	Fields []Field
}

func (typ StructType) TypeName() string {
	return typ.Name
}

type Field struct {
	Name string
	Type Type
}

type BasicType sym.Type

func (typ BasicType) TypeName() string {
	switch typ {
	case sym.TypeError:
		return "error"
	case sym.TypeVoid:
		return "void"
	case sym.TypeChar:
		return "char"
	case sym.TypeShort:
		return "short"
	case sym.TypeInt:
		return "int"
	case sym.TypeLong:
		return "long"
	case sym.TypeFloat:
		return "float"
	case sym.TypeDouble:
		return "double"
	case sym.TypeStruct:
		return "struct"
	case sym.TypeUnion:
		return "union"
	case sym.TypeEnum:
		return "enum"
	case sym.TypeEnumMember:
		return "enum member"
	case sym.TypeUnsignedChar:
		return "unsigned char"
	case sym.TypeUnsignedShort:
		return "unsigned short"
	case sym.TypeUnsignedInt:
		return "unsigned int"
	case sym.TypeUnsignedLong:
		return "unsigned long"
	}
	panic("unreachable")
}

type Type interface {
	TypeName() string
}

type Array struct {
	Elem    Type
	Lengths []uint32
}

func (typ Array) TypeName() string {
	buf := new(bytes.Buffer)
	for _, length := range typ.Lengths {
		fmt.Fprintf(buf, "[%d]", length)
	}
	return fmt.Sprintf("%s%s", typ.Elem, buf)
}

type EnumType struct {
	Name    string
	Members []EnumMember
}

type EnumMember struct {
	Name string
	Val  uint32
}

func (typ EnumType) TypeName() string {
	return typ.Name
}

func parseEnumType(syms []sym.Symbol) (*EnumType, int) {
	typ := new(EnumType)
	var n int
loop:
	for n = 0; n < len(syms); n++ {
		s := syms[n]
		switch data := s.Data().(type) {
		case *sym.Data94:
			if n == 0 {
				// Enum type definition.
				typ.Name = data.Name
				continue
			}
			member := EnumMember{
				Name: data.Name,
				Val:  s.Value(),
			}
			typ.Members = append(typ.Members, member)
		case *sym.Data96:
			if data.Val == ".eos" {
				break loop
			}
		default:
			panic(fmt.Sprintf("support for symbol data %T not yet implemented", data))
		}
	}
	return typ, n
}

func parseStructType(types map[string]Type, syms []sym.Symbol) (*StructType, int) {
	typ := new(StructType)
	var n int
loop:
	for n = 0; n < len(syms); n++ {
		s := syms[n]
		switch data := s.Data().(type) {
		case *sym.Data94:
			if n == 0 {
				// Struct type definition.
				typ.Name = data.Name
				continue
			}
			field := Field{
				Name: data.Name,
				Type: BasicType(data.Type),
			}
			typ.Fields = append(typ.Fields, field)
			// Definition.
		case *sym.Data96:
			if data.Val == ".eos" {
				break loop
			}
			// Key-value pair.
			var t Type = BasicType(data.Type)
			// TODO: Add support for enum.
			if data.Type&sym.TypeStruct != 0 {
				t = types[data.Key]
			}
			if sym.HasMod(data.Type, sym.ModArray) {
				t = Array{
					Elem:    t,
					Lengths: data.Lengths,
				}
			}
			field := Field{
				Name: data.Val,
				Type: t,
			}
			typ.Fields = append(typ.Fields, field)
		default:
			panic(fmt.Sprintf("support for symbol data %T not yet implemented", data))
		}
	}
	return typ, n
}

type FuncDecl struct {
	// Filled in by 0x8C.
	Name string
	// Filled in by 0x8C.
	Path string
	// Placeholder which will be filled by 0x94 symbols.
	Type Type
	// Filled in by 0x94.
	Params []Var
	// Filled in by 0x94.
	Locals []Var
}

type Var struct {
	Name string
	Type Type
}

func parseFunc(types map[string]Type, syms []sym.Symbol) (*FuncDecl, int) {
	ended, started := false, false
	decl := new(FuncDecl)
	var n int
loop:
	for n = 0; n < len(syms); n++ {
		s := syms[n]
		switch data := s.Data().(type) {
		// Definition of a function, struct, variable, parameter or union.
		case *sym.Data8C:
			// Function start.
			decl.Name = data.Name
			decl.Path = data.Path
		case *sym.Data8E:
			// Function end.
			break loop
		case *sym.Data90:
			// Local start.
			if started {
				panic("started twice")
			}
			started = true
		case *sym.Data92:
			// Local end.
			if ended {
				panic("ended twice")
			}
			ended = true
		case *sym.Data94:
			switch data.DefKind {
			case DefKindParam:
				param := Var{Name: data.Name, Type: BasicType(data.Type)}
				decl.Params = append(decl.Params, param)
			case DefKindLocal:
				local := Var{Name: data.Name, Type: BasicType(data.Type)}
				decl.Locals = append(decl.Locals, local)
			default:
				panic(fmt.Sprintf("support for definition kind %04X not yet implemented", data.DefKind))
			}
		case *sym.Data96:
			t, ok := types[data.Key]
			if !ok {
				panic("Silly rabbit, Trix are for kids!")
			}
			if sym.HasMod(data.Type, sym.ModArray) {
				t = Array{
					Elem:    t,
					Lengths: data.Lengths,
				}
			}
			switch data.DefKind {
			case DefKindParam:
				param := Var{Name: data.Val, Type: t}
				decl.Params = append(decl.Params, param)
			case DefKindLocal:
				local := Var{Name: data.Val, Type: t}
				decl.Locals = append(decl.Locals, local)
			default:
				panic(fmt.Sprintf("support for definition kind %04X not yet implemented", data.DefKind))
			}
		}
	}
	return decl, n
}
