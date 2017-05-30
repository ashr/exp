package d1

import (
	"bytes"
	"fmt"

	"github.com/decomp/exp/bin"
)

// parseString parses the NULL-terminated string at the given address.
func (exe *Executable) parseString(addr uint32) string {
	// Handle NULL-pointers.
	if addr == 0 {
		return ""
	}
	data := exe.file.Data(bin.Address(addr))
	pos := bytes.IndexByte(data, '\x00')
	if pos == -1 {
		panic(fmt.Errorf("unable to locate NULL-terminated string at address %q", addr))
	}
	return string(data[:pos])
}

// translateBool32 returns a Go version of the given 32-bit boolean value.
func translateBool32(v uint32) bool {
	switch v {
	case 0:
		return false
	case 1:
		return true
	default:
		panic(fmt.Errorf("invalid 32-bit boolean value; expected 0 or 1, got %d", v))
	}
}
