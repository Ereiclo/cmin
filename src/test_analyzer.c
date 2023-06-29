#include "y.tab.c"
#include "lex.yy.c"

void parse(FILE *file) {
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