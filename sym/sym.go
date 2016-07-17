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
	"github.com/mewkiz/pkg/term"
)

// TODO: Remove debug output.

// dbg is a logger which prefixes debug messages with "sym:".
var dbg = log.New(os.Stdout, term.WhiteBold("sym:"), log.Lshortfile)

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

	// Read header data.
	buf = make([]byte, 4)
	if _, err := io.ReadFull(r, buf); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("header data: % X", buf)

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

	// Parse symbol kind.
	var kind uint8
	if err := binary.Read(r, binary.LittleEndian, &kind); err != nil {
		return errutil.Err(err)
	}
	dbg.Printf("kind: %02X", kind)

	// Parse symbol.
	switch kind {
	default:
		panic(fmt.Sprintf("support for symbol kind %02X not yet implemented", kind))
	}

	panic("unreachable")
}
