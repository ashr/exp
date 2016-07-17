// Package sym provides access to Playstation 1 symbol files.
package sym

import (
	"bufio"
	"bytes"
	"encoding/binary"
	"fmt"
	"io"
	"log"
	"os"

	"github.com/mewkiz/pkg/errutil"
)

// TODO: Remove debug output.

// dbg is a logger which prefixes debug messages with the file name and line
// number of callees.
var dbg = log.New(os.Stdout, "", log.Lshortfile)

// TODO: Figure out what the unknown data represents (search for unknown, buf
// and []byte).

// TODO: Add test cases covering symbol kind 0x84, 0x86, 0x90, 0x92, 0x98 and
// 0x9A.

// TODO: Consider the return type of Parse.
//
// Alternative 1.
//
//    // A File represents a PS1 symbol file.
//    type File struct { ... }
//
//    Parse(r io.Reader) (*File, error)
//
// Alternative 2.
//
//    // A SourceFile contains debug information about the symbols of a given
//    // source file.
//    type SourceFile struct { ... }
//
//    Parse(r io.Reader) ([]*SourceFile, error)
//
// Alternative 3.
//
//    // A Symbol represents a debug symbol, and has one of the following
//    // underlying types.
//    //
//    //    *Function
//    //    *Type
//    //    ...
//    type Symbol interface { ... }
//
//    Parse(r io.Reader) ([]Symbol, error)

// ParseFile parses the given PS1 symbol file.
func ParseFile(path string) error {
	f, err := os.Open(path)
	if err != nil {
		return errutil.Err(err)
	}
	defer f.Close()
	return Parse(f)
}

// ParseBytes parses the given PS1 symbol file, reading from b.
func ParseBytes(b []byte) error {
	return Parse(bytes.NewReader(b))
}

// Parse parses the given PS1 symbol file, reading from r.
func Parse(r io.Reader) error {
	// Parse file header.
	br := bufio.NewReader(r)
	if err := parseHeader(br); err != nil {
		return errutil.Err(err)
	}

	// Parse symbols.
	for {
		if err := parseSymbol(br); err != nil {
			if err == io.EOF {
				break
			}
			return errutil.Err(err)
		}
	}

	return nil
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
func parseSymbol(r io.Reader) error {
	// Parse symbol offset.
	var offset uint32
	if err := binary.Read(r, binary.LittleEndian, &offset); err != nil {
		if err == io.EOF {
			return io.EOF
		}
		return errutil.Err(err)
	}
	dbg.Printf("offset: %08X", offset)

	// Symbol kind.
	//
	//    0x01 = section/segment.
	//    0x02 = global variable placement (inside section).
	//    0x80 = ?
	//    0x82 = ?
	//    0x84 = ?
	//    0x86 = ?
	//    0x88 = named source file.
	//    0x8A = unnamed source file.
	//    0x8C = function definition.
	//    0x8E = ?
	//    0x90 = ?
	//    0x92 = ?
	//    0x94 = global variable, function, enumerable type, enumerable member,
	//           structure type or structure field definition.
	//    0x96 = meta symbol; key-value pair.
	//    0x98 = ?
	//    0x9A = ?
	var kind uint8

	// Parse symbol kind.
	if err := binary.Read(r, binary.LittleEndian, &kind); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("kind: %02X", kind)

	// Parse symbol based on symbol kind.
	switch kind {
	case 0x01:
		return parseSymbol01(r)
	case 0x02:
		return parseSymbol02(r)
	case 0x80:
		return parseSymbol80(r)
	case 0x82:
		return parseSymbol82(r)
	case 0x84:
		return parseSymbol84(r)
	case 0x86:
		return parseSymbol86(r)
	case 0x88:
		return parseSymbol88(r)
	case 0x8A:
		return parseSymbol8A(r)
	case 0x8C:
		return parseSymbol8C(r)
	case 0x8E:
		return parseSymbol8E(r)
	case 0x90:
		return parseSymbol90(r)
	case 0x92:
		return parseSymbol92(r)
	case 0x94:
		return parseSymbol94(r)
	case 0x96:
		return parseSymbol96(r)
	case 0x98:
		return parseSymbol98(r)
	case 0x9A:
		return parseSymbol9A(r)
	default:
		panic(fmt.Sprintf("support for symbol kind %02X not yet implemented", kind))
	}

	panic("unreachable")
}

// parseSymbol01 parses a debug symbol of kind 0x01.
func parseSymbol01(r io.Reader) error {
	s, err := readString(r)
	if err != nil {
		return errutil.Err(err)
	}
	dbg.Println("s:", s)
	return nil
}

// parseSymbol02 parses a debug symbol of kind 0x02.
func parseSymbol02(r io.Reader) error {
	// Parse identifier name.
	name, err := readString(r)
	if err != nil {
		return errutil.Err(err)
	}
	dbg.Println("name:", name)
	return nil
}

// parseSymbol80 parses a debug symbol of kind 0x80.
func parseSymbol80(r io.Reader) error {
	// nothing to do.
	return nil
}

// parseSymbol82 parses a debug symbol of kind 0x82.
func parseSymbol82(r io.Reader) error {
	// Read unknown data.
	buf := make([]byte, 1)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x82 data: % X", buf)
	return nil
}

// parseSymbol84 parses a debug symbol of kind 0x84.
func parseSymbol84(r io.Reader) error {
	// Read unknown data.
	buf := make([]byte, 2)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x84 data: % X", buf)
	return nil
}

// parseSymbol86 parses a debug symbol of kind 0x86.
func parseSymbol86(r io.Reader) error {
	// Read unknown data.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x86 data: % X", buf)
	return nil
}

// parseSymbol88 parses a debug symbol of kind 0x88.
func parseSymbol88(r io.Reader) error {
	// Read unknown data.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x88 data: % X", buf)

	// Parse source path.
	path, err := readString(r)
	if err != nil {
		return errutil.Err(err)
	}
	dbg.Println("path:", path)

	return nil
}

// parseSymbol8A parses a debug symbol of kind 0x8A.
func parseSymbol8A(r io.Reader) error {
	// nothing to do.
	return nil
}

// parseSymbol8C parses a debug symbol of kind 0x8C.
func parseSymbol8C(r io.Reader) error {
	// Read unknown data.
	buf := make([]byte, 20)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x8C data: % X", buf)

	// Parse source path.
	path, err := readString(r)
	if err != nil {
		return errutil.Err(err)
	}
	dbg.Println("path:", path)

	// Parse function name.
	name, err := readString(r)
	if err != nil {
		return errutil.Err(err)
	}
	dbg.Println("name:", name)

	return nil
}

// parseSymbol8E parses a debug symbol of kind 0x8E.
func parseSymbol8E(r io.Reader) error {
	// Read unknown data.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x8E data: % X", buf)
	return nil
}

// parseSymbol90 parses a debug symbol of kind 0x90.
func parseSymbol90(r io.Reader) error {
	// Read unknown data.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x90 data: % X", buf)
	return nil
}

// parseSymbol92 parses a debug symbol of kind 0x92.
func parseSymbol92(r io.Reader) error {
	// Read unknown data.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x92 data: % X", buf)
	return nil
}

// parseSymbol94 parses a debug symbol of kind 0x94.
func parseSymbol94(r io.Reader) error {
	// Definition kind.
	//
	//    0002 = global variable or function definition.
	//    0008 = structure field definition.
	//    000A = structure type definition.
	//    000D = type alias definition.
	//    000F = enum type definition.
	//    0010 = enum member definition.
	//    0066 = end of symbol marker.
	var defKind uint16

	// Parse definition kind.
	if err := binary.Read(r, binary.LittleEndian, &defKind); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("defKind: %04X", defKind)

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

	//    0000 = long long
	//    0001 = void
	//    0002 = char
	//    0003 = short
	//    0004 = int
	//    0005 = long
	//    0006 = float
	//    0007 = double
	//    0008 = struct_type
	//    0009 = ?
	//    000A = enum_type
	//    000B = ? (enum member)
	//    000C = unsigned char
	//    000D = unsigned short
	//    000E = unsigned int
	//    000F = unsigned long

	//    0010 = long long *
	//    0011 = void *
	//    0012 = char *
	//    0013 = short *
	//    0014 = int *
	//    0015 = long *
	//    0016 = float *
	//    0017 = double *
	//    0018 = struct_type *
	//    0019 = ? *
	//    001A = enum_type *
	//    001B = ? *
	//    001C = unsigned char *
	//    001D = unsigned short *
	//    001E = unsigned int *
	//    001F = unsigned long *

	//    0020 = long long function
	//    0021 = void function
	//    0022 = char function
	//    0023 = short function
	//    0024 = int function
	//    0025 = long function
	//    0026 = float function
	//    0027 = double function
	//    0028 = struct_type function
	//    0029 = ? function
	//    002A = enum_type function
	//    002B = ? function
	//    002C = unsigned char function
	//    002D = unsigned short function
	//    002E = unsigned int function
	//    002F = unsigned long function

	//    0030 = long long array
	//    0031 = void array
	//    0032 = char array
	//    0033 = short array
	//    0034 = int array
	//    0035 = long array
	//    0036 = float array
	//    0037 = double array
	//    0038 = struct_type array
	//    0039 = ? array
	//    003A = enum_type array
	//    003B = ? array
	//    003C = unsigned char array
	//    003D = unsigned short array
	//    003E = unsigned int array
	//    003F = unsigned long array
	var typ uint16

	// Parse type.
	if err := binary.Read(r, binary.LittleEndian, &typ); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("typ: %04X", typ)

	// Read unknown data.
	buf := make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x94 data: % X", buf)

	// Parse identifier name.
	name, err := readString(r)
	if err != nil {
		return errutil.Err(err)
	}
	dbg.Println("name:", name)

	return nil
}

// parseSymbol96 parses a debug symbol of kind 0x96.
func parseSymbol96(r io.Reader) error {
	// Definition kind.
	//
	// ref: parseSymbol94.
	var defKind uint16

	// Parse definition kind.
	if err := binary.Read(r, binary.LittleEndian, &defKind); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("defKind: %04X", defKind)

	// Type.
	//
	// ref: parseSymbol94.
	var typ uint16

	// Parse type.
	if err := binary.Read(r, binary.LittleEndian, &typ); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("typ: %04X", typ)

	// Read unknown data.
	buf := make([]byte, 6)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x96 data: % X", buf)

	// Parse array lengths.
	n := getNArrays(typ)
	for i := 0; i < n; i++ {
		// Parse type.
		var length uint32
		if err := binary.Read(r, binary.LittleEndian, &length); err != nil {
			return errutil.Err(err)
		}
		dbg.Printf("length: %d", length)
	}

	// Parse key.
	key, err := readString(r)
	if err != nil {
		return errutil.Err(err)
	}
	dbg.Println("key:", key)

	// Parse value.
	val, err := readString(r)
	if err != nil {
		return errutil.Err(err)
	}
	dbg.Println("val:", val)

	return nil
}

// parseSymbol98 parses a debug symbol of kind 0x98.
func parseSymbol98(r io.Reader) error {
	// Read unknown data.
	buf := make([]byte, 8)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("symbol 0x98 data: % X", buf)
	return nil
}

// parseSymbol9A parses a debug symbol of kind 0x9A.
func parseSymbol9A(r io.Reader) error {
	// nothing to do.
	return nil
}

// getNArrays returns the number of arrays contained within the given type.
func getNArrays(typ uint16) int {
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
