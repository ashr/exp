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
	var structOrder []string
	structOrder = append(structOrder, "__vtbl_ptr_type")
	structOrder = append(structOrder, "t11TLinkedList1Z8PalEntry")
	structOrder = append(structOrder, "TP_LINK")
	for {
		for i := 0; i < len(syms); i++ {
			s := syms[i]
			switch data := s.Data().(type) {
			case *sym.Data94:
				switch data.DefKind {
				case DefKindTypeAlias:
					// Type alias for basic type.
					var typ Type = &BasicType{
						basic: data.Type & 0x000F,
					}
					typ = parseTypeMods(typ, data.Type&0xFFF0, nil)
					old, ok := types[data.Name]
					if ok {
						if !old.Equal(typ) {
							fmt.Println("old type:", old)
							fmt.Println("new type:", typ)
						}
					}
					types[data.Name] = typ
				case DefKindEnumType:
					typ := &EnumType{
						name: data.Name,
					}
					n := parseEnumType(typ, syms[i+1:])
					i += n + 1
					//old, ok := types[typ.name]
					//if ok {
					//	if !old.Equal(typ) {
					//		fmt.Println("old type:", old)
					//		fmt.Println("new type:", typ)
					//	}
					//}
					skip := false
					for name, old := range types {
						// TODO: Check if there exists an enum which the same members
						// but with a different ".fake" name.
						if name == typ.name {
							continue
						}
						switch old := old.(type) {
						case *EnumType:
							if membersEqual(old, typ) {
								old.aliases = append(old.aliases, typ.name)
								skip = true
							}
						}
					}
					if !skip {
						types[typ.name] = typ
					}
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
					//		if old, ok := old.(*StructType); ok && !old.partial {
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
						continue
					}
					insert := true
					for _, key := range structOrder {
						if key == typ.name {
							insert = false
							break
						}
					}
					if insert {
						structOrder = append(structOrder, typ.name)
					}
				case DefKindUnion:
					typ := &UnionType{
						name: data.Name,
					}
					types[typ.name] = typ
					n := parseUnionType(typ, types, syms[i+1:])
					i += n + 1
					if typ.partial {
						retry = true
						continue
					}
					insert := true
					for _, key := range structOrder {
						if key == typ.name {
							insert = false
							break
						}
					}
					if insert {
						structOrder = append(structOrder, typ.name)
					}
				}
			}
		}
		if !retry {
			break
		}
		retry = false
	}
	types["unknown"] = &BasicType{
		basic: sym.TypeInt,
	}

	// TODO: Alias BLOCKENTRYPTR should be pointer to struct.

	// Parse type aliases.
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data96:
			switch data.DefKind {
			case DefKindTypeAlias:
				switch data.Type & 0x000F {
				case sym.TypeStruct, sym.TypeEnum:
					typ := types[data.Key]
					typ = parseTypeMods(typ, data.Type&0xFFF0, data.Lengths)
					switch typ := typ.(type) {
					case *EnumType:
						typ.aliases = append(typ.aliases, data.Val)
					case *StructType:
						typ.aliases = append(typ.aliases, data.Val)
					case *PointerType:
						types[data.Val] = typ
					case nil:
						log.Println("Unable to find mapping for:")
						log.Println("   key:", data.Key)
						log.Println("   val:", data.Val)
					default:
						panic(fmt.Sprintf("support for type aliases on type %T not yet implemented", typ))
					}
				default:
					// Type alias for basic type.
					var typ Type = &BasicType{
						basic: data.Type & 0x000F,
					}
					typ = parseTypeMods(typ, data.Type&0xFFF0, data.Lengths)
					old, ok := types[data.Val]
					if ok {
						if !old.Equal(typ) {
							fmt.Println("old type:", old.Name())
							fmt.Println("new type:", typ.Name())
						}
					}
					types[data.Val] = typ
				}
			}
		}
	}

	// Print type definitions.
	var enums []string
	var basics []string
	for key, typ := range types {
		switch typ.(type) {
		case *EnumType:
			enums = append(enums, key)
		case *BasicType, *PointerType, *ArrayType, *FuncType:
			basics = append(basics, key)
		case *StructType, *UnionType:
			// Handled by structOrder.
		default:
			panic(fmt.Sprintf("support for type %T not yet implemented", typ))
		}
	}
	sort.Strings(enums)
	sort.Strings(basics)
	basics = append([]string{"unknown"}, basics...)

	// Print enums.
	for _, name := range enums {
		typ := types[name]
		switch typ := typ.(type) {
		case *EnumType:
			fmt.Println(typ.TypeDef())
		default:
			panic(fmt.Sprintf("support for type %T not yet implemented", typ))
		}
		fmt.Println()
	}

	// Print basic types.
	for _, name := range basics {
		typ := types[name]
		switch typ := typ.(type) {
		case *BasicType:
			fmt.Printf("typedef %s %s;\n", typ.Name(), name)
		case *PointerType:
			switch elem := typ.elem.(type) {
			case *StructType:
				fmt.Printf("typedef struct %s %s;\n", typ.Name(), name)
			case *FuncType:
				if ret, ok := elem.ret.(*PointerType); ok {
					if e, ok := ret.elem.(*StructType); ok {
						fmt.Printf("typedef struct %s* (*%s);\n", e.Name(), name)
						continue
					}
				}
				fmt.Printf("typedef %s (*%s);\n", elem.ret.Name(), name)
			default:
				fmt.Printf("typedef %s %s;\n", typ.Name(), name)
			}
		case *ArrayType:
			// TODO: Add support for nested arrays.
			fmt.Printf("typedef %s %s[%d];\n", typ.elem.Name(), name, typ.length)
		case *FuncType:
			fmt.Printf("typedef %s %s();", typ.ret.Name(), name)
		}
		fmt.Println()
	}

	// Print structs and unions.
	for _, name := range structOrder {
		typ := types[name]
		switch typ := typ.(type) {
		case *StructType:
			fmt.Println(typ.TypeDef())
			//case *UnionType:
			//	fmt.Println(typ.TypeDef())
		}
		fmt.Println()
	}

	return nil, nil

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

// parseUnionType parses a union type definition from the stream of symbols.
func parseUnionType(typ *UnionType, types map[string]Type, syms []sym.Symbol) int {
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			// Union member.
			switch data.DefKind {
			case DefKindUnionMember:
				var t Type = &BasicType{
					basic: data.Type & 0x000F,
				}
				t = parseTypeMods(t, data.Type&0xFFF0, nil)
				name := data.Name
				if name == ".vf" {
					name = "_vf"
				}
				member := &StructField{
					name: name,
					typ:  t,
				}
				typ.members = append(typ.members, member)
			}
		case *sym.Data96:
			// Union member.
			switch data.DefKind {
			case DefKindUnionMember:
				var t Type
				switch data.Type & 0x000F {
				case sym.TypeStruct, sym.TypeEnum, sym.TypeUnion:
					var ok bool
					t, ok = types[data.Key]
					if !ok {
						if data.Key == "__vtbl_ptr_type" {
							tt := &StructType{
								name:    "__vtbl_ptr_type",
								aliases: []string{"__vtbl_ptr_type"},
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
				name := data.Val
				if name == ".vf" {
					name = "_vf"
				}
				member := &StructField{
					name: name,
					typ:  t,
				}
				typ.members = append(typ.members, member)
			case DefKindEOS:
				// End of symbol.
				return i
			default:
				panic(fmt.Sprintf("expected DefKindUnionMember or DefKindEOS, got %v", data.DefKind))
			}
		}
	}
	panic("unreachable")
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
				name := data.Name
				if name == ".vf" {
					name = "_vf"
				}
				field := &StructField{
					name: name,
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
				case sym.TypeStruct, sym.TypeEnum, sym.TypeUnion:
					var ok bool
					t, ok = types[data.Key]
					if !ok {
						if data.Key == "__vtbl_ptr_type" {
							tt := &StructType{
								name:    "__vtbl_ptr_type",
								aliases: []string{"__vtbl_ptr_type"},
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
				name := data.Val
				if name == ".vf" {
					name = "_vf"
				}
				field := &StructField{
					name: name,
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

// membersEqual reports whether the members of t and u are equal.
func membersEqual(t, u *EnumType) bool {
	if len(t.members) != len(u.members) {
		return false
	}
	for i := range t.members {
		if *t.members[i] != *u.members[i] {
			return false
		}
	}
	return true
}

// parseTypeMods applies the given type modifiers to the provided type.
func parseTypeMods(typ Type, mods sym.Type, lengths []uint32) Type {
	// Parse type modifiers.
	const mask = 0x3
	arrayNum := 0
	for mods >>= 4; mods != 0; mods >>= 2 {
		// Pointer type.
		if mods&mask == sym.ModPointer {
			typ = &PointerType{
				elem: typ,
			}
			continue
		}

		// Array type.
		if mods&mask == sym.ModArray {
			typ = &ArrayType{
				elem:   typ,
				length: lengths[arrayNum],
			}
			arrayNum++
			continue
		}

		// Function type.
		if mods&mask == sym.ModFunction {
			typ = &FuncType{
				ret: typ,
			}
			continue
		}
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
			// Sort enum members by value.
			sort.Sort(SortByValue(typ.members))
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
	DefKindLocal1        = 0x0001 // local variable definition.
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

// SortByAddr implements the sort.Sort interface, sorting files by address.
type SortByAddr []*File

// Len is the number of elements in the collection.
func (fs SortByAddr) Len() int {
	return len(fs)
}

// Less reports whether the element with index i should sort before the element
// with index j.
func (fs SortByAddr) Less(i, j int) bool {
	return fs[i].addr < fs[j].addr
}

// Swap swaps the elements with indexes i and j.
func (fs SortByAddr) Swap(i, j int) {
	fs[i], fs[j] = fs[j], fs[i]
}

// SortByValue implements the sort.Sort interface, sorting enum members by
// value.
type SortByValue []*EnumMember

// Len is the number of elements in the collection.
func (ms SortByValue) Len() int {
	return len(ms)
}

// Less reports whether the element with index i should sort before the element
// with index j.
func (ms SortByValue) Less(i, j int) bool {
	if ms[i].val == ms[j].val {
		return ms[i].name < ms[j].name
	}
	return ms[i].val < ms[j].val
}

// Swap swaps the elements with indexes i and j.
func (ms SortByValue) Swap(i, j int) {
	ms[i], ms[j] = ms[j], ms[i]
}
