package sym

// A Symbol represents a debug symbol, and has one of the following underlying
// types.
//
//    *symbol01
//    ...
type Symbol interface {
	// Offset returns the offset of the symbol.
	Offset() uint32
	// Kind returns the symbol kind.
	Kind() uint8
}

// A symbol represents a debug symbol.
type symbol struct {
	// Symbol offset.
	offset uint32
	// Symbol kind.
	kind uint8
	// Holds symbol specific data, which has one of the following underlying
	// types.
	//
	//    *data01
	//    ...
	data interface{}
}

// Offset returns the offset of the symbol.
func (s symbol) Offset() uint32 {
	return s.offset
}

// Kind returns the symbol kind.
func (s symbol) Kind() uint8 {
	return s.kind
}

type data01 struct {
}

type data02 struct {
}

// Symbol kind 0x80 represents a line marker within the source file.
type data80 struct {
	// no data.
}

type data82 struct {
}

type data84 struct {
}

type data86 struct {
}

// Symbol kind 0x88 represents a named source file start marker.
type data88 struct {
	// Number of objects contained within the source file.
	nobjs uint32
	// Souce file path.
	path string
}

type data8A struct {
}

type data8C struct {
}

type data8E struct {
}

type data90 struct {
}

type data92 struct {
}

type data94 struct {
}

type data96 struct {
}

type data98 struct {
}

type data9A struct {
}
