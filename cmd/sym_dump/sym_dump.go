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
	DefKindLocal1        = 0x0001 // local variable definition.
	DefKindGlobalOrFunc1 = 0x0002 // global variable or function definition.
	DefKindGlobalOrFunc2 = 0x0003 // global function or function definition.
	DefKindLocal2        = 0x0004 // local variable definition.
	DefKind0006          = 0x0006 // error?
	DefKindStructField1  = 0x0008 // structure field definition.
	DefKindParam1        = 0x0009 // function parameter definition.
	DefKindStructType    = 0x000A // structure type definition.
	DefKindUnionMember   = 0x000B // union member.
	DefKindUnion         = 0x000C // union.
	DefKindTypeAlias     = 0x000D // type alias definition.
	DefKindEnumType      = 0x000F // enum type definition.
	DefKind0010          = 0x0010 // enum member definition?
	DefKindParam2        = 0x0011 // function parameter definition.
	DefKindStructField2  = 0x0012 // structure field definition.
	DefKind0066          = 0x0066 // end of symbol marker?
)

type Global struct {
	Addr uint32
	*Var
}

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
	globals := make(map[string]*Global)
	types := make(map[string]Type)

	aliasOrder := []string{}
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			// Definition.
			switch data.DefKind {
			case DefKindGlobalOrFunc1, DefKindGlobalOrFunc2:
				if sym.HasMod(data.Type, sym.ModFunction) {
					f := &FuncDecl{
						Name: data.Name,
						Type: BasicType(data.Type),
					}
					if old, ok := fs[f.Name]; ok {
						if len(old.Locals) > len(f.Locals) {
							f.Locals = old.Locals
						}
						if len(old.Params) > len(f.Params) {
							f.Params = old.Params
						}
						if len(old.Path) > len(f.Path) {
							f.Path = old.Path
						}
						if old.Type != nil && f.Type == nil {
							f.Type = old.Type
						}
					}
					fs[f.Name] = f
					fOrder = append(fOrder, f.Name)
					//pretty.Println("function:", f)
				} else {
					global := &Global{Addr: s.Value(), Var: &Var{Name: data.Name, Type: BasicType(data.Type)}}
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
				//fmt.Printf("type alias from %q to %q\n", data.Key, data.Val)
				//if name, ok := alias[data.Key]; ok {
				//   fmt.Printf("##### an alias already exists from %q to %q\n", data.Key, name)
				//}
				alias[data.Key] = data.Val
				aliasOrder = append(aliasOrder, data.Key)
				types[data.Val] = types[data.Key]
			case DefKindGlobalOrFunc1, DefKindGlobalOrFunc2:
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
					if old, ok := fs[f.Name]; ok {
						if len(old.Locals) > len(f.Locals) {
							f.Locals = old.Locals
						}
						if len(old.Params) > len(f.Params) {
							f.Params = old.Params
						}
						if len(old.Path) > len(f.Path) {
							f.Path = old.Path
						}
						if old.Type != nil && f.Type == nil {
							f.Type = old.Type
						}
					}
					fs[f.Name] = f
					fOrder = append(fOrder, f.Name)
					//pretty.Println("function:", f)
				} else {
					global := &Global{Addr: s.Value(), Var: &Var{Name: data.Val, Type: t}}
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
			if old, ok := fs[f.Name]; ok {
				if len(old.Locals) > len(f.Locals) {
					f.Locals = old.Locals
				}
				if len(old.Params) > len(f.Params) {
					f.Params = old.Params
				}
				if len(old.Path) > len(f.Path) {
					f.Path = old.Path
				}
				if old.Type != nil && f.Type == nil {
					f.Type = old.Type
				}
			}
			fs[f.Name] = f
			fOrder = append(fOrder, f.Name)
		}
	}
	pretty(fs, globals, types, fOrder, globalOrder, aliasOrder)
	return nil
}

type StructType struct {
	Name   string
	Fields []*Var
}

func (typ StructType) String() string {
	buf := new(bytes.Buffer)
	fmt.Fprintln(buf, "typedef struct {")
	for _, field := range typ.Fields {
		fmt.Fprintf(buf, "\t%s\n", field)
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
	case sym.TypeUnknown:
		buf.WriteString("unknown")
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
			field := &Var{
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
			field := &Var{
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
			//fmt.Printf("#### type of name %q already exists\n", typ.Name)
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
	Params []*Var
	// Filled in by 0x94.
	Locals []*Var
}

func (f *FuncDecl) String() string {
	buf := new(bytes.Buffer)
	paramsBuf := new(bytes.Buffer)
	for i, param := range f.Params {
		if i != 0 {
			paramsBuf.WriteString(", ")
		}
		paramsBuf.WriteString(param.String())
	}
	fmt.Fprintf(buf, "%s %s(%s) {\n", f.Type.TypeName(), f.Name, paramsBuf)
	for _, local := range f.Locals {
		_ = local
		fmt.Fprintf(buf, "\t%s;\n", local)
	}
	buf.WriteString("}")
	return buf.String()
}

type Var struct {
	Name string
	Type Type
}

func (v *Var) String() string {
	if t, ok := v.Type.(Array); ok {
		buf := new(bytes.Buffer)
		for _, length := range t.Lengths {
			fmt.Fprintf(buf, "[%d]", length)
		}
		return fmt.Sprintf("%s %s%s", t.Elem.TypeName(), v.Name, buf)
	}
	return fmt.Sprintf("%s %s", v.Type.TypeName(), v.Name)
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
			if n == 0 {
				decl.Name = data.Name
				decl.Path = data.Path
				continue
			}
			panic("wat?")
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
			case DefKindParam1, DefKindParam2:
				param := &Var{Name: data.Name, Type: BasicType(data.Type)}
				decl.Params = append(decl.Params, param)
			case DefKindLocal1, DefKindLocal2:
				local := &Var{Name: data.Name, Type: BasicType(data.Type)}
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
			case DefKindParam1, DefKindParam2:
				param := &Var{Name: data.Val, Type: t}
				decl.Params = append(decl.Params, param)
			case DefKindLocal1, DefKindLocal2:
				local := &Var{Name: data.Val, Type: t}
				decl.Locals = append(decl.Locals, local)
			default:
				// TODO: Implement.
				//panic(fmt.Sprintf("support for definition kind %04X not yet implemented", data.DefKind))
			}
		}
	}
	return decl, n
}
