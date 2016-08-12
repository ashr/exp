package main

import (
	"flag"
	"fmt"
	"log"
	"math"
	"sort"
	"strings"

	"github.com/kr/pretty"
	"github.com/mewkiz/pkg/errutil"
	"github.com/sanctuary/exp/sym"
)

func main() {
	flag.Parse()
	for _, path := range flag.Args() {
		files, err := parseFile(path)
		if err != nil {
			log.Fatal(err)
		}
		for _, file := range files {
			pretty.Println(file)
		}
	}
}

// parseFile parses the given Playstation 1 symbol file.
func parseFile(path string) ([]*File, error) {
	syms, err := sym.ParseFile(path)
	if err != nil {
		return nil, errutil.Err(err)
	}

	// Parse source files from 0x88 symbols.
	var files SortByAddr
	for _, s := range syms {
		switch data := s.Data().(type) {
		case *sym.Data88:
			file := &File{
				addr: s.Value(),
				path: cleanPath(data.Path),
			}
			files = append(files, file)
		}
	}
	first := &File{
		addr: 0,
		path: "_pre-other_.cpp",
	}
	last := &File{
		addr: math.MaxUint32,
		path: "_post-other_.cpp",
	}
	files = append(files, first, last)
	sort.Sort(files)

	// Parse type definitions.
	types := make(map[string]Type)
	retry := false
	for {
		for i := 0; i < len(syms); i++ {
			s := syms[i]
			switch data := s.Data().(type) {
			case *sym.Data94:
				switch data.DefKind {
				case DefKindEnumType:
					typ := &EnumType{
						name: data.Name,
					}
					//old, ok := types[typ.name]
					types[typ.name] = typ
					n := parseEnumType(typ, syms[i+1:])
					i += n + 1
					//if ok {
					//	if !old.Equal(typ) {
					//		if old, ok := old.(*StructType); !ok || !old.partial {
					//			fmt.Println("old type:", old)
					//			fmt.Println("new type:", typ)
					//		}
					//	}
					//}
				case DefKindStructType:
					typ := &StructType{
						name: data.Name,
					}
					//old, ok := types[typ.name]
					types[typ.name] = typ
					n := parseStructType(typ, types, syms[i+1:])
					i += n + 1
					//if ok {
					//	if !old.Equal(typ) {
					//		if old, ok := old.(*StructType); !ok || !old.partial {
					//			// NOTE: The MonsterStruct structure differs on the
					//			// following field:
					//			//
					//			//    -unsigned char unpackfilesize;
					//			//    +unsigned char packsize;
					//			//
					//			fmt.Println("old type:", old)
					//			fmt.Println("new type:", typ)
					//		}
					//	}
					//}
					if typ.partial {
						retry = true
						//delete(types, typ.name) // TODO: Remove?
						continue
					}
				}
			}
		}
		if !retry {
			break
		}
		retry = false
	}

	for _, typ := range types {
		fmt.Println(typ)
	}

	return nil, nil

	// TODO: alias.
	//case DefKindTypeAlias:

	// Parse functions starting with 0x8C and ending with 0x8E symbols.
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data8C:
			// Start of function declaration.
			f := &Func{
				addr: s.Value(),
				name: data.Name,
				path: data.Path,
			}
			n := parseFunc(f, syms[1:])
			i += n + 1
			insertFunc(files, f)
		}
	}

	return files, nil
}

// parseStructType parses a structure type definition from the stream of
// symbols.
func parseStructType(typ *StructType, types map[string]Type, syms []sym.Symbol) int {
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			// Structure field.
			switch data.DefKind {
			case DefKindStructField1, DefKindStructField2:
				var t Type = &BasicType{
					basic: data.Type & 0x000F,
				}
				t = parseTypeMods(t, data.Type&0xFFF0, nil)
				field := &StructField{
					name: data.Name,
					typ:  t,
				}
				typ.fields = append(typ.fields, field)
			}
		case *sym.Data96:
			// Structure field.
			switch data.DefKind {
			case DefKindStructField1, DefKindStructField2:
				var t Type
				switch data.Type & 0x000F {
				case sym.TypeStruct, sym.TypeEnum:
					var ok bool
					t, ok = types[data.Key]
					if !ok {
						if data.Key == "__vtbl_ptr_type" {
							tt := &StructType{
								name: "__vtbl_ptr_type",
							}
							types[tt.name] = tt
							t = tt
						} else {
							typ.partial = true
							continue
						}
					}
				default:
					t = &BasicType{
						basic: data.Type & 0x000F,
					}
				}
				t = parseTypeMods(t, data.Type&0xFFF0, data.Lengths)
				field := &StructField{
					name: data.Val,
					typ:  t,
				}
				typ.fields = append(typ.fields, field)
			case DefKindEOS:
				// End of symbol.
				return i
			default:
				panic(fmt.Sprintf("expected DefKindStructField1, DefKindStructField2 or DefKindEOS, got %v", data.DefKind))
			}
		}
	}
	panic("unreachable")
}

// parseTypeMods applies the given type modifiers to the provided type.
func parseTypeMods(typ Type, mods sym.Type, lengths []uint32) Type {
	// Parse type modifiers.
	const mask = 0x3
	arrayNum := 0
	for mods >>= 4; mods != 0; mods >>= 2 {
		// Pointer.
		if mods&mask == sym.ModPointer {
			typ = &PointerType{
				elem: typ,
			}
		}

		// Array type.
		if mods&mask == sym.ModArray {
			typ = &ArrayType{
				elem:   typ,
				length: lengths[arrayNum],
			}
			arrayNum++
		}

		// TODO: Implement support for function.
	}

	return typ
}

// parseEnumType parses an enum type definition from the stream of symbols.
func parseEnumType(typ *EnumType, syms []sym.Symbol) int {
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			// Enum member.
			if data.DefKind != DefKindEnumMember {
				panic(fmt.Sprintf("expected DefKindEnumMember, got %v", data.DefKind))
			}
			member := &EnumMember{
				name: data.Name,
				val:  s.Value(),
			}
			typ.members = append(typ.members, member)
		case *sym.Data96:
			// End of symbol.
			if data.DefKind != DefKindEOS {
				panic(fmt.Sprintf("expected DefKindEOS, got %v", data.DefKind))
			}
			return i
		}
	}
	panic("unreachable")
}

// A File represents a source file.
type File struct {
	// Start address.
	addr uint32
	// Source code file path.
	path string
	// Function declarations.
	//
	// TODO: Sort by address.
	funcs []*Func
	// Global variables.
	//
	// TODO: Sort by address.
	globals []*Global
	// Types.
	//
	// TODO: Sort by name.
	types []Type
}

// insertFunc inserts the given function into the list of source files based on
// the address of the function and the ranges of each source file.
func insertFunc(files []*File, f *Func) {
	find := func(i int) bool {
		return len(files)-1 == i || files[i].addr >= f.addr && f.addr < files[i+1].addr
	}
	i := sort.Search(len(files), find)
	if i < len(files) {
		// Append the given function to the source file covering its address.
		files[i].funcs = append(files[i].funcs, f)
	} else {
		panic("unreachable")
	}
}

// A Func represents a function declaration.
type Func struct {
	// Address of the function.
	addr uint32
	// Function name.
	name string
	// Source code file path; used for verification.
	path string
	// Extract the _Fiii part of the name for verification aganst the parameter
	// list.
	paramsStr string
	// List of parameters to the function.
	params []*Param
	// List of local variables in the function.
	locals []*Local
	// Return type of the function.
	retType Type
}

// Name returns the name of the definition.
func (f *Func) Name() string {
	return f.name
}

// parseFunc parses a function declaration starting with an 0x8C symbol and
// ending with an 0x8E symbol.
func parseFunc(f *Func, syms []sym.Symbol) int {
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch s.Data().(type) {
		case *sym.Data8C:
			// Start of function declaration.
			// TODO: Investigate.
			//panic("func start twice")
		case *sym.Data8E:
			// End of function declaration.
			return i
		case *sym.Data94:
			/*
				def, n := parse94(syms[i:])
				i += n
				switch def := def.(type) {
				case *Local:
					f.locals = append(f.locals, def)
				case *Param:
					f.params = append(f.params, def)
				default:
					panic(fmt.Sprintf("support for type %T not yet implemented", def))
				}
			*/
		case *sym.Data96:
			/*
				def, n := parse96(syms[i:])
				i += n
				switch def := def.(type) {
				case *Local:
					f.locals = append(f.locals, def)
				case *Param:
					f.params = append(f.params, def)
				default:
					panic(fmt.Sprintf("support for type %T not yet implemented", def))
				}
			*/
		}
	}
	panic("unreachable")
}

// Definition kinds.
const (
	DefKindLocal1 = 0x0001 // local variable definition.
	// TODO: Re-check if 1 and 2 represent exported.
	DefKindGlobalOrFunc1 = 0x0002 // global variable or function definition.
	DefKindGlobalOrFunc2 = 0x0003 // global variable or function definition.
	DefKindLocal2        = 0x0004 // local variable definition.
	DefKind0006          = 0x0006 // error?
	DefKindStructField1  = 0x0008 // structure field definition.
	DefKindParam1        = 0x0009 // function parameter definition.
	DefKindStructType    = 0x000A // structure type definition.
	DefKindUnionMember   = 0x000B // union member.
	DefKindUnion         = 0x000C // union.
	DefKindTypeAlias     = 0x000D // type alias definition.
	DefKindEnumType      = 0x000F // enum type definition.
	DefKindEnumMember    = 0x0010 // enum member definition.
	DefKindParam2        = 0x0011 // function parameter definition.
	DefKindStructField2  = 0x0012 // structure field definition.
	DefKindEOS           = 0x0066 // end of symbol marker.
)

// cleanPath returns a relative Unix path equivalent to the given absolute
// Windows path.
func cleanPath(path string) string {
	path = strings.ToLower(path)
	path = strings.Replace(path, "\\", "/", -1)
	if strings.HasPrefix(path, "c:/") || strings.HasPrefix(path, "d:/") {
		path = path[len("c:/"):]
	}
	return path
}

// SortByAddr is a slice of files sorted by address.
type SortByAddr []*File

func (fs SortByAddr) Len() int {
	return len(fs)
}

func (fs SortByAddr) Less(i, j int) bool {
	return fs[i].addr < fs[j].addr
}

func (fs SortByAddr) Swap(i, j int) {
	fs[i], fs[j] = fs[j], fs[i]
}
