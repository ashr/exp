package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"

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

var alias = make(map[string]string)

// parseFile parses the given Playstation 1 symbol file.
func parseFile(path string) error {
	syms, err := sym.ParseFile(path)
	if err != nil {
		return errutil.Err(err)
	}
	fOrder := []string{}
	fs := make(map[string]*FuncDecl)
	globalOrder := []string{}
	globals := make(map[string]*Var)
	types := make(map[string]Type)

	aliasOrder := []string{}
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
					fOrder = append(fOrder, f.Name)
					//pretty.Println("function:", f)
				} else {
					global := &Var{Name: data.Name, Type: BasicType(data.Type)}
					// TODO: Merge globals.
					globals[global.Name] = global
					globalOrder = append(globalOrder, global.Name)
					//pretty.Println("global:", global)
				}
			case DefKindStructType:
				n := parseStructType(types, syms[i:])
				i += n
				//pretty.Println("struct typ:", typ)
			case DefKindEnumType:
				n := parseEnumType(types, syms[i:])
				i += n
				//pretty.Println("enum typ:", typ)
			default:
				// TODO: Implement.
				//panic(fmt.Sprintf("definition kind %04X not yet implemented", data.DefKind))
			}
		case *sym.Data96:
			// Definition.
			switch data.DefKind {
			case DefKindTypeAlias:
				if len(data.Key) == 0 {
					// TODO: Check length 0.
				}
				fmt.Printf("type alias from %q to %q\n", data.Key, data.Val)
				if name, ok := alias[data.Key]; ok {
					fmt.Printf("##### an alias already exists from %q to %q\n", data.Key, name)
				}
				alias[data.Key] = data.Val
				aliasOrder = append(aliasOrder, data.Key)
				types[data.Val] = types[data.Key]
			case DefKindGlobalOrFunc:
				var t Type = BasicType(data.Type)
				if data.Type&0x000F == sym.TypeStruct || data.Type&0x000F == sym.TypeEnum {
					var ok bool
					t, ok = types[data.Key]
					if !ok {
						panic(fmt.Sprintf("unable to locate type %q (data %v)", data.Key, data))
					}
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
					fOrder = append(fOrder, f.Name)
					//pretty.Println("function:", f)
				} else {
					global := &Var{Name: data.Val, Type: t}
					// TODO: Merge globals.
					globals[global.Name] = global
					globalOrder = append(globalOrder, global.Name)
					//pretty.Println("global:", global)
				}
			}
		case *sym.Data8C:
			// function definition start.
			f, n := parseFunc(types, syms[i:])
			i += n
			//pretty.Println("function:", f)
			// TODO: Merge decls.
			fs[f.Name] = f
		}
	}
	pretty(fs, globals, types, fOrder, globalOrder, aliasOrder)
	return nil
}

type StructType struct {
	Name   string
	Fields []Field
}

func (typ StructType) String() string {
	buf := new(bytes.Buffer)
	fmt.Fprintln(buf, "typedef struct {")
	for _, field := range typ.Fields {
		if t, ok := field.Type.(Array); ok {
			l := new(bytes.Buffer)
			for _, length := range t.Lengths {
				fmt.Fprintf(l, "[%d]", length)
			}
			fmt.Fprintf(buf, "\t%s %s%s;\n", t.Elem.TypeName(), field.Name, l)
			continue
		}
		fmt.Fprintf(buf, "\t%s %s;\n", field.Type.TypeName(), field.Name)
	}
	fmt.Fprintf(buf, "} %s;\n", typ.TypeName())
	return buf.String()
}

func (typ StructType) TypeName() string {
	name, ok := alias[typ.Name]
	if !ok {
		panic(fmt.Sprintf("unable to locate struct name %q in alias", typ.Name))
	}
	return name
}

type Field struct {
	Name string
	Type Type
}

type BasicType sym.Type

func (typ BasicType) TypeName() string {
	mask := BasicType(sym.ModArray << 4)
	for i := 0; i < 6; i++ {
		if typ&(0x3<<(BasicType(i)*2+4)) == mask {
			typ &^= mask
		}
		mask <<= 2
	}
	buf := new(bytes.Buffer)
	switch typ & 0x000F {
	case sym.TypeError:
		buf.WriteString("error")
	case sym.TypeVoid:
		buf.WriteString("void")
	case sym.TypeChar:
		buf.WriteString("char")
	case sym.TypeShort:
		buf.WriteString("short")
	case sym.TypeInt:
		buf.WriteString("int")
	case sym.TypeLong:
		buf.WriteString("long")
	case sym.TypeFloat:
		buf.WriteString("float")
	case sym.TypeDouble:
		buf.WriteString("double")
	case sym.TypeStruct:
		buf.WriteString("struct")
	case sym.TypeUnion:
		buf.WriteString("union")
	case sym.TypeEnum:
		buf.WriteString("enum")
	case sym.TypeEnumMember:
		buf.WriteString("enum member")
	case sym.TypeUnsignedChar:
		buf.WriteString("unsigned char")
	case sym.TypeUnsignedShort:
		buf.WriteString("unsigned short")
	case sym.TypeUnsignedInt:
		buf.WriteString("unsigned int")
	case sym.TypeUnsignedLong:
		buf.WriteString("unsigned long")
	}

	mask = BasicType(sym.ModPointer << 4)
	for i := 0; i < 6; i++ {
		if typ&(0x3<<(BasicType(i)*2+4)) == mask {
			buf.WriteString("*")
			typ &^= mask
		}
		mask <<= 2
	}

	// TODO: Handle functions.

	return buf.String()
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
	return fmt.Sprintf("%s%s", typ.Elem.TypeName(), buf)
}

type EnumType struct {
	Name    string
	Members []EnumMember
}

func (typ EnumType) String() string {
	buf := new(bytes.Buffer)
	fmt.Fprintln(buf, "typedef enum {")
	for _, member := range typ.Members {
		fmt.Fprintf(buf, "\t%s = %d,\n", member.Name, member.Val)
	}
	fmt.Fprintf(buf, "} %s;\n", typ.TypeName())
	return buf.String()
}

type EnumMember struct {
	Name string
	Val  uint32
}

func (typ EnumType) TypeName() string {
	name, ok := alias[typ.Name]
	if !ok {
		panic(fmt.Sprintf("unable to locate enum name %q in alias", typ.Name))
	}
	return name
}

func parseEnumType(types map[string]Type, syms []sym.Symbol) int {
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
	if t, ok := types[typ.Name]; ok {
		if _, isdummy := t.(DummyType); !isdummy {
			panic("Why you no dummy?")
		}
	}
	types[typ.Name] = typ
	return n
}

func parseStructType(types map[string]Type, syms []sym.Symbol) int {
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
			if data.Type&0x000F == sym.TypeStruct || data.Type&0x000F == sym.TypeEnum {
				var ok bool
				t, ok = types[data.Key]
				if !ok {
					if len(data.Key) == 0 {
						panic(fmt.Sprintf("unable to locate type %q (data %v)", data.Key, data))
					}
					// Beautiful!
					dummy := DummyType{Name: data.Key}
					types[data.Key] = dummy
					//panic(fmt.Sprintf("unable to locate type %q (data %v)", data.Key, data))
					t = dummy
				}
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
	if t, ok := types[typ.Name]; ok {
		if _, isdummy := t.(DummyType); !isdummy {
			fmt.Printf("#### type of name %q already exists\n", typ.Name)
			// TODO: Fix through a serial (use no global map) implementation.
			//panic(fmt.Sprintf("#### type of name %q already exists and maps to %v; thus cannot add type %v\n", typ.Name, t, typ))
		}
	}
	types[typ.Name] = typ
	return n
}

type DummyType struct {
	Name string
}

func (typ DummyType) TypeName() string {
	name, ok := alias[typ.Name]
	if !ok {
		panic(fmt.Sprintf("unable to locate struct name %q in alias", typ.Name))
	}
	return name
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
				// TODO: Check why nested.
				//panic("started twice")
			}
			started = true
		case *sym.Data92:
			// Local end.
			if ended {
				// TODO: Check why nested.
				//panic("ended twice")
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
				// TODO: Implement.
				//panic(fmt.Sprintf("support for definition kind %04X not yet implemented", data.DefKind))
			}
		case *sym.Data96:
			var t Type = BasicType(data.Type)

			if data.Type&0x000F == sym.TypeStruct || data.Type&0x000F == sym.TypeEnum {
				var ok bool
				t, ok = types[data.Key]
				if !ok {
					panic(fmt.Sprintf("unable to locate type %q (data %v)", data.Key, data))
				}
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
				// TODO: Implement.
				//panic(fmt.Sprintf("support for definition kind %04X not yet implemented", data.DefKind))
			}
		}
	}
	return decl, n
}
