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
	//    0x8A = unnamed source file.
	//    0x94 = global variable, structure type or structure field definition.
	//    0x96 = meta symbol; key-value pair.
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
	case 0x8A:
		return parseSymbol8A(r)
	case 0x94:
		return parseSymbol94(r)
	case 0x96:
		return parseSymbol96(r)
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

// parseSymbol8A parses a debug symbol of kind 0x8A.
func parseSymbol8A(r io.Reader) error {
	// nothing to do.
	return nil
}

// parseSymbol94 parses a debug symbol of kind 0x94.
func parseSymbol94(r io.Reader) error {
	// Definition kind.
	//
	//    0002 = global variable definition.
	//    0008 = structure field definition.
	//    000A = structure type definition.
	//    000D = type alias definition.
	//    0066 = end of symbol marker.
	var defKind uint16

	// Parse definition kind.
	if err := binary.Read(r, binary.LittleEndian, &defKind); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("defKind: %04X", defKind)

	// Type.
	//
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
	//    000B = ?
	//    000C = unsigned char
	//    000D = unsigned short
	//    000E = unsigned int
	//    000F = unsigned long
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

	// TODO: Parse array lengths.

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
