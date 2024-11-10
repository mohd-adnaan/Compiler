
%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yyerror(const char *s);

%}

%token IF 1
%token ELSE 2
%token FOR 3
%token INT 4
%token FLOAT64 5
%token STRING 6
%token VAR 7
%token CONST 8
%token OUTPUT 9
%token ID 10
%token NUMBER 11
%token STRINGLITERAL 12
%token OPEN_BRACKET 13
%token CLOSE_BRACKET 14
%token PLUS 15
%token MINUS 16
%token MULTIPLY 17
%token DIVIDE 18
%token LESS_THAN_EQUAL 19
%token LESS_THAN 20
%token GREATER_THAN_EQUAL 21
%token GREATER_THAN 22
%token EQUALS 23
%token NOT_EQUALS 24
%token ASSIGN 25
%token ARRAY 26
%token LPREN 27
%token RPREN 28
%token DOT 29
%token COLCO 30
%token THEN 31
%token COMMA 32
%token RETURN 33
%token AMPR 34

%union {
    int ival;
    char *sval;
}

%%

program : package_declaration import_declaration statements
;

package_declaration : ID ID
;

import_declaration : ID STRINGLITERAL
;

statements : /* empty */
           | statement statements
;

statement : expression_statement
          | const_declaration
          | var_declaration
          | function_declaration
          | if_statement
          | for_statement
          | return_statement
          | dot_statement
          | assgn_statement
;

expression_statement : expression
;

const_declaration : CONST identifier ASSIGN expression
;

var_declaration : VAR identifier type
;

function_declaration : ID ID LPREN parameters RPREN type block
;

parameters : /* empty */
           | parameter_list
;

parameter_list : parameter
               | parameter_list COMMA parameter
;

arguments  : /* empty */
           | STRINGLITERAL
           | STRINGLITERAL COMMA ID
           | STRINGLITERAL COMMA ID COMMA ID
           | AMPR ID
;

parameter : ID type
;

params     : /* empty */
           | param_list
;

param_list : param
           | param_list COMMA param
;

param : ID
;

if_statement : IF expression block
             | IF expression block ELSE block
;

for_statement : FOR for_exp block
;

for_exp  : ID ASSIGN NUMBER COLCO ID relop NUMBER COLCO ID updt
         | ID ASSIGN NUMBER COLCO ID relop NUMBER COLCO updt ID
;

relop : LESS_THAN_EQUAL
      | LESS_THAN
      | GREATER_THAN_EQUAL
      | GREATER_THAN
      | EQUALS
      | NOT_EQUALS
;

updt  : PLUS PLUS
      | MINUS MINUS
;

block : OPEN_BRACKET statements CLOSE_BRACKET
;

return_statement : RETURN expression
;

dot_statement : ID DOT ID LPREN arguments RPREN
;

assgn_statement : ID ASSIGN ID LPREN params RPREN
;

expression : expression PLUS expression
           | expression MINUS expression
           | expression MULTIPLY expression
           | expression DIVIDE expression
           | expression LESS_THAN_EQUAL expression
           | expression LESS_THAN expression
           | expression GREATER_THAN_EQUAL expression
           | expression GREATER_THAN expression
           | expression EQUALS expression
           | expression NOT_EQUALS expression
           | identifier
           | NUMBER
;

identifier : ID
;

type : /* empty */
     | INT
     | FLOAT64
;

%%

int yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
    return 0;
}
