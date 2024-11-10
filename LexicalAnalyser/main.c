
#include <stdio.h>
#include "lex.yy.c"
#include "string.h"
#include "main.h"
int yylval;
int yylex();
const char* get_token_name(int token) {

switch (token) {
    case 1: return "IF";
    case 2: return "ELSE";
    case 3: return "FOR";
    case 4: return "INT";
    case 5: return "FLOAT64";
    case 6: return "STRING";
    case 7: return "VAR";
    case 8: return "CONST";
    case 9: return "OUTPUT";
    case 10: return "ID";
    case 11: return "NUMBER";
    case 12: return "STRINGLITERAL";
    case 13: return "OPEN_BRACKET";
    case 14: return "CLOSE_BRACKET";
    case 15: return "PLUS";
    case 16: return "MINUS";
    case 17: return "MULTIPLY";
    case 18: return "DIVIDE";
    case 19: return "LESS_THAN_EQUAL";
    case 20: return "LESS_THAN";
    case 21: return "GREATER_THAN_EQUAL";
    case 22: return "GREATER_THAN";
    case 23: return "EQUAL";
    case 24: return "NOT_EQUAL";
    case 25: return "ASSGN";
    case 26: return "ARRAY";
    case 27: return "LPREN";
    case 28: return "RPREN";
    case 29: return "DOT";
    case 30: return "COLCO";
    // ... add other token names here
    default: return "UNKNOWN";
    }
}

int main(){
int token;
while((token=yylex()) !=0){
const char* token_name = get_token_name(token);
printf("TOKEN: %s, TOKEN_NUM: %d\n", token_name, token);
}
return 0;
}

