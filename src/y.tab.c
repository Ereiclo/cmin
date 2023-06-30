/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lexical_analyzer.y"

   #include <stdio.h>
   #include <stdlib.h>
   #include <math.h>
   #include <string.h>
   int yylex(void);
   void yyerror(const char *s);
   int push_symbol(char*symbol);
   //FILE *yyin;
   FILE *out;
   char** symbol_table;
   int n_symbols = 0;
   char** function_table[2];
   int n_functions = 0;
   int actual_label = 0;

   int check_symbol_existence(char* symbol);
   char* concat_strings(char* dest, char* src){

      char* new_string = (char*) malloc(strlen(dest) + strlen(src) + 1);

      strcpy(new_string,dest);
      strcat(new_string,src);

   }



#line 31 "lexical_analyzer.y"


   typedef struct{
      char** values;
      int tamanio;
   } ls;

   typedef struct{
      char* code; 
      char* value;
      char* name;
   } node;

#line 114 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    CADENA = 280,                  /* CADENA  */
    NUMERO = 281,                  /* NUMERO  */
    DIV = 282,                     /* DIV  */
    PRINT = 283                    /* PRINT  */
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
#define CADENA 280
#define NUMERO 281
#define DIV 282
#define PRINT 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "lexical_analyzer.y"

    int num;
    ls lista;
    node nodo;
    char* value;


#line 231 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RETURN = 3,                     /* RETURN  */
  YYSYMBOL_FUNCTION = 4,                   /* FUNCTION  */
  YYSYMBOL_PAR_ABIERTO = 5,                /* PAR_ABIERTO  */
  YYSYMBOL_PAR_CERRADO = 6,                /* PAR_CERRADO  */
  YYSYMBOL_LLAVE_ABIERTA = 7,              /* LLAVE_ABIERTA  */
  YYSYMBOL_LLAVE_CERRADA = 8,              /* LLAVE_CERRADA  */
  YYSYMBOL_SUMA = 9,                       /* SUMA  */
  YYSYMBOL_COMA = 10,                      /* COMA  */
  YYSYMBOL_IGUAL = 11,                     /* IGUAL  */
  YYSYMBOL_MULT = 12,                      /* MULT  */
  YYSYMBOL_RESTA = 13,                     /* RESTA  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_CEIL = 16,                      /* CEIL  */
  YYSYMBOL_FLOOR = 17,                     /* FLOOR  */
  YYSYMBOL_LET = 18,                       /* LET  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_COMP = 22,                      /* COMP  */
  YYSYMBOL_FIN = 23,                       /* FIN  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_CADENA = 25,                    /* CADENA  */
  YYSYMBOL_NUMERO = 26,                    /* NUMERO  */
  YYSYMBOL_DIV = 27,                       /* DIV  */
  YYSYMBOL_PRINT = 28,                     /* PRINT  */
  YYSYMBOL_29_then_ = 29,                  /* "then"  */
  YYSYMBOL_30_ = 30,                       /* ';'  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '['  */
  YYSYMBOL_33_ = 33,                       /* ']'  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '!'  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_S = 46,                         /* S  */
  YYSYMBOL_CODE = 47,                      /* CODE  */
  YYSYMBOL_I = 48,                         /* I  */
  YYSYMBOL_IN = 49,                        /* IN  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_52_3 = 52,                      /* @3  */
  YYSYMBOL_LISTA_ARGS_PRINT = 53,          /* LISTA_ARGS_PRINT  */
  YYSYMBOL_SUB_CODE = 54,                  /* SUB_CODE  */
  YYSYMBOL_WHILE_BLOCK = 55,               /* WHILE_BLOCK  */
  YYSYMBOL_IF_BLOCK = 56,                  /* IF_BLOCK  */
  YYSYMBOL_IF_ELSE_BLOCK = 57,             /* IF_ELSE_BLOCK  */
  YYSYMBOL_P = 58,                         /* P  */
  YYSYMBOL_DECL = 59,                      /* DECL  */
  YYSYMBOL_exp = 60,                       /* exp  */
  YYSYMBOL_level1 = 61,                    /* level1  */
  YYSYMBOL_level2 = 62,                    /* level2  */
  YYSYMBOL_level3 = 63,                    /* level3  */
  YYSYMBOL_VALUE = 64,                     /* VALUE  */
  YYSYMBOL_65_4 = 65,                      /* $@4  */
  YYSYMBOL_NUM_LIKE = 66,                  /* NUM_LIKE  */
  YYSYMBOL_LOGIC = 67,                     /* LOGIC  */
  YYSYMBOL_OP1 = 68,                       /* OP1  */
  YYSYMBOL_OP2 = 69                        /* OP2  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  96

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,    44,     2,     2,
      34,    35,    42,    41,    36,    39,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    79,    87,    94,    99,   109,   108,   134,
     141,   133,   163,   168,   174,   179,   190,   202,   211,   222,
     222,   222,   226,   257,   285,   322,   322,   322,   326,   346,
     375,   391,   422,   436,   445,   466,   474,   488,   496,   516,
     530,   543,   555,   568,   567,   586,   591,   601,   610,   621,
     632,   651,   651,   652,   652,   653,   653,   653
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "RETURN", "FUNCTION",
  "PAR_ABIERTO", "PAR_CERRADO", "LLAVE_ABIERTA", "LLAVE_CERRADA", "SUMA",
  "COMA", "IGUAL", "MULT", "RESTA", "AND", "OR", "CEIL", "FLOOR", "LET",
  "WHILE", "IF", "ELSE", "COMP", "FIN", "ID", "CADENA", "NUMERO", "DIV",
  "PRINT", "then", "';'", "'='", "'['", "']'", "'('", "')'", "','", "'{'",
  "'}'", "'-'", "'!'", "'+'", "'*'", "'/'", "'%'", "$accept", "S", "CODE",
  "I", "IN", "$@1", "$@2", "@3", "LISTA_ARGS_PRINT", "SUB_CODE",
  "WHILE_BLOCK", "IF_BLOCK", "IF_ELSE_BLOCK", "P", "DECL", "exp", "level1",
  "level2", "level3", "VALUE", "$@4", "NUM_LIKE", "LOGIC", "OP1", "OP2", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      48,   -21,   -14,    28,    45,    49,    82,    61,   -61,    54,
     -61,   -61,   -61,   -61,    50,    56,    31,    31,    59,    60,
      24,   -61,   -61,   -61,    69,    68,    63,   -61,    31,    -2,
       1,    -9,    74,    12,   -26,   -61,    -6,    31,     6,   -61,
      10,    27,    65,    66,    70,    -4,   -61,   -61,   -61,   -61,
     -61,   -61,    19,    31,    31,   -61,   -61,    31,   -61,   -61,
     -61,    31,    19,    27,   -61,   -61,   -61,   -61,    35,    72,
     -61,     6,   -61,    -5,   -61,   -61,    74,    12,   -26,   -61,
      79,    71,   -61,    27,    73,    75,   -61,    16,    19,    76,
     -61,   -61,   -61,   -61,    31,    27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      14,     0,     0,     0,     7,     0,     0,     2,     4,     0,
       6,    21,    19,    20,    12,    30,     0,     0,     0,     0,
       0,     1,     3,     5,     0,     0,    40,    48,     0,     0,
       0,     0,    33,    35,    37,    39,     0,     0,     0,    17,
       0,    18,    28,     0,     0,     0,    41,    46,    42,    47,
      51,    52,    14,     0,     0,    54,    53,     0,    55,    56,
      57,     0,    14,     8,    49,    50,    10,    13,     0,     0,
      31,     0,    45,    14,    25,    22,    32,    34,    36,    38,
      23,     0,    16,    15,     0,     0,    27,    14,    14,     0,
      29,    44,    26,    24,     0,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,    30,     0,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -60,   -61,   -16,    52,    47,    53,    51,
     -61,    38,   -61,   -61,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,    74,     9,    18,    19,    81,    40,    10,
      11,    12,    13,    75,    14,    31,    32,    33,    34,    35,
      44,    66,    53,    57,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       8,    36,    80,    15,    41,    50,    51,    22,    50,    51,
      50,    51,    45,     1,     2,     3,    58,    59,    60,     4,
      16,    63,    46,     5,    47,    48,    52,    49,    93,    62,
      64,    72,    65,    86,     1,     2,     3,     1,     2,     3,
       4,    50,    51,     4,     5,    67,    68,     5,    26,    39,
      27,    55,    83,    56,    92,    26,    73,    27,    28,    26,
      82,    27,    17,    29,    30,    28,     1,     2,     3,    28,
      29,    30,     4,     8,    29,    30,     5,    -9,    95,     1,
       2,     3,    21,    20,    23,     4,    24,    22,    25,     5,
      37,   -14,    38,    42,    43,   -43,    54,    69,    84,    70,
      88,    77,    71,    87,    89,    76,    90,    94,    91,    85,
      78,     0,    79
};

static const yytype_int8 yycheck[] =
{
       0,    17,    62,    24,    20,    14,    15,     7,    14,    15,
      14,    15,    28,    18,    19,    20,    42,    43,    44,    24,
      34,    37,    24,    28,    26,    24,    35,    26,    88,    35,
      24,    35,    26,    38,    18,    19,    20,    18,    19,    20,
      24,    14,    15,    24,    28,    35,    36,    28,    24,    25,
      26,    39,    68,    41,    38,    24,    37,    26,    34,    24,
      25,    26,    34,    39,    40,    34,    18,    19,    20,    34,
      39,    40,    24,    73,    39,    40,    28,    32,    94,    18,
      19,    20,     0,    34,    30,    24,    36,    87,    32,    28,
      31,    30,    32,    24,    26,    32,    22,    32,    26,    33,
      21,    54,    32,    73,    33,    53,    33,    31,    33,    71,
      57,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    19,    20,    24,    28,    46,    47,    48,    49,
      54,    55,    56,    57,    59,    24,    34,    34,    50,    51,
      34,     0,    48,    30,    36,    32,    24,    26,    34,    39,
      40,    60,    61,    62,    63,    64,    60,    31,    32,    25,
      53,    60,    24,    26,    65,    60,    24,    26,    24,    26,
      14,    15,    35,    67,    22,    39,    41,    68,    42,    43,
      44,    69,    35,    60,    24,    26,    66,    35,    36,    32,
      33,    32,    35,    37,    48,    58,    61,    62,    63,    64,
      58,    52,    25,    60,    26,    66,    38,    47,    21,    33,
      33,    33,    38,    58,    31,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    50,    49,    51,
      52,    49,    49,    49,    49,    53,    53,    53,    53,    54,
      54,    54,    55,    56,    57,    58,    58,    58,    59,    59,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    65,    64,    64,    64,    64,    64,    66,
      66,    67,    67,    68,    68,    69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     0,     4,     0,
       0,     8,     1,     4,     0,     3,     3,     1,     1,     1,
       1,     1,     5,     5,     7,     1,     3,     2,     3,     6,
       2,     5,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     2,     2,     0,     5,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* S: CODE  */
#line 72 "lexical_analyzer.y"
{
   //printf("El codigo generado es:\n%s",$1.code);
   fwrite((yyvsp[0].nodo).code,1,strlen((yyvsp[0].nodo).code),out);
}
#line 1564 "y.tab.c"
    break;

  case 3: /* CODE: CODE I  */
#line 80 "lexical_analyzer.y"
{ 
   (yyval.nodo).code = concat_strings((yyvsp[-1].nodo).code,(yyvsp[0].nodo).code);

   free((yyvsp[-1].nodo).code);

}
#line 1575 "y.tab.c"
    break;

  case 4: /* CODE: I  */
#line 88 "lexical_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[0].nodo).code;
}
#line 1583 "y.tab.c"
    break;

  case 5: /* I: IN ';'  */
#line 95 "lexical_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[-1].nodo).code;
}
#line 1591 "y.tab.c"
    break;

  case 6: /* I: SUB_CODE  */
#line 100 "lexical_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[0].nodo).code;
}
#line 1599 "y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 109 "lexical_analyzer.y"
{
      if(!check_symbol_existence((yyvsp[0].value))) {
         yyerror("Variable does not exists");
         YYERROR;
      }
}
#line 1610 "y.tab.c"
    break;

  case 8: /* IN: ID $@1 '=' exp  */
#line 116 "lexical_analyzer.y"
{
   char* temp1 = (char*) malloc(100);
   sprintf(temp1,"lda %s\n",(yyvsp[-3].value));
                                    //es $4 porque cuando se pone acciones
                                    //en el medio (lo que esta a la derecha de ID)
                                    //eso cuenta como si fuera un symbolo mas
   char* temp2 = concat_strings(temp1,(yyvsp[0].nodo).code);

   (yyval.nodo).code = concat_strings(temp2,"sto \n");

   free(temp1);
   free(temp2);
   free((yyvsp[-3].value));
   free((yyvsp[-1].value));
   free((yyvsp[0].nodo).code);
}
#line 1631 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 134 "lexical_analyzer.y"
{
   if(!check_symbol_existence((yyvsp[0].value))) {
      yyerror("Variable does not exists");
      YYERROR;
   }
}
#line 1642 "y.tab.c"
    break;

  case 10: /* @3: %empty  */
#line 141 "lexical_analyzer.y"
{

   (yyval.nodo).code = (char*) malloc(200);
   char template_string[] = "lod %s\n%sad \n";
   sprintf((yyval.nodo).code,template_string,(yyvsp[-3].value),(yyvsp[0].nodo).code);

   free((yyvsp[-3].value));
   free((yyvsp[0].nodo).code);


}
#line 1658 "y.tab.c"
    break;

  case 11: /* IN: ID $@2 '[' NUM_LIKE @3 ']' '=' exp  */
#line 153 "lexical_analyzer.y"
{
   char* temp = concat_strings((yyvsp[-3].nodo).code,(yyvsp[0].nodo).code);

   (yyval.nodo).code = concat_strings(temp,"sto \n");

   free(temp);
   free((yyvsp[-3].nodo).code);
   free((yyvsp[0].nodo).code);
}
#line 1672 "y.tab.c"
    break;

  case 12: /* IN: DECL  */
#line 164 "lexical_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[0].nodo).code;
}
#line 1680 "y.tab.c"
    break;

  case 13: /* IN: PRINT '(' LISTA_ARGS_PRINT ')'  */
#line 169 "lexical_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[-1].nodo).code;

}
#line 1689 "y.tab.c"
    break;

  case 14: /* IN: %empty  */
#line 174 "lexical_analyzer.y"
       {
   (yyval.nodo).code = strdup("");
}
#line 1697 "y.tab.c"
    break;

  case 15: /* LISTA_ARGS_PRINT: LISTA_ARGS_PRINT ',' exp  */
#line 180 "lexical_analyzer.y"
{
   char* temp = concat_strings((yyvsp[0].nodo).code,"print_c \n");

   (yyval.nodo).code = concat_strings((yyvsp[-2].nodo).code,temp);

   free((yyvsp[-2].nodo).code);
   free((yyvsp[0].nodo).code);

}
#line 1711 "y.tab.c"
    break;

  case 16: /* LISTA_ARGS_PRINT: LISTA_ARGS_PRINT ',' CADENA  */
#line 191 "lexical_analyzer.y"
{
   char* temp = malloc(200);

   sprintf(temp,"print_s %s\n",(yyvsp[0].value));
   (yyval.nodo).code = concat_strings((yyvsp[-2].nodo).code,temp);

   free(temp);
   free((yyvsp[0].value));

}
#line 1726 "y.tab.c"
    break;

  case 17: /* LISTA_ARGS_PRINT: CADENA  */
#line 203 "lexical_analyzer.y"
{
   (yyval.nodo).code = malloc(200);
   sprintf((yyval.nodo).code,"print_s %s\n",(yyvsp[0].value));

   free((yyvsp[0].value));

}
#line 1738 "y.tab.c"
    break;

  case 18: /* LISTA_ARGS_PRINT: exp  */
#line 212 "lexical_analyzer.y"
{

   (yyval.nodo).code = concat_strings((yyvsp[0].nodo).code,"print_c \n");

   free((yyvsp[0].nodo).code);

}
#line 1750 "y.tab.c"
    break;

  case 19: /* SUB_CODE: IF_BLOCK  */
#line 222 "lexical_analyzer.y"
                   {(yyval.nodo).code = (yyvsp[0].nodo).code;}
#line 1756 "y.tab.c"
    break;

  case 20: /* SUB_CODE: IF_ELSE_BLOCK  */
#line 222 "lexical_analyzer.y"
                                                        {(yyval.nodo).code = (yyvsp[0].nodo).code;}
#line 1762 "y.tab.c"
    break;

  case 21: /* SUB_CODE: WHILE_BLOCK  */
#line 222 "lexical_analyzer.y"
                                                                                           {(yyval.nodo).code = (yyvsp[0].nodo).code;}
#line 1768 "y.tab.c"
    break;

  case 22: /* WHILE_BLOCK: WHILE '(' exp ')' P  */
#line 227 "lexical_analyzer.y"
{
   int start_label = actual_label++;
   int end_label = actual_label++;

   char* temp1 = malloc(100);
   sprintf(temp1,"lab L%d\n",start_label);
   char* temp2 = malloc(100);
   sprintf(temp2,"ne \ntjp L%d\n",end_label);
   char* temp3 = malloc(100);
   sprintf(temp3,"ujp L%d\nlab L%d\n",start_label,end_label);

   char*temp4 = concat_strings(temp1,(yyvsp[-2].nodo).code);
   char*temp5 = concat_strings(temp4,temp2);
   char* temp6 = concat_strings((yyvsp[0].nodo).code,temp3);

   (yyval.nodo).code = concat_strings(temp5,temp6);

   free((yyvsp[-2].nodo).code);
   free((yyvsp[0].nodo).code);
   free(temp1);
   free(temp2);
   free(temp3);
   free(temp4);
   free(temp5);
   free(temp6);

}
#line 1800 "y.tab.c"
    break;

  case 23: /* IF_BLOCK: IF '(' exp ')' P  */
#line 258 "lexical_analyzer.y"
{

   int label = actual_label++;

   char* temp1 = malloc(100);
   sprintf(temp1,"ne \ntjp L%d\n",label);

   char* temp2 = malloc(100);
   sprintf(temp2,"lab L%d\n",label);

   char* temp3 = concat_strings((yyvsp[-2].nodo).code,temp1);
   char* temp4 = concat_strings((yyvsp[0].nodo).code,temp2);




   (yyval.nodo).code = concat_strings(temp3,temp4);

   free((yyvsp[-2].nodo).code);
   free((yyvsp[0].nodo).code);
   free(temp1);
   free(temp2);
   free(temp3);
   free(temp4);
}
#line 1830 "y.tab.c"
    break;

  case 24: /* IF_ELSE_BLOCK: IF '(' exp ')' P ELSE P  */
#line 286 "lexical_analyzer.y"
{
   int label_else = actual_label++;
   int label_end = actual_label++;

   char* temp1 = malloc(100);
   sprintf(temp1,"ne \ntjp L%d\n",label_else);

   char* temp2 = malloc(100);
   sprintf(temp2,"ujp L%d\nlab L%d\n",label_end,label_else);

   char* temp3 = malloc(100);
   sprintf(temp3,"lab L%d\n",label_end);

   char* temp4 = concat_strings((yyvsp[-4].nodo).code,temp1);

   char* temp5 = concat_strings((yyvsp[-2].nodo).code,temp2);

   char* temp6 = concat_strings((yyvsp[0].nodo).code,temp3);


   char* temp7 = concat_strings(temp4,temp5);

   (yyval.nodo).code = concat_strings(temp7,temp6);

   free((yyvsp[-4].nodo).code);
   free((yyvsp[-2].nodo).code);
   free((yyvsp[0].nodo).code);
   free(temp1);
   free(temp2);
   free(temp3);
   free(temp4);
   free(temp5);
   free(temp6);

}
#line 1870 "y.tab.c"
    break;

  case 25: /* P: I  */
#line 322 "lexical_analyzer.y"
     {(yyval.nodo).code = (yyvsp[0].nodo).code;}
#line 1876 "y.tab.c"
    break;

  case 26: /* P: '{' CODE '}'  */
#line 322 "lexical_analyzer.y"
                                         {(yyval.nodo).code = (yyvsp[-1].nodo).code;}
#line 1882 "y.tab.c"
    break;

  case 27: /* P: '{' '}'  */
#line 322 "lexical_analyzer.y"
                                                                         {(yyval.nodo).code =strdup("");}
#line 1888 "y.tab.c"
    break;

  case 28: /* DECL: DECL ',' ID  */
#line 327 "lexical_analyzer.y"
{
   if(check_symbol_existence((yyvsp[0].value))){
      yyerror("Variable already exists");
      YYABORT; 
   }


   char* temp = (char*) malloc(100);

   sprintf(temp,"new_var %s\n",(yyvsp[0].value));
   (yyval.nodo).code = concat_strings((yyvsp[-2].nodo).code,temp);
   push_symbol((yyvsp[0].value));

   free((yyvsp[0].value));
   free((yyvsp[-2].nodo).code);
   free(temp);

}
#line 1911 "y.tab.c"
    break;

  case 29: /* DECL: DECL ',' ID '[' NUMERO ']'  */
#line 347 "lexical_analyzer.y"
{
   if(check_symbol_existence((yyvsp[-3].value))){
      yyerror("Variable already exists");
      YYABORT; 
   }

   double num_d = atof((yyvsp[-1].value));
   int num_i = atoi((yyvsp[-1].value));
   if((int) ceil(num_d) != num_i){
      yyerror("Array size must be an integer");
      YYABORT;
   }else if(num_i < 1){
      yyerror("Array size must be at least 1");
      YYABORT;
   }

   char* temp = (char*) malloc(200);
   char template_string[] = "new_var %s\nlda %s\nnew_arr %d\nsto \n";
   sprintf(temp,template_string,(yyvsp[-3].value),(yyvsp[-3].value),num_i);

   (yyval.nodo).code = concat_strings((yyvsp[-5].nodo).code,temp);
   push_symbol((yyvsp[-3].value));

   free(temp);
   free((yyvsp[-3].value));
   free((yyvsp[-1].value));
}
#line 1943 "y.tab.c"
    break;

  case 30: /* DECL: LET ID  */
#line 376 "lexical_analyzer.y"
{
   if(check_symbol_existence((yyvsp[0].value))){
      yyerror("Variable already exists");
      YYABORT; 
   }

   
   (yyval.nodo).code = (char*) malloc(100);
   sprintf((yyval.nodo).code,"new_var %s\n",(yyvsp[0].value));
   push_symbol((yyvsp[0].value));

   free((yyvsp[0].value));
   
}
#line 1962 "y.tab.c"
    break;

  case 31: /* DECL: LET ID '[' NUMERO ']'  */
#line 392 "lexical_analyzer.y"
{
   if(check_symbol_existence((yyvsp[-3].value))){
      yyerror("Variable already exists");
      YYABORT; 
   }

   double num_d = atof((yyvsp[-1].value));
   int num_i = atoi((yyvsp[-1].value));
   if((int) ceil(num_d) != num_i){
      yyerror("Array size must be an integer");
      YYABORT;
   }else if(num_i < 1){
      yyerror("Array size must be at least 1");
      YYABORT;
   }



   (yyval.nodo).code = (char*) malloc(200);
   char template_string[] = "new_var %s\nlda %s\nnew_arr %d\nsto \n";
   sprintf((yyval.nodo).code,template_string,(yyvsp[-3].value),(yyvsp[-3].value),num_i);
   push_symbol((yyvsp[-3].value));

   free((yyvsp[-3].value));
   free((yyvsp[-1].value));
}
#line 1993 "y.tab.c"
    break;

  case 32: /* exp: exp LOGIC level1  */
#line 423 "lexical_analyzer.y"
{
   char* temp = concat_strings((yyvsp[-2].nodo).code,(yyvsp[0].nodo).code);
   if(strcmp((yyvsp[-1].value),"and") == 0)
      (yyval.nodo).code = concat_strings(temp,"land \n");
   else if(strcmp((yyvsp[-1].value),"or") == 0)
      (yyval.nodo).code = concat_strings(temp,"lor \n");

   free(temp);
   free((yyvsp[-2].nodo).code);
   free((yyvsp[-1].value));
   free((yyvsp[0].nodo).code);
}
#line 2010 "y.tab.c"
    break;

  case 33: /* exp: level1  */
#line 437 "lexical_analyzer.y"
{

   (yyval.nodo).code = (yyvsp[0].nodo).code;

}
#line 2020 "y.tab.c"
    break;

  case 34: /* level1: level1 COMP level2  */
#line 446 "lexical_analyzer.y"
{
   char* temp = concat_strings((yyvsp[-2].nodo).code,(yyvsp[0].nodo).code);
   if(strcmp((yyvsp[-1].value),">=") == 0)
      (yyval.nodo).code = concat_strings(temp,"geq \n");
   else if(strcmp((yyvsp[-1].value),"<=") == 0)
      (yyval.nodo).code = concat_strings(temp,"leq \n");
   else if(strcmp((yyvsp[-1].value),"<") == 0)
      (yyval.nodo).code = concat_strings(temp,"le \n");
   else if(strcmp((yyvsp[-1].value),">") == 0)
      (yyval.nodo).code = concat_strings(temp,"ge \n");
   else if(strcmp((yyvsp[-1].value),"==") == 0)
      (yyval.nodo).code = concat_strings(temp,"equi \n");

   free(temp);
   free((yyvsp[-2].nodo).code);
   free((yyvsp[-1].value));
   free((yyvsp[0].nodo).code);

}
#line 2044 "y.tab.c"
    break;

  case 35: /* level1: level2  */
#line 466 "lexical_analyzer.y"
       {

   (yyval.nodo).code = (yyvsp[0].nodo).code;

}
#line 2054 "y.tab.c"
    break;

  case 36: /* level2: level2 OP1 level3  */
#line 475 "lexical_analyzer.y"
{
   char* temp = concat_strings((yyvsp[-2].nodo).code,(yyvsp[0].nodo).code);
   if(strcmp((yyvsp[-1].value),"+") == 0)
      (yyval.nodo).code = concat_strings(temp,"ad \n");
   else if(strcmp((yyvsp[-1].value),"-") == 0)
      (yyval.nodo).code = concat_strings(temp,"sb \n");

   free(temp);
   free((yyvsp[-2].nodo).code);
   free((yyvsp[-1].value));
   free((yyvsp[0].nodo).code);
}
#line 2071 "y.tab.c"
    break;

  case 37: /* level2: level3  */
#line 488 "lexical_analyzer.y"
       {

   (yyval.nodo).code = (yyvsp[0].nodo).code;

}
#line 2081 "y.tab.c"
    break;

  case 38: /* level3: level3 OP2 VALUE  */
#line 497 "lexical_analyzer.y"
{


   char* temp = concat_strings((yyvsp[-2].nodo).code,(yyvsp[0].nodo).code);
   if(strcmp((yyvsp[-1].value),"*") == 0)
      (yyval.nodo).code = concat_strings(temp,"mp \n");
   else if(strcmp((yyvsp[-1].value),"/") == 0)
      (yyval.nodo).code = concat_strings(temp,"dv \n");
   else if(strcmp((yyvsp[-1].value),"%") == 0)
      (yyval.nodo).code = concat_strings(temp,"mod \n");
   //else if(strcmp($2,"//") == 0)
   //   $$.code = concat_strings(temp,"dvf \n");

   free(temp);
   free((yyvsp[-2].nodo).code);
   free((yyvsp[-1].value));
   free((yyvsp[0].nodo).code);
}
#line 2104 "y.tab.c"
    break;

  case 39: /* level3: VALUE  */
#line 517 "lexical_analyzer.y"
{


   (yyval.nodo).code = (yyvsp[0].nodo).code;

   //printf("code: %s",$$.code);
   //free(actual_code);
   //free($1.code);
   //free($1.name);
}
#line 2119 "y.tab.c"
    break;

  case 40: /* VALUE: ID  */
#line 531 "lexical_analyzer.y"
{
   if(!check_symbol_existence((yyvsp[0].value))){
      yyerror("Variable does not exists");
      YYABORT;
   }
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"lod %s\n",(yyvsp[0].value));
   free((yyvsp[0].value));
   //$$.name = $<value>1;
   //printf("%s\n",$$.name);
}
#line 2135 "y.tab.c"
    break;

  case 41: /* VALUE: '-' ID  */
#line 544 "lexical_analyzer.y"
{
   if(!check_symbol_existence((yyvsp[0].value))){
      yyerror("Variable does not exists");
      YYABORT;
   }
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"lod %s\nldc -1\nmp \n",(yyvsp[0].value));
   free((yyvsp[0].value));

}
#line 2150 "y.tab.c"
    break;

  case 42: /* VALUE: '!' ID  */
#line 556 "lexical_analyzer.y"
{
      if(!check_symbol_existence((yyvsp[0].value))){
      yyerror("Variable does not exists");
      YYABORT;
   }
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"lod %s\nne \n",(yyvsp[0].value));
   free((yyvsp[0].value));

}
#line 2165 "y.tab.c"
    break;

  case 43: /* $@4: %empty  */
#line 568 "lexical_analyzer.y"
{
   if(!check_symbol_existence((yyvsp[0].value))) {
      yyerror("Variable does not exists");
      YYERROR;
   }
}
#line 2176 "y.tab.c"
    break;

  case 44: /* VALUE: ID $@4 '[' NUM_LIKE ']'  */
#line 575 "lexical_analyzer.y"
{
   
   (yyval.nodo).code = (char*) malloc(200);
   char template_string[] = "lod %s\n%sad \nloa \n";
   sprintf((yyval.nodo).code,template_string,(yyvsp[-4].value),(yyvsp[-1].nodo).code);

   free((yyvsp[-4].value));
   free((yyvsp[-1].nodo).code);

}
#line 2191 "y.tab.c"
    break;

  case 45: /* VALUE: '(' exp ')'  */
#line 587 "lexical_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[-1].nodo).code;
}
#line 2199 "y.tab.c"
    break;

  case 46: /* VALUE: '-' NUMERO  */
#line 592 "lexical_analyzer.y"
{
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"ldc %s\nldc -1\nmp \n",(yyvsp[0].value));
   free((yyvsp[0].value));
   //$$.code = strdup("");
   //$$.name = $<value>1;
}
#line 2211 "y.tab.c"
    break;

  case 47: /* VALUE: '!' NUMERO  */
#line 602 "lexical_analyzer.y"
{
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"ldc %s\nne \n",(yyvsp[0].value));
   free((yyvsp[0].value));
   //$$.code = strdup("");
   //$$.name = $<value>1;
}
#line 2223 "y.tab.c"
    break;

  case 48: /* VALUE: NUMERO  */
#line 611 "lexical_analyzer.y"
{
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"ldc %s\n",(yyvsp[0].value));
   free((yyvsp[0].value));
   //$$.code = strdup("");
   //$$.name = $<value>1;
}
#line 2235 "y.tab.c"
    break;

  case 49: /* NUM_LIKE: ID  */
#line 622 "lexical_analyzer.y"
{
   if(!check_symbol_existence((yyvsp[0].value))) {
      yyerror("Variable does not exists");
      YYERROR;
   }
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"lod %s\n",(yyvsp[0].value));
   free((yyvsp[0].value));
}
#line 2249 "y.tab.c"
    break;

  case 50: /* NUM_LIKE: NUMERO  */
#line 633 "lexical_analyzer.y"
{ 
   double num_d = atof((yyvsp[0].value));
   int num_i = atoi((yyvsp[0].value));
   if((int) ceil(num_d) != num_i){
      yyerror("Array index must be an integer");
      YYABORT;
   }else if(num_i < 0){
      yyerror("Array index must be at least 0");
      YYABORT;
   }

   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"ldc %d\n",num_i);
   free((yyvsp[0].value));
   //$$.code = strdup("");
   //$$.name = $<value>1;
}
#line 2271 "y.tab.c"
    break;

  case 51: /* LOGIC: AND  */
#line 651 "lexical_analyzer.y"
           {(yyval.value) = (yyvsp[0].value);}
#line 2277 "y.tab.c"
    break;

  case 52: /* LOGIC: OR  */
#line 651 "lexical_analyzer.y"
                                  {(yyval.value) = (yyvsp[0].value);}
#line 2283 "y.tab.c"
    break;

  case 53: /* OP1: '+'  */
#line 652 "lexical_analyzer.y"
         {(yyval.value) = (yyvsp[0].value);}
#line 2289 "y.tab.c"
    break;

  case 54: /* OP1: '-'  */
#line 652 "lexical_analyzer.y"
                                  {(yyval.value) = (yyvsp[0].value);}
#line 2295 "y.tab.c"
    break;

  case 55: /* OP2: '*'  */
#line 653 "lexical_analyzer.y"
         {(yyval.value) = (yyvsp[0].value);}
#line 2301 "y.tab.c"
    break;

  case 56: /* OP2: '/'  */
#line 653 "lexical_analyzer.y"
                                 {(yyval.value) = (yyvsp[0].value);}
#line 2307 "y.tab.c"
    break;

  case 57: /* OP2: '%'  */
#line 653 "lexical_analyzer.y"
                                                        {(yyval.value) = (yyvsp[0].value);}
#line 2313 "y.tab.c"
    break;


#line 2317 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 655 "lexical_analyzer.y"





