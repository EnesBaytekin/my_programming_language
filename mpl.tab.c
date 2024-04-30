
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "mpl.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void list_add_item(list_node **head, data_type *data);
void list_insert_item(list_node **head, int index, data_type *data);
void list_delete_item(list_node **head, int index);
data_type *list_get_item(list_node *head, int index);
int list_get_length(list_node *head);
void list_print(list_node *head, int level);
list_node *list_copy(list_node *head);

data_type_pointers *var_values[MAX_VAR_COUNT];
char var_names[MAX_VAR_COUNT][MAX_VAR_NAME_LENGTH];
int var_count = 0;

void yyerror(char *error_message);
int yylex(void);

int get_index_of_var(char *var_name);
node_type *get_node_from_int(int value);
node_type *get_node_from_flt(float value);
node_type *get_node_from_chr(char value);
node_type *get_node_from_str(char *value);
node_type *get_node_from_lst();
node_type *get_node_from_var(int index);
node_type *get_node_from_opr(int operation, int operand_count, node_type *operand1, node_type *operand2, node_type *operand3, node_type *operand4);
void free_node(node_type *p);
data_type *ex(node_type *p);



/* Line 189 of yacc.c  */
#line 109 "mpl.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     CHR = 259,
     FLT = 260,
     STR = 261,
     VAR = 262,
     IF = 263,
     WHILE = 264,
     FOR = 265,
     PRINT = 266,
     TO_INT = 267,
     TO_FLT = 268,
     TO_CHR = 269,
     TO_STR = 270,
     TYPE = 271,
     LENGTH = 272,
     IFX = 273,
     ELSE = 274,
     GET_ITEM = 275,
     OR = 276,
     AND = 277,
     NOT = 278,
     LE = 279,
     GE = 280,
     NE = 281,
     EQ = 282,
     MINUS = 283
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 36 "mpl.y"

    int ival;
    float fval;
    char cval;
    char *sval;
    struct list_node_tag *lval;
    int index;
    node_type *node;



/* Line 214 of yacc.c  */
#line 185 "mpl.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 197 "mpl.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   392

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNRULES -- Number of states.  */
#define YYNSTATES  107

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    42,     2,     2,     2,     2,
      36,    37,    32,    30,     2,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    35,
      24,    38,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    26,
      27,    28,    29,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    14,    20,    26,
      31,    41,    47,    55,    59,    61,    64,    66,    68,    70,
      72,    74,    76,    81,    86,    91,    96,   101,   106,   111,
     114,   117,   121,   125,   129,   133,   137,   141,   145,   149,
     153,   157,   161,   165
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    47,    48,    -1,    -1,    35,
      -1,    50,    35,    -1,    11,    36,    50,    37,    35,    -1,
       9,    36,    50,    37,    48,    -1,     7,    38,    50,    35,
      -1,    10,    36,     7,    38,    50,    39,    50,    37,    48,
      -1,     8,    36,    50,    37,    48,    -1,     8,    36,    50,
      37,    48,    19,    48,    -1,    40,    49,    41,    -1,    48,
      -1,    49,    48,    -1,     3,    -1,     5,    -1,     4,    -1,
       6,    -1,     7,    -1,    42,    -1,     7,    43,    50,    44,
      -1,    12,    36,    50,    37,    -1,    13,    36,    50,    37,
      -1,    14,    36,    50,    37,    -1,    15,    36,    50,    37,
      -1,    16,    36,    50,    37,    -1,    17,    36,    50,    37,
      -1,    23,    50,    -1,    31,    50,    -1,    50,    21,    50,
      -1,    50,    22,    50,    -1,    50,    30,    50,    -1,    50,
      31,    50,    -1,    50,    32,    50,    -1,    50,    33,    50,
      -1,    50,    24,    50,    -1,    50,    25,    50,    -1,    50,
      29,    50,    -1,    50,    28,    50,    -1,    50,    27,    50,
      -1,    50,    26,    50,    -1,    36,    50,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    83,    84,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   100,   101,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CHR", "FLT", "STR", "VAR", "IF",
  "WHILE", "FOR", "PRINT", "TO_INT", "TO_FLT", "TO_CHR", "TO_STR", "TYPE",
  "LENGTH", "IFX", "ELSE", "GET_ITEM", "OR", "AND", "NOT", "'<'", "'>'",
  "LE", "GE", "NE", "EQ", "'+'", "'-'", "'*'", "'/'", "MINUS", "';'",
  "'('", "')'", "'='", "':'", "'{'", "'}'", "'#'", "'['", "']'", "$accept",
  "program", "function", "statement", "statement_list", "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    60,    62,   279,   280,   281,   282,
      43,    45,    42,    47,   283,    59,    40,    41,    61,    58,
     123,   125,    35,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     5,     5,     4,
       9,     5,     7,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    16,    18,    17,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,    21,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      29,    30,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    13,    15,    31,    32,    37,    38,    42,    41,    40,
      39,    33,    34,    35,    36,     9,    22,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    11,     8,     0,
       7,     0,     0,    12,     0,     0,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    25,    44,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -32
static const yytype_int16 yypact[] =
{
     -32,     6,    82,   -32,   -32,   -32,   -32,   -32,   -31,   -16,
     -15,   -14,   -12,   -11,     2,     3,    23,    26,    27,   122,
     122,   -32,   122,    82,   -32,   -32,   332,   122,   122,   122,
     122,    54,   122,   122,   122,   122,   122,   122,   122,    21,
     359,   -32,   178,   -32,    37,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   -32,   347,   141,
     192,   206,    31,   220,   234,   248,   262,   276,   290,   304,
     -32,   -32,   -32,   359,   359,    25,    25,    25,    25,    25,
      25,   -28,   -28,   -32,   -32,   -32,   -32,    82,    82,   122,
      30,   -32,   -32,   -32,   -32,   -32,   -32,    52,   -32,   162,
     -32,    82,   122,   -32,   318,    82,   -32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,   -21,   -32,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      40,    41,    43,    42,    55,    56,     3,    27,    58,    59,
      60,    61,    28,    63,    64,    65,    66,    67,    68,    69,
      29,    30,    31,    72,    32,    33,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    34,    35,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    53,    54,    55,    56,    36,
      19,    62,    37,    38,    28,   100,    97,    98,    20,    89,
      99,   101,    21,    22,     0,     0,     0,    23,    71,    24,
     103,     0,     0,   104,   106,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,    21,    22,     0,
       0,     0,    23,     0,    24,     4,     5,     6,     7,    39,
       0,     0,     0,     0,    13,    14,    15,    16,    17,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    22,     0,
       0,     0,    45,    46,    24,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    45,    46,    86,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,    45,
      46,   102,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,    45,    46,    70,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,    45,    46,    87,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,    45,    46,    88,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,    45,    46,    90,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,    45,
      46,    91,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,    45,    46,    92,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,    45,    46,    93,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,    45,    46,    94,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,    45,    46,    95,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,    45,
      46,    96,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,    45,    46,   105,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,    57,    45,    46,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,    85,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56
};

static const yytype_int8 yycheck[] =
{
      19,    20,    23,    22,    32,    33,     0,    38,    27,    28,
      29,    30,    43,    32,    33,    34,    35,    36,    37,    38,
      36,    36,    36,    44,    36,    36,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    36,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    30,    31,    32,    33,    36,
      23,     7,    36,    36,    43,    35,    87,    88,    31,    38,
      89,    19,    35,    36,    -1,    -1,    -1,    40,    41,    42,
     101,    -1,    -1,   102,   105,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    21,    22,    42,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    44,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    21,
      22,    39,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    21,    22,    37,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    21,    22,    37,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    21,    22,    37,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    21,    22,    37,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    21,
      22,    37,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    21,    22,    37,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    21,    22,    37,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    21,    22,    37,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    21,    22,    37,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    21,
      22,    37,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    21,    22,    37,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    23,
      31,    35,    36,    40,    42,    48,    50,    38,    43,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,     7,
      50,    50,    50,    48,    49,    21,    22,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    35,    50,    50,
      50,    50,     7,    50,    50,    50,    50,    50,    50,    50,
      37,    41,    48,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    35,    44,    37,    37,    38,
      37,    37,    37,    37,    37,    37,    37,    48,    48,    50,
      35,    19,    39,    48,    50,    37,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 79 "mpl.y"
    { printf("OK"); exit(0); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 83 "mpl.y"
    { free(ex((yyvsp[(2) - (2)].node))); free_node((yyvsp[(2) - (2)].node)); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 88 "mpl.y"
    { (yyval.node) = get_node_from_opr(';', 2, NULL, NULL, NULL, NULL); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 89 "mpl.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 90 "mpl.y"
    { (yyval.node) = get_node_from_opr(PRINT, 1, (yyvsp[(3) - (5)].node), NULL, NULL, NULL); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 91 "mpl.y"
    { (yyval.node) = get_node_from_opr(WHILE, 2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), NULL, NULL); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 92 "mpl.y"
    { (yyval.node) = get_node_from_opr('=', 2, get_node_from_var((yyvsp[(1) - (4)].index)), (yyvsp[(3) - (4)].node), NULL, NULL); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 93 "mpl.y"
    { (yyval.node) = get_node_from_opr(FOR, 4, get_node_from_var((yyvsp[(3) - (9)].index)), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 94 "mpl.y"
    { (yyval.node) = get_node_from_opr(IF, 2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), NULL, NULL); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 95 "mpl.y"
    { (yyval.node) = get_node_from_opr(IF, 3, (yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node), NULL); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 96 "mpl.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 100 "mpl.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 101 "mpl.y"
    { (yyval.node) = get_node_from_opr(';', 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL, NULL); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 105 "mpl.y"
    { (yyval.node) = get_node_from_int((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 106 "mpl.y"
    { (yyval.node) = get_node_from_flt((yyvsp[(1) - (1)].fval)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 107 "mpl.y"
    { (yyval.node) = get_node_from_chr((yyvsp[(1) - (1)].cval)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 108 "mpl.y"
    { (yyval.node) = get_node_from_str((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 109 "mpl.y"
    { (yyval.node) = get_node_from_var((yyvsp[(1) - (1)].index)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 110 "mpl.y"
    { (yyval.node) = get_node_from_lst(); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 111 "mpl.y"
    { (yyval.node) = get_node_from_opr(GET_ITEM, 2, get_node_from_var((yyvsp[(1) - (4)].index)), (yyvsp[(3) - (4)].node), NULL, NULL); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 112 "mpl.y"
    { (yyval.node) = get_node_from_opr(TO_INT, 1, (yyvsp[(3) - (4)].node), NULL, NULL, NULL); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 113 "mpl.y"
    { (yyval.node) = get_node_from_opr(TO_FLT, 1, (yyvsp[(3) - (4)].node), NULL, NULL, NULL); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 114 "mpl.y"
    { (yyval.node) = get_node_from_opr(TO_CHR, 1, (yyvsp[(3) - (4)].node), NULL, NULL, NULL); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 115 "mpl.y"
    { (yyval.node) = get_node_from_opr(TO_STR, 1, (yyvsp[(3) - (4)].node), NULL, NULL, NULL); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 116 "mpl.y"
    { (yyval.node) = get_node_from_opr(TYPE,   1, (yyvsp[(3) - (4)].node), NULL, NULL, NULL); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 117 "mpl.y"
    { (yyval.node) = get_node_from_opr(LENGTH, 1, (yyvsp[(3) - (4)].node), NULL, NULL, NULL); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 118 "mpl.y"
    { (yyval.node) = get_node_from_opr(NOT, 2, (yyvsp[(2) - (2)].node), NULL, NULL, NULL); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 119 "mpl.y"
    { (yyval.node) = get_node_from_opr(MINUS,  1, (yyvsp[(2) - (2)].node), NULL, NULL, NULL); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 120 "mpl.y"
    { (yyval.node) = get_node_from_opr(OR,  2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 121 "mpl.y"
    { (yyval.node) = get_node_from_opr(AND, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 122 "mpl.y"
    { (yyval.node) = get_node_from_opr('+', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 123 "mpl.y"
    { (yyval.node) = get_node_from_opr('-', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 124 "mpl.y"
    { (yyval.node) = get_node_from_opr('*', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 125 "mpl.y"
    { (yyval.node) = get_node_from_opr('/', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 126 "mpl.y"
    { (yyval.node) = get_node_from_opr('<', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 127 "mpl.y"
    { (yyval.node) = get_node_from_opr('>', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 128 "mpl.y"
    { (yyval.node) = get_node_from_opr(EQ,  2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 129 "mpl.y"
    { (yyval.node) = get_node_from_opr(NE,  2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 130 "mpl.y"
    { (yyval.node) = get_node_from_opr(GE,  2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 131 "mpl.y"
    { (yyval.node) = get_node_from_opr(LE,  2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 132 "mpl.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1812 "mpl.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 135 "mpl.y"


void yyerror(char *error_message) {
    fprintf(stderr, "%s", error_message);
    exit(1);
}

int main(void) {
    yyparse();
    return 0;
}

int get_index_of_var(char *var_name) {
    for (int i=0; i<MAX_VAR_COUNT; ++i) {
        if (i < var_count && strcmp(var_names[i], var_name) == 0)
            return i;
    }
    strcpy(var_names[var_count], var_name);
    var_count += 1;
    return var_count-1;
}

node_type *get_node_from_int(int value) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tINTEGER;
    p->int_node.value = value;
    return p;
}

node_type *get_node_from_flt(float value) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tFLOAT;
    p->flt_node.value = value;
    return p;
}

node_type *get_node_from_chr(char value) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tCHARACTER;
    p->chr_node.value = value;
    return p;
}

node_type *get_node_from_str(char *value) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tSTRING;
    char *new_str = (char *)malloc(sizeof(char)*(strlen(value)+1));
    if (new_str == NULL) yyerror("out of memory");
    new_str[0] = '\0';
    strcat(new_str, value);
    p->str_node.value = new_str;
    return p;
}

node_type *get_node_from_lst() {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tLIST;
        // list_node *new_list = (list_node *)malloc(sizeof(list_node));
        // if (new_list == NULL) yyerror("out of memory");
    list_node *new_list = NULL;
    p->lst_node.value = new_list;
    return p;
}

node_type *get_node_from_var(int index) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tVARIABLE;
    p->var_node.index = index;
    return p;
}

node_type *get_node_from_opr(int operation, int operand_count, node_type *operand1, node_type *operand2, node_type *operand3, node_type *operand4) {
    node_type *p = (node_type *)malloc(sizeof(node_type));
    if (p == NULL) yyerror("out of memory");
    p->type = tOPERATION;
    p->opr_node.operation = operation;
    p->opr_node.operand_count = operand_count;
    p->opr_node.operands = (node_type **)malloc(operand_count*sizeof(node_type *));
    if (operand_count >= 1) p->opr_node.operands[0] = operand1;
    if (operand_count >= 2) p->opr_node.operands[1] = operand2;
    if (operand_count >= 3) p->opr_node.operands[2] = operand3;
    if (operand_count >= 4) p->opr_node.operands[3] = operand4;
    return p;
}

void free_node(node_type *p) {
    if (p == NULL) return;
    if (p->type == tOPERATION) {
        for (int i=0; i<p->opr_node.operand_count; ++i) 
            free_node(p->opr_node.operands[i]);
        free(p->opr_node.operands);
    }
    free(p);
}

int is_number(char *text) {
    int is_a_number = 1;
    int digits_started = 0;
    int digits_finished = 0;
    for (int i=0; text[i] != '\0'; ++i) {
        if (48 <= text[i] && text[i] < 58) {
            digits_started = 1;
            if (digits_finished) is_a_number = 0;
        } else if (
            (text[i] == '\n') ||
            (text[i] == '\t') ||
            (text[i] == ' ')
            ) {
            if (digits_started) digits_finished = 1;
        } else {
            is_a_number = 0;
        }
    }
    return is_a_number;
}

int is_float(char *text) {
    int is_a_number = 1;
    int digits_started = 0;
    int digits_finished = 0;
    int dot_found = 0;
    for (int i=0; text[i] != '\0'; ++i) {
        if (text[i] == '.') {
            if (dot_found) is_a_number = 0;
            else dot_found = 1;
        } else if (48 <= text[i] && text[i] < 58) {
            digits_started = 1;
            if (digits_finished) is_a_number = 0;
        } else if (
            (text[i] == '\n') ||
            (text[i] == '\t') ||
            (text[i] == ' ')
            ) {
            if (digits_started) digits_finished = 1;
        } else {
            is_a_number = 0;
        }
    }
    return is_a_number;
}

data_type *ex(node_type *p) {
    data_type *new_data = (data_type *)malloc(sizeof(data_type));
    if (new_data == NULL) yyerror("out of memory");
    new_data->type = tNULL;
    new_data->ival = 0;
    if (p == NULL) return new_data;
    switch (p->type) {
        case tINTEGER: {
            new_data->type = tINTEGER;
            new_data->ival = p->int_node.value;
        } break;
        case tFLOAT: {
            new_data->type = tFLOAT;
            new_data->fval = p->flt_node.value;
        } break;
        case tCHARACTER: {
            new_data->type = tCHARACTER;
            new_data->cval = p->chr_node.value;
        } break;
        case tSTRING: {
            new_data->type = tSTRING;
            new_data->sval = p->str_node.value;
        } break;
        case tLIST: {
            new_data->type = tLIST;
            new_data->lval = p->lst_node.value;
        } break;
        case tVARIABLE: {
            data_type_pointers *var_data = var_values[p->var_node.index];
            new_data->type = var_data->type;
            if      (var_data->type == tINTEGER)   new_data->ival = *var_data->ival;
            else if (var_data->type == tFLOAT)     new_data->fval = *var_data->fval;
            else if (var_data->type == tCHARACTER) new_data->cval = *var_data->cval;
            else if (var_data->type == tLIST)      new_data->lval = *var_data->lval;
            else if (var_data->type == tSTRING)    new_data->sval = *var_data->sval;
        } break;
        case tOPERATION: {
            switch (p->opr_node.operation) {
                case IF: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if ( (data->type == tINTEGER   && data->ival    != 0) || 
                         (data->type == tFLOAT     && data->fval    != 0) || 
                         (data->type == tCHARACTER && data->cval    != 0) || 
                         (data->type == tSTRING    && data->sval[0] != 0) ) {
                        free(ex(p->opr_node.operands[1]));
                    } else if (p->opr_node.operand_count > 2) {
                        free(ex(p->opr_node.operands[2]));
                    }
                    free(data);
                } break;
                case WHILE: {
                    while (1) {
                        data_type *data = ex(p->opr_node.operands[0]);
                        if ( (data->type == tINTEGER   && data->ival    != 0) || 
                             (data->type == tCHARACTER && data->cval    != 0) || 
                             (data->type == tFLOAT     && data->fval    != 0) || 
                             (data->type == tSTRING    && data->sval[0] != 0) ) {
                            free(ex(p->opr_node.operands[1]));
                        } else {
                            free(data);
                            break;
                        }
                        free(data);
                    }
                } break;
                case FOR: {
                    data_type *data_from = ex(p->opr_node.operands[1]);
                    data_type *data_to   = ex(p->opr_node.operands[2]);
                    int do_for = 1;
                    int ifrom = 0;                    
                    int ito   = 0;
                    if (data_from->type == tINTEGER) ifrom = data_from->ival; else do_for = 0;
                    if (data_to->type   == tINTEGER) ito   = data_to->ival;   else do_for = 0;
                    if (ifrom >= ito) do_for = 0;
                    if (do_for) {
                        data_type_pointers *var_data = (data_type_pointers *)malloc(sizeof(data_type_pointers));
                        if (var_data == NULL) yyerror("out of memory");
                        var_data->type = tINTEGER;
                        var_data->ival = &ifrom;
                        free(var_values[p->opr_node.operands[0]->var_node.index]);
                        var_values[p->opr_node.operands[0]->var_node.index] = var_data;

                        while (ifrom < ito) {
                            free(ex(p->opr_node.operands[3]));
                            ifrom += 1;

                            var_data = (data_type_pointers *)malloc(sizeof(data_type_pointers));
                            if (var_data == NULL) yyerror("out of memory");
                            var_data->type = tINTEGER;
                            var_data->ival = &ifrom;
                            free(var_values[p->opr_node.operands[0]->var_node.index]);
                            var_values[p->opr_node.operands[0]->var_node.index] = var_data;
                        } 
                        var_data = (data_type_pointers *)malloc(sizeof(data_type_pointers));
                        if (var_data == NULL) yyerror("out of memory");
                        var_data->type = tINTEGER;
                        var_data->ival = &ifrom;
                        free(var_values[p->opr_node.operands[0]->var_node.index]);
                        var_values[p->opr_node.operands[0]->var_node.index] = var_data;
                    }
                    free(data_from);
                    free(data_to);
                } break;
                case PRINT: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if      (data->type == tINTEGER)   printf("%d\n", data->ival);
                    else if (data->type == tFLOAT)     printf("%f\n", data->fval);
                    else if (data->type == tCHARACTER) printf("%c\n", data->cval);
                    else if (data->type == tSTRING)    printf("%s\n", data->sval);
                    else if (data->type == tLIST)      list_print(data->lval, 0);
                    else if (data->type == tNULL)      printf("<NaT>\n");
                    free(data);
                } break;
                case TYPE: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    char *new_str = (char *)malloc(sizeof(char)*6);
                    if (new_str == NULL) yyerror("out of memory");
                    if      (data->type == tINTEGER)   sprintf(new_str, "<INT>");
                    else if (data->type == tCHARACTER) sprintf(new_str, "<CHR>");
                    else if (data->type == tFLOAT)     sprintf(new_str, "<FLT>");
                    else if (data->type == tSTRING)    sprintf(new_str, "<STR>");
                    else if (data->type == tLIST)      sprintf(new_str, "<LST>");
                    else if (data->type == tNULL)      sprintf(new_str, "<NaT>");
                    new_data->type = tSTRING;
                    new_data->sval = new_str;
                    free(data);
                } break;
                case TO_INT: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data->ival;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tINTEGER;
                        new_data->ival = (int)data->fval;
                    }
                    else if (data->type == tCHARACTER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data->cval;
                    }
                    else if (data->type == tSTRING) {
                        if (is_number(data->sval)) {
                            new_data->type = tINTEGER;
                            new_data->ival = atoi(data->sval);
                        }
                    }
                    free(data);
                } break;
                case TO_FLT: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data->ival;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data->fval;
                    }
                    else if (data->type == tCHARACTER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data->cval;
                    }
                    else if (data->type == tSTRING) {
                        if (is_float(data->sval)) {
                            new_data->type = tFLOAT;
                            new_data->fval = atof(data->sval);
                        }
                    }
                    free(data);
                } break;
                case TO_CHR: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tCHARACTER;
                        new_data->cval = data->ival;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tCHARACTER;
                        new_data->cval = (int)data->fval;
                    }
                    else if (data->type == tCHARACTER) {
                        new_data->type = tCHARACTER;
                        new_data->cval = data->cval;
                    }
                    else if (data->type == tSTRING) {
                        new_data->type = tCHARACTER;
                        new_data->cval = data->sval[0];
                    }
                    free(data);
                } break;
                case TO_STR: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tSTRING;

                        int digit_count = 0;
                        int number = data->ival;
                        while (number != 0) {
                            number /= 10;
                            digit_count += 1;
                        }

                        char *new_str = (char *)malloc(sizeof(char)*(digit_count+1));
                        if (new_str == NULL) yyerror("out of memory");
                        sprintf(new_str, "%d", data->ival);
                        new_data->sval = new_str;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tSTRING;

                        int digit_count = 0;
                        int number = (int)data->fval;
                        while (number != 0) {
                            number /= 10;
                            digit_count += 1;
                        }

                        char *new_str = (char *)malloc(sizeof(char)*(digit_count+8));
                        if (new_str == NULL) yyerror("out of memory");
                        sprintf(new_str, "%f", data->fval);
                        new_data->sval = new_str;
                    }
                    else if (data->type == tCHARACTER) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*2);
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = data->cval;
                        new_str[1] = '\0';
                        new_data->sval = new_str;
                    }
                    else if (data->type == tSTRING) {
                        new_data->type = tSTRING;
                        new_data->sval = data->sval;
                    }
                    free(data);
                } break;
                case ';': {
                    free(ex(p->opr_node.operands[0]));
                    data_type *data = ex(p->opr_node.operands[1]);
                    if      (data->type == tINTEGER)   new_data->ival == data->ival;
                    else if (data->type == tFLOAT)     new_data->fval == data->fval;
                    else if (data->type == tCHARACTER) new_data->cval == data->cval;
                    else if (data->type == tSTRING)    new_data->sval == data->sval;
                    free(data);
                } break;
                case '=': {
                    data_type *data = ex(p->opr_node.operands[1]);
                    data_type_pointers *var_data = (data_type_pointers *)malloc(sizeof(data_type_pointers));
                    if (var_data == NULL) yyerror("out of memory");
                    var_data->type = data->type;
                    if      (data->type == tINTEGER)   var_data->ival = &data->ival;
                    else if (data->type == tFLOAT)     var_data->fval = &data->fval;
                    else if (data->type == tCHARACTER) var_data->cval = &data->cval;
                    else if (data->type == tLIST)      *var_data->lval = data->lval;
                    else if (data->type == tSTRING)    *var_data->sval = data->sval;
                    free(var_values[p->opr_node.operands[0]->var_node.index]);
                    var_values[p->opr_node.operands[0]->var_node.index] = var_data;
                    // free(data);
                } break;
                case GET_ITEM: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tLIST && data2->type == tINTEGER) {
                        new_data = list_get_item(list_copy(data1->lval), data2->ival);
                    }
                    else if (data1->type == tSTRING && data2->type == tINTEGER) {
                        new_data->type = tCHARACTER;
                        new_data->cval = data1->sval[data2->ival];
                    }
                    free(data1);
                    free(data2);
                } break;
                case LENGTH: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tLIST) {
                        new_data->type = tINTEGER;
                        new_data->ival = list_get_length(data->lval);
                    } else if (data->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = strlen(data->sval);
                    }
                    free(data);
                } break;
                case MINUS: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = -data->ival;
                    } else if (data->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = -data->fval;
                    } else if (data->type == tSTRING) {
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data->sval)));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        strcat(new_str, data->sval+1);
                        new_data->type = tSTRING;
                        new_data->sval = new_str;
                    } else if (data->type == tLIST) {
                        list_node *new_list = list_copy(data->lval);
                        list_delete_item(&new_list, 0);
                        new_data->type = tLIST;
                        new_data->lval = new_list;
                    }
                    free(data);
                } break;
                case '+': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tLIST) {
                        list_node *new_list = list_copy(data1->lval);
                        list_add_item(&new_list, data2);
                        new_data->type = tLIST;
                        new_data->lval = new_list;
                    }
                    else if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival + data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival + data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval + data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval + data2->fval;
                    }
                    else if (data1->type == tSTRING && data2->type == tSTRING) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data1->sval)+strlen(data2->sval)+1));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        strcat(new_str, data1->sval);
                        strcat(new_str, data2->sval);
                        new_data->sval = new_str;
                    }
                    else if (data1->type == tSTRING && data2->type == tCHARACTER) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data1->sval)+2));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        strcat(new_str, data1->sval);
                        new_str[strlen(data1->sval)] = data2->cval;
                        new_str[strlen(data1->sval)+1] = '\0';
                        new_data->sval = new_str;
                    }
                    else if (data1->type == tCHARACTER && data2->type == tSTRING) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data2->sval)+2));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = data1->cval;
                        new_str[1] = '\0';
                        strcat(new_str, data2->sval);
                        new_str[strlen(data2->sval)+1] = '\0';
                        new_data->sval = new_str;
                    }
                    else if (data1->type == tCHARACTER && data2->type == tCHARACTER) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(3));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = data1->cval;
                        new_str[1] = data2->cval;
                        new_str[2] = '\0';
                        new_data->sval = new_str;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '-': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tLIST && data2->type == tINTEGER) {
                        list_node *new_list = list_copy(data1->lval);
                        list_delete_item(&new_list, data2->ival);
                        new_data->type = tLIST;
                        new_data->lval = new_list;
                    }
                    else if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival - data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival - data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval - data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval - data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '*': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival * data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival * data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval * data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval * data2->fval;
                    }
                    else if (data1->type == tSTRING && data2->type == tINTEGER) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data1->sval)*data2->ival+1));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        for (int i=0; i<data2->ival; ++i)
                            strcat(new_str, data1->sval);
                        new_data->sval = new_str;
                    }
                    else if (data1->type == tINTEGER && data2->type == tSTRING) {
                        new_data->type = tSTRING;
                        char *new_str = (char *)malloc(sizeof(char)*(strlen(data2->sval)*data1->ival+1));
                        if (new_str == NULL) yyerror("out of memory");
                        new_str[0] = '\0';
                        for (int i=0; i<data1->ival; ++i)
                            strcat(new_str, data2->sval);
                        new_data->sval = new_str;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '/': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival / data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival / data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval / data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval / data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '<': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival < data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival < data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval < data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval < data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case '>': {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival > data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival > data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval > data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval > data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case LE: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival <= data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival <= data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval <= data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval <= data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case GE: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival >= data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival >= data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval >= data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval >= data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case EQ: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival == data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival == data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval == data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval == data2->fval;
                    }
                    else if (data1->type == tCHARACTER && data2->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->cval == data2->cval;
                    }
                    else if (data1->type == tSTRING && data2->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = (strcmp(data1->sval, data2->sval) == 0);
                    }
                    free(data1);
                    free(data2);
                } break;
                case NE: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival != data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival != data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval != data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval != data2->fval;
                    }
                    else if (data1->type == tCHARACTER && data2->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->cval != data2->cval;
                    }
                    else if (data1->type == tSTRING && data2->type == tSTRING) {
                        new_data->type = tINTEGER;
                        new_data->ival = (strcmp(data1->sval, data2->sval) != 0);
                    }
                    free(data1);
                    free(data2);
                } break;
                case AND: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival && data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival && data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval && data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval && data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case OR: {
                    data_type *data1 = ex(p->opr_node.operands[0]);
                    data_type *data2 = ex(p->opr_node.operands[1]);
                    if (data1->type == tINTEGER && data2->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = data1->ival || data2->ival;
                    }
                    else if (data1->type == tINTEGER && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->ival || data2->fval;
                    }
                    else if (data1->type == tFLOAT && data2->type == tINTEGER) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval || data2->ival;
                    }
                    else if (data1->type == tFLOAT && data2->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = data1->fval || data2->fval;
                    }
                    free(data1);
                    free(data2);
                } break;
                case NOT: {
                    data_type *data = ex(p->opr_node.operands[0]);
                    if (data->type == tINTEGER) {
                        new_data->type = tINTEGER;
                        new_data->ival = !data->ival;
                    }
                    else if (data->type == tFLOAT) {
                        new_data->type = tFLOAT;
                        new_data->fval = !data->fval;
                    }
                    free(data);
                } break;
            }
        } break;
    }
    return new_data;
}


/************************
 *     LINKED LISTS     *
 ************************/


void list_add_item(list_node **head, data_type *data) {
    list_node *p = *head;
    list_node *pre = NULL;
    data_type *new_data = (data_type *)malloc(sizeof(data_type));
    new_data->type = data->type;
    new_data->ival = data->ival;
    list_node *new_node = (list_node *)malloc(sizeof(list_node));
    if (new_node == NULL) return;
    new_node->data = new_data;
    new_node->next = NULL;
    while (p != NULL) {
        pre = p;
        p = p->next;
    }
    if (pre == NULL)
        *head = new_node;
    else {
        pre->next = new_node;
    }
}

void list_insert_item(list_node **head, int index, data_type *data) {
    list_node *p = *head;
    list_node *pre = NULL;
    data_type *new_data = (data_type *)malloc(sizeof(data_type));
    new_data->type = data->type;
    new_data->ival = data->ival;
    list_node *new_node = (list_node *)malloc(sizeof(list_node));
    if (new_node == NULL) return;
    new_node->data = new_data;
    new_node->next = NULL;
    while (p != NULL && index > 0) {
        pre = p;
        p = p->next;
        index -= 1;
    }
    if (pre == NULL) {
        *head = new_node;
    }
    else {
        pre->next = new_node;
    }
    new_node->next = p;
}

void list_delete_item(list_node **head, int index) {
    list_node *p = *head;
    list_node *pre = NULL;
    if (p == NULL) return;
    while (p != NULL && index > 0) {
        pre = p;
        p = p->next;
        index -= 1;
    }
    if (pre == NULL)
        *head = p->next;
    else
        pre->next = p->next;
    free(p->data);
    free(p);
}

data_type *list_get_item(list_node *head, int index) {
    list_node *p = head;
    while (p != NULL && index > 0) {
        p = p->next;
        index -= 1;
    }
    return p->data;
}

int list_get_length(list_node *head) {
    list_node *p = head;
    int length = 0;
    while (p != NULL) {
        p = p->next;
        length += 1;
    }
    return length;
}

void list_print(list_node *head, int level) {
    char tabs[level*4+1];
    for (int i=0; i<level*4; ++i)
        tabs[i] = ' ';
    tabs[level*4] = '\0';

    list_node *p = head;
    printf("[\n", tabs);
    while (p != NULL) {
        if      (p->data->type == tINTEGER)   printf("    %s<INT> %d\n", tabs, p->data->ival);
        else if (p->data->type == tFLOAT)     printf("    %s<FLT> %f\n", tabs, p->data->fval);
        else if (p->data->type == tCHARACTER) printf("    %s<CHR> '%c'\n", tabs, p->data->cval);
        else if (p->data->type == tSTRING)    printf("    %s<STR> \"%s\"\n", tabs, p->data->sval);
        else if (p->data->type == tLIST)      {
                                                printf("    %s<LST> ", tabs);
                                                list_print(p->data->lval, level+1);
                                              }
        else if (p->data->type == tNULL)      printf("    %s<NaT>\n", tabs);
        p = p->next;
    }
    printf("%s]\n", tabs);
}

list_node *list_copy(list_node *head) {
    if (head == NULL)
        return NULL;

    list_node *new_node = (list_node *)malloc(sizeof(list_node));
    if (new_node == NULL) yyerror("out of memory");

    data_type *item = (data_type *)malloc(sizeof(data_type));
    if (item == NULL) yyerror("out of memory");
    item->type = head->data->type;
    if      (head->data->type == tINTEGER)   item->ival = head->data->ival;
    else if (head->data->type == tFLOAT)     item->fval = head->data->fval;
    else if (head->data->type == tCHARACTER) item->cval = head->data->cval;
    else if (head->data->type == tSTRING)    item->sval = head->data->sval;
    else if (head->data->type == tLIST)      item->lval = head->data->lval;
    
    new_node->data = item;
    new_node->next = list_copy(head->next);

    return new_node;
}

