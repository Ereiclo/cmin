#include "y.tab.c"
#include "lex.yy.c"


int push_symbol(char*symbol){

    symbol_table[n_symbols++] = strdup(symbol);
}


int check_symbol_existence(char* symbol){


    for(int i= 0; i < n_symbols;++i){
        if(strcmp(symbol_table[i],symbol) == 0) return 1;

    }

    return 0;

}


void create_symbol_table(int size,int max_length){
    symbol_table = (char**) malloc(sizeof(char*)*size);

    for(int i= 0; i < size;++i){
        symbol_table[i] = (char*) malloc(max_length+1);
    }

}

void parse(FILE *file) {


   create_symbol_table(1000,100);
   yyin = file;
   yyparse();
}


void yyerror(const char *s) {
      printf("%s (%s) in line %d\n", s, yytext,  yylineno);

    //printf("\n%s\n", s);
}
void main(int argc,char**argv){
    if(argc < 2){
        printf("No file to compile\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    out = fopen("exe.cm","w");
    parse(file);   
    fclose(file);
    fclose(out);
}