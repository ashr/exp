// Package d1 provides access to information related to the Diablo 1 game.
package d1

import (
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
func ParseFile(path string) (*Executable, error) {
	file, err := bin.ParseFile(path)
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
