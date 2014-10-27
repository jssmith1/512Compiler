/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 13 "decaf.y" /* yacc.c:339  */


#include <cstdlib>
#include <cstdio>
#define YYDEBUG 1
int yylex();
int yyerror(const char * s);


#line 76 "decaf.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "decaf.tab.h".  */
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
#line 41 "decaf.y" /* yacc.c:355  */
 
 int iVal; /* integer value */ 
 char * sVal; /* string value*/ 
 
 //nodeType *nPtr; /* node pointer */ 

#line 177 "decaf.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 206 "decaf.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    55,    56,    60,    61,    65,    69,    70,
      74,    75,    76,    80,    84,    88,    92,    93,    97,    98,
      99,   100,   104,   105,   109,   110,   114,   118,   119,   120,
     124,   125,   126,   127,   131,   132,   136,   137,   141,   142,
     146,   150,   151,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   189,   190,   191,   195,   196,   200,   201,   205,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   221,
     222,   226,   227,   231,   232,   233,   234,   235,   239,   240,
     244,   245
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BREAK", "CLASS", "CONTINUE", "ELSE",
  "EXTENDS", "IF", "NEW", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN",
  "STATIC", "SUPER", "THIS", "WHILE", "BOOLEAN", "CHAR", "INT", "VOID",
  "DECAF_NULL", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "SEMICOLON", "COMMA", "PERIOD", "ASSIGN", "GREATER", "LESS",
  "NOT", "EQ", "GEQ", "LEQ", "NEQ", "PLUS", "MINUS", "MUL", "DIV", "AND",
  "OR", "MOD", "IDENTIFIER", "CHARACTER", "STRING", "BOOLEAN_LITERAL",
  "INTEGER", "UMINUS", "UPLUS", "$accept", "Start", "Classes", "Class",
  "Super", "Members", "Member", "Field", "Method", "Ctor", "Modifiers",
  "Modifier", "FormalArgs", "FormalArgList", "FormalArg", "Type",
  "PrimitiveType", "VarDeclaratorList", "VarDeclarator", "VarDeclaratorId",
  "Block", "Statements", "Statement", "Expression", "Primary",
  "NewArrayExpr", "Dimensions", "Dimension", "NonNewArrayExpr",
  "FieldExpr", "ArrayExpr", "Literal", "ActualArgs", "ExprList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-29)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,   -17,    37,    16,  -137,    11,  -137,  -137,    -8,  -137,
      80,  -137,    91,  -137,  -137,  -137,  -137,  -137,  -137,    -9,
      98,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,    25,
    -137,   -21,  -137,  -137,     4,    84,    70,    25,    53,  -137,
      41,  -137,  -137,    22,  -137,   -20,  -137,  -137,  -137,    84,
    -137,    66,    99,   207,  -137,    23,  -137,   105,    71,  -137,
    -137,  -137,    83,    95,  -137,  -137,   207,   207,   207,   207,
      72,  -137,  -137,  -137,  -137,   320,   100,  -137,   117,  -137,
    -137,  -137,  -137,   119,   122,   130,   143,   131,  -137,  -137,
      87,   -20,  -137,  -137,   287,    72,   117,   109,   227,  -137,
    -137,  -137,   164,   207,  -137,  -137,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     110,  -137,  -137,  -137,   207,  -137,   305,   138,    78,  -137,
     117,  -137,  -137,   117,   140,  -137,  -137,   320,   186,   269,
     320,   403,   198,   370,   392,   381,   359,   104,    35,  -137,
     132,   348,   334,    73,   140,   250,  -137,   120,  -137,  -137,
    -137,  -137,   320,  -137,  -137,   120,  -137,   158,   120,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     0,     8,
       0,     7,    16,     8,     6,     9,    10,    11,    12,     0,
      16,    20,    21,    19,    18,    30,    31,    32,    33,    28,
      17,     0,    27,     5,     0,     0,     0,    38,     0,    34,
      36,    23,    28,     0,    24,     0,    41,    15,    29,     0,
      13,     0,     0,     0,    22,     0,    38,    26,     0,    14,
      35,    39,     0,     0,    81,    93,     0,     0,     0,     0,
      74,    96,    97,    94,    95,    37,    71,    72,    73,    88,
      87,    80,    25,     0,     0,     0,     0,     0,    40,    43,
      74,     0,    53,    42,     0,     0,     0,     0,     0,    70,
      68,    69,     0,     0,    91,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    52,    51,     0,    50,     0,     0,     0,    47,
      75,    77,    83,    76,    90,    82,    99,   100,     0,     0,
      54,    60,    59,    57,    62,    61,    58,    63,    64,    65,
      66,    56,    55,    67,    89,     0,    49,     0,    44,    78,
      86,    98,   101,    79,    85,     0,    48,    45,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,   172,  -137,   163,  -137,  -137,  -137,  -137,
    -137,  -137,   144,  -137,   127,   -15,   115,    94,   145,   152,
      -4,  -137,  -136,   -53,  -137,  -137,    93,   -61,  -137,  -137,
    -137,  -137,   -87,  -137
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    12,    15,    16,    17,    18,
      19,    30,    35,    43,    44,    91,    32,    38,    39,    40,
      92,    58,    93,    94,    76,    77,   130,   104,    78,    79,
      80,    81,   105,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    21,    22,    23,    31,    24,    36,    36,   132,    25,
      26,    27,    28,    98,    99,   100,   101,   121,     8,    45,
       1,   166,    25,    26,    27,    28,    37,    56,    41,   167,
       5,    47,   169,   126,   131,   131,     9,     6,    29,    11,
      45,    25,    26,    27,    28,    59,    54,   160,    34,   137,
     139,    42,    55,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   164,    52,   159,
      42,   155,   159,    53,    83,   113,    84,   115,   116,    85,
      62,   119,    50,    51,    86,   162,    63,    64,    87,    25,
      26,    27,    28,    65,    66,   102,    46,    88,    48,   103,
      89,    25,    26,    27,    28,    13,    67,   158,    51,    46,
     102,    68,    69,    56,   103,   115,   116,    14,    90,    71,
      72,    73,    74,    83,    33,    84,    97,    61,    85,    62,
      95,   120,    52,    86,   -28,    63,    64,    87,    25,    26,
      27,    28,    65,    66,   103,    46,   115,   116,   122,    89,
     119,   123,    62,   124,   127,    67,   134,   154,    63,    64,
      68,    69,   157,   102,   168,    65,    66,    90,    71,    72,
      73,    74,   125,    62,   115,     7,    20,    96,    67,    63,
      64,    49,    82,    68,    69,   128,    65,    66,   136,   133,
      70,    71,    72,    73,    74,    62,    60,    57,     0,    67,
       0,    63,    64,     0,    68,    69,     0,     0,    65,    66,
     161,    70,    71,    72,    73,    74,    62,     0,     0,     0,
       0,    67,    63,    64,     0,     0,    68,    69,     0,    65,
      66,   107,   -29,    70,    71,    72,    73,    74,   113,   114,
     115,   116,    67,     0,   119,     0,     0,    68,    69,     0,
       0,   135,     0,     0,    70,    71,    72,    73,    74,   106,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   165,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   163,     0,     0,
       0,   106,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   129,     0,     0,   106,
     107,   108,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   156,     0,     0,   106,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   106,   107,   108,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   107,   108,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     119,   107,   108,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   107,   108,   119,   109,   110,   111,     0,   113,
     114,   115,   116,   107,   108,   119,     0,   110,   111,     0,
     113,   114,   115,   116,   107,   108,   119,     0,   110,   -29,
       0,   113,   114,   115,   116,   107,   108,   119,     0,   -29,
       0,     0,   113,   114,   115,   116,   -29,     0,   119,     0,
       0,     0,     0,   113,   114,   115,   116,     0,     0,   119
};

static const yytype_int16 yycheck[] =
{
      53,    10,    11,    12,    19,    14,    27,    27,    95,    18,
      19,    20,    21,    66,    67,    68,    69,    78,     7,    34,
       4,   157,    18,    19,    20,    21,    47,    47,    24,   165,
      47,    35,   168,    86,    95,    96,    25,     0,    47,    47,
      55,    18,    19,    20,    21,    49,    24,   134,    23,   102,
     103,    47,    30,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   154,    27,   130,
      47,   124,   133,    32,     3,    40,     5,    42,    43,     8,
       9,    46,    29,    30,    13,   138,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    23,    25,    26,    28,    27,
      29,    18,    19,    20,    21,    25,    35,    29,    30,    25,
      23,    40,    41,    47,    27,    42,    43,    26,    47,    48,
      49,    50,    51,     3,    26,     5,    31,    28,     8,     9,
      47,    31,    27,    13,    47,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    27,    25,    42,    43,    29,    29,
      46,    29,     9,    23,    23,    35,    47,    47,    15,    16,
      40,    41,    24,    23,     6,    22,    23,    47,    48,    49,
      50,    51,    29,     9,    42,     3,    13,    62,    35,    15,
      16,    37,    55,    40,    41,    91,    22,    23,    24,    96,
      47,    48,    49,    50,    51,     9,    51,    45,    -1,    35,
      -1,    15,    16,    -1,    40,    41,    -1,    -1,    22,    23,
      24,    47,    48,    49,    50,    51,     9,    -1,    -1,    -1,
      -1,    35,    15,    16,    -1,    -1,    40,    41,    -1,    22,
      23,    33,    34,    47,    48,    49,    50,    51,    40,    41,
      42,    43,    35,    -1,    46,    -1,    -1,    40,    41,    -1,
      -1,    24,    -1,    -1,    47,    48,    49,    50,    51,    32,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    28,    -1,    -1,
      -1,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    29,    -1,    -1,    32,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    29,    -1,    -1,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    33,    34,    46,    36,    37,    38,    -1,    40,
      41,    42,    43,    33,    34,    46,    -1,    37,    38,    -1,
      40,    41,    42,    43,    33,    34,    46,    -1,    37,    38,
      -1,    40,    41,    42,    43,    33,    34,    46,    -1,    37,
      -1,    -1,    40,    41,    42,    43,    33,    -1,    46,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    -1,    -1,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    55,    56,    57,    47,     0,    57,     7,    25,
      58,    47,    59,    25,    26,    60,    61,    62,    63,    64,
      59,    10,    11,    12,    14,    18,    19,    20,    21,    47,
      65,    69,    70,    26,    23,    66,    27,    47,    71,    72,
      73,    24,    47,    67,    68,    69,    25,    74,    28,    66,
      29,    30,    27,    32,    24,    30,    47,    73,    75,    74,
      72,    28,     9,    15,    16,    22,    23,    35,    40,    41,
      47,    48,    49,    50,    51,    77,    78,    79,    82,    83,
      84,    85,    68,     3,     5,     8,    13,    17,    26,    29,
      47,    69,    74,    76,    77,    47,    70,    31,    77,    77,
      77,    77,    23,    27,    81,    86,    32,    33,    34,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      31,    81,    29,    29,    23,    29,    77,    23,    71,    29,
      80,    81,    86,    80,    47,    24,    24,    77,    87,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    47,    77,    29,    24,    29,    81,
      86,    24,    77,    28,    86,    24,    76,    76,     6,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    60,    60,    61,    62,    63,    64,    64,    65,    65,
      65,    65,    66,    66,    67,    67,    68,    69,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    79,    79,    80,    80,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     5,     2,     0,     2,
       1,     1,     1,     4,     5,     4,     0,     2,     1,     1,
       1,     1,     3,     2,     1,     3,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       3,     0,     2,     1,     3,     5,     7,     2,     4,     3,
       2,     2,     2,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     1,     1,     1,     1,     3,     3,     1,     2,     3,
       1,     1,     3,     3,     2,     4,     4,     1,     1,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     3,     2,
       1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 51 "decaf.y" /* yacc.c:1646  */
    {}
#line 1560 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "decaf.y" /* yacc.c:1646  */
    {}
#line 1566 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "decaf.y" /* yacc.c:1646  */
    {}
#line 1572 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 60 "decaf.y" /* yacc.c:1646  */
    {}
#line 1578 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 61 "decaf.y" /* yacc.c:1646  */
    {}
#line 1584 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 65 "decaf.y" /* yacc.c:1646  */
    {}
#line 1590 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 69 "decaf.y" /* yacc.c:1646  */
    {}
#line 1596 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 70 "decaf.y" /* yacc.c:1646  */
    {}
#line 1602 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 74 "decaf.y" /* yacc.c:1646  */
    {}
#line 1608 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 75 "decaf.y" /* yacc.c:1646  */
    {}
#line 1614 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 76 "decaf.y" /* yacc.c:1646  */
    {}
#line 1620 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 80 "decaf.y" /* yacc.c:1646  */
    {}
#line 1626 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 84 "decaf.y" /* yacc.c:1646  */
    {}
#line 1632 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "decaf.y" /* yacc.c:1646  */
    {}
#line 1638 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 92 "decaf.y" /* yacc.c:1646  */
    {}
#line 1644 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 97 "decaf.y" /* yacc.c:1646  */
    {}
#line 1650 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "decaf.y" /* yacc.c:1646  */
    {}
#line 1656 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 99 "decaf.y" /* yacc.c:1646  */
    {}
#line 1662 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "decaf.y" /* yacc.c:1646  */
    {}
#line 1668 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 104 "decaf.y" /* yacc.c:1646  */
    {}
#line 1674 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 105 "decaf.y" /* yacc.c:1646  */
    {}
#line 1680 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 109 "decaf.y" /* yacc.c:1646  */
    {}
#line 1686 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "decaf.y" /* yacc.c:1646  */
    {}
#line 1692 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 114 "decaf.y" /* yacc.c:1646  */
    {}
#line 1698 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 118 "decaf.y" /* yacc.c:1646  */
    {}
#line 1704 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 119 "decaf.y" /* yacc.c:1646  */
    {}
#line 1710 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 120 "decaf.y" /* yacc.c:1646  */
    {}
#line 1716 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 124 "decaf.y" /* yacc.c:1646  */
    {}
#line 1722 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 125 "decaf.y" /* yacc.c:1646  */
    {}
#line 1728 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 126 "decaf.y" /* yacc.c:1646  */
    {}
#line 1734 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 127 "decaf.y" /* yacc.c:1646  */
    {}
#line 1740 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 131 "decaf.y" /* yacc.c:1646  */
    {}
#line 1746 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 132 "decaf.y" /* yacc.c:1646  */
    {}
#line 1752 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 136 "decaf.y" /* yacc.c:1646  */
    {}
#line 1758 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 141 "decaf.y" /* yacc.c:1646  */
    {}
#line 1764 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 146 "decaf.y" /* yacc.c:1646  */
    {}
#line 1770 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 150 "decaf.y" /* yacc.c:1646  */
    {}
#line 1776 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 151 "decaf.y" /* yacc.c:1646  */
    {}
#line 1782 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 154 "decaf.y" /* yacc.c:1646  */
    {}
#line 1788 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 155 "decaf.y" /* yacc.c:1646  */
    {}
#line 1794 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 156 "decaf.y" /* yacc.c:1646  */
    {}
#line 1800 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 157 "decaf.y" /* yacc.c:1646  */
    {}
#line 1806 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 158 "decaf.y" /* yacc.c:1646  */
    {}
#line 1812 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 159 "decaf.y" /* yacc.c:1646  */
    {}
#line 1818 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 160 "decaf.y" /* yacc.c:1646  */
    {}
#line 1824 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 161 "decaf.y" /* yacc.c:1646  */
    {}
#line 1830 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 162 "decaf.y" /* yacc.c:1646  */
    {}
#line 1836 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 163 "decaf.y" /* yacc.c:1646  */
    {}
#line 1842 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 164 "decaf.y" /* yacc.c:1646  */
    {}
#line 1848 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 168 "decaf.y" /* yacc.c:1646  */
    {}
#line 1854 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 169 "decaf.y" /* yacc.c:1646  */
    {}
#line 1860 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 170 "decaf.y" /* yacc.c:1646  */
    {}
#line 1866 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 171 "decaf.y" /* yacc.c:1646  */
    {}
#line 1872 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 172 "decaf.y" /* yacc.c:1646  */
    {}
#line 1878 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 173 "decaf.y" /* yacc.c:1646  */
    {}
#line 1884 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 174 "decaf.y" /* yacc.c:1646  */
    {}
#line 1890 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 175 "decaf.y" /* yacc.c:1646  */
    {}
#line 1896 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 176 "decaf.y" /* yacc.c:1646  */
    {}
#line 1902 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 177 "decaf.y" /* yacc.c:1646  */
    {}
#line 1908 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 178 "decaf.y" /* yacc.c:1646  */
    {}
#line 1914 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 179 "decaf.y" /* yacc.c:1646  */
    {}
#line 1920 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 180 "decaf.y" /* yacc.c:1646  */
    {}
#line 1926 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 181 "decaf.y" /* yacc.c:1646  */
    {}
#line 1932 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 182 "decaf.y" /* yacc.c:1646  */
    {}
#line 1938 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 183 "decaf.y" /* yacc.c:1646  */
    {}
#line 1944 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 184 "decaf.y" /* yacc.c:1646  */
    {}
#line 1950 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 185 "decaf.y" /* yacc.c:1646  */
    {}
#line 1956 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 189 "decaf.y" /* yacc.c:1646  */
    {}
#line 1962 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 190 "decaf.y" /* yacc.c:1646  */
    {}
#line 1968 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 191 "decaf.y" /* yacc.c:1646  */
    {}
#line 1974 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 195 "decaf.y" /* yacc.c:1646  */
    {}
#line 1980 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 196 "decaf.y" /* yacc.c:1646  */
    {}
#line 1986 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 200 "decaf.y" /* yacc.c:1646  */
    {}
#line 1992 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 201 "decaf.y" /* yacc.c:1646  */
    {}
#line 1998 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 205 "decaf.y" /* yacc.c:1646  */
    {}
#line 2004 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 209 "decaf.y" /* yacc.c:1646  */
    {}
#line 2010 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 210 "decaf.y" /* yacc.c:1646  */
    {}
#line 2016 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 211 "decaf.y" /* yacc.c:1646  */
    {}
#line 2022 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 212 "decaf.y" /* yacc.c:1646  */
    {}
#line 2028 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 213 "decaf.y" /* yacc.c:1646  */
    {}
#line 2034 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 214 "decaf.y" /* yacc.c:1646  */
    {}
#line 2040 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 215 "decaf.y" /* yacc.c:1646  */
    {}
#line 2046 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 216 "decaf.y" /* yacc.c:1646  */
    {}
#line 2052 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 217 "decaf.y" /* yacc.c:1646  */
    {}
#line 2058 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 221 "decaf.y" /* yacc.c:1646  */
    {}
#line 2064 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 222 "decaf.y" /* yacc.c:1646  */
    {}
#line 2070 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 226 "decaf.y" /* yacc.c:1646  */
    {}
#line 2076 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 227 "decaf.y" /* yacc.c:1646  */
    {}
#line 2082 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 231 "decaf.y" /* yacc.c:1646  */
    {}
#line 2088 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 232 "decaf.y" /* yacc.c:1646  */
    {}
#line 2094 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 233 "decaf.y" /* yacc.c:1646  */
    {}
#line 2100 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 234 "decaf.y" /* yacc.c:1646  */
    {}
#line 2106 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 235 "decaf.y" /* yacc.c:1646  */
    {}
#line 2112 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 239 "decaf.y" /* yacc.c:1646  */
    {}
#line 2118 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 240 "decaf.y" /* yacc.c:1646  */
    {}
#line 2124 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 244 "decaf.y" /* yacc.c:1646  */
    {}
#line 2130 "decaf.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 245 "decaf.y" /* yacc.c:1646  */
    {}
#line 2136 "decaf.tab.c" /* yacc.c:1646  */
    break;


#line 2140 "decaf.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 247 "decaf.y" /* yacc.c:1906  */

const char * const* token_table = yytname;

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
