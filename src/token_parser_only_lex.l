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
comentario ("/*"([^/]|{nada})*"*/")|("//".*)
fin_inst ";"
numero ([0-9]+("."[0-9]*){0,1})|("."[0-9]+)|inf
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
main_keyword "main"
while_keyword while
if_keyword if
else_keyword else 
lista_args {par_abierto}{nada}*({id}|({id}{nada}*","{nada}*)+{id}){nada}*{par_cerrado}
coma ","
igual "="
mult "*"
resta "-"
suma "+"
mod "%"
div "/"
comp ">="|"<="|"<"|">"|"=="|"!="
and "&&"
or "||"
cadena \"([^"]|{nada})*\"
negate "!"
print_keyword print







%%


{comentario} {}



{main_keyword} {
}


{print_keyword} {
	printf("%s",yytext);
}

{return_keyword} {
	

	printf("%s",yytext);
}
{funct_keyword} {
	
	printf("%s",yytext);
}
{par_abierto} {
	
	printf("%s",yytext);
}
{par_cerrado} {
	
	printf("%s",yytext);
}
{llave_abierta} {
	
	printf("%s",yytext);
}
{llave_cerrada} {
	
	printf("%s",yytext);
}
{cor_abierto} {
	
	printf("%s",yytext);
}
{cor_cerrado} {
	
	printf("%s",yytext);
}

{suma} {
	
	yylval.value = strdup("+");

	printf("%s",yytext);
}
{coma} {
	
	printf("%s",yytext);
}
{igual} {
	
	yylval.value = strdup("=");
	printf("%s",yytext);
}
{mult} {
	

	yylval.value = strdup("*");
	printf("%s",yytext);
}
{div} {
	
	yylval.value = strdup("/");
	printf("%s",yytext);
}
{resta} {
	
	yylval.value = strdup("-");
	printf("%s",yytext);
}
{mod} {
	
	yylval.value = strdup("%");
	printf("%s",yytext);
}
{and} {
	
	yylval.value = strdup("and");
	printf("%s",yytext);
}
{or} {
	
	yylval.value = strdup("or");
	printf("%s",yytext);
}
{ceil_keyword} {
	
	printf("%s",yytext);
}
{floor_keyword} {
	printf("%s",yytext);
}
{let_keyword} {
	
	printf("%s",yytext);
}
{while_keyword} {
	
	printf("%s",yytext);
}
{if_keyword} {
	
	printf("%s",yytext);
}
{else_keyword} {
	printf("%s",yytext);
}
{comp} {
	//tipo de comp
	yylval.value = strdup(yytext);

	printf("%s",yytext);
}
{fin_inst} {
	printf("%s",yytext);
}

{numero} {
	

	//valor del numero
	yylval.value = strdup(yytext);
	printf("%s",yytext);
}
{id} {
	//guardar valor del id

	yylval.value = strdup(yytext);

	printf("%s",yytext);
}
{cadena} {
	
	//valor de la cadena (quitando comillas)
	int length = strlen(yytext);
	yylval.value = malloc( length - 1 );
	memcpy(yylval.value,&yytext[1],length-2);
	yylval.value[length-2] = '\0';

	printf("empezo%stermino\n",yytext);
}


{negate} {

	printf("%s",yytext);
}

{nada}+ {//printf("encontro nada\n");
	}

. {printf("%s",yytext);yyerror("Unexpected token"); return YYerror;}


%%



