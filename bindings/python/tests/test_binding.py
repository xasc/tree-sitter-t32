from unittest import TestCase

import tree_sitter, tree_sitter_t32


class TestLanguage(TestCase):
    def test_can_load_grammar(self):
        try:
            tree_sitter.Language(tree_sitter_t32.language())
        except Exception:
            self.fail("Error loading T32 grammar")
