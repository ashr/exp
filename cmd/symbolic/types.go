package main

import (
	"fmt"

	"github.com/sanctuary/exp/sym"
)

// A Def represents a definition.
type Def interface {
	// Name returns the name of the definition.
	Name() string
}

// === [ variables and parameters ] ============================================

// A Local represents a local variable.
type Local struct {
	// Variable name.
	name string
	// Variable type.
	typ Type
}

// Name returns the name of the definition.
func (l *Local) Name() string {
	return l.name
}

// A Param represents a function parameter.
type Param struct {
	// Parameter name.
	name string
	// Parameter type.
	typ Type
}

// Name returns the name of the definition.
func (p *Param) Name() string {
	return p.name
}

// A Global represents a global variable.
type Global struct {
	// Address of the global variable.
	addr uint32
	// Global variable name.
	name string
	// Global variable type.
	typ Type
}

// Name returns the name of the definition.
func (p *Global) Name() string {
	return p.name
}

// === [ types ] ===============================================================

var types map[string][]struct {
	start int
	typ   Type
}

// A Type represents a Type.
type Type interface {
	Def
	// Equal reports whether t and u are of equal types.
	Equal(u Type) bool
}

// A BasicType represents a pointer type.
type BasicType struct {
	// Basic type; only the 4 least significant bits of a symbol type.
	basic sym.Type
}

// Equal reports whether t and u are of equal types.
func (t *BasicType) Equal(u Type) bool {
	if u, ok := u.(*BasicType); ok {
		return t.basic == u.basic
	}
	return false
}

// Name returns the name of the definition.
func (typ *BasicType) Name() string {
	switch typ.basic & 0x000F {
	case sym.TypeError:
		return "error"
	case sym.TypeVoid:
		return "void"
	case sym.TypeChar:
		return "char"
	case sym.TypeShort:
		return "short"
	case sym.TypeInt:
		return "int"
	case sym.TypeLong:
		return "long"
	case sym.TypeFloat:
		return "float"
	case sym.TypeDouble:
		return "double"
	case sym.TypeStruct:
		return "struct"
	case sym.TypeUnion:
		return "union"
	case sym.TypeEnum:
		return "enum"
	case sym.TypeEnumMember:
		return "enum member"
	case sym.TypeUnsignedChar:
		return "unsigned char"
	case sym.TypeUnsignedShort:
		return "unsigned short"
	case sym.TypeUnsignedInt:
		return "unsigned int"
	case sym.TypeUnsignedLong:
		return "unsigned long"
	}
	panic("unreachable")
}

// A PointerType represents a pointer type.
type PointerType struct {
	// Element type.
	elem Type
}

// Equal reports whether t and u are of equal types.
func (t *PointerType) Equal(u Type) bool {
	if u, ok := u.(*PointerType); ok {
		return t.elem.Equal(u.elem)
	}
	return false
}

// Name returns the name of the definition.
func (typ *PointerType) Name() string {
	return fmt.Sprintf("*%s", typ.elem.Name())
}

// An ArrayType represents an array type.
type ArrayType struct {
	// Array element.
	elem Type
	// Array length.
	length uint32
}

// Equal reports whether t and u are of equal types.
func (t *ArrayType) Equal(u Type) bool {
	if u, ok := u.(*ArrayType); ok {
		return t.elem.Equal(u.elem) && t.length == u.length
	}
	return false
}

// Name returns the name of the definition.
func (typ *ArrayType) Name() string {
	return fmt.Sprintf("%s[%d]", typ.elem.Name(), typ.length)
}

// A EnumType represents an enum type.
type EnumType struct {
	// Enum name.
	name string
	// Enum fields.
	members []*EnumMember
}

// Equal reports whether t and u are of equal types.
func (t *EnumType) Equal(u Type) bool {
	if u, ok := u.(*EnumType); ok {
		if t.name != u.name {
			return false
		}
		if len(t.members) != len(u.members) {
			return false
		}
		for i := range t.members {
			if *t.members[i] != *u.members[i] {
				return false
			}
		}
	}
	return true
}

// Name returns the name of the definition.
func (typ *EnumType) Name() string {
	return typ.name
}

// An EnumMember represents an enum member.
type EnumMember struct {
	// Enum name.
	name string
	// Enum value.
	val uint32
}

// A StructType represents a structure type.
type StructType struct {
	// Structure name.
	name string
	// Structure fields.
	fields []*StructField
}

// Equal reports whether t and u are of equal types.
func (t *StructType) Equal(u Type) bool {
	if u, ok := u.(*StructType); ok {
		if t.name != u.name {
			return false
		}
		if len(t.fields) != len(u.fields) {
			return false
		}
		for i := range t.fields {
			if t.fields[i].name != u.fields[i].name {
				return false
			}
			if !t.fields[i].typ.Equal(u.fields[i].typ) {
				return false
			}
		}
	}
	return true
}

// Name returns the name of the definition.
func (typ *StructType) Name() string {
	return typ.name
}

// A StructField represents a structure field.
type StructField struct {
	// Field name.
	name string
	// Field type.
	typ Type
}

// Name returns the name of the definition.
func (f *StructField) Name() string {
	return f.name
}
