package d1

import (
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
	for i, b := range data {
		if b == 0 {
			return string(data[:i])
		}
	}
	panic(fmt.Errorf("unable to locate NULL-terminated string at address %q", addr))
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
