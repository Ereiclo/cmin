flex token_parser_only_lex.l
yacc lexical_analyzer.y
gcc test_parser.c -o exe
./exe