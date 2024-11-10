
%{
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
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
{ws} {/* No action and no return */}
if      { yylval = IF; return IF; }
else  { yylval = ELSE; return ELSE; }
for    { yylval = FOR; return FOR; }

int     { yylval = INT; return INT; }
float64  { yylval = FLOAT64; return FLOAT64; }
string    { yylval = STRING; return STRING; }

var { yylval = VAR; return VAR; }
const  { yylval = CONST; return CONST; }
output { yylval = OUTPUT; return OUTPUT; }

{id} { yylval = ID; return ID; }
{number} { yylval = NUMBER; return NUMBER; }
{stringliteral} { yylval = STRINGLITERAL; return STRINGLITERAL; }

"<=" { yylval = LESS_THAN_EQUAL; return LESS_THAN_EQUAL; }
"<" { yylval = LESS_THAN; return LESS_THAN; }
">=" { yylval = GREATER_THAN_EQUAL; return GREATER_THAN_EQUAL;}
">" { yylval = GREATER_THAN; return GREATER_THAN; }
"==" { yylval = EQUALS; return EQUALS; }
"!=" { yylval = NOT_EQUALS; return NOT_EQUALS; }
"=" { yylval = ASSIGN; return ASSIGN; }
":=" { yylval = ASSIGN; return ASSIGN; }
"{" { yylval = OPEN_BRACKET; return OPEN_BRACKET; }
"}" { yylval = CLOSE_BRACKET; return CLOSE_BRACKET; }
"+" { yylval = PLUS; return PLUS; }
"-" { yylval = MINUS; return MINUS; }
"*" { yylval = MULTIPLY; return MULTIPLY; }
"/" { yylval = DIVIDE; return DIVIDE; }
"." { yylval = DOT; return DOT; }
"\\[\\]" { yylval = ARRAY; return ARRAY; }
"(" { yylval = LPREN; return LPREN; }
")" { yylval = RPREN; return RPREN; }
";"|"," { yylval = COLCO; return COLCO; }
. { yylval = yytext[0]; return yytext[0]; }
%%
int yywrap() {
return 1;
}









