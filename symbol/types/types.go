// Package types declares the data types of the C programming language.
package types

import (
	"bytes"
	"fmt"
	"strings"
)

// A Type represents a type of C, and has one of the following underlying types.
//
//    *Basic
//    *Pointer
//    *Array
//    *Enum
//    *Struct
//    *Union
//    *Func
type Type interface {
	fmt.Stringer
	// TypeName returns the name of the type.
	TypeName() string
	// Equal reports whether t and u are of equal types.
	Equal(u Type) bool
}

// Basic represents a basic type.
type Basic struct {
	// Kind of basic type.
	Kind
}

// TypeName returns the name of the type.
func (t *Basic) TypeName() string {
	return t.String()
}

// Equal reports whether t and u are of equal types.
func (t *Basic) Equal(u Type) bool {
	if u, ok := u.(*Basic); ok {
		return t.Kind == u.Kind
	}
	return false
}

// Kind describes the kind of basic type.
type Kind int

// Basic types.
const (
	Unknown       Kind = iota // unknown
	Void                      // void
	Char                      // char
	Short                     // short
	Int                       // int
	Long                      // long
	Float                     // float
	Double                    // double
	UnsignedChar              // unsigned char
	UnsignedShort             // unsigned short
	UnsignedInt               // unsigned int
	UnsignedLong              // unsigned long
)

func (kind Kind) String() string {
	switch kind {
	case Unknown:
		return "unknown"
	case Void:
		return "void"
	case Char:
		return "char"
	case Short:
		return "short"
	case Int:
		return "int"
	case Long:
		return "long"
	case Float:
		return "float"
	case Double:
		return "double"
	case UnsignedChar:
		return "unsigned char"
	case UnsignedShort:
		return "unsigned short"
	case UnsignedInt:
		return "unsigned int"
	case UnsignedLong:
		return "unsigned long"
	}
	panic(fmt.Sprintf("support for basic type of kind %d not yet implemented", int(kind)))
}

// A Pointer represents a pointer type.
type Pointer struct {
	// Element type.
	Elem Type
}

func (t *Pointer) String() string {
	return fmt.Sprintf("%s*", t.Elem.TypeName())
}

// TypeName returns the name of the type.
func (t *Pointer) TypeName() string {
	return t.String()
}

// Equal reports whether t and u are of equal types.
func (t *Pointer) Equal(u Type) bool {
	if u, ok := u.(*Pointer); ok {
		return t.Elem.Equal(u.Elem)
	}
	return false
}

// An Array represents an array type.
type Array struct {
	// Element type.
	Elem Type
	// Array length.
	Len int
}

func (t *Array) String() string {
	return fmt.Sprintf("%s[%d]", t.Elem.TypeName(), t.Len)
}

// TypeName returns the name of the type.
func (t *Array) TypeName() string {
	return t.String()
}

// Equal reports whether t and u are of equal types.
func (t *Array) Equal(u Type) bool {
	if u, ok := u.(*Array); ok {
		if !t.Elem.Equal(u.Elem) {
			return false
		}
		return t.Len == u.Len
	}
	return false
}

// An Enum represents an enumerate type.
type Enum struct {
	// Enum name.
	Name string
	// Enum members.
	Members []*EnumMember
}

func (t *Enum) String() string {
	buf := &bytes.Buffer{}
	buf.WriteString("enum ")
	if len(t.Name) > 0 {
		if isFake(t.Name) {
			fmt.Fprintf(buf, "/* %s */ ", t.Name)
		} else {
			fmt.Fprintf(buf, "%s ", t.Name)
		}
	}
	buf.WriteString("{\n")
	for _, member := range t.Members {
		fmt.Fprintf(buf, "\t%s = %d,\n", member.Name, member.Val)
	}
	buf.WriteString("}")
	return buf.String()
}

// TypeName returns the name of the type.
func (t *Enum) TypeName() string {
	if len(t.Name) == 0 {
		panic(fmt.Sprintf("unable to return type name of unnamed enum"))
	}
	return fmt.Sprintf("enum %s", t.Name)
}

// Equal reports whether t and u are of equal types.
func (t *Enum) Equal(u Type) bool {
	if u, ok := u.(*Enum); ok {
		if t.Name != u.Name {
			return false
		}
		if len(t.Members) != len(u.Members) {
			return false
		}
		for i := range t.Members {
			x, y := t.Members[i], u.Members[i]
			if *x != *y {
				return false
			}
		}
		return true
	}
	return false
}

// An EnumMember represents an enum member.
type EnumMember struct {
	// Enum member name.
	Name string
	// Enum member value.
	Val int
}

// A Struct represents a structure type.
type Struct struct {
	// Struct name.
	Name string
	// Struct fields.
	Fields []Var
}

func (t *Struct) String() string {
	buf := &bytes.Buffer{}
	buf.WriteString("struct ")
	if len(t.Name) > 0 {
		if isFake(t.Name) {
			fmt.Fprintf(buf, "/* %s */ ", t.Name)
		} else {
			fmt.Fprintf(buf, "%s ", t.Name)
		}
	}
	buf.WriteString("{\n")
	for _, field := range t.Fields {
		fmt.Fprintf(buf, "\t%s;\n", field)
	}
	buf.WriteString("}")
	return buf.String()
}

// TypeName returns the name of the type.
func (t *Struct) TypeName() string {
	if len(t.Name) == 0 {
		panic(fmt.Sprintf("unable to return type name of unnamed struct"))
	}
	return fmt.Sprintf("struct %s", t.Name)
}

// Equal reports whether t and u are of equal types.
func (t *Struct) Equal(u Type) bool {
	// HACK, but works. Support recursive types.
	return t.String() == u.String()
}

// A Union represents a union type.
type Union struct {
	// Union name.
	Name string
	// Union fields.
	Fields []Var
}

func (t *Union) String() string {
	buf := &bytes.Buffer{}
	buf.WriteString("union ")
	if len(t.Name) > 0 {
		if isFake(t.Name) {
			fmt.Fprintf(buf, "/* %s */ ", t.Name)
		} else {
			fmt.Fprintf(buf, "%s ", t.Name)
		}
	}
	buf.WriteString("{\n")
	for _, field := range t.Fields {
		fmt.Fprintf(buf, "\t%s;\n", field)
	}
	buf.WriteString("}")
	return buf.String()
}

// TypeName returns the name of the type.
func (t *Union) TypeName() string {
	if len(t.Name) == 0 {
		panic(fmt.Sprintf("unable to return type name of unnamed union"))
	}
	if isFake(t.Name) {
		return strings.Replace(t.String(), "\n", "\n\t", -1)
	}
	return fmt.Sprintf("union %s", t.Name)
}

// Equal reports whether t and u are of equal types.
func (t *Union) Equal(u Type) bool {
	// HACK, but works. Support recursive types.
	return t.String() == u.String()
}

// A Func represents a function signature.
type Func struct {
	// Return type.
	Result Type
	// Function parameters.
	Params []Var
}

func (t *Func) String() string {
	buf := &bytes.Buffer{}
	fmt.Fprintf(buf, "%s ()(", t.Result.TypeName())
	for i, param := range t.Params {
		if i != 0 {
			buf.WriteString(", ")
		}
		buf.WriteString(param.String())
	}
	buf.WriteString(")")
	return buf.String()
}

// TypeName returns the name of the type.
func (t *Func) TypeName() string {
	return t.String()
}

// Equal reports whether t and u are of equal types.
func (t *Func) Equal(u Type) bool {
	if u, ok := u.(*Func); ok {
		if !t.Result.Equal(u.Result) {
			return false
		}
		if len(t.Params) != len(u.Params) {
			return false
		}
		for i := range t.Params {
			x, y := t.Params[i], u.Params[i]
			if !isVarEqual(x, y) {
				return false
			}
		}
		return true
	}
	return false
}

// A Var represents a global variable, a local variable or a function parameter.
type Var struct {
	// Variable type.
	Type Type
	// Variable name.
	Name string
}

func (v Var) String() string {
	switch t := v.Type.(type) {
	case *Pointer:
		// HACK, but works. The syntax of the C type system is pre-historic.
		v.Name = fmt.Sprintf("*%s", v.Name)
		v.Type = t.Elem
		return v.String()
	case *Array:
		// HACK, but works. The syntax of the C type system is pre-historic.
		v.Name = fmt.Sprintf("%s[%d]", v.Name, t.Len)
		v.Type = t.Elem
		return v.String()
	case *Func:
		// HACK, but works. The syntax of the C type system is pre-historic.
		buf := &bytes.Buffer{}
		fmt.Fprintf(buf, "(%s)(", v.Name)
		for i, param := range t.Params {
			if i != 0 {
				buf.WriteString(", ")
			}
			buf.WriteString(param.String())
		}
		buf.WriteString(")")
		v.Name = buf.String()
		v.Type = t.Result
		return v.String()
	default:
		return fmt.Sprintf("%s %s", t.TypeName(), v.Name)
	}
}

// isVarEqual reports whether the given variables are equal.
func isVarEqual(x, y Var) bool {
	if !x.Type.Equal(y.Type) {
		return false
	}
	return x.Name == y.Name
}

// isFake reports whether the given name is a fake name used for unnamed debug
// symbols.
func isFake(name string) bool {
	return strings.HasPrefix(name, ".") && strings.HasSuffix(name, "fake")
}
