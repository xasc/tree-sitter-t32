package tree_sitter_t32_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"gitlab.com/xasc/tree-sitter-t32"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_t32.Language())
	if language == nil {
		t.Errorf("Error loading T32 grammar")
	}
}
