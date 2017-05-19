// Package d1 provides access to information related to the Diablo 1 game.
package d1

import (
	"crypto/sha1"
	"fmt"
	"io/ioutil"

	"github.com/decomp/exp/bin"
	_ "github.com/decomp/exp/bin/pe" // register PE decoder
	"github.com/pkg/errors"
)

// Executable provides access to information stored within the diablo.exe
// executable.
type Executable struct {
	// Monster data.
	Monsters []MonsterData

	// Underlying file of the executable.
	file *bin.File
}

// ParseFile parses the given diablo.exe executable.
func ParseFile(exePath string) (*Executable, error) {
	// Sanity check.
	buf, err := ioutil.ReadFile(exePath)
	if err != nil {
		return nil, errors.WithStack(err)
	}
	sum := fmt.Sprintf("%040x", sha1.Sum(buf))
	switch sum {
	case "ebaee2acb462a0ae9c895a0e33079c94796cb0b6":
		// supported.
	default:
		return nil, errors.Errorf("support for parsing diablo.exe with SHA1 hashsum `%s` not yet implemented", sum)
	}
	// Parse executable.
	file, err := bin.ParseFile(exePath)
	if err != nil {
		return nil, errors.WithStack(err)
	}
	exe := &Executable{
		file: file,
	}
	// Parse monster data.
	if err := exe.parseMonsterData(); err != nil {
		return nil, errors.WithStack(err)
	}
	return exe, nil
}
