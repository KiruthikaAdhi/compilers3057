/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    RELOP = 258,
    ID = 259,
    NUM = 260,
    TRUE = 261,
    FALSE = 262,
    NEG = 263,
    LAND = 264,
    LOR = 265,
    IF = 266,
    ELSE = 267,
    PLUS = 268,
    MINUS = 269,
    LB = 270,
    RB = 271,
    ASSIGN = 272,
    SC = 273,
    MUL = 274,
    MOD = 275,
    DIV = 276,
    INT = 277,
    FLOAT = 278
  };
#endif
/* Tokens.  */
#define RELOP 258
#define ID 259
#define NUM 260
#define TRUE 261
#define FALSE 262
#define NEG 263
#define LAND 264
#define LOR 265
#define IF 266
#define ELSE 267
#define PLUS 268
#define MINUS 269
#define LB 270
#define RB 271
#define ASSIGN 272
#define SC 273
#define MUL 274
#define MOD 275
#define DIV 276
#define INT 277
#define FLOAT 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "foc.y" /* yacc.c:1909  */

	char* str;
	struct{
		LIST* truelist;
		LIST* falselist;
	} list;
	int instr;
	struct{
		char* addr;
		char* base;
		NODE* w;
		} array;
	char* addr;
	int width;

#line 116 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
