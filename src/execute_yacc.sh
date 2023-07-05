flex token_parser.l
yacc syntax_analyzer.y -d -Wno-yacc
gcc test_analyzer.c -o exe  -lm -g
./exe 