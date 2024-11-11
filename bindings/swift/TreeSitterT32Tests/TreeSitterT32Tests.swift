import XCTest
import SwiftTreeSitter
import TreeSitterT32

final class TreeSitterT32Tests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_t32())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading T32 grammar")
    }
}
