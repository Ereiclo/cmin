%{
   #include <stdio.h>
   #include <stdlib.h>
   //#include <math.h>
   #include <string.h>
   int yylex(void);
   void yyerror(char *s);
   FILE *yyin;
   int actual_temp = 0;

   char* concat_strings(char* dest, char* src){

      char* new_string = (char*) malloc(strlen(dest) + strlen(src) + 1);

      strcpy(new_string,dest);
      strcat(new_string,src);

   }
%}

%{
   typedef   struct {
      char* tipo;
      int tamanio;
   } tipot;

   typedef struct{
      char* code; 
      char* value;
      char* name;
   } node;
%}


%token RETURN FUNCTION PAR_ABIERTO PAR_CERRADO
%token LLAVE_ABIERTA LLAVE_CERRADA SUMA COMA IGUAL
%token MULT RESTA AND OR CEIL FLOOR LET WHILE IF ELSE COMP FIN
%token ID LISTA_ARGS CADENA NUMERO DIV

%union {
    tipot estru;
    int num;
    node nodo;
    char* value;

}


%type<value> OP1 OP2 LOGIC
%type<nodo> exp level1 level2 level3
%type<nodo> VALUE



%{
    //%type<estru> C;

%}


%%
S: exp {
   printf("El codigo generado es:\n%s",$1.code);
}
exp: exp LOGIC level1 | level1 {
   $$.name = (char*) malloc(51);
   sprintf($$.name,"t%d",actual_temp++);


   char* actual_code = (char*) malloc(101);
   sprintf(actual_code,"%s=%s\n",$$.name,$1.name);


   $$.code = concat_strings($1.code,actual_code);

   free(actual_code);
   free($1.code);
   free($1.name);

}
level1: level1 COMP level2 | level2 {
   $$.name = (char*) malloc(51);
   sprintf($$.name,"t%d",actual_temp++);


   char* actual_code = (char*) malloc(101);
   sprintf(actual_code,"%s=%s\n",$$.name,$1.name);


   $$.code = concat_strings($1.code,actual_code);

   free(actual_code);
   free($1.code);
   free($1.name);


}
level2: level2 OP1 level3 | level3 {
   $$.name = (char*) malloc(51);
   sprintf($$.name,"t%d",actual_temp++);


   char* actual_code = (char*) malloc(101);
   sprintf(actual_code,"%s=%s\n",$$.name,$1.name);



   $$.code = concat_strings($1.code,actual_code);

   free(actual_code);
   free($1.code);
   free($1.name);

}
level3: level3 OP2 VALUE {
   $$.name = (char*) malloc(51);
   sprintf($$.name,"t%d",actual_temp++);


   char* actual_code = (char*) malloc(102);
   sprintf(actual_code,"%s=%s%s%s\n",$$.name,
                                 $1.name,     
                                 $2,
                                 $3.name);


   $$.code = concat_strings(concat_strings($1.code,$3.code),actual_code);

   free(actual_code);
   free($1.code);
   free($1.name);
   free($2);
   free($3.name);
   free($3.code);
} 
| VALUE {
   $$.name = (char*) malloc(51);
   sprintf($$.name,"t%d",actual_temp++);


   char* actual_code = (char*) malloc(101);
   sprintf(actual_code,"%s=%s\n",$$.name,$1.name);


   $$.code = concat_strings($1.code,actual_code);

   free(actual_code);
   free($1.code);
   free($1.name);
}
VALUE: ID {
   $$.code = strdup("");
   $$.name = $<value>1;
   //printf("%s\n",$$.name);
} | PAR_ABIERTO exp PAR_CERRADO {$$.code = strdup("");}| NUMERO {
   $$.code = strdup("");
   $$.name = $<value>1;
}
LOGIC: AND {$$ = $<value>1;} | OR {$$ = $<value>1;}
OP1: SUMA {$$ = $<value>1;} | RESTA  {$$ = $<value>1;}
OP2: MULT {$$ = $<value>1;} | DIV {$$ = $<value>1;}

%%

void parse(FILE *file) {
   yyin = file;
   yyparse();
   fclose(yyin);
}

void yyerror(char *s) {
   printf("\n%s\n", s);
}





