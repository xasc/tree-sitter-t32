package tree_sitter_t32_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_t32 "codeberg.org/xasc/tree-sitter-t32/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_t32.Language())
	if language == nil {
		t.Errorf("Error loading T32 grammar")
	}
}
