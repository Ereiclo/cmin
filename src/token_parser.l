%{
    #include <stdio.h>
    #include <string.h>

    char **split_by_commas(char *s)
    {
        int length = strlen(s);
        char **string_array = (char **)malloc(sizeof(char *) * length + 1);
        int actual_length = 0;
        char *temp_buffer = (char *)malloc(sizeof(char) * length + 1);

        for (int i = 0, j = 0; i <= length; ++i)
        {
            if (s[i] == ',' || s[i] == '\0')
            {
                temp_buffer[j] = '\0';
                string_array[actual_length++] = strdup(temp_buffer);
                j = 0;
            }
            else
            {
                temp_buffer[j++] = s[i];
            }
        }

        free(temp_buffer);

        string_array[actual_length] = NULL;


        return string_array;
    }

    void remove_spaces(char* s) {
            char* d = s;
            do {
                while (*d == ' ' || *d  == '\t' || *d == '\n' || *d == '\r') {
                    ++d;
                }
            } while (*s++ = *d++);
    }



%}

%option noyywrap

id [a-zA-Z]+[a-z0-9A-Z]*
nada [ \t\n\r]
comentario ("/*"([^*]|{nada})*"*/")|("//".*)
fin_inst ";"
numero "-"{0,1}([0-9]+("."[0-9]*){0,1})|"-"{0,1}("."[0-9]+)
par_abierto "("
par_cerrado ")"
llave_abierta "{"
llave_cerrada "}"
cor_abierto "["
cor_cerrado "]"
funct_keyword function
ceil_keyword ceil
floor_keyword floor
let_keyword let
return_keyword return
while_keyword while
if_keyword if
else_keyword else 
lista_args {par_abierto}{nada}*({id}|({id}{nada}*","{nada}*)+{id}){nada}*{par_cerrado}
coma ","
igual "="
mult "*"
resta "-"
suma "+"
comp ">="|"<="|"<"|">"|"=="
and "&&"
or "||"
cadena \"([^"]|{nada})*\"







%%


{return_keyword} {printf("return keyword\n");}
{funct_keyword} {printf("function keyword\n");}
{par_abierto} {printf("parentesis abierto\n");}
{par_cerrado} {printf("parentesis cerrado\n");}
{llave_abierta} {printf("llave abierta\n");}
{llave_cerrada} {printf("llave cerrada\n");}
{suma} {printf("encontro suma\n");}
{coma} {printf("encontro coma\n");}
{igual} {printf("encontro igual\n");}
{mult} {printf("encontro mult\n");}
{resta} {printf("encontro resta\n");}
{and} {printf("encontro and\n");}
{or} {printf("encontro or\n");}
{ceil_keyword} {printf("encontro ceil built-in\n");}
{floor_keyword} {printf("encontro floor built-in\n");}
{let_keyword} {printf("encontro let\n");}
{while_keyword} {printf("encontro while\n");}
{if_keyword} {printf("encontro if\n");}
{else_keyword} {printf("encontro else\n");}
{comp} {printf("encontro comp operator: %s\n",yytext);}
{fin_inst} {printf("fin instruccion\n");}
{id} {printf("id: %s\n",yytext);}
{comentario} {printf("comentario: %s\n",yytext);}
{lista_args} {
    char* cleaned = strdup(yytext);
    // remove_spaces(cleaned);
    printf("lista argumentos: %s\n",yytext);
}
{cadena} {printf("cadena: %s\n",yytext);}
{numero} {printf("numero: %s\n",yytext);}
{nada}+ {//printf("encontro nada\n");
    }


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

