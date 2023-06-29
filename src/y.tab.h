/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    RETURN = 258,                  /* RETURN  */
    FUNCTION = 259,                /* FUNCTION  */
    PAR_ABIERTO = 260,             /* PAR_ABIERTO  */
    PAR_CERRADO = 261,             /* PAR_CERRADO  */
    LLAVE_ABIERTA = 262,           /* LLAVE_ABIERTA  */
    LLAVE_CERRADA = 263,           /* LLAVE_CERRADA  */
    SUMA = 264,                    /* SUMA  */
    COMA = 265,                    /* COMA  */
    IGUAL = 266,                   /* IGUAL  */
    MULT = 267,                    /* MULT  */
    RESTA = 268,                   /* RESTA  */
    AND = 269,                     /* AND  */
    OR = 270,                      /* OR  */
    CEIL = 271,                    /* CEIL  */
    FLOOR = 272,                   /* FLOOR  */
    LET = 273,                     /* LET  */
    WHILE = 274,                   /* WHILE  */
    IF = 275,                      /* IF  */
    ELSE = 276,                    /* ELSE  */
    COMP = 277,                    /* COMP  */
    FIN = 278,                     /* FIN  */
    ID = 279,                      /* ID  */
    LISTA_ARGS = 280,              /* LISTA_ARGS  */
    CADENA = 281,                  /* CADENA  */
    NUMERO = 282,                  /* NUMERO  */
    DIV = 283                      /* DIV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define RETURN 258
#define FUNCTION 259
#define PAR_ABIERTO 260
#define PAR_CERRADO 261
#define LLAVE_ABIERTA 262
#define LLAVE_CERRADA 263
#define SUMA 264
#define COMA 265
#define IGUAL 266
#define MULT 267
#define RESTA 268
#define AND 269
#define OR 270
#define CEIL 271
#define FLOOR 272
#define LET 273
#define WHILE 274
#define IF 275
#define ELSE 276
#define COMP 277
#define FIN 278
#define ID 279
#define LISTA_ARGS 280
#define CADENA 281
#define NUMERO 282
#define DIV 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "lexical_analyzer.y"

    tipot estru;
    int num;
    node nodo;
    char* value;


#line 131 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
