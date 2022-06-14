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
     _PROGRAM = 258,
     _ENDVARS = 259,
     _ENDPROCS = 260,
     _VARIABLES = 261,
     _NOVARIABLES = 262,
     _INTEGER = 263,
     _REAL = 264,
     _ECONST = 265,
     _STRING = 266,
     _PROCEDURES = 267,
     _NOPROCEDURES = 268,
     _PROCEDURE = 269,
     _BEGIN = 270,
     _END = 271,
     _FOR = 272,
     _TO = 273,
     _DO = 274,
     _IF = 275,
     _THEN = 276,
     _ELSE = 277,
     _READ = 278,
     _WRITE = 279,
     _ID = 280,
     _ICONST = 281,
     _RCONST = 282,
     _LITERAL = 283,
     _LBRACK = 284,
     _RBRACK = 285,
     _LPAREN = 286,
     _RPAREN = 287,
     _SEMI = 288,
     _COLON = 289,
     _COMMA = 290,
     _ASSIGN = 291,
     _PLUS = 292,
     _MINUS = 293,
     _MULT = 294,
     _DIVIDE = 295,
     _EQL = 296,
     _LESS = 297,
     _GTR = 298,
     _LEQ = 299,
     _GEQ = 300,
     _NEQ = 301
   };
#endif
/* Tokens.  */
#define _PROGRAM 258
#define _ENDVARS 259
#define _ENDPROCS 260
#define _VARIABLES 261
#define _NOVARIABLES 262
#define _INTEGER 263
#define _REAL 264
#define _ECONST 265
#define _STRING 266
#define _PROCEDURES 267
#define _NOPROCEDURES 268
#define _PROCEDURE 269
#define _BEGIN 270
#define _END 271
#define _FOR 272
#define _TO 273
#define _DO 274
#define _IF 275
#define _THEN 276
#define _ELSE 277
#define _READ 278
#define _WRITE 279
#define _ID 280
#define _ICONST 281
#define _RCONST 282
#define _LITERAL 283
#define _LBRACK 284
#define _RBRACK 285
#define _LPAREN 286
#define _RPAREN 287
#define _SEMI 288
#define _COLON 289
#define _COMMA 290
#define _ASSIGN 291
#define _PLUS 292
#define _MINUS 293
#define _MULT 294
#define _DIVIDE 295
#define _EQL 296
#define _LESS 297
#define _GTR 298
#define _LEQ 299
#define _GEQ 300
#define _NEQ 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "parser.y"
{
  int    integer;
  char*  string;
}
/* Line 1529 of yacc.c.  */
#line 146 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

