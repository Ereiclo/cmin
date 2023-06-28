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
%type<nodo> exp level1 level2 level3 CODE IN I
%type<nodo> VALUE



%{
    //%type<estru> C;

%}


%%
S: CODE {
   printf("El codigo generado es:\n%s",$1.code);
}
CODE: CODE I { 
   $$.code = concat_strings($1.code,$2.code);

   free($1.code);

}| I  {
   $$.code = $1.code;
}
I: IN FIN {
   $$.code = $1.code;
}
IN: exp {
   $$.code = $1.code;
}
| ID IGUAL exp {
   char* temp1 = (char*) malloc(100);
   sprintf(temp1,"lda %s\n",$<value>1);
   char* temp2 = concat_strings(temp1,$3.code);

   $$.code = concat_strings(temp2,"sto\n");

   free(temp1);
   free(temp2);
   free($<value>1);
   free($<value>2);
   free($3.code);
}
exp: exp LOGIC level1 {
   char* temp = concat_strings($1.code,$3.code);
   if(strcmp($2,"and") == 0)
      $$.code = concat_strings(temp,"land\n");
   else if(strcmp($2,"or") == 0)
      $$.code = concat_strings(temp,"lor\n");

   free(temp);
   free($1.code);
   free($2);
   free($3.code);
}
| level1 {

   $$.code = $1.code;

}
level1: level1 COMP level2 {
   char* temp = concat_strings($1.code,$3.code);
   if(strcmp($<value>2,">=") == 0)
      $$.code = concat_strings(temp,"geq\n");
   else if(strcmp($<value>2,"<=") == 0)
      $$.code = concat_strings(temp,"leq\n");
   else if(strcmp($<value>2,"<") == 0)
      $$.code = concat_strings(temp,"le\n");
   else if(strcmp($<value>2,">") == 0)
      $$.code = concat_strings(temp,"ge\n");
   else if(strcmp($<value>2,"==") == 0)
      $$.code = concat_strings(temp,"equi\n");

   free(temp);
   free($1.code);
   free($<value>2);
   free($3.code);

}
| level2 {

   $$.code = $1.code;

}
level2: level2 OP1 level3 {
   char* temp = concat_strings($1.code,$3.code);
   if(strcmp($2,"+") == 0)
      $$.code = concat_strings(temp,"ad\n");
   else if(strcmp($2,"-") == 0)
      $$.code = concat_strings(temp,"sb\n");

   free(temp);
   free($1.code);
   free($2);
   free($3.code);
}
| level3 {


   $$.code = $1.code;



}
level3: level3 OP2 VALUE {


   char* temp = concat_strings($1.code,$3.code);
   if(strcmp($2,"*") == 0)
      $$.code = concat_strings(temp,"mp\n");
   else if(strcmp($2,"/") == 0)
      $$.code = concat_strings(temp,"dv\n");

   free(temp);
   free($1.code);
   free($2);
   free($3.code);
} 
| VALUE {


   $$.code = $1.code;

   //free(actual_code);
   //free($1.code);
   //free($1.name);
}
VALUE: ID {
   $$.code = (char*) malloc(60);
   sprintf($$.code,"lod %s\n",$<value>1);
   free($<value>1);
   //$$.name = $<value>1;
   //printf("%s\n",$$.name);
} | PAR_ABIERTO exp PAR_CERRADO {
   $$.code = $2.code;
   }
   | NUMERO {

   $$.code = (char*) malloc(60);
   sprintf($$.code,"ldc %s\n",$<value>1);
   free($<value>1);
   //$$.code = strdup("");
   //$$.name = $<value>1;
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





