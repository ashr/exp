package sym

import "fmt"

// TODO: Figure out how to access symbol specific data.

// A Symbol represents a debug symbol.
type Symbol interface {
	// Value returns the value of the symbol.
	Value() uint32
	// Kind returns the symbol kind.
	Kind() uint8
	// Data returns symbol specific data.
	Data() interface{}
}

// A symbol represents a debug symbol.
type symbol struct {
	// Symbol value.
	value uint32
	// Symbol kind.
	kind uint8
	// Holds symbol specific data, which has one of the following underlying
	// types.
	//
	//    *data01
	//    ...
	data interface{}
}

// Value returns the value of the symbol.
func (s symbol) Value() uint32 {
	return s.value
}

// Kind returns the symbol kind.
func (s symbol) Kind() uint8 {
	return s.kind
}

// Data returns symbol specific data.
func (s symbol) Data() interface{} {
	return s.data
}

type Data01 struct {
}

type Data02 struct {
}

// Symbol kind 0x80 represents a line marker within the source file.
type Data80 struct {
	// no data.
}

type Data82 struct {
}

type Data84 struct {
}

type Data86 struct {
}

// Symbol kind 0x88 represents a named source file start marker.
type Data88 struct {
	// Number of objects contained within the source file.
	NObjs uint32
	// Souce file path.
	Path string
}

type Data8A struct {
}

// Symbol kind 0x8C represents the start marker of a function declaration.
type Data8C struct {
	// Unknown data.
	Unknown [20]byte
	// Source code file path.
	Path string
	// Function name.
	Name string
}

// Symbol kind 0x8E represents a line number marker associated with the directly
// preceding function definition.
type Data8E struct {
	// Line number.
	Line uint32
}

type Data90 struct {
}

type Data92 struct {
}

// Symbol kind 0x94 represents a definition of a function, struct, variable,
// parameter or union.
type Data94 struct {
	// Definition kind.
	DefKind uint16
	// Type.
	Type Type
	// Unknown data.
	Unknown [4]byte
	// Symbol name.
	Name string
}

// Symbol kind 0x96 represents a key-value pair meta-symbol, used to describe
// end of symbol markers, type aliases, variable definitions of structure,
// enumerable or array types.
type Data96 struct {
	// Definition kind.
	DefKind uint16
	// Type.
	Type Type
	// Unknown data.
	Unknown [6]byte
	// Array lengths.
	Lengths []uint32
	// Key-value pair.
	Key, Val string
}

// A Type represents a C type, where the 4 least significant bits represent a
// basic type and each pair of 2 bits of the remaining 12 bits represent a type
// modifier.
type Type uint16

// String returns the string representation of the type.
func (t Type) String() string {
	typ := uint16(t)
	s := ""
	basic := basicString(typ & 0x000F)
	s += basic
	mask := (typ & 0xFFF0) >> 4
	wat := false
	for i := 0; i < 6; i++ {
		mod := mask & 0x3
		if mod == ModNone {
			wat = true
			continue
		}
		m := modString(mod)
		if wat {
			panic("WAT?")
		}
		s = m + "(" + s + ")"
		mask >>= 2
	}
	return s
}

const (
	TypeError         = 0x0 // error
	TypeVoid          = 0x1 // void
	TypeChar          = 0x2 // char
	TypeShort         = 0x3 // short
	TypeInt           = 0x4 // int
	TypeLong          = 0x5 // long
	TypeFloat         = 0x6 // float
	TypeDouble        = 0x7 // double
	TypeStruct        = 0x8 // struct
	TypeUnion         = 0x9 // union
	TypeEnum          = 0xA // enum
	TypeEnumMember    = 0xB // enum member
	TypeUnsignedChar  = 0xC // unsigned char
	TypeUnsignedShort = 0xD // unsigned short
	TypeUnsignedInt   = 0xE // unsigned int
	TypeUnsignedLong  = 0xF // unsigned long
)

const (
	ModNone     = 0x0 // basic type
	ModPointer  = 0x1 // pointer
	ModFunction = 0x2 // function
	ModArray    = 0x3 // array
)

// HasMod reports whether the given type has the specified type modifier.
func HasMod(typ Type, modifier uint16) bool {
	mask := (typ & 0xFFF0) >> 4
	wat := false
	for i := 0; i < 6; i++ {
		mod := mask & 0x3
		if mod == ModNone {
			wat = true
			continue
		}
		if wat {
			panic("WAT?")
		}
		if uint16(mod) == modifier {
			return true
		}
		mask >>= 2
	}
	return false
}

// modString returns the string representation of the givne type modifier.
func modString(mod uint16) string {
	switch mod {
	case ModNone:
		return "basic type"
	case ModPointer:
		return "pointer"
	case ModFunction:
		return "function"
	case ModArray:
		return "array"
	}
	panic(fmt.Sprintf("unknown type modifier %v", mod))
}

// basicString returns the string representation of the givne basic type.
func basicString(basic uint16) string {
	switch basic {
	case TypeError:
		return "error"
	case TypeVoid:
		return "void"
	case TypeChar:
		return "char"
	case TypeShort:
		return "short"
	case TypeInt:
		return "int"
	case TypeLong:
		return "long"
	case TypeFloat:
		return "float"
	case TypeDouble:
		return "double"
	case TypeStruct:
		return "struct"
	case TypeUnion:
		return "union"
	case TypeEnum:
		return "enum"
	case TypeEnumMember:
		return "enum member"
	case TypeUnsignedChar:
		return "unsigned char"
	case TypeUnsignedShort:
		return "unsigned short"
	case TypeUnsignedInt:
		return "unsigned int"
	case TypeUnsignedLong:
		return "unsigned long"
	}
	panic(fmt.Sprintf("unknown basic type %v", basic))
}

type Data98 struct {
}

type Data9A struct {
}
