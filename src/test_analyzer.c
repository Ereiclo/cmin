#include "y.tab.c"
#include "lex.yy.c"


void push_variable(char*name,char*scope){

    table_variable[n_variables].name = strdup(name);
    table_variable[n_variables].scope = strdup(scope);

    ++n_variables;
}


int check_variable_existence(char* name, char* scope){


    for(int i= 0; i < n_variables;++i){
        if(strcmp(table_variable[i].name,name) == 0 &&
           strcmp(table_variable[i].scope,scope) == 0) return 1;

    }

    return 0;

}


void create_variable_table(int size,int max_length){
    table_variable = (struct variable*) malloc(sizeof(struct variable)*size);

    for(int i= 0; i < size;++i){
        table_variable[i].name = (char*) malloc(max_length+1);
        table_variable[i].scope = (char*) malloc(max_length+1);
    }

}

void declare_function(char*name,int n_args){

    table_function[n_functions].name = name;
    table_function[n_functions].n_args = n_args;
    table_function[n_functions].defined = 0;

    ++n_functions;
}

void define_function(char*name){

    for(int i= 0; i < n_functions;++i){
        if(strcmp(table_function[i].name,name) == 0) {
            table_function[i].defined = 1;
            return;
        }
    }
}

int check_function_existence(char* name){
    for(int i= 0; i < n_functions;++i){
        // printf("%s %d\n", table_function[i].name,table_function[i].n_args );
        if(strcmp(table_function[i].name,name) == 0) {
            return 1;
        }
    }

    return 0;
}

int is_defined(char* name, int args){
    for(int i= 0; i < n_functions;++i){
        if(strcmp(table_function[i].name,name) == 0) {
            return table_function[i].defined;
        }
    }

    return 0;
}

int is_valid_call(char*name, int args){
    for(int i= 0; i < n_functions;++i){
        if(strcmp(table_function[i].name,name) == 0) {

            struct function actual_function = table_function[i];



            if(actual_function.n_args != args) return -1;
            else return 1;
        }
    }

    return 0;

}

int is_valid_definition(char*name, int args){
    for(int i= 0; i < n_functions;++i){
        if(strcmp(table_function[i].name,name) == 0) {

            struct function actual_function = table_function[i];
            // printf("%s %d %d",actual_function.name,actual_function.defined,actual_function.n_args);


            if(actual_function.defined == 1) return -1;
            else if(actual_function.n_args != args) return -2;
            else return 1;

        }
    }

    return 0;
}

char* check_undefined_function(){
    for(int i= 0; i < n_functions;++i){
        if(table_function[i].defined == 0) {
            char* error_string = malloc(100);
            sprintf(error_string,"Undefined function %s",table_function[i].name);
            return error_string;
        }
    }


    return "";
}

void create_function_table(int size,int max_length){
    table_function = (struct function*) malloc(sizeof(struct function)*size);

    for(int i= 0; i < size;++i){
        table_function[i].name = (char*) malloc(max_length+1);
    }

}

void parse(FILE *file) {


   actual_scope = strdup("");
   create_function_table(1000,100);
   create_variable_table(1000,100);
   yyin = file;
   yyparse();
}


void yyerror(const char *s) {
      printf("%s in line %d\n", s, yylineno);

    //printf("\n%s\n", s);
}
void main(int argc,char**argv){
    FILE *file = fopen("input", "r");
    out = fopen("exe.cm","w");
    parse(file);   
    fclose(file);
    fclose(out);
}