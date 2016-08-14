package main

import (
	"bytes"
	"fmt"
	"strings"

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
	case sym.TypeUnknown:
		return "unknown"
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
	return fmt.Sprintf("%s*", typ.elem.Name())
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
	// Enum fields; sorted by value.
	members []*EnumMember
	// Type aliases.
	aliases []string
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

// TypeDef returns a type definition for the given type.
func (typ *EnumType) TypeDef() string {
	buf := new(bytes.Buffer)
	if strings.HasPrefix(typ.name, ".") && strings.HasSuffix(typ.name, "fake") {
		fmt.Fprintf(buf, "// %s\nenum {\n", typ.name)
	} else {
		fmt.Fprintf(buf, "typedef enum %s {\n", typ.name)
	}
	for _, member := range typ.members {
		fmt.Fprintf(buf, "\t%s = %d,\n", member.name, member.val)
	}
	aliasBuf := new(bytes.Buffer)
	for i, alias := range typ.aliases {
		if i != 0 {
			aliasBuf.WriteString(",")
		}
		aliasBuf.WriteString(" ")
		if strings.HasPrefix(alias, ".") && strings.HasSuffix(alias, "fake") {
			alias = fmt.Sprintf("/* %s */", alias)
		}
		aliasBuf.WriteString(alias)
	}
	fmt.Fprintf(buf, "}%s;", aliasBuf)
	return buf.String()
}

// An EnumMember represents an enum member.
type EnumMember struct {
	// Enum name.
	name string
	// Enum value.
	val uint32
}

// A FuncType represents a function type.
type FuncType struct {
	// Return type.
	ret Type
}

// Equal reports whether t and u are of equal types.
func (t *FuncType) Equal(u Type) bool {
	if u, ok := u.(*FuncType); ok {
		return t.ret.Equal(u.ret)
	}
	return false
}

// Name returns the name of the definition.
func (t *FuncType) Name() string {
	return fmt.Sprintf("%s()", t.ret.Name())
}

// A UnionType represents a union type.
type UnionType struct {
	// Union name.
	name string
	// Union members.
	members []*StructField
	// Type aliases.
	aliases []string
	// Union only contains partial information.
	partial bool
}

// Equal reports whether t and u are of equal types.
func (t *UnionType) Equal(u Type) bool {
	if u, ok := u.(*UnionType); ok {
		// HACK, but works.
		return t.TypeDef() == u.TypeDef()
	}
	return false
}

// Name returns the name of the definition.
func (t *UnionType) Name() string {
	return t.name
}

// TypeDef returns a string representation
func (typ *UnionType) TypeDef() string {
	buf := new(bytes.Buffer)
	name := typ.name
	if strings.HasPrefix(name, ".") && strings.HasSuffix(name, "fake") {
		name = fmt.Sprintf("/* %s */", name)
	}
	fmt.Fprintf(buf, "typedef union %s {\n", name)
	for _, member := range typ.members {
		fmt.Fprintf(buf, "\t%s;\n", member)
	}
	aliasBuf := new(bytes.Buffer)
	for i, alias := range typ.aliases {
		if i != 0 {
			aliasBuf.WriteString(",")
		}
		aliasBuf.WriteString(" ")
		if strings.HasPrefix(alias, ".") && strings.HasSuffix(alias, "fake") {
			alias = fmt.Sprintf("/* %s */", alias)
		}
		aliasBuf.WriteString(alias)
	}
	fmt.Fprintf(buf, "}%s;", aliasBuf)
	return buf.String()
}

// A StructType represents a structure type.
type StructType struct {
	// Structure name.
	name string
	// Structure fields.
	fields []*StructField
	// Type aliases.
	aliases []string
	// Struct only contains partial information.
	partial bool
}

// Equal reports whether t and u are of equal types.
func (t *StructType) Equal(u Type) bool {
	if u, ok := u.(*StructType); ok {
		// HACK, but works.
		return t.TypeDef() == u.TypeDef()
	}
	return false
	// NOTE: The out-commented version may be prettier, but gets stuck in an
	// infinite loop for self-referential types; e.g.
	//
	//    typedef struct Foo {
	//       Foo *next;
	//    };
	//
	/*
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
	*/
}

// Name returns the name of the definition.
func (typ *StructType) Name() string {
	return typ.name
}

// TypeDef returns a string representation
func (typ *StructType) TypeDef() string {
	buf := new(bytes.Buffer)
	name := typ.name
	if strings.HasPrefix(name, ".") && strings.HasSuffix(name, "fake") {
		name = fmt.Sprintf("/* %s */", name)
	}
	fmt.Fprintf(buf, "typedef struct %s {\n", name)
	for _, field := range typ.fields {
		fmt.Fprintf(buf, "\t%s;\n", field)
	}
	aliasBuf := new(bytes.Buffer)
	for i, alias := range typ.aliases {
		if i != 0 {
			aliasBuf.WriteString(",")
		}
		aliasBuf.WriteString(" ")
		if strings.HasPrefix(alias, ".") && strings.HasSuffix(alias, "fake") {
			alias = fmt.Sprintf("/* %s */", alias)
		}
		aliasBuf.WriteString(alias)
	}
	fmt.Fprintf(buf, "}%s;", aliasBuf)
	return buf.String()
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

func (f *StructField) String() string {
	t := f.typ.Name()
	var array string
	if start := strings.Index(t, "["); start != -1 {
		if end := strings.LastIndex(t, "]"); end != -1 {
			array = t[start : end+1]
			t = t[:start] + t[end+1:]
		}
	}
	isFuncPtr := false
	if start := strings.Index(t, "()*"); start != -1 {
		t = t[:start] + t[start+len("()*"):]
		isFuncPtr = true
	}
	isFunc := false
	if !isFuncPtr {
		if start := strings.Index(t, "()"); start != -1 {
			t = t[:start] + t[start+len("()"):]
			isFunc = true
		}
	}
	isStruct := containsStructType(f.typ)
	if typ, ok := f.typ.(*UnionType); ok {
		if strings.HasPrefix(t, ".") && strings.HasSuffix(t, "fake") {
			buf := new(bytes.Buffer)
			fmt.Fprintf(buf, "union {\n")
			for _, member := range typ.members {
				fmt.Fprintf(buf, "\t\t%s;\n", member)
			}
			fmt.Fprintf(buf, "\t}")
			t = buf.String()
		}
	}
	if isStruct {
		t = fmt.Sprintf("struct %s", t)
	}
	if isFunc {
		return fmt.Sprintf("%s (*%s%s)()", t, f.name, array)
	}
	if isFuncPtr {
		return fmt.Sprintf("%s (**%s%s)()", t, f.name, array)
	}
	return fmt.Sprintf("%s %s%s", t, f.name, array)
}

// containsStructType reports whether the given type contains a structure type.
func containsStructType(typ Type) bool {
	switch typ := typ.(type) {
	case *StructType:
		return true
	case *PointerType:
		return containsStructType(typ.elem)
	case *ArrayType:
		return containsStructType(typ.elem)
	default:
		return false
	}
}
