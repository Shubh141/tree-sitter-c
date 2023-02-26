#include <stdio.h>
#include <src/tree_sitter/parser.h>

int main() {
  // Initialize the parser.
  TSParser *parser = ts_parser_new();
  ts_parser_set_language(parser, ts_language_load(
    // Load the language definition for C.
    ts_builtin_languages_find_by_name("c")
  ));

  // Parse some C code.
  const char *code = "int main() { return 0; }";
  TSTree *tree = ts_parser_parse_string(
    parser, NULL, code, strlen(code)
  );

  // Print the syntax tree.
  ts_tree_print_dot_graph(ts_tree_root_node(tree), stdout);

  // Clean up.
  ts_tree_delete(tree);
  ts_parser_delete(parser);

  return 0;
}
