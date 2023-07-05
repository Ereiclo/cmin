cd src
flex token_parser.l
yacc syntax_analyzer.y -d -Wno-yacc 
gcc cmin_compiler.c -o exe  -lm -g
cp ./exe ../build/cmincompile
cp ./cminrun ../build/
