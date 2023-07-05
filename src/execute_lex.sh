flex token_parser_only_lex.l
yacc syntax_analyzer.y -Wno-yacc
gcc test_parser.c -o exe -lm
./exe