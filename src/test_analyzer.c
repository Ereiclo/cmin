#include "y.tab.c"
#include "lex.yy.c"

void parse(FILE *file);
void main(){
    FILE *file = fopen("input", "r");
    parse(file);   
}