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
   fclose(yyin);
}


void yyerror(const char *s) {
      printf("%s (%s) in line %d\n", s, yytext,  yylineno);

    //printf("\n%s\n", s);
}
void main(){
    FILE *file = fopen("input", "r");
    parse(file);   
}