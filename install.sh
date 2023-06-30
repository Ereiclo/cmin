cd src
flex token_parser.l
yacc lexical_analyzer.y -d -Wno-yacc
gcc cmin_compiler.c -o exe  -lm
cp ./exe ../build/cmincompile
cp ./cminrun ../build/
