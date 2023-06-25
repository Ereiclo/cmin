%{
    #include <stdio.h>
%}

%option noyywrap

id [a-z]+[a-z0-9A-Z]


nada [ \t\n\r]
comentario ("/*"([^*]|{nada})*"*/")|("//".*)
fin_inst ";"



%%


{id} {printf("id: %s\n",yytext);}
{comentario} {printf("comentario: %s\n",yytext);}
{nada}+ {printf("encontro nada\n");}
{fin_inst} {printf("fin instruccion\n");}

%%


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

