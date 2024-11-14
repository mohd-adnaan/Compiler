#include <stdio.h>
#include "string.h"
#include "parser.tab.h"

extern int yyparse(void);//from lex.yy.c
extern FILE *yyin;

int main() {
    printf("\nStarting parsing...\n\n");
    yyparse(); // Start parsing
    printf("\n\nPARSING FINISHED SUCCESSFULLY.\n");
    return 0;
}
