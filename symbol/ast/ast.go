// Package ast declares the types used to represent abstract syntax trees of C
// soure code.
package ast

import (
	"bytes"
	"fmt"

	"github.com/sanctuary/symbol/types"
)

// A TypeDef represents a type definition.
type TypeDef struct {
	// Type.
	Type types.Type
	// Type aliases.
	Aliases []string
}

func (def *TypeDef) String() string {
	buf := &bytes.Buffer{}
	for i, alias := range def.Aliases {
		if i != 0 {
			buf.WriteString(", ")
		}
		buf.WriteString(alias)
	}
	switch typ := def.Type.(type) {
	case *types.Basic, *types.Enum, *types.Struct, *types.Union:
		return fmt.Sprintf("typedef %s %s;", typ, buf)
	case *types.Pointer, *types.Array, *types.Func:
		if len(def.Aliases) != 1 {
			panic(fmt.Sprintf("expected 1 alias for %T type definition, got %d", typ, len(def.Aliases)))
		}
		v := types.Var{Type: def.Type, Name: def.Aliases[0]}
		return fmt.Sprintf("typedef %s;", v)
	default:
		panic(fmt.Sprintf("support for type %T not yet implemented", typ))
	}
}
