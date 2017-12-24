package ast_test

import (
	"strings"
	"testing"

	"github.com/sanctuary/symbol/ast"
	"github.com/sanctuary/symbol/types"
)

var (
	// Basic types.
	unknownType       *types.Basic
	voidType          *types.Basic
	charType          *types.Basic
	shortType         *types.Basic
	intType           *types.Basic
	longType          *types.Basic
	floatType         *types.Basic
	doubleType        *types.Basic
	unsignedCharType  *types.Basic
	unsignedShortType *types.Basic
	unsignedIntType   *types.Basic
	unsignedLongType  *types.Basic

	// Pointer types.
	ptrType *types.Pointer

	// Array types.
	arrayType *types.Array

	// Enum types.
	enumType *types.Enum

	// Struct types.
	structType             *types.Struct
	recStructType          *types.Struct
	structFuncPtrFieldType *types.Struct

	// Union types.
	unionType *types.Union

	// Function types.
	funcType *types.Func

	// Function pointer type.
	funcPtrType *types.Pointer
)

func init() {
	// Basic types.
	unknownType = &types.Basic{Kind: types.Unknown}
	voidType = &types.Basic{Kind: types.Void}
	charType = &types.Basic{Kind: types.Char}
	shortType = &types.Basic{Kind: types.Short}
	intType = &types.Basic{Kind: types.Int}
	longType = &types.Basic{Kind: types.Long}
	floatType = &types.Basic{Kind: types.Float}
	doubleType = &types.Basic{Kind: types.Double}
	unsignedCharType = &types.Basic{Kind: types.UnsignedChar}
	unsignedShortType = &types.Basic{Kind: types.UnsignedShort}
	unsignedIntType = &types.Basic{Kind: types.UnsignedInt}
	unsignedLongType = &types.Basic{Kind: types.UnsignedLong}

	// Pointer types.
	ptrType = &types.Pointer{Elem: intType}

	// Array types.
	arrayType = &types.Array{Elem: intType, Len: 1}

	x := types.Var{Type: intType, Name: "x"}
	y := types.Var{Type: intType, Name: "y"}

	// Enum types.
	enumType = &types.Enum{
		Name: "foo",
		Members: []*types.EnumMember{
			{Name: "FOO_A", Val: 1},
			{Name: "FOO_B", Val: 2},
			{Name: "FOO_C", Val: 3},
		},
	}

	// Struct types.
	structType = &types.Struct{
		Name:   "foo",
		Fields: []types.Var{x, y},
	}

	// Union types.
	unionType = &types.Union{
		Name:   "foo",
		Fields: []types.Var{x, y},
	}

	// Function types.
	funcType = &types.Func{
		Result: intType,
		Params: []types.Var{x, y},
	}

	// Function pointer type.
	funcPtrType = &types.Pointer{Elem: funcType}

	// Recursive struct type.
	recStructType = &types.Struct{
		Name: "foo",
	}
	rec := types.Var{
		Type: &types.Pointer{recStructType},
		Name: "rec",
	}
	recStructType.Fields = append(recStructType.Fields, rec)

	// Struct type with function field.
	f := types.Var{Type: funcPtrType, Name: "f"}
	structFuncPtrFieldType = &types.Struct{
		Name:   "foo",
		Fields: []types.Var{f},
	}
}

func TestTypeDefString(t *testing.T) {
	golden := []struct {
		def  *ast.TypeDef
		want string
	}{
		// i=0, basic type.
		{
			def:  &ast.TypeDef{Type: intType, Aliases: []string{"foo"}},
			want: "typedef int foo;",
		},

		// i=1, pointer type.
		{
			def:  &ast.TypeDef{Type: ptrType, Aliases: []string{"foo"}},
			want: "typedef int *foo;",
		},

		// i=2, array type.
		{
			def:  &ast.TypeDef{Type: arrayType, Aliases: []string{"foo"}},
			want: "typedef int foo[1];",
		},

		// i=3, enum type.
		{
			def: &ast.TypeDef{Type: enumType, Aliases: []string{"bar"}},
			want: `
typedef enum foo {
	FOO_A = 1,
	FOO_B = 2,
	FOO_C = 3,
} bar;`,
		},

		// i=4, struct type.
		{
			def: &ast.TypeDef{Type: structType, Aliases: []string{"bar"}},
			want: `
typedef struct foo {
	int x;
	int y;
} bar;`,
		},

		// i=5, union type.
		{
			def: &ast.TypeDef{Type: unionType, Aliases: []string{"bar"}},
			want: `
typedef union foo {
	int x;
	int y;
} bar;`,
		},

		// i=6, function type.
		{
			def: &ast.TypeDef{Type: funcType, Aliases: []string{"foo"}},
			want: `
typedef int (foo)(int x, int y);`,
		},

		// i=7, function pointer type.
		{
			def: &ast.TypeDef{Type: funcPtrType, Aliases: []string{"foo"}},
			want: `
typedef int (*foo)(int x, int y);`,
		},

		// i=8, recursive struct type.
		{
			def: &ast.TypeDef{Type: recStructType, Aliases: []string{"bar"}},
			want: `
typedef struct foo {
	struct foo *rec;
} bar;`,
		},

		// i=9, struct type with function field.
		{
			def: &ast.TypeDef{Type: structFuncPtrFieldType, Aliases: []string{"bar"}},
			want: `
typedef struct foo {
	int (*f)(int x, int y);
} bar;`,
		},
	}

	for i, g := range golden {
		want := strings.TrimSpace(g.want)
		got := g.def.String()
		if got != want {
			t.Errorf("i=%d; string mismatch; expected %v, got %v", i, want, got)
			continue
		}
	}
}
