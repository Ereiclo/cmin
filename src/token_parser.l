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
%option yylineno

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
div "/"
comp ">="|"<="|"<"|">"|"=="
and "&&"
or "||"
cadena \"([^"]|{nada})*\"
negate "!"







%%


{return_keyword} {
    

    return RETURN;
}
{funct_keyword} {
    
    return FUNCTION;
}
{par_abierto} {
    
    return '(';
}
{par_cerrado} {
    
    return ')';
}
{llave_abierta} {
    
    return '{';
}
{llave_cerrada} {
    
    return '}';
}
{cor_abierto} {
    
    return '[';
}
{cor_cerrado} {
    
    return ']';
}

{suma} {
    
    yylval.value = strdup("+");

    return '+';
}
{coma} {
    
    return ',';
}
{igual} {
    
    yylval.value = strdup("=");
    return '=';
}
{mult} {
    

    yylval.value = strdup("*");
    return '*';
}
{div} {
    
    yylval.value = strdup("/");
    return '/';
}
{resta} {
    
    yylval.value = strdup("-");
    return '-';
}
{and} {
    
    yylval.value = strdup("and");
    return AND;
}
{or} {
    
    yylval.value = strdup("or");
    return OR;
}
{ceil_keyword} {
    
    return CEIL;
}
{floor_keyword} {
    return FLOOR;
}
{let_keyword} {
    
    return LET;
}
{while_keyword} {
    
    return WHILE;
}
{if_keyword} {
    
    return IF;
}
{else_keyword} {
    return ELSE;
}
{comp} {
    //tipo de comp
    yylval.value = strdup(yytext);

    return COMP;
}
{fin_inst} {
    return ';';
}
{id} {
    //guardar valor del id

    yylval.value = strdup(yytext);

    return ID;
}
{comentario} {

}

{cadena} {
    
    //valor de la cadena
    return CADENA;
}
{numero} {
    

    //valor del numero
    yylval.value = strdup(yytext);
    return NUMERO;
}

{negate} {

    return '!';
}
{nada}+ {//printf("encontro nada\n");
    }

. {yyerror("Unexpected token"); return YYerror;}


%%

