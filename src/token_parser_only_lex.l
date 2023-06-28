%{
    #include <stdio.h>
    #include <string.h>
    #include "y.tab.h"

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


{return_keyword} {
    printf("return keyword\n");
    // return 258;
}
{funct_keyword} {
    printf("function keyword\n");
    // return FUNCTION;
}
{par_abierto} {
    printf("parentesis abierto\n");
    // return PAR_ABIERTO;
}
{par_cerrado} {
    printf("parentesis cerrado\n");
    // return PAR_CERRADO;
}
{llave_abierta} {
    printf("llave abierta\n");
    // return LLAVE_ABIERTA;
}
{llave_cerrada} {
    printf("llave cerrada\n");
    // return LLAVE_CERRADA;
}
{suma} {
    printf("encontro suma\n");
    // return SUMA;
}
{coma} {
    printf("encontro coma\n");
    // return COMA;
}
{igual} {
    printf("encontro igual\n");
    // return IGUAL;
}
{mult} {
    printf("encontro mult\n");
    // return MULT;
}
{resta} {
    printf("encontro resta\n");
    // return RESTA;
}
{and} {
    printf("encontro and\n");
    // return AND;
}
{or} {
    printf("encontro or\n");
    // return OR;
}
{ceil_keyword} {
    printf("encontro ceil built-in\n");
    // return CEIL;
}
{floor_keyword} {printf("encontro floor built-in\n");
    // return FLOOR;
}
{let_keyword} {
    printf("encontro let\n");
    // return LET;
}
{while_keyword} {
    printf("encontro while\n");
    // return WHILE;
}
{if_keyword} {
    printf("encontro if\n");
    // return IF;
}
{else_keyword} {
    printf("encontro else\n");
    // return ELSE;
}
{comp} {
    printf("encontro comp operator: %s\n",yytext);
    //tipo de comp

    // return COMP;
}
{fin_inst} {
    printf("fin instruccion\n");
    // return FIN;
}
{id} {
    printf("id: %s\n",yytext);
    //guardar valor del id

    // return ID;
}
{comentario} {
    printf("comentario: %s\n",yytext);
}
{lista_args} {
    char* cleaned = strdup(yytext);
    // remove_spaces(cleaned);
    printf("lista argumentos: %s\n",yytext);


    // return LISTA_ARGS;
}
{cadena} {
    printf("cadena: %s\n",yytext);
    //valor de la cadena
    // return CADENA;
}
{numero} {
    printf("numero: %s\n",yytext);

    //valor del numero
    // return NUMERO;
}
{nada}+ {//printf("encontro nada\n");
    }


%%

