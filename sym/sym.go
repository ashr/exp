// Package sym provides access to Playstation 1 symbol files.
package sym

import (
	"bufio"
	"bytes"
	"encoding/binary"
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"os"

	"github.com/mewkiz/pkg/errutil"
)

// TODO: Remove debug output.

// dbg is a logger which prefixes debug messages with the file name and line
// number of callees.
var dbg = log.New(ioutil.Discard, "", log.Lshortfile)

// TODO: Figure out what the unknown data represents (search for unknown, buf
// and []byte).

// TODO: Add test cases covering symbol kind 0x84, 0x86, 0x90, 0x92, 0x98 and
// 0x9A.

// ParseFile parses the given PS1 symbol file.
func ParseFile(path string) ([]Symbol, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, errutil.Err(err)
	}
	defer f.Close()
	return Parse(f)
}

// ParseBytes parses the given PS1 symbol file, reading from b.
func ParseBytes(b []byte) ([]Symbol, error) {
	return Parse(bytes.NewReader(b))
}

// Parse parses the given PS1 symbol file, reading from r.
func Parse(r io.Reader) ([]Symbol, error) {
	// Parse file header.
	br := bufio.NewReader(r)
	if err := parseHeader(br); err != nil {
		return nil, errutil.Err(err)
	}

	// Parse symbols.
	var syms []Symbol
	for i := 0; ; i++ {
		sym, err := parseSymbol(br, i)
		if err != nil {
			if err == io.EOF {
				break
			}
			return nil, errutil.Err(err)
		}
		syms = append(syms, sym)
	}

	return syms, nil
}

// parseHeader parsers the header of the given PS1 symbol file.
func parseHeader(r io.Reader) error {
	// Verify PS1 symbol file signature.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	signature := []byte{'M', 'N', 'D', 0x01}
	if !bytes.Equal(buf, signature) {
		return fmt.Errorf("sym.parseHeader: invalid PS1 symbol file signature; expected %q, got %q", signature, buf)
	}

	// Read unknown header data.
	buf = make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	//dbg.Printf("header data: % X", buf)

	return nil
}

// parseSymbol parses a debug symbol of the given PS1 symbol file.
func parseSymbol(r io.Reader, i int) (Symbol, error) {
	// Parse symbol value.
	var value uint32
	if err := binary.Read(r, binary.LittleEndian, &value); err != nil {
		if err == io.EOF {
			return nil, io.EOF
		}
		return nil, errutil.Err(err)
	}

	// Symbol kind.
	//
	//    0x01 = compiler and C runtime definitions.
	//    0x02 = global variable or function address.
	//    0x06 = class method?
	//    0x80 = line marker
	//    0x82 = ?
	//    0x84 = ?
	//    0x86 = ?
	//    0x88 = named source file.
	//    0x8A = unnamed source file.
	//    0x8C = function definition start.
	//    0x8E = function definition stop.
	//    0x90 = local variable definition start.
	//    0x92 = local variable definition stop.
	//    0x94 = definition; such as global variable, local variable, function,
	//           enumerable type, enumerable member, structure type or structure
	//           field definition.
	//    0x96 = meta symbol; key-value pair.
	//    0x98 = ?
	//    0x9A = ?
	var kind uint8

	// Parse symbol kind.
	if err := binary.Read(r, binary.LittleEndian, &kind); err != nil {
		return nil, errutil.Err(err)
	}
	switch kind {
	case 0x80, 0x82, 0x86, 0x98:
		// ignore.
	default:
		dbg.Println()
		dbg.Printf("=== [ symbol %d ] ===\n", i)
		dbg.Println()
		dbg.Printf("value: %08X", value)
		dbg.Printf("kind: %02X", kind)
	}

	// Parse symbol based on symbol kind.
	var data interface{}
	var err error
	switch kind {
	case 0x01:
		data, err = parseSymbol01(r)
	case 0x02:
		data, err = parseSymbol02(r)
	case 0x80:
		data, err = parseSymbol80(r)
	case 0x82:
		data, err = parseSymbol82(r)
	case 0x84:
		data, err = parseSymbol84(r)
	case 0x86:
		data, err = parseSymbol86(r)
	case 0x88:
		data, err = parseSymbol88(r)
	case 0x8A:
		data, err = parseSymbol8A(r)
	case 0x8C:
		data, err = parseSymbol8C(r)
	case 0x8E:
		data, err = parseSymbol8E(r)
	case 0x90:
		data, err = parseSymbol90(r)
	case 0x92:
		data, err = parseSymbol92(r)
	case 0x94:
		data, err = parseSymbol94(r)
	case 0x96:
		data, err = parseSymbol96(r)
	case 0x98:
		data, err = parseSymbol98(r)
	case 0x9A:
		data, err = parseSymbol9A(r)
	default:
		panic(fmt.Sprintf("support for symbol kind %02X not yet implemented", kind))
	}
	if err != nil {
		return nil, errutil.Err(err)
	}
	return &symbol{value: value, kind: kind, data: data}, nil
}

// parseSymbol01 parses a debug symbol of kind 0x01.
func parseSymbol01(r io.Reader) (*Data01, error) {
	s, err := readString(r)
	if err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Println("s:", s)
	return &Data01{}, nil
}

// parseSymbol02 parses a debug symbol of kind 0x02.
func parseSymbol02(r io.Reader) (*Data02, error) {
	// Parse identifier name.
	name, err := readString(r)
	if err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Println("name:", name)
	return &Data02{}, nil
}

// parseSymbol80 parses a debug symbol of kind 0x80.
func parseSymbol80(r io.Reader) (*Data80, error) {
	// nothing to do.
	return nil, nil
}

// parseSymbol82 parses a debug symbol of kind 0x82.
func parseSymbol82(r io.Reader) (*Data82, error) {
	// Read unknown data.
	buf := make([]byte, 1)
	if _, err := io.ReadFull(r, buf); err != nil {
		return nil, errutil.Err(err)
	}
	//dbg.Printf("symbol 0x82 data: % X", buf)
	return &Data82{}, nil
}

// parseSymbol84 parses a debug symbol of kind 0x84.
func parseSymbol84(r io.Reader) (*Data84, error) {
	// Read unknown data.
	buf := make([]byte, 2)
	if _, err := io.ReadFull(r, buf); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("data: % X", buf)
	return &Data84{}, nil
}

// parseSymbol86 parses a debug symbol of kind 0x86.
func parseSymbol86(r io.Reader) (*Data86, error) {
	// Read unknown data.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return nil, errutil.Err(err)
	}
	//dbg.Printf("symbol 0x86 data: % X", buf)
	return &Data86{}, nil
}

// parseSymbol88 parses a debug symbol of kind 0x88.
func parseSymbol88(r io.Reader) (*Data88, error) {
	// Parse object count.
	data := new(Data88)
	if err := binary.Read(r, binary.LittleEndian, &data.NObjs); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("nobjs: %d", data.NObjs)

	// Parse source path.
	path, err := readString(r)
	if err != nil {
		return nil, errutil.Err(err)
	}
	data.Path = path
	dbg.Println("path:", path)

	return data, nil
}

// parseSymbol8A parses a debug symbol of kind 0x8A.
func parseSymbol8A(r io.Reader) (*Data8A, error) {
	// nothing to do.
	return nil, nil
}

// parseSymbol8C parses a debug symbol of kind 0x8C.
func parseSymbol8C(r io.Reader) (*Data8C, error) {
	data := new(Data8C)
	// Read unknown data.
	if _, err := io.ReadFull(r, data.Unknown[:]); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("data: % X", data.Unknown[:])

	// Parse source path.
	path, err := readString(r)
	if err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Println("path:", path)
	data.Path = path

	// Parse function name.
	name, err := readString(r)
	if err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Println("name:", name)
	data.Name = name

	return data, nil
}

// parseSymbol8E parses a debug symbol of kind 0x8E.
func parseSymbol8E(r io.Reader) (*Data8E, error) {
	// Parse object count.
	data := new(Data8E)
	if err := binary.Read(r, binary.LittleEndian, &data.Line); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("line: %d", data.Line)
	return data, nil
}

// parseSymbol90 parses a debug symbol of kind 0x90.
func parseSymbol90(r io.Reader) (*Data90, error) {
	// Read unknown data.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("data: % X", buf)
	return &Data90{}, nil
}

// parseSymbol92 parses a debug symbol of kind 0x92.
func parseSymbol92(r io.Reader) (*Data92, error) {
	// Read unknown data.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("data: % X", buf)
	return &Data92{}, nil
}

// parseSymbol94 parses a debug symbol of kind 0x94.
func parseSymbol94(r io.Reader) (*Data94, error) {
	// Parse definition kind.
	data := new(Data94)
	if err := binary.Read(r, binary.LittleEndian, &data.DefKind); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("defKind: %04X", data.DefKind)

	// Type. A type is made up of a 4-bit basic type specifyer, and a set of
	// 2-bit type modifiers.

	//     Basic type                                            xxxx
	//        Modifier                                        xx
	//           Modifier                                  xx
	//              Modifier                            xx
	//                 Modifier                      xx
	//                    Modifier                xx
	//                       Modifier          xx

	// Example.
	//
	//     int * f_0064() {}
	//
	// Interpretation.
	//
	//     int                                                   0100
	//        function                                        10
	//           pointer                                   01
	//                                                  00
	//                                               00
	//                                            00
	//                                         00
	//
	//                                  0x64 = 00 00 00 00 01 10 0100

	// Example.
	//
	//     int (*v_0094)();
	//
	// Interpretation.
	//
	//     int                                                   0100
	//        pointer                                         01
	//           function                                  10
	//                                                  00
	//                                               00
	//                                            00
	//                                         00
	//
	//                                  0x94 = 00 00 00 00 10 01 0100

	//    0000 = error
	//    0001 = void
	//    0002 = char
	//    0003 = short
	//    0004 = int
	//    0005 = long
	//    0006 = float
	//    0007 = double
	//    0008 = struct_type
	//    0009 = union
	//    000A = enum_type
	//    000B = enum_member
	//    000C = unsigned char
	//    000D = unsigned short
	//    000E = unsigned int
	//    000F = unsigned long

	//    0010 = error *
	//    0011 = void *
	//    0012 = char *
	//    0013 = short *
	//    0014 = int *
	//    0015 = long *
	//    0016 = float *
	//    0017 = double *
	//    0018 = struct_type *
	//    0019 = union *
	//    001A = enum_type *
	//    001B = enum_member *
	//    001C = unsigned char *
	//    001D = unsigned short *
	//    001E = unsigned int *
	//    001F = unsigned long *

	//    0020 = error function
	//    0021 = void function
	//    0022 = char function
	//    0023 = short function
	//    0024 = int function
	//    0025 = long function
	//    0026 = float function
	//    0027 = double function
	//    0028 = struct_type function
	//    0029 = union function
	//    002A = enum_type function
	//    002B = enum_member function
	//    002C = unsigned char function
	//    002D = unsigned short function
	//    002E = unsigned int function
	//    002F = unsigned long function

	//    0030 = error array
	//    0031 = void array
	//    0032 = char array
	//    0033 = short array
	//    0034 = int array
	//    0035 = long array
	//    0036 = float array
	//    0037 = double array
	//    0038 = struct_type array
	//    0039 = union array
	//    003A = enum_type array
	//    003B = enum_member array
	//    003C = unsigned char array
	//    003D = unsigned short array
	//    003E = unsigned int array
	//    003F = unsigned long array

	// Parse type.
	if err := binary.Read(r, binary.LittleEndian, &data.Type); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("typ: %04X;    %v", uint16(data.Type), data.Type)

	// Read unknown data.
	if _, err := io.ReadFull(r, data.Unknown[:]); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("data: % X", data.Unknown[:])

	// Parse identifier name.
	name, err := readString(r)
	if err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Println("name:", name)
	data.Name = name

	return data, nil
}

// parseSymbol96 parses a debug symbol of kind 0x96.
func parseSymbol96(r io.Reader) (*Data96, error) {
	data := new(Data96)
	// Parse definition kind.
	if err := binary.Read(r, binary.LittleEndian, &data.DefKind); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("defKind: %04X", data.DefKind)

	// Parse type.
	if err := binary.Read(r, binary.LittleEndian, &data.Type); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("typ: %04X;    %v", uint16(data.Type), data.Type)

	// Read unknown data.
	if _, err := io.ReadFull(r, data.Unknown[:]); err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Printf("data: % X", data.Unknown[:])

	// Parse array lengths.
	n := getNArrays(data.Type)
	for i := 0; i < n; i++ {
		// Parse type.
		var length uint32
		if err := binary.Read(r, binary.LittleEndian, &length); err != nil {
			return nil, errutil.Err(err)
		}
		data.Lengths = append(data.Lengths, length)
		dbg.Printf("length: %d", length)
	}

	// Parse key.
	var err error
	data.Key, err = readString(r)
	if err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Println("key:", data.Key)

	// Parse value.
	data.Val, err = readString(r)
	if err != nil {
		return nil, errutil.Err(err)
	}
	dbg.Println("val:", data.Val)

	return data, nil
}

// parseSymbol98 parses a debug symbol of kind 0x98.
func parseSymbol98(r io.Reader) (*Data98, error) {
	// Read unknown data.
	buf := make([]byte, 8)
	if _, err := io.ReadFull(r, buf); err != nil {
		return nil, errutil.Err(err)
	}
	//dbg.Printf("symbol 0x98 data: % X", buf)
	return &Data98{}, nil
}

// parseSymbol9A parses a debug symbol of kind 0x9A.
func parseSymbol9A(r io.Reader) (*Data9A, error) {
	// nothing to do.
	return nil, nil
}

// getNArrays returns the number of arrays contained within the given type.
func getNArrays(typ Type) int {
	n := 0
	for x := typ >> 4; x != 0; x >>= 2 {
		// Check if array modifier (0b11).
		if x&0x3 == 0x3 {
			n++
		}
	}
	return n
}

// readString parses and returns a length prefixed string.
func readString(r io.Reader) (string, error) {
	// Parse length prefix.
	var n uint8
	if err := binary.Read(r, binary.LittleEndian, &n); err != nil {
		return "", errutil.Err(err)
	}

	// Read string.
	buf := make([]byte, n)
	if _, err := io.ReadFull(r, buf); err != nil {
		return "", errutil.Err(err)
	}

	return string(buf), nil
}
