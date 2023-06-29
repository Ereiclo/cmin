flex token_parser.l
yacc lexical_analyzer.y -d -Wno-yacc
gcc test_analyzer.c -o exe
./exe