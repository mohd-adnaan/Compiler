/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 1,
     ELSE = 2,
     FOR = 3,
     INT = 4,
     FLOAT64 = 5,
     STRING = 6,
     VAR = 7,
     CONST = 8,
     OUTPUT = 9,
     ID = 10,
     NUMBER = 11,
     STRINGLITERAL = 12,
     OPEN_BRACKET = 13,
     CLOSE_BRACKET = 14,
     PLUS = 15,
     MINUS = 16,
     MULTIPLY = 17,
     DIVIDE = 18,
     LESS_THAN_EQUAL = 19,
     LESS_THAN = 20,
     GREATER_THAN_EQUAL = 21,
     GREATER_THAN = 22,
     EQUALS = 23,
     NOT_EQUALS = 24,
     ASSIGN = 25,
     ARRAY = 26,
     LPREN = 27,
     RPREN = 28,
     DOT = 29,
     COLCO = 30,
     THEN = 31,
     COMMA = 32,
     RETURN = 33,
     AMPR = 34
   };
#endif
/* Tokens.  */
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 47 "parser.y"
{
    int ival;
    char *sval;
}
/* Line 1529 of yacc.c.  */
#line 126 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

