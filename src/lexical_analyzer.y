%{
   #include <stdio.h>
   #include <stdlib.h>
   #include <math.h>
   #include <string.h>
   int yylex(void);
   void yyerror(const char *s);
   int push_symbol(char*symbol);
   //FILE *yyin;
   char** symbol_table;
   int n_symbols = 0;
   char** function_table[2];
   int n_functions = 0;

   int check_symbol_existence(char* symbol);
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
%type<nodo> VALUE DECL NUM_LIKE
%define parse.error detailed


%{
    //%type<estru> C;

%}


%%
S: CODE {
   printf("El codigo generado es:\n%s",$1.code);
};
CODE: CODE I { 
   $$.code = concat_strings($1.code,$2.code);

   free($1.code);

}| I  {
   $$.code = $1.code;
}; 
I: IN ';' {
   $$.code = $1.code;
};
IN: exp {
   $$.code = $1.code;
} 
| ID {
   if(!check_symbol_existence($<value>1)) {
      yyerror("Variable does not exists");
      YYERROR;
   }
} '='   exp {
   char* temp1 = (char*) malloc(100);
   sprintf(temp1,"lda %s\n",$<value>1);
                                    //es $4 porque cuando se pone acciones
                                    //en el medio (lo que esta a la derecha de ID)
                                    //eso cuenta como si fuera un symbolo mas
   char* temp2 = concat_strings(temp1,$4.code);

   $$.code = concat_strings(temp2,"sto\n");

   free(temp1);
   free(temp2);
   free($<value>1);
   free($<value>3);
   free($4.code);
}|
DECL {
   $$.code = $1.code;
}
| %empty {
   $$.code = strdup("");
};

DECL: DECL ',' ID  {
   if(check_symbol_existence($<value>3)){
      yyerror("Variable already exists");
      YYABORT; 
   }


   char* temp = (char*) malloc(100);

   sprintf(temp,"new_var %s\n",$<value>3);
   $$.code = concat_strings($1.code,temp);
   push_symbol($<value>3);

   free($<value>3);
   free($1.code);
   free(temp);

} | DECL ',' ID '[' NUMERO ']' {
   if(check_symbol_existence($<value>3)){
      yyerror("Variable already exists");
      YYABORT; 
   }

   double num_d = atof($<value>5);
   int num_i = atoi($<value>5);
   if((int) ceil(num_d) != num_i){
      yyerror("Array size must be an integer");
      YYABORT;
   }else if(num_i < 1){
      yyerror("Array size must be at least 1");
      YYABORT;
   }

   char* temp = (char*) malloc(200);
   char template_string[] = "new_var %s\nlda %s\nnew_arr %d\nsto\n";
   sprintf(temp,template_string,$<value>3,$<value>3,num_i);

   $$.code = concat_strings($1.code,temp);
   push_symbol($<value>3);

   free(temp);
   free($<value>3);
   free($<value>5);
}
| LET ID {
   if(check_symbol_existence($<value>2)){
      yyerror("Variable already exists");
      YYABORT; 
   }

   
   $$.code = (char*) malloc(100);
   sprintf($$.code,"new_var %s\n",$<value>2);
   push_symbol($<value>2);

   free($<value>2);
   
} | LET ID '[' NUMERO ']' {
   if(check_symbol_existence($<value>2)){
      yyerror("Variable already exists");
      YYABORT; 
   }

   double num_d = atof($<value>4);
   int num_i = atoi($<value>4);
   if((int) ceil(num_d) != num_i){
      yyerror("Array size must be an integer");
      YYABORT;
   }else if(num_i < 1){
      yyerror("Array size must be at least 1");
      YYABORT;
   }



   $$.code = (char*) malloc(200);
   char template_string[] = "new_var %s\nlda %s\nnew_arr %d\nsto\n";
   sprintf($$.code,template_string,$<value>2,$<value>2,num_i);
   push_symbol($<value>2);

   

   free($<value>2);
   free($<value>4);

};


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

};
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

};
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



};
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

   //printf("code: %s",$$.code);
   //free(actual_code);
   //free($1.code);
   //free($1.name);
};
VALUE: ID {
   if(!check_symbol_existence($<value>1)){
      yyerror("Variable does not exists");
      YYABORT;
   }
   $$.code = (char*) malloc(60);
   sprintf($$.code,"lod %s\n",$<value>1);
   free($<value>1);
   //$$.name = $<value>1;
   //printf("%s\n",$$.name);
} |
ID {
   if(!check_symbol_existence($<value>1)) {
      yyerror("Variable does not exists");
      YYERROR;
   }
 } '[' NUM_LIKE ']'

 {
   
   $$.code = (char*) malloc(200);
   char template_string[] = "lod %s\n%sad\nloa\n";
   sprintf($$.code,template_string,$<value>1,$4.code);

   free($<value>1);
   free($4.code);

} 
| '(' exp ')' {
   $$.code = $2.code;
   }
| NUMERO {
   $$.code = (char*) malloc(60);
   sprintf($$.code,"ldc %s\n",$<value>1);
   free($<value>1);
   //$$.code = strdup("");
   //$$.name = $<value>1;
};
NUM_LIKE: ID {
   if(!check_symbol_existence($<value>1)) {
      yyerror("Variable does not exists");
      YYERROR;
   }
   $$.code = (char*) malloc(60);
   sprintf($$.code,"lod %s\n",$<value>1);
   free($<value>1);
} | NUMERO { 
   double num_d = atof($<value>1);
   int num_i = atoi($<value>1);
   if((int) ceil(num_d) != num_i){
      yyerror("Array index must be an integer");
      YYABORT;
   }else if(num_i < 0){
      yyerror("Array index must be at least 0");
      YYABORT;
   }

   $$.code = (char*) malloc(60);
   sprintf($$.code,"ldc %d\n",num_i);
   free($<value>1);
   //$$.code = strdup("");
   //$$.name = $<value>1;
}
LOGIC: AND {$$ = $<value>1;} | OR {$$ = $<value>1;};
OP1: '+' {$$ = $<value>1;} | '-'  {$$ = $<value>1;};
OP2: '*' {$$ = $<value>1;} | '/' {$$ = $<value>1;};

%%




