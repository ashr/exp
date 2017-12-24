package types_test

import "github.com/sanctuary/symbol/types"

// Verify that the C types implement the Type interface.
var (
	_ types.Type = &types.Basic{}
	_ types.Type = &types.Pointer{}
	_ types.Type = &types.Array{}
	_ types.Type = &types.Enum{}
	_ types.Type = &types.Struct{}
	_ types.Type = &types.Union{}
	_ types.Type = &types.Func{}
)
