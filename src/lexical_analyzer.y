%{
   #include <stdio.h>
   #include <stdlib.h>
   #include <math.h>
   #include <string.h>
   int yylex(void);
   void yyerror(const char *s);
   //FILE *yyin;
   FILE *out;
   struct function{
      char* name;
      int n_args;
      int defined;
   };

   struct variable{
      char* name;
      char* scope;

   };


   struct function* table_function;
   struct variable* table_variable;
   int n_variables = 0;
   int n_functions = 0;
   int actual_label = 0;
   char* actual_scope;
   int id_actual_scope = 0;

   int check_variable_existence(char* symbol,char*scope);
   void push_variable(char*symbol,char*scope);
   void declare_function(char*name,int n_args);
   void define_function(char*name);
   int check_function_existence(char* name);
   int is_defined(char* name, int args);
   int is_valid_call(char*name, int args);
   int is_valid_definition(char*name, int args);
   char* check_undefined_function();

   char* concat_strings(char* dest, char* src){

      char* new_string = (char*) malloc(strlen(dest) + strlen(src) + 1);

      strcpy(new_string,dest);
      strcat(new_string,src);

   }



%}

%{

   typedef struct{
      char** values;
      int tamanio;
   } ls;

   typedef struct{
      char* code; 
      int count;
   } node;
%}


%token RETURN FUNCTION MAIN
%token AND OR CEIL FLOOR LET WHILE IF ELSE COMP 
%token ID CADENA NUMERO PRINT

%union {
    int count;
    ls lista;
    node nodo;
    char* value;
    double* lista_num;

}


%type<value> OP1 OP2 LOGIC 
%type<nodo> exp level1 level2 level3 CODE IN I LISTA_ARGS_PRINT
%type<nodo> VALUE DECL NUM_LIKE SUB_CODE IF_BLOCK IF_ELSE_BLOCK P WHILE_BLOCK
%type<nodo> FUNCT_MAIN FUNCT_DEF FUNCT_DEFS UNARY
%type<nodo> LISTA_ARGS_DEF LISTA_ARGS_CALL ID_ASSIGN
%type<lista_num> LISTA_ARRAY LISTA_ARGS_NUM
%define parse.error detailed

%right "then" ELSE


%%


S: 
FUNCT_DECLS FUNCT_DEFS FUNCT_MAIN {

   char* temp = concat_strings("ujp $main\n",$2.code);
   char* result = concat_strings(temp,$3.code);

   fwrite(result,1,strlen(result),out);
   free(temp);
   free($2.code);
   free($3.code);
} | 

FUNCT_MAIN 
{
   //printf("El codigo generado es:\n%s",$1.code);
   fwrite($1.code,1,strlen($1.code),out);
};



FUNCT_DECLS : FUNCT_DECLS FUNCT_DECL | FUNCT_DECL;

FUNCT_DEFS : FUNCT_DEFS FUNCT_DEF
{
   $$.code = concat_strings($1.code,$2.code);

   free($1.code);
   free($2.code);
} | 

FUNCT_DEF
{
   $$.code = $1.code;
};


FUNCT_DECL: 

FUNCTION ID '(' LISTA_ARGS_DEF ')' ';' 
{
   if(check_function_existence($<value>2)){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s already declared",$<value>2);
      yyerror(error_string);
      YYABORT;
   }

   declare_function(strdup($<value>2),$4.count);

   free($<value>2);
   free($4.code);

};

FUNCT_DEF: 

FUNCTION ID '(' LISTA_ARGS_DEF ')' '{' CODE '}' 
{
   free(actual_scope);
   actual_scope = strdup("");

   if(is_valid_definition($<value>2,$4.count) == 0){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s not declared",$<value>2);
      yyerror(error_string);
      YYABORT;
   }
   else if(is_valid_definition($<value>2,$4.count) == -1){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s already defined",$<value>2);
      yyerror(error_string);
      YYABORT;
   } else if(is_valid_definition($<value>2,$4.count) == -2){
      char* error_string  = malloc(100);
      sprintf(error_string,"Definition of function %s does not match number of args of declaration",$<value>2);
      yyerror(error_string);
      YYABORT;
   }

   define_function($<value>2);


   //hacer validaciones
   char* temp1 = malloc(100);

   sprintf(temp1,"lab $%s\nscope \n",$<value>2);

   char*temp2 = concat_strings(temp1,$4.code);

   char* temp3 = concat_strings(temp2,$7.code);

   $$.code = concat_strings(temp3,"ldc 0\nendscope \nreturn_jp \n");


   free(temp1);
   free(temp2);
   free(temp3);
   free($<value>2);
   free($4.code);
   free($7.code);



} | 

FUNCTION ID '(' LISTA_ARGS_DEF ')' '{' '}'
{

   if(is_valid_definition($<value>2,$4.count) == 0){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s not declared",$<value>2);
      yyerror(error_string);
      YYABORT;
   }
   else if(is_valid_definition($<value>2,$4.count) == -1){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s already defined",$<value>2);
      yyerror(error_string);
      YYABORT;
   } else if(is_valid_definition($<value>2,$4.count) == -2){
      char* error_string  = malloc(100);
      sprintf(error_string,"Definition of function %s does not match number of args of declaration",$<value>2);
      yyerror(error_string);
      YYABORT;
   }


   define_function($<value>2);

   char* temp1 = malloc(100);

   sprintf(temp1,"lab $%s\nscope \n",$<value>2);

   char*temp2 = concat_strings(temp1,$4.code);


   $$.code = concat_strings(temp2,"ldc 0\nendscope \nreturn_jp \n");


   free(temp1);
   free(temp2);
   free($<value>2);
   free($4.code);

};

FUNCT_MAIN: 

FUNCTION MAIN  '(' ')' '{'

{ 
   free(actual_scope);
   actual_scope = strdup("main");
}
 
CODE '}'
{
   char* error_string = check_undefined_function();

   if(strcmp(error_string,"") != 0){

      yyerror(error_string);
      YYABORT;
   }

   char* temp = concat_strings("lab $main\nscope \n",$7.code);

   $$.code = concat_strings(temp,"endscope \n");


   free($7.code);
   free(temp);


} | 

FUNCTION MAIN '(' ')' '{' '}'
{
   char* error_string = check_undefined_function();

   if(strcmp(error_string,"") != 0){

      yyerror(error_string);
      YYABORT;
   }


   $$.code = strdup("lab $main\nscope \nendscope \n");

};


LISTA_ARGS_DEF: 

LISTA_ARGS_DEF ',' ID 
{
   if(check_variable_existence($<value>3,actual_scope) == 1){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",$<value>3);
      yyerror(error_string);
      YYERROR;
   }
   // printf("ke:%s\n",$<value>3);

   push_variable(strdup($<value>3),actual_scope);

   $$.count = $1.count + 1;

   char* temp = malloc(200);

   sprintf(temp,"sto \nnew_var %s\nlda %s\nlod $\nsto \n",$<value>3,$<value>3);

   $$.code = concat_strings(temp,$1.code);

   free($1.code);
   free($<value>3);
} |  

ID 
{
   free(actual_scope);
   actual_scope = malloc(100);
   sprintf(actual_scope,"scope%d",id_actual_scope++);
   push_variable(strdup($<value>1),actual_scope);


   $$.count = 1;

   $$.code = malloc(200);

   sprintf($$.code,"sto \nnew_var %s\nlda %s\nlod $\nsto \n",$<value>1,$<value>1);

   free($<value>1);
} | 

%empty
{
   free(actual_scope);
   actual_scope = malloc(100);
   sprintf(actual_scope,"scope%d",id_actual_scope++);
   $$.count = 0;
   $$.code = strdup("");
};


CODE:

CODE I 
{ 
   $$.code = concat_strings($1.code,$2.code);

   free($1.code);

} | 

I  
{
   $$.code = $1.code;
}; 

I: 

IN ';' 
{
   $$.code = $1.code;
} |

SUB_CODE 
{
   $$.code = $1.code;
} 

;

IN: 
 
ID_ASSIGN {$$.code = $1.code;} |

ID '[' NUM_LIKE 
{
   if(!check_variable_existence($<value>1,actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",$<value>1);
      yyerror(error_string);
      YYABORT;
   }

   $<nodo>$.code = (char*) malloc(200);
   char template_string[] = "lod %s\n%sad \n";
   sprintf($<nodo>$.code,template_string,$<value>1,$3.code);

   free($<value>1);
   free($3.code);


} 
']' '=' exp 
{
   char* temp = concat_strings($<nodo>4.code,$7.code);

   $$.code = concat_strings(temp,"sto \n");

   free(temp);
   free($<nodo>4.code);
   free($7.code);
} |

DECL
{
   $$.code = $1.code;
} |

ID '(' LISTA_ARGS_CALL ')'
{
   if(is_valid_call($<value>1,$3.count) == 0){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s does not exists",$<value>1);
      yyerror(error_string);
      YYABORT;
   }
   else if(is_valid_call($<value>1,$3.count) == -1){
      char* error_string  = malloc(100);
      sprintf(error_string,"Call to function %s does not match number of args",$<value>1);
      yyerror(error_string);
      YYABORT;

   }
   char* temp = malloc(100);
   sprintf(temp,"call_jp $%s\npop \n",$<value>1);
   $$.code = concat_strings($3.code,temp);

   free(temp);
   free($3.code);

} |

PRINT '(' LISTA_ARGS_PRINT ')'
{
   $$.code = $3.code;

} |

RETURN exp {
   //no hacerlo en main
   // printf("%sa",actual_scope);
   if(strcmp(actual_scope,"main") == 0){
      yyerror("Main cannnot return");
      YYABORT;
   }
   $$.code = concat_strings($2.code,"endscope \nreturn_jp \n");

   free($2.code);

} | 

%empty {
   $$.code = strdup("");
};

ID_ASSIGN: 

ID '=' LISTA_ARRAY 
{
   if(!check_variable_existence($<value>1,actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",$<value>1);
      yyerror(error_string);
      YYABORT;
   }

   char* actual_code = strdup("");
   int size = $3[0];

   for(int i = 1; i < (size + 1);++i){
      char* prev_code = actual_code;
      char* temp = malloc(300);
      double actual_num = $3[i];
      // printf("%f\n",actual_num);
      sprintf(temp,"lod %s\nldc %d\nad \nldc %f\nsto \n",$<value>1,i-1,actual_num);

      actual_code = concat_strings(prev_code,temp);

      free(prev_code);
      free(temp);


   }
   char* temp = malloc(100);
   sprintf(temp,"lda %s\nnew_arr %d\nsto \n",$<value>1,size);

   $$.code = concat_strings(temp,actual_code);

   free($<value>1);
   free($3);
   free(temp);
   free(actual_code);

} | 

ID '=' exp 
{

   if(!check_variable_existence($<value>1,actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",$<value>1);
      yyerror(error_string);
      YYABORT;
   }
   char* temp1 = (char*) malloc(100);
   sprintf(temp1,"lda %s\n",$<value>1);
   char* temp2 = concat_strings(temp1,$3.code);

   $$.code = concat_strings(temp2,"sto \n");

   free(temp1);
   free(temp2);
   free($<value>1);
   free($<value>2);
   free($3.code);
};


LISTA_ARRAY: '[' LISTA_ARGS_NUM ']'  {$$ = $2;};

LISTA_ARGS_NUM: 

LISTA_ARGS_NUM ',' NUMERO 
{
   $$ = $1;
   int size = $$[0];
   $$[size] = atof($<value>3);
   $$[0] = size + 1;
   // printf("%f\n",atof($<value>3));

} |

NUMERO 
{
   $$ = (double*) malloc(sizeof(double)*100);
   $$[0] = 1;
   $$[1] = atof($<value>1);

   // printf("%f\n",atof($<value>1));
};

LISTA_ARGS_PRINT: 
LISTA_ARGS_PRINT ',' exp 
{
   char* temp = concat_strings($3.code,"print_c \n");

   $$.code = concat_strings($1.code,temp);

   free($1.code);
   free($3.code);

} | 

LISTA_ARGS_PRINT ',' CADENA 
{
   char* temp = malloc(200);

   sprintf(temp,"print_s %s\n",$<value>3);
   $$.code = concat_strings($1.code,temp);

   free(temp);
   free($<value>3);

} | 

CADENA 
{
   $$.code = malloc(200);
   sprintf($$.code,"print_s %s\n",$<value>1);

   free($<value>1);

} | 

exp
{

   $$.code = concat_strings($1.code,"print_c \n");

   free($1.code);

}



SUB_CODE: IF_BLOCK {$$.code = $1.code;} | IF_ELSE_BLOCK {$$.code = $1.code;} | WHILE_BLOCK {$$.code = $1.code;};

WHILE_BLOCK: 

WHILE '(' exp ')' P 
{
   int start_label = actual_label++;
   int end_label = actual_label++;

   char* temp1 = malloc(100);
   sprintf(temp1,"lab L%d\n",start_label);
   char* temp2 = malloc(100);
   sprintf(temp2,"ne \ntjp L%d\n",end_label);
   char* temp3 = malloc(100);
   sprintf(temp3,"ujp L%d\nlab L%d\n",start_label,end_label);

   char*temp4 = concat_strings(temp1,$3.code);
   char*temp5 = concat_strings(temp4,temp2);
   char* temp6 = concat_strings($5.code,temp3);

   $$.code = concat_strings(temp5,temp6);

   free($3.code);
   free($5.code);
   free(temp1);
   free(temp2);
   free(temp3);
   free(temp4);
   free(temp5);
   free(temp6);

};


IF_BLOCK: 
IF '(' exp ')' P %prec "then"
{

   int label = actual_label++;

   char* temp1 = malloc(100);
   sprintf(temp1,"ne \ntjp L%d\n",label);

   char* temp2 = malloc(100);
   sprintf(temp2,"lab L%d\n",label);

   char* temp3 = concat_strings($3.code,temp1);
   char* temp4 = concat_strings($5.code,temp2);




   $$.code = concat_strings(temp3,temp4);

   free($3.code);
   free($5.code);
   free(temp1);
   free(temp2);
   free(temp3);
   free(temp4);
};

IF_ELSE_BLOCK: 
IF '(' exp ')' P ELSE P
{
   int label_else = actual_label++;
   int label_end = actual_label++;

   char* temp1 = malloc(100);
   sprintf(temp1,"ne \ntjp L%d\n",label_else);

   char* temp2 = malloc(100);
   sprintf(temp2,"ujp L%d\nlab L%d\n",label_end,label_else);

   char* temp3 = malloc(100);
   sprintf(temp3,"lab L%d\n",label_end);

   char* temp4 = concat_strings($3.code,temp1);

   char* temp5 = concat_strings($5.code,temp2);

   char* temp6 = concat_strings($7.code,temp3);


   char* temp7 = concat_strings(temp4,temp5);

   $$.code = concat_strings(temp7,temp6);

   free($3.code);
   free($5.code);
   free($7.code);
   free(temp1);
   free(temp2);
   free(temp3);
   free(temp4);
   free(temp5);
   free(temp6);

};

P: I {$$.code = $1.code;} | '{' CODE '}' {$$.code = $2.code;}; | '{' '}' {$$.code =strdup("");}

DECL: 

DECL ',' ID 
{
   if(check_variable_existence($<value>3,actual_scope)){
      char * error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",$<value>3);
      yyerror(error_string);
      YYABORT; 
   }


   char* temp = (char*) malloc(100);

   sprintf(temp,"new_var %s\n",$<value>3);
   $$.code = concat_strings($1.code,temp);
   push_variable($<value>3,actual_scope);

   free($<value>3);
   free($1.code);
   free(temp);

} | 

DECL ',' ID '[' NUMERO ']' 
{
   if(check_variable_existence($<value>3,actual_scope)){
      char * error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",$<value>3);
      yyerror(error_string);
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
   char template_string[] = "new_var %s\nlda %s\nnew_arr %d\nsto \n";
   sprintf(temp,template_string,$<value>3,$<value>3,num_i);

   $$.code = concat_strings($1.code,temp);
   push_variable($<value>3,actual_scope);

   free(temp);
   free($<value>3);
   free($<value>5);
} |

LET ID 
{
   if(check_variable_existence($<value>2,actual_scope)){
      char * error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",$<value>2);
      yyerror(error_string);
      YYABORT; 
   }

   
   $$.code = (char*) malloc(100);
   sprintf($$.code,"new_var %s\n",$<value>2);
   push_variable($<value>2,actual_scope);

   free($<value>2);
   
} | 

LET ID '[' NUMERO ']' 
{
   if(check_variable_existence($<value>2,actual_scope)){
      char * error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",$<value>2);
      yyerror(error_string);
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
   char template_string[] = "new_var %s\nlda %s\nnew_arr %d\nsto \n";
   sprintf($$.code,template_string,$<value>2,$<value>2,num_i);
   push_variable($<value>2,actual_scope);

   free($<value>2);
   free($<value>4);
};


exp:

exp LOGIC level1 
{
   char* temp = concat_strings($1.code,$3.code);
   if(strcmp($2,"and") == 0)
      $$.code = concat_strings(temp,"land \n");
   else if(strcmp($2,"or") == 0)
      $$.code = concat_strings(temp,"lor \n");

   free(temp);
   free($1.code);
   free($2);
   free($3.code);
} |

level1 
{

   $$.code = $1.code;

};

level1: 

level1 COMP level2 
{
   char* temp = concat_strings($1.code,$3.code);
   if(strcmp($<value>2,">=") == 0)
      $$.code = concat_strings(temp,"geq \n");
   else if(strcmp($<value>2,"<=") == 0)
      $$.code = concat_strings(temp,"leq \n");
   else if(strcmp($<value>2,"<") == 0)
      $$.code = concat_strings(temp,"le \n");
   else if(strcmp($<value>2,">") == 0)
      $$.code = concat_strings(temp,"ge \n");
   else if(strcmp($<value>2,"==") == 0)
      $$.code = concat_strings(temp,"equi \n");

   free(temp);
   free($1.code);
   free($<value>2);
   free($3.code);

} |

level2 {

   $$.code = $1.code;

};

level2: 

level2 OP1 level3 
{
   char* temp = concat_strings($1.code,$3.code);
   if(strcmp($2,"+") == 0)
      $$.code = concat_strings(temp,"ad \n");
   else if(strcmp($2,"-") == 0)
      $$.code = concat_strings(temp,"sb \n");

   free(temp);
   free($1.code);
   free($2);
   free($3.code);
} |

level3 {

   $$.code = $1.code;

};

level3:

level3 OP2 UNARY 
{


   char* temp = concat_strings($1.code,$3.code);
   if(strcmp($2,"*") == 0)
      $$.code = concat_strings(temp,"mp \n");
   else if(strcmp($2,"/") == 0)
      $$.code = concat_strings(temp,"dv \n");
   else if(strcmp($2,"%") == 0)
      $$.code = concat_strings(temp,"mod \n");
   //else if(strcmp($2,"//") == 0)
   //   $$.code = concat_strings(temp,"dvf \n");

   free(temp);
   free($1.code);
   free($2);
   free($3.code);
} |

UNARY
{


   $$.code = $1.code;

   //printf("code: %s",$$.code);
   //free(actual_code);
   //free($1.code);
   //free($1.name);
};

UNARY: 

'!' VALUE 
{
   $$.code = concat_strings($2.code,"ne \n");
   free($2.code);

} | 

'-' VALUE 

{
   $$.code = concat_strings($2.code,"ldc -1\nmp \n");

   free($2.code);

} | 

VALUE
{
   $$.code = $1.code;
};


VALUE:

ID 
{
   if(!check_variable_existence($<value>1,actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",$<value>1);
      yyerror(error_string);
      YYABORT;
   }
   $$.code = (char*) malloc(60);
   sprintf($$.code,"lod %s\n",$<value>1);
   free($<value>1);
   //$$.name = $<value>1;
   //printf("%s\n",$$.name);
} | 


ID 
'[' NUM_LIKE ']'
{
   if(!check_variable_existence($<value>1,actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",$<value>1);
      yyerror(error_string);
      YYABORT;
   }
   
   $$.code = (char*) malloc(200);
   char template_string[] = "lod %s\n%sad \nloa \n";
   sprintf($$.code,template_string,$<value>1,$3.code);

   free($<value>1);
   free($3.code);

} |

ID '(' LISTA_ARGS_CALL ')'
{
   if(is_valid_call($<value>1,$3.count) == 0){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s does not exists",$<value>1);
      yyerror(error_string);
      YYABORT;
   }
   else if(is_valid_call($<value>1,$3.count) == -1){
      char* error_string  = malloc(100);
      sprintf(error_string,"Call to function %s does not match number of args",$<value>1);
      yyerror(error_string);
      YYABORT;

   }
   char* temp = malloc(100);
   sprintf(temp,"call_jp $%s\n",$<value>1);
   $$.code = concat_strings($3.code,temp);

   free(temp);
   free($3.code);

} |

CEIL '(' exp ')' 
{
   $$.code = concat_strings($3.code,"ceil \n");

} |

FLOOR '(' exp ')' 
{
   $$.code = concat_strings($3.code,"floor \n");

} |

'(' exp ')' 
{
   $$.code = $2.code;
} | 


NUMERO
{
   $$.code = (char*) malloc(60);
   sprintf($$.code,"ldc %s\n",$<value>1);
   free($<value>1);
   //$$.code = strdup("");
   //$$.name = $<value>1;
};

LISTA_ARGS_CALL: 

LISTA_ARGS_CALL ',' exp 
{
   char* temp = concat_strings("lda $\n",$3.code);


   $$.code = concat_strings($1.code,temp);
   $$.count = $1.count + 1;

   free(temp);
   free($3.code);
} | 

exp 
{
   $$.code = concat_strings("lda $\n",$1.code);
   $$.count = 1;

   free($1.code);

} | 

%empty

{
   $$.code = strdup("");
   $$.count = 0;

};

NUM_LIKE: 

ID 
{

   if(!check_variable_existence($<value>1,actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",$<value>1);
      yyerror(error_string);
      YYABORT;
   }
   
   $$.code = (char*) malloc(60);
   sprintf($$.code,"lod %s\n",$<value>1);
   free($<value>1);
} | 

NUMERO 
{ 
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
};

LOGIC: AND {$$ = $<value>1;} | OR {$$ = $<value>1;};
OP1: '+' {$$ = $<value>1;} | '-'  {$$ = $<value>1;};
OP2: '*' {$$ = $<value>1;} | '/' {$$ = $<value>1;} |'%' {$$ = $<value>1;};

%%




