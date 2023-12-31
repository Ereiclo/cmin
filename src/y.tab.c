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
#line 1 "syntax_analyzer.y"

   #include <stdio.h>
   #include <stdlib.h>
   #include <math.h>
   #include <string.h>
   int yylex(void);
   void yyerror(const char *s);
   //FILE *yyin;
   FILE *out;
   struct function{
      char* name;
      int n_args;
      int defined;
   };

   struct variable{
      char* name;
      char* scope;

   };


   struct function* table_function;
   struct variable* table_variable;
   int n_variables = 0;
   int n_functions = 0;
   int actual_label = 0;
   char* actual_scope;
   int id_actual_scope = 0;

   int check_variable_existence(char* symbol,char*scope);
   void push_variable(char*symbol,char*scope);
   void declare_function(char*name,int n_args);
   void define_function(char*name);
   int check_function_existence(char* name);
   int is_defined(char* name, int args);
   int is_valid_call(char*name, int args);
   int is_valid_definition(char*name, int args);
   char* check_undefined_function();

   char* concat_strings(char* dest, char* src){

      char* new_string = (char*) malloc(strlen(dest) + strlen(src) + 1);

      strcpy(new_string,dest);
      strcat(new_string,src);

   }



#line 54 "syntax_analyzer.y"


   typedef struct{
      char** values;
      int tamanio;
   } ls;

   typedef struct{
      char* code; 
      int count;
   } node;

#line 136 "y.tab.c"

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
    MAIN = 260,                    /* MAIN  */
    AND = 261,                     /* AND  */
    OR = 262,                      /* OR  */
    CEIL = 263,                    /* CEIL  */
    FLOOR = 264,                   /* FLOOR  */
    LET = 265,                     /* LET  */
    WHILE = 266,                   /* WHILE  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    COMP = 269,                    /* COMP  */
    ID = 270,                      /* ID  */
    CADENA = 271,                  /* CADENA  */
    NUMERO = 272,                  /* NUMERO  */
    PRINT = 273                    /* PRINT  */
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
#define MAIN 260
#define AND 261
#define OR 262
#define CEIL 263
#define FLOOR 264
#define LET 265
#define WHILE 266
#define IF 267
#define ELSE 268
#define COMP 269
#define ID 270
#define CADENA 271
#define NUMERO 272
#define PRINT 273

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 72 "syntax_analyzer.y"

    int count;
    ls lista;
    node nodo;
    char* value;
    double* lista_num;


#line 234 "y.tab.c"

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
  YYSYMBOL_MAIN = 5,                       /* MAIN  */
  YYSYMBOL_AND = 6,                        /* AND  */
  YYSYMBOL_OR = 7,                         /* OR  */
  YYSYMBOL_CEIL = 8,                       /* CEIL  */
  YYSYMBOL_FLOOR = 9,                      /* FLOOR  */
  YYSYMBOL_LET = 10,                       /* LET  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_COMP = 14,                      /* COMP  */
  YYSYMBOL_ID = 15,                        /* ID  */
  YYSYMBOL_CADENA = 16,                    /* CADENA  */
  YYSYMBOL_NUMERO = 17,                    /* NUMERO  */
  YYSYMBOL_PRINT = 18,                     /* PRINT  */
  YYSYMBOL_19_then_ = 19,                  /* "then"  */
  YYSYMBOL_20_ = 20,                       /* '('  */
  YYSYMBOL_21_ = 21,                       /* ')'  */
  YYSYMBOL_22_ = 22,                       /* ';'  */
  YYSYMBOL_23_ = 23,                       /* '{'  */
  YYSYMBOL_24_ = 24,                       /* '}'  */
  YYSYMBOL_25_ = 25,                       /* ','  */
  YYSYMBOL_26_ = 26,                       /* '['  */
  YYSYMBOL_27_ = 27,                       /* ']'  */
  YYSYMBOL_28_ = 28,                       /* '='  */
  YYSYMBOL_29_ = 29,                       /* '!'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_S = 36,                         /* S  */
  YYSYMBOL_FUNCT_DECLS = 37,               /* FUNCT_DECLS  */
  YYSYMBOL_FUNCT_DEFS = 38,                /* FUNCT_DEFS  */
  YYSYMBOL_FUNCT_DECL = 39,                /* FUNCT_DECL  */
  YYSYMBOL_FUNCT_DEF = 40,                 /* FUNCT_DEF  */
  YYSYMBOL_FUNCT_MAIN = 41,                /* FUNCT_MAIN  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_LISTA_ARGS_DEF = 43,            /* LISTA_ARGS_DEF  */
  YYSYMBOL_CODE = 44,                      /* CODE  */
  YYSYMBOL_I = 45,                         /* I  */
  YYSYMBOL_IN = 46,                        /* IN  */
  YYSYMBOL_47_2 = 47,                      /* @2  */
  YYSYMBOL_ID_ASSIGN = 48,                 /* ID_ASSIGN  */
  YYSYMBOL_LISTA_ARRAY = 49,               /* LISTA_ARRAY  */
  YYSYMBOL_LISTA_ARGS_NUM = 50,            /* LISTA_ARGS_NUM  */
  YYSYMBOL_LISTA_ARGS_PRINT = 51,          /* LISTA_ARGS_PRINT  */
  YYSYMBOL_SUB_CODE = 52,                  /* SUB_CODE  */
  YYSYMBOL_WHILE_BLOCK = 53,               /* WHILE_BLOCK  */
  YYSYMBOL_IF_BLOCK = 54,                  /* IF_BLOCK  */
  YYSYMBOL_IF_ELSE_BLOCK = 55,             /* IF_ELSE_BLOCK  */
  YYSYMBOL_P = 56,                         /* P  */
  YYSYMBOL_DECL = 57,                      /* DECL  */
  YYSYMBOL_exp = 58,                       /* exp  */
  YYSYMBOL_ANDLEVEL = 59,                  /* ANDLEVEL  */
  YYSYMBOL_level1 = 60,                    /* level1  */
  YYSYMBOL_level2 = 61,                    /* level2  */
  YYSYMBOL_level3 = 62,                    /* level3  */
  YYSYMBOL_UNARY = 63,                     /* UNARY  */
  YYSYMBOL_VALUE = 64,                     /* VALUE  */
  YYSYMBOL_LISTA_ARGS_CALL = 65,           /* LISTA_ARGS_CALL  */
  YYSYMBOL_NUM_LIKE = 66,                  /* NUM_LIKE  */
  YYSYMBOL_OP1 = 67,                       /* OP1  */
  YYSYMBOL_OP2 = 68                        /* OP2  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


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
       2,     2,     2,    29,     2,     2,     2,    34,     2,     2,
      20,    21,    32,    31,    25,    30,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
       2,    28,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    24,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   108,   116,   116,   118,   126,   134,   152,
     201,   246,   244,   272,   290,   314,   331,   343,   351,   358,
     363,   372,   375,   374,   403,   408,   432,   438,   451,   457,
     496,   519,   523,   533,   543,   554,   566,   575,   586,   586,
     586,   590,   621,   649,   686,   686,   686,   690,   712,   743,
     761,   794,   805,   812,   823,   829,   852,   860,   874,   882,
     902,   916,   923,   932,   940,   956,   975,   999,  1005,  1011,
    1017,  1028,  1040,  1049,  1059,  1074,  1093,  1093,  1094,  1094,
    1094
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
  "end of file", "error", "invalid token", "RETURN", "FUNCTION", "MAIN",
  "AND", "OR", "CEIL", "FLOOR", "LET", "WHILE", "IF", "ELSE", "COMP", "ID",
  "CADENA", "NUMERO", "PRINT", "then", "'('", "')'", "';'", "'{'", "'}'",
  "','", "'['", "']'", "'='", "'!'", "'-'", "'+'", "'*'", "'/'", "'%'",
  "$accept", "S", "FUNCT_DECLS", "FUNCT_DEFS", "FUNCT_DECL", "FUNCT_DEF",
  "FUNCT_MAIN", "$@1", "LISTA_ARGS_DEF", "CODE", "I", "IN", "@2",
  "ID_ASSIGN", "LISTA_ARRAY", "LISTA_ARGS_NUM", "LISTA_ARGS_PRINT",
  "SUB_CODE", "WHILE_BLOCK", "IF_BLOCK", "IF_ELSE_BLOCK", "P", "DECL",
  "exp", "ANDLEVEL", "level1", "level2", "level3", "UNARY", "VALUE",
  "LISTA_ARGS_CALL", "NUM_LIKE", "OP1", "OP2", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    12,    31,    36,  -122,  -122,    43,    50,  -122,    54,
      85,  -122,  -122,    33,    83,    88,    34,  -122,  -122,    86,
    -122,    27,    83,    92,    89,    98,   109,    39,    83,  -122,
     162,  -122,  -122,   -15,    40,    58,   116,   122,   123,    48,
     125,    82,  -122,   113,  -122,  -122,  -122,  -122,  -122,   121,
     104,   130,   134,   136,    -8,  -122,    58,   161,   161,   150,
     156,   153,    49,    69,  -122,  -122,   138,    58,    58,    58,
     106,    -4,    26,  -122,  -122,  -122,   160,  -122,   115,    58,
      58,    58,   106,    -1,  -122,  -122,    58,    58,    58,  -122,
    -122,    58,  -122,  -122,  -122,    58,   151,     2,     3,   150,
      56,  -122,  -122,  -122,   165,  -122,   150,  -122,    61,   150,
     157,  -122,     7,     8,    74,   152,  -122,   156,   153,    49,
      69,  -122,   158,   148,   148,  -122,    58,   159,  -122,   107,
    -122,    42,   167,  -122,  -122,  -122,  -122,  -122,   126,  -122,
    -122,   174,   150,   163,   171,  -122,  -122,   150,   166,  -122,
     137,   148,    58,  -122,  -122,  -122,  -122,   150
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     5,     3,     0,     0,     1,     0,
       0,     4,     7,     0,    16,     0,     0,     6,     2,     0,
      15,     0,    16,     0,    11,     0,     0,     0,    16,    13,
      28,     8,    14,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    18,     0,    21,    20,    40,    38,    39,    24,
      28,     0,     0,     0,    64,    70,     0,     0,     0,    27,
      52,    54,    56,    58,    60,    63,    49,     0,     0,    73,
       0,     0,     0,    12,    17,    19,     0,    10,    28,     0,
       0,    73,     0,     0,    61,    62,     0,     0,     0,    77,
      76,     0,    78,    79,    80,     0,     0,     0,     0,    72,
       0,    74,    75,    22,     0,    29,    30,    36,     0,    37,
      47,     9,     0,     0,     0,     0,    69,    51,    53,    55,
      57,    59,     0,    28,    28,    25,     0,     0,    33,     0,
      26,     0,     0,    67,    68,    66,    65,    50,    28,    44,
      41,    42,    71,     0,     0,    31,    35,    34,     0,    46,
      28,    28,     0,    32,    48,    45,    43,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,   186,   180,   182,  -122,    25,   -48,
     -40,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -121,  -122,   -35,   108,   110,   111,   105,   100,    47,
     117,   118,  -122,  -122
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    10,     4,    12,     5,    30,    21,    41,
      42,    43,   127,    44,   105,   129,   108,    45,    46,    47,
      48,   140,    49,    99,    60,    61,    62,    63,    64,    65,
     100,   103,    91,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    74,    78,   141,    52,    53,    86,    31,    50,    86,
      86,    54,    81,    55,    86,    86,    56,     6,    82,     1,
     116,    83,   104,   123,   124,    57,    58,     7,   133,   134,
     156,     8,    97,    98,    52,    53,   106,   109,    74,     6,
       9,    54,   107,    55,   112,   113,    56,    27,    25,    23,
      52,    53,    26,    34,    19,    57,    58,    54,   146,    55,
      33,    51,    56,    13,    26,    26,    52,    53,    69,    15,
      14,    57,    58,    54,    70,    55,    71,   125,    56,    89,
      90,   126,   130,   139,   139,    35,   131,    57,    58,    16,
     150,   142,    36,    37,    38,   135,   147,    39,    20,   126,
      40,    92,    93,    94,    84,    85,    73,    35,    22,    24,
      74,   139,    28,    29,    36,    37,    38,   157,    35,    39,
      31,   101,    40,   102,    32,    36,    37,    38,    77,    35,
      39,    66,   144,    40,   145,    75,    36,    37,    38,   111,
      35,    39,    67,    68,    40,    72,    76,    36,    37,    38,
     149,    35,    39,    50,    79,    40,    80,    86,    36,    37,
      38,   155,    87,    39,    96,    35,    40,    88,   122,    52,
      53,   138,    36,    37,    38,   110,    54,    39,    55,   136,
      40,    56,   128,   132,   148,   137,   143,   151,   153,    11,
      17,   152,    18,   154,   117,   121,   120,   118,   114,   119,
     115
};

static const yytype_uint8 yycheck[] =
{
      35,    41,    50,   124,     8,     9,     7,    22,    23,     7,
       7,    15,    20,    17,     7,     7,    20,     5,    26,     4,
      21,    56,    26,    21,    21,    29,    30,    15,    21,    21,
     151,     0,    67,    68,     8,     9,    71,    72,    78,     5,
       4,    15,    16,    17,    79,    80,    20,    22,    21,    15,
       8,     9,    25,    28,    21,    29,    30,    15,    16,    17,
      21,    21,    20,    20,    25,    25,     8,     9,    20,    15,
      20,    29,    30,    15,    26,    17,    28,    21,    20,    30,
      31,    25,    21,   123,   124,     3,    25,    29,    30,     4,
     138,   126,    10,    11,    12,    21,   131,    15,    15,    25,
      18,    32,    33,    34,    57,    58,    24,     3,    20,    23,
     150,   151,    20,    24,    10,    11,    12,   152,     3,    15,
      22,    15,    18,    17,    15,    10,    11,    12,    24,     3,
      15,    15,    25,    18,    27,    22,    10,    11,    12,    24,
       3,    15,    20,    20,    18,    20,    25,    10,    11,    12,
      24,     3,    15,    23,    20,    18,    20,     7,    10,    11,
      12,    24,     6,    15,    26,     3,    18,    14,    17,     8,
       9,    23,    10,    11,    12,    15,    15,    15,    17,    27,
      18,    20,    17,    26,    17,    27,    27,    13,    17,     3,
      10,    28,    10,    27,    86,    95,    91,    87,    81,    88,
      82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    36,    37,    39,    41,     5,    15,     0,     4,
      38,    39,    40,    20,    20,    15,     4,    40,    41,    21,
      15,    43,    20,    15,    23,    21,    25,    43,    20,    24,
      42,    22,    15,    21,    43,     3,    10,    11,    12,    15,
      18,    44,    45,    46,    48,    52,    53,    54,    55,    57,
      23,    21,     8,     9,    15,    17,    20,    29,    30,    58,
      59,    60,    61,    62,    63,    64,    15,    20,    20,    20,
      26,    28,    20,    24,    45,    22,    25,    24,    44,    20,
      20,    20,    26,    58,    64,    64,     7,     6,    14,    30,
      31,    67,    32,    33,    34,    68,    26,    58,    58,    58,
      65,    15,    17,    66,    26,    49,    58,    16,    51,    58,
      15,    24,    58,    58,    65,    66,    21,    59,    60,    61,
      62,    63,    17,    21,    21,    21,    25,    47,    17,    50,
      21,    25,    26,    21,    21,    21,    27,    27,    23,    45,
      56,    56,    58,    27,    25,    27,    16,    58,    17,    24,
      44,    13,    28,    17,    27,    24,    56,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    38,    38,    39,    40,
      40,    42,    41,    41,    43,    43,    43,    44,    44,    45,
      45,    46,    47,    46,    46,    46,    46,    46,    46,    48,
      48,    49,    50,    50,    51,    51,    51,    51,    52,    52,
      52,    53,    54,    55,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     1,     2,     1,     6,     8,
       7,     0,     8,     6,     3,     1,     0,     2,     1,     2,
       1,     1,     0,     7,     1,     4,     4,     2,     0,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     5,     5,     7,     1,     3,     2,     3,     6,     2,
       5,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     1,     1,     4,     4,     4,     4,     3,
       1,     3,     1,     0,     1,     1,     1,     1,     1,     1,
       1
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
  case 2: /* S: FUNCT_DECLS FUNCT_DEFS FUNCT_MAIN  */
#line 97 "syntax_analyzer.y"
                                  {

   char* temp = concat_strings("ujp $main\n",(yyvsp[-1].nodo).code);
   char* result = concat_strings(temp,(yyvsp[0].nodo).code);

   fwrite(result,1,strlen(result),out);
   free(temp);
   free((yyvsp[-1].nodo).code);
   free((yyvsp[0].nodo).code);
}
#line 1619 "y.tab.c"
    break;

  case 3: /* S: FUNCT_MAIN  */
#line 109 "syntax_analyzer.y"
{
   //printf("El codigo generado es:\n%s",$1.code);
   fwrite((yyvsp[0].nodo).code,1,strlen((yyvsp[0].nodo).code),out);
}
#line 1628 "y.tab.c"
    break;

  case 6: /* FUNCT_DEFS: FUNCT_DEFS FUNCT_DEF  */
#line 119 "syntax_analyzer.y"
{
   (yyval.nodo).code = concat_strings((yyvsp[-1].nodo).code,(yyvsp[0].nodo).code);

   free((yyvsp[-1].nodo).code);
   free((yyvsp[0].nodo).code);
}
#line 1639 "y.tab.c"
    break;

  case 7: /* FUNCT_DEFS: FUNCT_DEF  */
#line 127 "syntax_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[0].nodo).code;
}
#line 1647 "y.tab.c"
    break;

  case 8: /* FUNCT_DECL: FUNCTION ID '(' LISTA_ARGS_DEF ')' ';'  */
#line 135 "syntax_analyzer.y"
{
   if(check_function_existence((yyvsp[-4].value))){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s already declared",(yyvsp[-4].value));
      yyerror(error_string);
      YYABORT;
   }

   declare_function(strdup((yyvsp[-4].value)),(yyvsp[-2].nodo).count);

   free((yyvsp[-4].value));
   free((yyvsp[-2].nodo).code);

}
#line 1666 "y.tab.c"
    break;

  case 9: /* FUNCT_DEF: FUNCTION ID '(' LISTA_ARGS_DEF ')' '{' CODE '}'  */
#line 153 "syntax_analyzer.y"
{
   free(actual_scope);
   actual_scope = strdup("");

   if(is_valid_definition((yyvsp[-6].value),(yyvsp[-4].nodo).count) == 0){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s not declared",(yyvsp[-6].value));
      yyerror(error_string);
      YYABORT;
   }
   else if(is_valid_definition((yyvsp[-6].value),(yyvsp[-4].nodo).count) == -1){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s already defined",(yyvsp[-6].value));
      yyerror(error_string);
      YYABORT;
   } else if(is_valid_definition((yyvsp[-6].value),(yyvsp[-4].nodo).count) == -2){
      char* error_string  = malloc(100);
      sprintf(error_string,"Definition of function %s does not match number of args of declaration",(yyvsp[-6].value));
      yyerror(error_string);
      YYABORT;
   }

   define_function((yyvsp[-6].value));


   //hacer validaciones
   char* temp1 = malloc(100);

   sprintf(temp1,"lab $%s\nscope \n",(yyvsp[-6].value));

   char*temp2 = concat_strings(temp1,(yyvsp[-4].nodo).code);

   char* temp3 = concat_strings(temp2,(yyvsp[-1].nodo).code);

   (yyval.nodo).code = concat_strings(temp3,"ldc 0\nendscope \nreturn_jp \n");


   free(temp1);
   free(temp2);
   free(temp3);
   free((yyvsp[-6].value));
   free((yyvsp[-4].nodo).code);
   free((yyvsp[-1].nodo).code);



}
#line 1718 "y.tab.c"
    break;

  case 10: /* FUNCT_DEF: FUNCTION ID '(' LISTA_ARGS_DEF ')' '{' '}'  */
#line 202 "syntax_analyzer.y"
{

   if(is_valid_definition((yyvsp[-5].value),(yyvsp[-3].nodo).count) == 0){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s not declared",(yyvsp[-5].value));
      yyerror(error_string);
      YYABORT;
   }
   else if(is_valid_definition((yyvsp[-5].value),(yyvsp[-3].nodo).count) == -1){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s already defined",(yyvsp[-5].value));
      yyerror(error_string);
      YYABORT;
   } else if(is_valid_definition((yyvsp[-5].value),(yyvsp[-3].nodo).count) == -2){
      char* error_string  = malloc(100);
      sprintf(error_string,"Definition of function %s does not match number of args of declaration",(yyvsp[-5].value));
      yyerror(error_string);
      YYABORT;
   }


   define_function((yyvsp[-5].value));

   char* temp1 = malloc(100);

   sprintf(temp1,"lab $%s\nscope \n",(yyvsp[-5].value));

   char*temp2 = concat_strings(temp1,(yyvsp[-3].nodo).code);


   (yyval.nodo).code = concat_strings(temp2,"ldc 0\nendscope \nreturn_jp \n");


   free(temp1);
   free(temp2);
   free((yyvsp[-5].value));
   free((yyvsp[-3].nodo).code);

}
#line 1762 "y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 246 "syntax_analyzer.y"
{ 
   free(actual_scope);
   actual_scope = strdup("main");
}
#line 1771 "y.tab.c"
    break;

  case 12: /* FUNCT_MAIN: FUNCTION MAIN '(' ')' '{' $@1 CODE '}'  */
#line 252 "syntax_analyzer.y"
{
   char* error_string = check_undefined_function();

   if(strcmp(error_string,"") != 0){

      yyerror(error_string);
      YYABORT;
   }

   char* temp = concat_strings("lab $main\nscope \n",(yyvsp[-1].nodo).code);

   (yyval.nodo).code = concat_strings(temp,"endscope \n");


   free((yyvsp[-1].nodo).code);
   free(temp);


}
#line 1795 "y.tab.c"
    break;

  case 13: /* FUNCT_MAIN: FUNCTION MAIN '(' ')' '{' '}'  */
#line 273 "syntax_analyzer.y"
{
   char* error_string = check_undefined_function();

   if(strcmp(error_string,"") != 0){

      yyerror(error_string);
      YYABORT;
   }


   (yyval.nodo).code = strdup("lab $main\nscope \nendscope \n");

}
#line 1813 "y.tab.c"
    break;

  case 14: /* LISTA_ARGS_DEF: LISTA_ARGS_DEF ',' ID  */
#line 291 "syntax_analyzer.y"
{
   if(check_variable_existence((yyvsp[0].value),actual_scope) == 1){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",(yyvsp[0].value));
      yyerror(error_string);
      YYERROR;
   }
   // printf("ke:%s\n",$<value>3);

   push_variable(strdup((yyvsp[0].value)),actual_scope);

   (yyval.nodo).count = (yyvsp[-2].nodo).count + 1;

   char* temp = malloc(200);

   sprintf(temp,"sto \nnew_var %s\nlda %s\nlod $\nsto \n",(yyvsp[0].value),(yyvsp[0].value));

   (yyval.nodo).code = concat_strings(temp,(yyvsp[-2].nodo).code);

   free((yyvsp[-2].nodo).code);
   free((yyvsp[0].value));
}
#line 1840 "y.tab.c"
    break;

  case 15: /* LISTA_ARGS_DEF: ID  */
#line 315 "syntax_analyzer.y"
{
   free(actual_scope);
   actual_scope = malloc(100);
   sprintf(actual_scope,"scope%d",id_actual_scope++);
   push_variable(strdup((yyvsp[0].value)),actual_scope);


   (yyval.nodo).count = 1;

   (yyval.nodo).code = malloc(200);

   sprintf((yyval.nodo).code,"sto \nnew_var %s\nlda %s\nlod $\nsto \n",(yyvsp[0].value),(yyvsp[0].value));

   free((yyvsp[0].value));
}
#line 1860 "y.tab.c"
    break;

  case 16: /* LISTA_ARGS_DEF: %empty  */
#line 332 "syntax_analyzer.y"
{
   free(actual_scope);
   actual_scope = malloc(100);
   sprintf(actual_scope,"scope%d",id_actual_scope++);
   (yyval.nodo).count = 0;
   (yyval.nodo).code = strdup("");
}
#line 1872 "y.tab.c"
    break;

  case 17: /* CODE: CODE I  */
#line 344 "syntax_analyzer.y"
{ 
   (yyval.nodo).code = concat_strings((yyvsp[-1].nodo).code,(yyvsp[0].nodo).code);

   free((yyvsp[-1].nodo).code);

}
#line 1883 "y.tab.c"
    break;

  case 18: /* CODE: I  */
#line 352 "syntax_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[0].nodo).code;
}
#line 1891 "y.tab.c"
    break;

  case 19: /* I: IN ';'  */
#line 359 "syntax_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[-1].nodo).code;
}
#line 1899 "y.tab.c"
    break;

  case 20: /* I: SUB_CODE  */
#line 364 "syntax_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[0].nodo).code;
}
#line 1907 "y.tab.c"
    break;

  case 21: /* IN: ID_ASSIGN  */
#line 372 "syntax_analyzer.y"
          {(yyval.nodo).code = (yyvsp[0].nodo).code;}
#line 1913 "y.tab.c"
    break;

  case 22: /* @2: %empty  */
#line 375 "syntax_analyzer.y"
{
   if(!check_variable_existence((yyvsp[-2].value),actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",(yyvsp[-2].value));
      yyerror(error_string);
      YYABORT;
   }

   (yyval.nodo).code = (char*) malloc(200);
   char template_string[] = "lod %s\n%sad \n";
   sprintf((yyval.nodo).code,template_string,(yyvsp[-2].value),(yyvsp[0].nodo).code);

   free((yyvsp[-2].value));
   free((yyvsp[0].nodo).code);


}
#line 1935 "y.tab.c"
    break;

  case 23: /* IN: ID '[' NUM_LIKE @2 ']' '=' exp  */
#line 393 "syntax_analyzer.y"
{
   char* temp = concat_strings((yyvsp[-3].nodo).code,(yyvsp[0].nodo).code);

   (yyval.nodo).code = concat_strings(temp,"sto \n");

   free(temp);
   free((yyvsp[-3].nodo).code);
   free((yyvsp[0].nodo).code);
}
#line 1949 "y.tab.c"
    break;

  case 24: /* IN: DECL  */
#line 404 "syntax_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[0].nodo).code;
}
#line 1957 "y.tab.c"
    break;

  case 25: /* IN: ID '(' LISTA_ARGS_CALL ')'  */
#line 409 "syntax_analyzer.y"
{
   if(is_valid_call((yyvsp[-3].value),(yyvsp[-1].nodo).count) == 0){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s does not exists",(yyvsp[-3].value));
      yyerror(error_string);
      YYABORT;
   }
   else if(is_valid_call((yyvsp[-3].value),(yyvsp[-1].nodo).count) == -1){
      char* error_string  = malloc(100);
      sprintf(error_string,"Call to function %s does not match number of args",(yyvsp[-3].value));
      yyerror(error_string);
      YYABORT;

   }
   char* temp = malloc(100);
   sprintf(temp,"call_jp $%s\npop \n",(yyvsp[-3].value));
   (yyval.nodo).code = concat_strings((yyvsp[-1].nodo).code,temp);

   free(temp);
   free((yyvsp[-1].nodo).code);

}
#line 1984 "y.tab.c"
    break;

  case 26: /* IN: PRINT '(' LISTA_ARGS_PRINT ')'  */
#line 433 "syntax_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[-1].nodo).code;

}
#line 1993 "y.tab.c"
    break;

  case 27: /* IN: RETURN exp  */
#line 438 "syntax_analyzer.y"
           {
   //no hacerlo en main
   // printf("%sa",actual_scope);
   if(strcmp(actual_scope,"main") == 0){
      yyerror("Main cannnot return");
      YYABORT;
   }
   (yyval.nodo).code = concat_strings((yyvsp[0].nodo).code,"endscope \nreturn_jp \n");

   free((yyvsp[0].nodo).code);

}
#line 2010 "y.tab.c"
    break;

  case 28: /* IN: %empty  */
#line 451 "syntax_analyzer.y"
       {
   (yyval.nodo).code = strdup("");
}
#line 2018 "y.tab.c"
    break;

  case 29: /* ID_ASSIGN: ID '=' LISTA_ARRAY  */
#line 458 "syntax_analyzer.y"
{
   if(!check_variable_existence((yyvsp[-2].value),actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",(yyvsp[-2].value));
      yyerror(error_string);
      YYABORT;
   }

   char* actual_code = strdup("");
   int size = (yyvsp[0].lista_num)[0];
   // printf("%f\n",$3[1]);

   for(int i = 1; i < (size + 1);++i){
      char* prev_code = actual_code;
      char* temp = malloc(300);
      double actual_num = (yyvsp[0].lista_num)[i];
      // printf("%f\n",actual_num);
      sprintf(temp,"lod %s\nldc %d\nad \nldc %f\nsto \n",(yyvsp[-2].value),i-1,actual_num);

      actual_code = concat_strings(prev_code,temp);

      free(prev_code);
      free(temp);


   }
   char* temp = malloc(100);
   sprintf(temp,"lda %s\nnew_arr %d\nsto \n",(yyvsp[-2].value),size);

   (yyval.nodo).code = concat_strings(temp,actual_code);

   free((yyvsp[-2].value));
   free((yyvsp[0].lista_num));
   free(temp);
   free(actual_code);

}
#line 2060 "y.tab.c"
    break;

  case 30: /* ID_ASSIGN: ID '=' exp  */
#line 497 "syntax_analyzer.y"
{

   if(!check_variable_existence((yyvsp[-2].value),actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",(yyvsp[-2].value));
      yyerror(error_string);
      YYABORT;
   }
   char* temp1 = (char*) malloc(100);
   sprintf(temp1,"lda %s\n",(yyvsp[-2].value));
   char* temp2 = concat_strings(temp1,(yyvsp[0].nodo).code);

   (yyval.nodo).code = concat_strings(temp2,"sto \n");

   free(temp1);
   free(temp2);
   free((yyvsp[-2].value));
   free((yyvsp[-1].value));
   free((yyvsp[0].nodo).code);
}
#line 2085 "y.tab.c"
    break;

  case 31: /* LISTA_ARRAY: '[' LISTA_ARGS_NUM ']'  */
#line 519 "syntax_analyzer.y"
                                     {(yyval.lista_num) = (yyvsp[-1].lista_num);}
#line 2091 "y.tab.c"
    break;

  case 32: /* LISTA_ARGS_NUM: LISTA_ARGS_NUM ',' NUMERO  */
#line 524 "syntax_analyzer.y"
{
   (yyval.lista_num) = (yyvsp[-2].lista_num);
   int size = (yyval.lista_num)[0];
   (yyval.lista_num)[size+1] = atof((yyvsp[0].value));
   (yyval.lista_num)[0]++;
   // printf("%f %d\n",atof($<value>3),size);

}
#line 2104 "y.tab.c"
    break;

  case 33: /* LISTA_ARGS_NUM: NUMERO  */
#line 534 "syntax_analyzer.y"
{
   (yyval.lista_num) = (double*) malloc(sizeof(double)*100);
   (yyval.lista_num)[0] = 1;
   (yyval.lista_num)[1] = atof((yyvsp[0].value));

   // printf("%f\n",atof($<value>1));
}
#line 2116 "y.tab.c"
    break;

  case 34: /* LISTA_ARGS_PRINT: LISTA_ARGS_PRINT ',' exp  */
#line 544 "syntax_analyzer.y"
{
   char* temp = concat_strings((yyvsp[0].nodo).code,"print_c \n");

   (yyval.nodo).code = concat_strings((yyvsp[-2].nodo).code,temp);

   free((yyvsp[-2].nodo).code);
   free((yyvsp[0].nodo).code);

}
#line 2130 "y.tab.c"
    break;

  case 35: /* LISTA_ARGS_PRINT: LISTA_ARGS_PRINT ',' CADENA  */
#line 555 "syntax_analyzer.y"
{
   char* temp = malloc(200);

   sprintf(temp,"print_s %s\n",(yyvsp[0].value));
   (yyval.nodo).code = concat_strings((yyvsp[-2].nodo).code,temp);

   free(temp);
   free((yyvsp[0].value));

}
#line 2145 "y.tab.c"
    break;

  case 36: /* LISTA_ARGS_PRINT: CADENA  */
#line 567 "syntax_analyzer.y"
{
   (yyval.nodo).code = malloc(200);
   sprintf((yyval.nodo).code,"print_s %s\n",(yyvsp[0].value));

   free((yyvsp[0].value));

}
#line 2157 "y.tab.c"
    break;

  case 37: /* LISTA_ARGS_PRINT: exp  */
#line 576 "syntax_analyzer.y"
{

   (yyval.nodo).code = concat_strings((yyvsp[0].nodo).code,"print_c \n");

   free((yyvsp[0].nodo).code);

}
#line 2169 "y.tab.c"
    break;

  case 38: /* SUB_CODE: IF_BLOCK  */
#line 586 "syntax_analyzer.y"
                   {(yyval.nodo).code = (yyvsp[0].nodo).code;}
#line 2175 "y.tab.c"
    break;

  case 39: /* SUB_CODE: IF_ELSE_BLOCK  */
#line 586 "syntax_analyzer.y"
                                                        {(yyval.nodo).code = (yyvsp[0].nodo).code;}
#line 2181 "y.tab.c"
    break;

  case 40: /* SUB_CODE: WHILE_BLOCK  */
#line 586 "syntax_analyzer.y"
                                                                                           {(yyval.nodo).code = (yyvsp[0].nodo).code;}
#line 2187 "y.tab.c"
    break;

  case 41: /* WHILE_BLOCK: WHILE '(' exp ')' P  */
#line 591 "syntax_analyzer.y"
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
#line 2219 "y.tab.c"
    break;

  case 42: /* IF_BLOCK: IF '(' exp ')' P  */
#line 622 "syntax_analyzer.y"
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
#line 2249 "y.tab.c"
    break;

  case 43: /* IF_ELSE_BLOCK: IF '(' exp ')' P ELSE P  */
#line 650 "syntax_analyzer.y"
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
#line 2289 "y.tab.c"
    break;

  case 44: /* P: I  */
#line 686 "syntax_analyzer.y"
     {(yyval.nodo).code = (yyvsp[0].nodo).code;}
#line 2295 "y.tab.c"
    break;

  case 45: /* P: '{' CODE '}'  */
#line 686 "syntax_analyzer.y"
                                         {(yyval.nodo).code = (yyvsp[-1].nodo).code;}
#line 2301 "y.tab.c"
    break;

  case 46: /* P: '{' '}'  */
#line 686 "syntax_analyzer.y"
                                                                         {(yyval.nodo).code =strdup("");}
#line 2307 "y.tab.c"
    break;

  case 47: /* DECL: DECL ',' ID  */
#line 691 "syntax_analyzer.y"
{
   if(check_variable_existence((yyvsp[0].value),actual_scope)){
      char * error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",(yyvsp[0].value));
      yyerror(error_string);
      YYABORT; 
   }


   char* temp = (char*) malloc(100);

   sprintf(temp,"new_var %s\n",(yyvsp[0].value));
   (yyval.nodo).code = concat_strings((yyvsp[-2].nodo).code,temp);
   push_variable((yyvsp[0].value),actual_scope);

   free((yyvsp[0].value));
   free((yyvsp[-2].nodo).code);
   free(temp);

}
#line 2332 "y.tab.c"
    break;

  case 48: /* DECL: DECL ',' ID '[' NUMERO ']'  */
#line 713 "syntax_analyzer.y"
{
   if(check_variable_existence((yyvsp[-3].value),actual_scope)){
      char * error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",(yyvsp[-3].value));
      yyerror(error_string);
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
   push_variable((yyvsp[-3].value),actual_scope);

   free(temp);
   free((yyvsp[-3].value));
   free((yyvsp[-1].value));
}
#line 2366 "y.tab.c"
    break;

  case 49: /* DECL: LET ID  */
#line 744 "syntax_analyzer.y"
{
   if(check_variable_existence((yyvsp[0].value),actual_scope)){
      char * error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",(yyvsp[0].value));
      yyerror(error_string);
      YYABORT; 
   }

   
   (yyval.nodo).code = (char*) malloc(100);
   sprintf((yyval.nodo).code,"new_var %s\n",(yyvsp[0].value));
   push_variable((yyvsp[0].value),actual_scope);

   free((yyvsp[0].value));
   
}
#line 2387 "y.tab.c"
    break;

  case 50: /* DECL: LET ID '[' NUMERO ']'  */
#line 762 "syntax_analyzer.y"
{
   if(check_variable_existence((yyvsp[-3].value),actual_scope)){
      char * error_string = malloc(100);
      sprintf(error_string,"Variable %s already exists",(yyvsp[-3].value));
      yyerror(error_string);
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
   push_variable((yyvsp[-3].value),actual_scope);

   free((yyvsp[-3].value));
   free((yyvsp[-1].value));
}
#line 2420 "y.tab.c"
    break;

  case 51: /* exp: exp OR ANDLEVEL  */
#line 795 "syntax_analyzer.y"
{
   char* temp = concat_strings((yyvsp[-2].nodo).code,(yyvsp[0].nodo).code);
   (yyval.nodo).code = concat_strings(temp,"lor \n");

   free(temp);
   free((yyvsp[-2].nodo).code);
   free((yyvsp[-1].value));
   free((yyvsp[0].nodo).code);
}
#line 2434 "y.tab.c"
    break;

  case 52: /* exp: ANDLEVEL  */
#line 806 "syntax_analyzer.y"
{

   (yyval.nodo).code = (yyvsp[0].nodo).code;

}
#line 2444 "y.tab.c"
    break;

  case 53: /* ANDLEVEL: ANDLEVEL AND level1  */
#line 813 "syntax_analyzer.y"
{
   char* temp = concat_strings((yyvsp[-2].nodo).code,(yyvsp[0].nodo).code);
   (yyval.nodo).code = concat_strings(temp,"land \n");

   free(temp);
   free((yyvsp[-2].nodo).code);
   free((yyvsp[-1].value));
   free((yyvsp[0].nodo).code);

}
#line 2459 "y.tab.c"
    break;

  case 54: /* ANDLEVEL: level1  */
#line 824 "syntax_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[0].nodo).code;
}
#line 2467 "y.tab.c"
    break;

  case 55: /* level1: level1 COMP level2  */
#line 830 "syntax_analyzer.y"
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
   else if(strcmp((yyvsp[-1].value),"!=") == 0)
      (yyval.nodo).code = concat_strings(temp,"nequi \n");

   free(temp);
   free((yyvsp[-2].nodo).code);
   free((yyvsp[-1].value));
   free((yyvsp[0].nodo).code);

}
#line 2493 "y.tab.c"
    break;

  case 56: /* level1: level2  */
#line 852 "syntax_analyzer.y"
       {

   (yyval.nodo).code = (yyvsp[0].nodo).code;

}
#line 2503 "y.tab.c"
    break;

  case 57: /* level2: level2 OP1 level3  */
#line 861 "syntax_analyzer.y"
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
#line 2520 "y.tab.c"
    break;

  case 58: /* level2: level3  */
#line 874 "syntax_analyzer.y"
       {

   (yyval.nodo).code = (yyvsp[0].nodo).code;

}
#line 2530 "y.tab.c"
    break;

  case 59: /* level3: level3 OP2 UNARY  */
#line 883 "syntax_analyzer.y"
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
#line 2553 "y.tab.c"
    break;

  case 60: /* level3: UNARY  */
#line 903 "syntax_analyzer.y"
{


   (yyval.nodo).code = (yyvsp[0].nodo).code;

   //printf("code: %s",$$.code);
   //free(actual_code);
   //free($1.code);
   //free($1.name);
}
#line 2568 "y.tab.c"
    break;

  case 61: /* UNARY: '!' VALUE  */
#line 917 "syntax_analyzer.y"
{
   (yyval.nodo).code = concat_strings((yyvsp[0].nodo).code,"ne \n");
   free((yyvsp[0].nodo).code);

}
#line 2578 "y.tab.c"
    break;

  case 62: /* UNARY: '-' VALUE  */
#line 925 "syntax_analyzer.y"
{
   (yyval.nodo).code = concat_strings((yyvsp[0].nodo).code,"ldc -1\nmp \n");

   free((yyvsp[0].nodo).code);

}
#line 2589 "y.tab.c"
    break;

  case 63: /* UNARY: VALUE  */
#line 933 "syntax_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[0].nodo).code;
}
#line 2597 "y.tab.c"
    break;

  case 64: /* VALUE: ID  */
#line 941 "syntax_analyzer.y"
{
   if(!check_variable_existence((yyvsp[0].value),actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",(yyvsp[0].value));
      yyerror(error_string);
      YYABORT;
   }
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"lod %s\n",(yyvsp[0].value));
   free((yyvsp[0].value));
   //$$.name = $<value>1;
   //printf("%s\n",$$.name);
}
#line 2615 "y.tab.c"
    break;

  case 65: /* VALUE: ID '[' NUM_LIKE ']'  */
#line 958 "syntax_analyzer.y"
{
   if(!check_variable_existence((yyvsp[-3].value),actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",(yyvsp[-3].value));
      yyerror(error_string);
      YYABORT;
   }
   
   (yyval.nodo).code = (char*) malloc(200);
   char template_string[] = "lod %s\n%sad \nloa \n";
   sprintf((yyval.nodo).code,template_string,(yyvsp[-3].value),(yyvsp[-1].nodo).code);

   free((yyvsp[-3].value));
   free((yyvsp[-1].nodo).code);

}
#line 2636 "y.tab.c"
    break;

  case 66: /* VALUE: ID '(' LISTA_ARGS_CALL ')'  */
#line 976 "syntax_analyzer.y"
{
   if(is_valid_call((yyvsp[-3].value),(yyvsp[-1].nodo).count) == 0){
      char* error_string  = malloc(100);
      sprintf(error_string,"Function %s does not exists",(yyvsp[-3].value));
      yyerror(error_string);
      YYABORT;
   }
   else if(is_valid_call((yyvsp[-3].value),(yyvsp[-1].nodo).count) == -1){
      char* error_string  = malloc(100);
      sprintf(error_string,"Call to function %s does not match number of args",(yyvsp[-3].value));
      yyerror(error_string);
      YYABORT;

   }
   char* temp = malloc(100);
   sprintf(temp,"call_jp $%s\n",(yyvsp[-3].value));
   (yyval.nodo).code = concat_strings((yyvsp[-1].nodo).code,temp);

   free(temp);
   free((yyvsp[-1].nodo).code);

}
#line 2663 "y.tab.c"
    break;

  case 67: /* VALUE: CEIL '(' exp ')'  */
#line 1000 "syntax_analyzer.y"
{
   (yyval.nodo).code = concat_strings((yyvsp[-1].nodo).code,"ceil \n");

}
#line 2672 "y.tab.c"
    break;

  case 68: /* VALUE: FLOOR '(' exp ')'  */
#line 1006 "syntax_analyzer.y"
{
   (yyval.nodo).code = concat_strings((yyvsp[-1].nodo).code,"floor \n");

}
#line 2681 "y.tab.c"
    break;

  case 69: /* VALUE: '(' exp ')'  */
#line 1012 "syntax_analyzer.y"
{
   (yyval.nodo).code = (yyvsp[-1].nodo).code;
}
#line 2689 "y.tab.c"
    break;

  case 70: /* VALUE: NUMERO  */
#line 1018 "syntax_analyzer.y"
{
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"ldc %s\n",(yyvsp[0].value));
   free((yyvsp[0].value));
   //$$.code = strdup("");
   //$$.name = $<value>1;
}
#line 2701 "y.tab.c"
    break;

  case 71: /* LISTA_ARGS_CALL: LISTA_ARGS_CALL ',' exp  */
#line 1029 "syntax_analyzer.y"
{
   char* temp = concat_strings("lda $\n",(yyvsp[0].nodo).code);


   (yyval.nodo).code = concat_strings((yyvsp[-2].nodo).code,temp);
   (yyval.nodo).count = (yyvsp[-2].nodo).count + 1;

   free(temp);
   free((yyvsp[0].nodo).code);
}
#line 2716 "y.tab.c"
    break;

  case 72: /* LISTA_ARGS_CALL: exp  */
#line 1041 "syntax_analyzer.y"
{
   (yyval.nodo).code = concat_strings("lda $\n",(yyvsp[0].nodo).code);
   (yyval.nodo).count = 1;

   free((yyvsp[0].nodo).code);

}
#line 2728 "y.tab.c"
    break;

  case 73: /* LISTA_ARGS_CALL: %empty  */
#line 1051 "syntax_analyzer.y"
{
   (yyval.nodo).code = strdup("");
   (yyval.nodo).count = 0;

}
#line 2738 "y.tab.c"
    break;

  case 74: /* NUM_LIKE: ID  */
#line 1060 "syntax_analyzer.y"
{

   if(!check_variable_existence((yyvsp[0].value),actual_scope)){
      char* error_string = malloc(100);
      sprintf(error_string,"Variable %s does not exists",(yyvsp[0].value));
      yyerror(error_string);
      YYABORT;
   }
   
   (yyval.nodo).code = (char*) malloc(60);
   sprintf((yyval.nodo).code,"lod %s\n",(yyvsp[0].value));
   free((yyvsp[0].value));
}
#line 2756 "y.tab.c"
    break;

  case 75: /* NUM_LIKE: NUMERO  */
#line 1075 "syntax_analyzer.y"
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
#line 2778 "y.tab.c"
    break;

  case 76: /* OP1: '+'  */
#line 1093 "syntax_analyzer.y"
         {(yyval.value) = (yyvsp[0].value);}
#line 2784 "y.tab.c"
    break;

  case 77: /* OP1: '-'  */
#line 1093 "syntax_analyzer.y"
                                  {(yyval.value) = (yyvsp[0].value);}
#line 2790 "y.tab.c"
    break;

  case 78: /* OP2: '*'  */
#line 1094 "syntax_analyzer.y"
         {(yyval.value) = (yyvsp[0].value);}
#line 2796 "y.tab.c"
    break;

  case 79: /* OP2: '/'  */
#line 1094 "syntax_analyzer.y"
                                 {(yyval.value) = (yyvsp[0].value);}
#line 2802 "y.tab.c"
    break;

  case 80: /* OP2: '%'  */
#line 1094 "syntax_analyzer.y"
                                                        {(yyval.value) = (yyvsp[0].value);}
#line 2808 "y.tab.c"
    break;


#line 2812 "y.tab.c"

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

#line 1096 "syntax_analyzer.y"





