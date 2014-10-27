/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_DECAF_TAB_H_INCLUDED
# define YY_YY_DECAF_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BREAK = 258,
    CLASS = 259,
    CONTINUE = 260,
    ELSE = 261,
    EXTENDS = 262,
    IF = 263,
    NEW = 264,
    PRIVATE = 265,
    PROTECTED = 266,
    PUBLIC = 267,
    RETURN = 268,
    STATIC = 269,
    SUPER = 270,
    THIS = 271,
    WHILE = 272,
    BOOLEAN = 273,
    CHAR = 274,
    INT = 275,
    VOID = 276,
    DECAF_NULL = 277,
    LPAREN = 278,
    RPAREN = 279,
    LBRACE = 280,
    RBRACE = 281,
    LBRACKET = 282,
    RBRACKET = 283,
    SEMICOLON = 284,
    COMMA = 285,
    PERIOD = 286,
    ASSIGN = 287,
    GREATER = 288,
    LESS = 289,
    NOT = 290,
    EQ = 291,
    GEQ = 292,
    LEQ = 293,
    NEQ = 294,
    PLUS = 295,
    MINUS = 296,
    MUL = 297,
    DIV = 298,
    AND = 299,
    OR = 300,
    MOD = 301,
    IDENTIFIER = 302,
    CHARACTER = 303,
    STRING = 304,
    BOOLEAN_LITERAL = 305,
    INTEGER = 306,
    UMINUS = 307,
    UPLUS = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 41 "decaf.y" /* yacc.c:1909  */
 
 int iVal; /* integer value */ 
 char * sVal; /* string value*/ 
 
 //nodeType *nPtr; /* node pointer */ 

#line 115 "decaf.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_DECAF_TAB_H_INCLUDED  */
