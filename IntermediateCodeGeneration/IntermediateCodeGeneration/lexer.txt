%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
%}

%option yylineno

/* Token definitions */
%{
#define IF 1
#define ELSE 2
#define FOR 3
#define INT 4
#define FLOAT64 5
#define STRING 6
#define VAR 7
#define CONST 8
#define OUTPUT 9
#define ID 10
#define NUMBER 11
#define STRINGLITERAL 12
#define OPEN_BRACKET 13
#define CLOSE_BRACKET 14
#define PLUS 15
#define MINUS 16
#define MULTIPLY 17
#define DIVIDE 18
#define LESS_THAN_EQUAL 19
#define LESS_THAN 20
#define GREATER_THAN_EQUAL 21
#define GREATER_THAN 22
#define EQUALS 23
#define NOT_EQUALS 24
#define ASSIGN 25
#define ARRAY 26
#define LPREN 27
#define RPREN 28
#define DOT 29
#define COLCO 30
#define THEN 31
#define COMMA 32
#define RETURN 33
#define AMPR 34
%}

/* Regular definitions */
delim [ \t\n]
ws {delim}+
letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
number {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
stringliteral \"([^\\\n]|(\\.))*?\"

/* Data type definitions */
%%
{ws}            { /* No action and no return */ }
return          { yylval.sval = "RETURN"; printf("RETURN token found\n"); return RETURN; }
if              { yylval.sval = "IF"; printf("IF token found\n"); return IF; }
else            { yylval.sval = "ELSE"; printf("ELSE token found\n"); return ELSE; }
for             { yylval.sval = "FOR"; printf("FOR token found\n"); return FOR; }
then            { yylval.sval = "THEN"; printf("THEN token found\n"); return THEN; }
int             { yylval.sval = "INT"; printf("INT token found\n"); return INT; }
float64         { yylval.sval = "FLOAT64"; printf("FLOAT64 token found\n"); return FLOAT64; }
string          { yylval.sval = "STRING"; printf("STRING token found\n"); return STRING; }
var             { yylval.sval = "VAR"; printf("VAR token found\n"); return VAR; }
const           { yylval.sval = "CONST"; printf("CONST token found\n"); return CONST; }
output          { yylval.sval = "OUTPUT"; printf("OUTPUT token found\n"); return OUTPUT; }
{id}            { yylval.sval = "ID"; printf("ID token found: %s\n", yytext); return ID; }
{number}        { yylval.sval = "NUMBER"; printf("NUMBER token found: %s\n", yytext); return NUMBER; }
{stringliteral} { yylval.sval = "STRINGLITERAL"; printf("STRINGLITERAL token found: %s\n", yytext); return STRINGLITERAL; }
"<="            { yylval.sval = "LESS_THAN_EQUAL"; printf("LESS_THAN_EQUAL token found\n"); return LESS_THAN_EQUAL; }
"<"             { yylval.sval = "LESS_THAN"; printf("LESS_THAN token found\n"); return LESS_THAN; }
">="            { yylval.sval = "GREATER_THAN_EQUAL"; printf("GREATER_THAN_EQUAL token found\n"); return GREATER_THAN_EQUAL; }
">"             { yylval.sval = "GREATER_THAN"; printf("GREATER_THAN token found\n"); return GREATER_THAN; }
"=="            { yylval.sval = "EQUALS"; printf("EQUALS token found\n"); return EQUALS; }
"!="            { yylval.sval = "NOT_EQUALS"; printf("NOT_EQUALS token found\n"); return NOT_EQUALS; }
"="             { yylval.sval = "ASSIGN"; printf("ASSIGN token found\n"); return ASSIGN; }
":="            { yylval.sval = "ASSIGN"; printf("ASSIGN token found\n"); return ASSIGN; }
"{"             { yylval.sval = "OPEN_BRACKET"; printf("OPEN_BRACKET token found\n"); return OPEN_BRACKET; }
"}"             { yylval.sval = "CLOSE_BRACKET"; printf("CLOSE_BRACKET token found\n"); return CLOSE_BRACKET; }
"+"             { yylval.sval = "PLUS"; printf("PLUS token found\n"); return PLUS; }
"-"             { yylval.sval = "MINUS"; printf("MINUS token found\n"); return MINUS; }
"*"             { yylval.sval = "MULTIPLY"; printf("MULTIPLY token found\n"); return MULTIPLY; }
"/"             { yylval.sval = "DIVIDE"; printf("DIVIDE token found\n"); return DIVIDE; }
"."             { yylval.sval = "DOT"; printf("DOT token found\n"); return DOT; }
"\\[\\]"        { yylval.sval = "ARRAY"; printf("ARRAY token found\n"); return ARRAY; }
"("             { yylval.sval = "LPREN"; printf("LPREN token found\n"); return LPREN; }
")"             { yylval.sval = "RPREN"; printf("RPREN token found\n"); return RPREN; }
";"             { yylval.sval = "COLCO"; printf("COLCO token found\n"); return COLCO; }
","             { yylval.sval = "COMMA"; printf("COMMA token found\n"); return COMMA; }
"&"             { yylval.sval = "AMPR"; printf("AMPERSAND token found\n"); return AMPR; }
.               { yylval.sval = yytext; printf("Unrecognized token: %s\n", yytext); return yytext[0]; }
%%

int yywrap() {
    return 1;
}
