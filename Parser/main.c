#include <stdio.h>
#include <string.h>
#include "parser.tab.h"

// Declare external functions
extern int yyparse(void);
extern FILE *yyin;

int main() {
    printf("\nStarting parsing...\n\n");
    yyparse(); // Start parsing
    printf("\n\nPARSING FINISHED SUCCESSFULLY.\n");
    return 0;
}