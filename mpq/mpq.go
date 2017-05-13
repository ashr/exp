// Package mpq provides access to MPQ archives.
package mpq

// An Archive is an MPQ archive.
type Archive struct {
}

// Open opens the given MPQ archive.
func Open(mpqPath string) (*Archive, error) {
	panic("not yet implemented")
}

// ReadFile returns the contents of the given file in the archive.
func (a *Archive) ReadFile(relPath string) ([]byte, error) {
	panic("not yet implemented")
}

// Files returns the list of file paths contained within the archive.
func (a *Archive) Files() []string {
	panic("not yet implemented")
}
