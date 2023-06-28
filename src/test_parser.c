#include "y.tab.c"
#include "lex.yy.c"

int main (int argc, char *argv[]){
    if ((yyin = fopen("input","rt"))==NULL){
        printf("\n No se puede abrir el archivo %s\n",argv[1]);
    }
    else{
        // printf(" Se abrio el archivo %s\n",argv[1]);
        yylex();
        fclose(yyin);
    }
    return 0;
}


