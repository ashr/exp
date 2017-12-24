// symmetry is a tool for decoding PlayStation 1 symbol files.
package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"github.com/mewkiz/pkg/errutil"
	"github.com/sanctuary/exp/sym"
	"github.com/sanctuary/symbol/ast"
	ctypes "github.com/sanctuary/symbol/types"
)

// dbg is a logger which prefixes debug messages with the file name and line
// number of callees.
var dbg = log.New(os.Stderr, "", log.Lshortfile)

var (
	// When flagFunc is set, print function declarations.
	flagFunc bool
	// When flagGlobal is set, print global declarations.
	flagGlobal bool
	// When flagType is set, print type definitions.
	flagType bool
	// When flagOutputGo is set, output as Go literals.
	flagOutputGo bool
	// When flagOutputIni is set, output as ini key-value pairs.
	flagOutputIni bool
	// When flagOutputFiles is set, output to known source files.
	flagOutputFiles bool
)

func main() {
	flag.BoolVar(&flagFunc, "func", false, "print function declarations")
	flag.BoolVar(&flagGlobal, "global", false, "print global declarations")
	flag.BoolVar(&flagType, "type", false, "print type definitions")
	flag.BoolVar(&flagOutputGo, "output_go", false, "output as Go literals")
	flag.BoolVar(&flagOutputIni, "output_ini", false, "output as ini key-value pairs")
	flag.BoolVar(&flagOutputFiles, "output_files", false, "output to known source files")
	flag.Parse()
	if !flagFunc && !flagGlobal && !flagType {
		// Default to printing functions if no output preference has been
		// specified.
		flagFunc = true
	}
	for _, path := range flag.Args() {
		if err := parseFile(path); err != nil {
			log.Fatal(err)
		}
	}
}

// parseFile parses the given Playstation 1 symbol file.
func parseFile(path string) error {
	syms, err := sym.ParseFile(path)
	if err != nil {
		return errutil.Err(err)
	}

	// Parse type definitions.
	types := make(map[string]ctypes.Type)
	defs := make(map[string]*ast.TypeDef)
	// Add dummy type definition for "__vtbl_ptr_type", which is used in d.sym
	// but never defined.
	vtblTyp := &ctypes.Struct{Name: "__vtbl_ptr_type"}
	types[vtblTyp.Name] = vtblTyp
	defs[vtblTyp.Name] = &ast.TypeDef{Type: vtblTyp, Aliases: []string{vtblTyp.Name}}
	intType := &ctypes.Basic{Kind: ctypes.Int}
	types["unknown"] = intType
	defs["unknown"] = &ast.TypeDef{Type: intType, Aliases: []string{"unknown"}}
	var structOrder []string
	for {
		var missing bool
		structOrder, missing = parseTypes(types, defs, syms)
		//dbg.Println("missing:", missing)
		if !missing {
			break
		}
	}

	// Parse type alises.
	parseTypeAliases(types, defs, syms)

	// Parse function definitions.
	functions := parseFuncs(types, syms)

	// Print function definitions.
	if flagFunc {
		var fs OrderByAddr
		for _, f := range functions {
			fs = append(fs, f)
		}
		sort.Sort(fs)
		if flagOutputFiles {
			src := make(map[string][]*Function)
			for _, f := range fs {
				path := unixPath(f.Path)
				src[path] = append(src[path], f)
			}
			var keys []string
			for key := range src {
				keys = append(keys, key)
			}
			sort.Strings(keys)
			for _, path := range keys {
				dir := filepath.Join("_dump_", filepath.Dir(path))
				dstPath := filepath.Join("_dump_", path)
				if err := os.MkdirAll(dir, 0755); err != nil {
					return errutil.Err(err)
				}
				fw, err := os.Create(dstPath)
				if err != nil {
					return errutil.Err(err)
				}
				defer fw.Close()

				fs := src[path]
				if flagOutputGo {
					// Output sources.
					//
					// Example output:
					//    struct Source sources[] = {
					//       {0x80155E1C, "diabpsx/psxsrc/fmv.cpp"},
					//    };
					if _, err := fmt.Fprintln(fw, "struct Source sources[] = {"); err != nil {
						return errutil.Err(err)
					}
					for _, f := range fs {
						if _, err := fmt.Fprintf(fw, "\t{0x%08X, %q},\n", f.Addr, path); err != nil {
							return errutil.Err(err)
						}
					}
					if _, err := fmt.Fprintln(fw, "};"); err != nil {
						return errutil.Err(err)
					}

					// Output function declarations.
					//
					// Example output:
					//    struct Ident functions[] = {
					//       {0x80155E1C, "_cd_seek", "void _cd_seek(int sec)"},
					//    };
					if _, err := fmt.Fprintln(fw, "struct Ident functions[] = {"); err != nil {
						return errutil.Err(err)
					}
					for _, f := range fs {
						if _, err := fmt.Fprintf(fw, "\t{0x%08X, %q, %q},\n", f.Addr, f.Name, f.Sig()); err != nil {
							return errutil.Err(err)
						}
					}
					if _, err := fmt.Fprintln(fw, "};"); err != nil {
						return errutil.Err(err)
					}
				} else if flagOutputIni {
					for _, f := range fs {
						const format = `
[%s]
psx_jp   = 0x%08X
win_109b =
mac_109  =

`
						if _, err := fmt.Fprintf(fw, format[1:], f.Name, f.Addr); err != nil {
							return errutil.Err(err)
						}
					}
				} else {
					for _, f := range fs {
						if _, err := fmt.Fprintf(fw, "%v\n\n", f); err != nil {
							return errutil.Err(err)
						}
					}
				}
			}
		} else if flagOutputGo {
			// Output sources.
			//
			// Example output:
			//    struct Source sources[] = {
			//       {0x80155E1C, "diabpsx/psxsrc/fmv.cpp"},
			//    };
			fmt.Println("struct Source sources[] = {")
			for _, f := range fs {
				path := strings.ToLower(f.Path)
				path = strings.Replace(path, `\`, "/", -1)
				if len(path) > len("c:/") && strings.HasPrefix(path[1:], ":/") {
					path = path[len("c:/"):]
				}
				fmt.Printf("\t{0x%08X, %q},\n", f.Addr, path)
			}
			fmt.Println("};")

			// Output function declarations.
			//
			// Example output:
			//    struct Ident functions[] = {
			//       {0x80155E1C, "_cd_seek", "void _cd_seek(int sec)"},
			//    };
			fmt.Println("struct Ident functions[] = {")
			for _, f := range fs {
				fmt.Printf("\t{0x%08X, %q, %q},\n", f.Addr, f.Name, f.Sig())
			}
			fmt.Println("};")
		} else {
			for _, f := range fs {
				fmt.Printf("%v\n\n", f)
			}
		}
	}

	// Print type definitions.
	if flagType {
		var (
			enums  []string
			basics []string
			funcs  []string
			//structs []string
			unions []string
		)
		for name, typ := range types {
			switch typ.(type) {
			case *ctypes.Basic:
				if name == "unknown" {
					continue
				}
				if name == "__int64" {
					// Ignore __int64 type, as IDA gives the following error for it.
					//
					//    "Error: The current type can not be short or long"
				}
				basics = append(basics, name)
			case *ctypes.Pointer:
				basics = append(basics, name)
			case *ctypes.Array:
				basics = append(basics, name)
			case *ctypes.Enum:
				enums = append(enums, name)
			case *ctypes.Struct:
				// nothing to do.
				//structs = append(structs, name)
			case *ctypes.Union:
				unions = append(unions, name)
			case *ctypes.Func:
				funcs = append(funcs, name)
			default:
				panic(fmt.Sprintf("support for type %T not yet implemented", typ))
			}
		}
		sort.Strings(enums)
		sort.Strings(basics)
		basics = append([]string{"unknown"}, basics...)
		sort.Strings(funcs)
		//sort.Strings(structs)
		sort.Strings(unions)
		for _, name := range enums {
			if def, ok := defs[name]; ok {
				fmt.Println(def)
			} else if typ, ok := types[name]; ok {
				fmt.Printf("%s;\n", typ)
			} else {
				panic(fmt.Sprintf("missing enum type %q", name))
			}
			fmt.Println()
		}
		for _, name := range basics {
			if def, ok := defs[name]; ok {
				fmt.Println(def)
			} else {
				panic(fmt.Sprintf("missing basic type %q", name))
			}
			fmt.Println()
		}
		for _, name := range funcs {
			if def, ok := defs[name]; ok {
				fmt.Println(def)
			} else {
				panic(fmt.Sprintf("missing function type %q", name))
			}
			fmt.Println()
		}
		for _, name := range structOrder {
			if def, ok := defs[name]; ok {
				fmt.Println(def)
			} else {
				panic(fmt.Sprintf("missing struct type %q", name))
			}
			fmt.Println()
		}
		for _, name := range unions {
			if isFake(name) {
				//dbg.Printf("ignoring type definition of unnnamed union %q: %v", name, types[name])
				continue
			}
			if def, ok := defs[name]; ok {
				fmt.Println(def)
			} else {
				panic(fmt.Sprintf("missing union type %q", name))
			}
			fmt.Println()
		}
	}

	if flagGlobal {
		panic("support for printing global declarations not yet implemented.")
	}

	return nil
}

// unixPath converts the given absolute Windows path into a relative Unix path.
//
// Examples:
//    * Input:  "C:\DIABPSX\GLIBDEV\SOURCE\TASKER.C"
//    * Output: "diabpsx/glibdev/source/tasker.c"
func unixPath(path string) string {
	path = strings.ToLower(path)
	path = strings.Replace(path, `\`, "/", -1)
	if len(path) > len("c:/") && strings.HasPrefix(path[1:], ":/") {
		path = path[len("c:/"):]
	}
	return path
}

// Function represents a function definition.
type Function struct {
	// Function name.
	Name string
	// Source file path.
	Path string
	// Function address.
	Addr uint32
	// Function type.
	Type *ctypes.Func
	// Function parameters.
	Params []ctypes.Var
	// Local variables.
	Locals []ctypes.Var
}

// Sig returns a string representation of the function signature.
func (f *Function) Sig() string {
	buf := &bytes.Buffer{}
	fmt.Fprintf(buf, "%s %s(", f.Type.Result.TypeName(), f.Name)
	for i, param := range f.Params {
		if i > 0 {
			buf.WriteString(", ")
		}
		buf.WriteString(param.String())
	}
	buf.WriteString(")")
	return buf.String()
}

func (f *Function) String() string {
	buf := &bytes.Buffer{}
	fmt.Fprintf(buf, "// Path: %s\n", f.Path)
	fmt.Fprintf(buf, "// Addr: 0x%08X\n", f.Addr)
	fmt.Fprintf(buf, "%s {\n", f.Sig())
	for _, local := range f.Locals {
		fmt.Fprintf(buf, "\t%s;\n", local)
	}
	buf.WriteString("}")
	return buf.String()
}

// A FuncID specifies a given function, based on its function name and address.
//
// Examples:
//    FuncID = "0x80163D9C" + "___" + "PRIM_GetPrim__FPP7LINE_F2"
type FuncID string

func funcID(addr uint32, name string) FuncID {
	return FuncID(fmt.Sprintf("0x%08X___%s", addr, name))
}

// parseFuncs parses and returns function definitions from the stream
// of symbols.
func parseFuncs(types map[string]ctypes.Type, syms []sym.Symbol) map[FuncID]*Function {
	fs := make(map[FuncID]*Function)
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data8C:
			// Function definition.
			addr := s.Value()
			id := funcID(addr, data.Name)
			f, ok := fs[id]
			if !ok {
				f = &Function{Addr: addr}
				fs[id] = f
			}
			f.Name = data.Name
			f.Path = data.Path
			n := parseFuncVars(f, types, syms[i+1:])
			i += n + 1
		case *sym.Data94:
			// Parse function return type.
			switch data.DefKind {
			case DefKindGlobalOrFunc1, DefKindGlobalOrFunc2:
				basic := data.Type & 0x000F
				typ := parseBasicType(basic)
				mods := data.Type & 0xFFF0
				typ = parseTypeMods(typ, mods, nil)
				t, ok := typ.(*ctypes.Func)
				if !ok {
					continue
				}
				addr := s.Value()
				id := funcID(addr, data.Name)
				f, ok := fs[id]
				if !ok {
					f = &Function{Addr: addr}
					fs[id] = f
				}
				f.Type = t
				f.Name = data.Name
			}
		case *sym.Data96:
			// Parse function return type.
			switch data.DefKind {
			case DefKindGlobalOrFunc1, DefKindGlobalOrFunc2:
				basic := data.Type & 0x000F
				var typ ctypes.Type
				switch basic {
				case sym.TypeEnum, sym.TypeStruct, sym.TypeUnion:
					// Lookup type name from key.
					var ok bool
					typ, ok = types[data.Key]
					if !ok {
						panic(fmt.Sprintf("unable to locate %q", data.Key))
					}
				default:
					typ = parseBasicType(basic)
				}
				mods := data.Type & 0xFFF0
				typ = parseTypeMods(typ, mods, data.Lengths)
				t, ok := typ.(*ctypes.Func)
				if !ok {
					continue
				}
				addr := s.Value()
				id := funcID(addr, data.Val)
				f, ok := fs[id]
				if !ok {
					f = &Function{Addr: addr}
					fs[id] = f
				}
				f.Type = t
				f.Name = data.Val
			}
		}
	}
	return fs
}

// parseFuncVars parses function parameters and local variables from the stream
// of symbols.
func parseFuncVars(f *Function, types map[string]ctypes.Type, syms []sym.Symbol) int {
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			switch data.DefKind {
			case DefKindParam1, DefKindParam2:
				basic := data.Type & 0x000F
				typ := parseBasicType(basic)
				mods := data.Type & 0xFFF0
				typ = parseTypeMods(typ, mods, nil)
				param := ctypes.Var{Type: typ, Name: data.Name}
				f.Params = append(f.Params, param)
			case DefKindLocal1, DefKindLocal2:
				basic := data.Type & 0x000F
				typ := parseBasicType(basic)
				mods := data.Type & 0xFFF0
				typ = parseTypeMods(typ, mods, nil)
				local := ctypes.Var{Type: typ, Name: data.Name}
				f.Locals = append(f.Locals, local)
			}
		case *sym.Data96:
			switch data.DefKind {
			case DefKindParam1, DefKindParam2:
				basic := data.Type & 0x000F
				var typ ctypes.Type
				switch basic {
				case sym.TypeEnum, sym.TypeStruct, sym.TypeUnion:
					// Lookup type name from key.
					var ok bool
					typ, ok = types[data.Key]
					if !ok {
						panic(fmt.Sprintf("unable to locate %q", data.Key))
					}
				default:
					typ = parseBasicType(basic)
				}
				mods := data.Type & 0xFFF0
				typ = parseTypeMods(typ, mods, data.Lengths)
				param := ctypes.Var{Type: typ, Name: data.Val}
				f.Params = append(f.Params, param)
			case DefKindLocal1, DefKindLocal2:
				basic := data.Type & 0x000F
				var typ ctypes.Type
				switch basic {
				case sym.TypeEnum, sym.TypeStruct, sym.TypeUnion:
					// Lookup type name from key.
					var ok bool
					typ, ok = types[data.Key]
					if !ok {
						panic(fmt.Sprintf("unable to locate %q", data.Key))
					}
				default:
					typ = parseBasicType(basic)
				}
				mods := data.Type & 0xFFF0
				typ = parseTypeMods(typ, mods, data.Lengths)
				local := ctypes.Var{Type: typ, Name: data.Val}
				f.Locals = append(f.Locals, local)
			}
		case *sym.Data8E:
			// End of function definition.
			return i
		}
	}
	panic("unreachable")
}

// parseTypes parses and returns type definitions from the stream of symbols.
func parseTypes(types map[string]ctypes.Type, defs map[string]*ast.TypeDef, syms []sym.Symbol) (structOrder []string, missing bool) {
	// The MonsterStruct structure is defined twice, with one field changed. Only
	// track the order of each structure name once.
	structs := make(map[string]bool)
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			switch data.DefKind {
			case DefKindTypeAlias:
				// Type alias of basic type.
				basic := data.Type & 0x000F
				typ := parseBasicType(basic)
				mods := data.Type & 0xFFF0
				typ = parseTypeMods(typ, mods, nil)
				if old, ok := types[data.Name]; ok {
					if !old.Equal(typ) {
						//dbg.Println("old:", old)
						//dbg.Println("typ:", typ)
					}
				}
				//dbg.Printf("alias %q: %v\n", data.Name, typ)
				types[data.Name] = typ
				defs[data.Name] = &ast.TypeDef{Type: typ, Aliases: []string{data.Name}}
			case DefKindEnumType:
				// Enum type definition.
				typ := &ctypes.Enum{
					Name: data.Name,
				}
				n := parseEnumType(typ, syms[i+1:])
				i += n + 1
				if old, ok := types[data.Name]; ok {
					if !old.Equal(typ) {
						//dbg.Println("old:", old)
						//dbg.Println("typ:", typ)
					}
				}
				//dbg.Printf("enum %q: %v\n", data.Name, typ)
				if !isEnumPresent(types, typ) {
					types[data.Name] = typ
				}
			case DefKindStructType:
				// Struct type definition.
				typ := &ctypes.Struct{
					Name: data.Name,
				}
				old, ok := types[data.Name]
				types[data.Name] = typ
				n, partial := parseStructType(typ, types, syms[i+1:])
				i += n + 1
				if partial {
					missing = true
					//dbg.Println("partial struct:", typ)
					continue
				}
				if !structs[typ.Name] {
					structOrder = append(structOrder, typ.Name)
					structs[typ.Name] = true
				}
				if ok {
					if !old.Equal(typ) {
						//dbg.Println("old:", old)
						//dbg.Println("typ:", typ)
					}
				}
				//dbg.Printf("struct %q: %v\n", data.Name, typ)
			case DefKindUnionType:
				// Union type definition.
				typ := &ctypes.Union{
					Name: data.Name,
				}
				old, ok := types[data.Name]
				types[data.Name] = typ
				n, partial := parseUnionType(typ, types, syms[i+1:])
				i += n + 1
				if partial {
					missing = true
					//dbg.Println("partial union:", typ)
					continue
				}
				if ok {
					if !old.Equal(typ) {
						//dbg.Println("old:", old)
						//dbg.Println("typ:", typ)
					}
				}
			}
		}
	}
	return structOrder, missing
}

// parseTypeAliases parses and returns type aliases from the stream of symbols.
func parseTypeAliases(types map[string]ctypes.Type, defs map[string]*ast.TypeDef, syms []sym.Symbol) {
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data96:
			switch data.DefKind {
			case DefKindTypeAlias:
				// Type alias key-value pair.
				basic := data.Type & 0x000F
				switch basic {
				case sym.TypeEnum, sym.TypeStruct, sym.TypeUnion:
					// Lookup type name from key.
					orig, ok := types[data.Key]
					if !ok {
						panic(fmt.Sprintf("unable to locate %q", data.Key))
					}
					// Handle type modifiers.
					mods := data.Type & 0xFFF0
					typ := parseTypeMods(orig, mods, data.Lengths)
					alias := true
					nptrs := 0
					outer := typ
					for !outer.Equal(orig) {
						switch t := outer.(type) {
						case *ctypes.Basic, *ctypes.Enum, *ctypes.Struct, *ctypes.Union:
							// nothing to do.
						case *ctypes.Pointer:
							outer = t.Elem
							nptrs++
						case *ctypes.Array:
							outer = t.Elem
							panic("support for array type alias not yet implemented")
						case *ctypes.Func:
							outer = t.Result
							alias = false
						default:
							panic(fmt.Sprintf("support for type %T not yet implemented", t))
						}
					}
					// Add type alias.
					if def, ok := defs[data.Key]; alias && ok {
						name := strings.Repeat("*", nptrs) + data.Val
						def.Aliases = append(def.Aliases, name)
					} else {
						def := &ast.TypeDef{Type: typ, Aliases: []string{data.Val}}
						types[data.Val] = typ
						defs[data.Val] = def
					}
					//dbg.Printf("alias %q: %v\n", data.Val, typ)
				default:
					orig := parseBasicType(basic)
					mods := data.Type & 0xFFF0
					typ := parseTypeMods(orig, mods, data.Lengths)
					def := &ast.TypeDef{Type: typ, Aliases: []string{data.Val}}
					types[data.Val] = typ
					defs[data.Val] = def
					//dbg.Printf("alias %q: %v\n", data.Val, typ)
				}
			}
		}
	}
}

// parseStructType parses a struct type from the stream of symbols.
func parseStructType(typ *ctypes.Struct, types map[string]ctypes.Type, syms []sym.Symbol) (n int, partial bool) {
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			switch data.DefKind {
			case DefKindStructField1, DefKindStructField2:
				basic := data.Type & 0x000F
				t := parseBasicType(basic)
				mods := data.Type & 0xFFF0
				t = parseTypeMods(t, mods, nil)
				field := ctypes.Var{Type: t, Name: data.Name}
				typ.Fields = append(typ.Fields, field)
			default:
				panic(fmt.Sprintf("support for DefKind %04X not yet implemented", uint16(data.DefKind)))
			}
		case *sym.Data96:
			switch data.DefKind {
			case DefKindStructField1:
				basic := data.Type & 0x000F
				var t ctypes.Type
				switch basic {
				case sym.TypeEnum, sym.TypeStruct, sym.TypeUnion:
					// Lookup type name from key.
					var ok bool
					t, ok = types[data.Key]
					if !ok {
						//dbg.Printf("unable to locate %q", data.Key)
						partial = true
						continue
					}
				default:
					t = parseBasicType(basic)
				}
				mods := data.Type & 0xFFF0
				t = parseTypeMods(t, mods, data.Lengths)
				name := data.Val
				if data.Key == "__vtbl_ptr_type" && name == ".vf" {
					name = "_vf"
				}
				field := ctypes.Var{Type: t, Name: name}
				typ.Fields = append(typ.Fields, field)
			case DefKindEOS:
				if data.Key != typ.Name {
					panic(fmt.Sprintf("expected %q, got %q", typ.Name, data.Key))
				}
				if data.Val != ".eos" {
					panic(fmt.Sprintf(`expected ".eos", got %q`, data.Val))
				}
				return i, partial
			default:
				panic(fmt.Sprintf("support for DefKind %04X not yet implemented", uint16(data.DefKind)))
			}
		default:
			panic(fmt.Sprintf("support for symbol data type %T not yet implemented", data))
		}
	}
	panic("unreachable")
}

// parseUnionType parses a union type from the stream of symbols.
func parseUnionType(typ *ctypes.Union, types map[string]ctypes.Type, syms []sym.Symbol) (n int, partial bool) {
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			switch data.DefKind {
			case DefKindUnionField:
				basic := data.Type & 0x000F
				t := parseBasicType(basic)
				mods := data.Type & 0xFFF0
				t = parseTypeMods(t, mods, nil)
				field := ctypes.Var{Type: t, Name: data.Name}
				typ.Fields = append(typ.Fields, field)
			default:
				panic(fmt.Sprintf("support for DefKind %04X not yet implemented", uint16(data.DefKind)))
			}
		case *sym.Data96:
			switch data.DefKind {
			case DefKindUnionField:
				basic := data.Type & 0x000F
				var t ctypes.Type
				switch basic {
				case sym.TypeEnum, sym.TypeStruct, sym.TypeUnion:
					// Lookup type name from key.
					var ok bool
					t, ok = types[data.Key]
					if !ok {
						//dbg.Printf("unable to locate %q", data.Key)
						partial = true
						continue
					}
				default:
					t = parseBasicType(basic)
				}
				mods := data.Type & 0xFFF0
				t = parseTypeMods(t, mods, data.Lengths)
				field := ctypes.Var{Type: t, Name: data.Val}
				typ.Fields = append(typ.Fields, field)
			case DefKindEOS:
				if data.Key != typ.Name {
					panic(fmt.Sprintf("expected %q, got %q", typ.Name, data.Key))
				}
				if data.Val != ".eos" {
					panic(fmt.Sprintf(`expected ".eos", got %q`, data.Val))
				}
				return i, partial
			default:
				panic(fmt.Sprintf("support for DefKind %04X not yet implemented", uint16(data.DefKind)))
			}
		default:
			panic(fmt.Sprintf("support for symbol data type %T not yet implemented", data))
		}
	}
	panic("unreachable")
}

// parseEnumType parses an enum type from the stream of symbols.
func parseEnumType(typ *ctypes.Enum, syms []sym.Symbol) int {
	for i := 0; i < len(syms); i++ {
		s := syms[i]
		switch data := s.Data().(type) {
		case *sym.Data94:
			switch data.DefKind {
			case DefKindEnumMember:
				member := &ctypes.EnumMember{
					Name: data.Name,
					// TODO: Handle negative values (e.g. 0xFFFFFFFF).
					Val: int(s.Value()),
				}
				typ.Members = append(typ.Members, member)
			default:
				panic(fmt.Sprintf("support for DefKind %04X not yet implemented", uint16(data.DefKind)))
			}
		case *sym.Data96:
			switch data.DefKind {
			case DefKindEOS:
				if data.Key != typ.Name {
					panic(fmt.Sprintf("expected %q, got %q", typ.Name, data.Key))
				}
				if data.Val != ".eos" {
					panic(fmt.Sprintf(`expected ".eos", got %q`, data.Val))
				}
				sort.Sort(OrderByValue(typ.Members))
				return i
			default:
				panic(fmt.Sprintf("support for DefKind %04X not yet implemented", uint16(data.DefKind)))
			}
		default:
			panic(fmt.Sprintf("support for symbol data type %T not yet implemented", data))
		}
	}
	panic("unreachable")
}

// parseBasicType parses and returns a basic type based on the given symbol type
// specifier.
func parseBasicType(symType sym.Type) ctypes.Type {
	switch symType & 0x000F {
	case sym.TypeUnknown:
		return &ctypes.Basic{Kind: ctypes.Unknown}
	case sym.TypeVoid:
		return &ctypes.Basic{Kind: ctypes.Void}
	case sym.TypeChar:
		return &ctypes.Basic{Kind: ctypes.Char}
	case sym.TypeShort:
		return &ctypes.Basic{Kind: ctypes.Short}
	case sym.TypeInt:
		return &ctypes.Basic{Kind: ctypes.Int}
	case sym.TypeLong:
		return &ctypes.Basic{Kind: ctypes.Long}
	case sym.TypeFloat:
		return &ctypes.Basic{Kind: ctypes.Float}
	case sym.TypeDouble:
		return &ctypes.Basic{Kind: ctypes.Double}
	case sym.TypeUnsignedChar:
		return &ctypes.Basic{Kind: ctypes.UnsignedChar}
	case sym.TypeUnsignedShort:
		return &ctypes.Basic{Kind: ctypes.UnsignedShort}
	case sym.TypeUnsignedInt:
		return &ctypes.Basic{Kind: ctypes.UnsignedInt}
	case sym.TypeUnsignedLong:
		return &ctypes.Basic{Kind: ctypes.UnsignedLong}
	default:
		panic(fmt.Sprintf("support for basic type 0x%04X not yet implemented", uint16(symType&0x000F)))
	}
}

// parseTypeMods applies the given type modifiers to the provided type.
func parseTypeMods(typ ctypes.Type, mods sym.Type, lengths []uint32) ctypes.Type {
	// Parse type modifiers.
	const mask = 0x3
	arrayNum := len(lengths) - 1
	for i := 6; i >= 0; i-- {
		m := uint16(mods) >> (4 + (2 * uint16(i))) & mask
		switch {
		case m == sym.ModPointer:
			// Pointer type.
			typ = &ctypes.Pointer{
				Elem: typ,
			}
		case m == sym.ModArray:
			// Array type.
			typ = &ctypes.Array{
				Elem: typ,
				Len:  int(lengths[arrayNum]),
			}
			arrayNum--
		case m == sym.ModFunction:
			// Function type.
			typ = &ctypes.Func{
				Result: typ,
			}
		}
	}
	return typ
}

// Definition kinds.
const (
	DefKindLocal1        = 0x0001 // local variable definition.
	DefKindGlobalOrFunc1 = 0x0002 // global variable or function definition.
	DefKindGlobalOrFunc2 = 0x0003 // global variable or function definition.
	DefKindLocal2        = 0x0004 // local variable definition.
	//DefKind0006          = 0x0006 // error?
	DefKindStructField1 = 0x0008 // structure field definition.
	DefKindParam1       = 0x0009 // function parameter definition.
	DefKindStructType   = 0x000A // structure type definition.
	DefKindUnionField   = 0x000B // union field definition.
	DefKindUnionType    = 0x000C // union type definition.
	DefKindTypeAlias    = 0x000D // type alias definition.
	DefKindEnumType     = 0x000F // enum type definition.
	DefKindEnumMember   = 0x0010 // enum member definition.
	DefKindParam2       = 0x0011 // function parameter definition.
	DefKindStructField2 = 0x0012 // structure field definition.
	DefKindEOS          = 0x0066 // end of symbol marker.
)

// OrderByValue implements the sort.Sort interface, sorting enum members by
// value.
type OrderByValue []*ctypes.EnumMember

// Len is the number of elements in the collection.
func (ms OrderByValue) Len() int {
	return len(ms)
}

// Less reports whether the element with index i should sort before the element
// with index j.
func (ms OrderByValue) Less(i, j int) bool {
	if ms[i].Val == ms[j].Val {
		return ms[i].Name < ms[j].Name
	}
	return ms[i].Val < ms[j].Val
}

// Swap swaps the elements with indexes i and j.
func (ms OrderByValue) Swap(i, j int) {
	ms[i], ms[j] = ms[j], ms[i]
}

// isFake reports whether the given name is a fake name used for unnamed debug
// symbols.
func isFake(name string) bool {
	return strings.HasPrefix(name, ".") && strings.HasSuffix(name, "fake")
}

// isEnumPresents reports whether the given enum type is present in the type
// map.
func isEnumPresent(types map[string]ctypes.Type, t *ctypes.Enum) bool {
	for _, u := range types {
		if u, ok := u.(*ctypes.Enum); ok {
			if isEnumMembersEqual(t, u) {
				//dbg.Printf("ignoring enum %q which is equal to %q", t.Name, u.Name)
				return true
			}
		}
	}
	return false
}

// isEnumEqual reports whether the enum members of t and u are equal.
func isEnumMembersEqual(t, u *ctypes.Enum) bool {
	if len(t.Members) != len(u.Members) {
		return false
	}
	for i := range t.Members {
		x, y := t.Members[i], u.Members[i]
		if *x != *y {
			return false
		}
	}
	return true
}

// OrderByAddr implements the sort.Sort interface, sorting function definitions
// by address.
type OrderByAddr []*Function

// Len is the number of elements in the collection.
func (fs OrderByAddr) Len() int {
	return len(fs)
}

// Less reports whether the element with index i should sort before the element
// with index j.
func (fs OrderByAddr) Less(i, j int) bool {
	switch {
	case fs[i].Addr < fs[j].Addr:
		return true
	case fs[i].Addr == fs[j].Addr:
		return fs[i].Name < fs[j].Name
	default:
		return false
	}
}

// Swap swaps the elements with indexes i and j.
func (fs OrderByAddr) Swap(i, j int) {
	fs[i], fs[j] = fs[j], fs[i]
}
