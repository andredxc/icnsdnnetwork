/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         pfl_parse
#define yylex           pfl_lex
#define yyerror         pfl_error
#define yydebug         pfl_debug
#define yynerrs         pfl_nerrs


/* Copy the first part of user declarations.  */
#line 8 "gramm.y" /* yacc.c:339  */



//#define YYDEBUG 1

/*
hack to overcome the  "warning C4273: 'malloc' : inconsistent dll linkage" in visual studio when linking the dll C runtime
*/
#ifdef WIN32
  #define YYMALLOC malloc
  #define YYFREE free
#endif

#include <stdlib.h>
#include "defs.h"
#include "compile.h"
#include "utils.h"
#include "pflexpression.h"
#include "tree.h"
#include "symbols.h"
#include "typecheck.h"
#include "../nbee/globals/utils.h"
#include <limits.h>




#line 100 "parser.cpp" /* yacc.c:339  */

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
   by #include "parser.hpp".  */
#ifndef YY_PFL_PARSER_HPP_INCLUDED
# define YY_PFL_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int pfl_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PFL_RETURN_PACKET = 258,
    PFL_EXTRACT_FIELDS = 259,
    PFL_ON = 260,
    PFL_PORT = 261,
    PFL_NUMBER = 262,
    PFL_HEXNUMBER = 263,
    PFL_PROTOCOL = 264,
    PFL_PROTOFIELD = 265,
    PFL_PROTOCOL_INDEX = 266,
    PFL_PROTOFIELD_INDEX = 267,
    PFL_PROTOMULTIFIELD_INDEX = 268,
    PFL_MULTIPROTOFIELD = 269,
    PFL_PROTOMULTIFIELD = 270,
    PFL_IPV4ADDR = 271,
    PFL_IPV6ADDR = 272,
    PFL_MACADDR = 273,
    PFL_ADD = 274,
    PFL_ADDADD = 275,
    PFL_SUB = 276,
    PFL_MULMUL = 277,
    PFL_BWAND = 278,
    PFL_BWOR = 279,
    PFL_BWXOR = 280,
    PFL_BWNOT = 281,
    PFL_SHL = 282,
    PFL_SHR = 283,
    PFL_AND = 284,
    PFL_OR = 285,
    PFL_NOT = 286,
    PFL_EQ = 287,
    PFL_NE = 288,
    PFL_LT = 289,
    PFL_LE = 290,
    PFL_GT = 291,
    PFL_GE = 292,
    PFL_MATCHES = 293,
    PFL_CONTAINS = 294,
    PFL_SENSITIVE = 295,
    PFL_STRING = 296,
    PFL_IN = 297,
    PFL_NOTIN = 298,
    PFL_QUESTION = 299,
    PFL_ANY = 300,
    PFL_TUNNELED = 301,
    PFL_FULLENCAP = 302,
    PFL_NOSESSION = 303,
    PFL_NOACK = 304,
    PFL_MUL = 305,
    PFL_MUOLMUL = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "gramm.y" /* yacc.c:355  */

    FieldsList_t    			*FieldsList;
    SymbolField					*Field;
    PFLStatement    			*stmt;
    PFLAction       			*act;
    PFLExpression				*exp;
    uint32						index;
    Node						*IRExp;
    char						id[ID_LEN];
    uint32						number;	
    bool						flag;
    PFLRepeatOperator   		repOp;
    PFLSetExpression*			setExp;     
    list<PFLSetExpression*>* 	setExpList;  
    list<PFLExpression*>*   	expList; 

#line 209 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
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



int pfl_parse (struct ParserInfo *parserInfo);

#endif /* !YY_PFL_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 63 "gramm.y" /* yacc.c:358  */


//NOTE: these declarations are duplicated in scanner.l, so if you modify them here you need to do the same in the other file
int pfl_lex (YYSTYPE *lvalp, YYLTYPE *llocp, struct ParserInfo *parserInfo);
int pfl_error(YYLTYPE *llocp, struct ParserInfo *parserInfo, const char *s);

PFLExpression *GenUnOpNode(PFLOperator op, PFLExpression *kid);
PFLExpression *GenBinOpNode(PFLOperator op, PFLExpression *kid1, PFLExpression *kid2);
PFLExpression *GenTermNode(SymbolProto *protocol, Node *irExpr);
PFLExpression *MergeNotInTermNode(ParserInfo *parserInfo, PFLExpression *node1);
PFLExpression *MergeTermNodes(ParserInfo *parserInfo, HIROpcodes op, PFLExpression *node1, PFLExpression *node2);
PFLExpression *ManagePFLProtoField(char *protoName, ParserInfo *parserInfo, YYLTYPE *llocp);

PFLExpression *GenProtoBytesRef(YYLTYPE *llocp, ParserInfo *parserInfo, char *protocol, uint32 offs, uint32 len);
PFLExpression *GenNumber(struct ParserInfo *parserInfo, uint32 value);
PFLExpression *GenString(struct ParserInfo *parserInfo, string value);	
bool CheckOperandTypes(ParserInfo *parserInfo, PFLExpression *expr);
SymbolField *CheckField(ParserInfo *parserInfo, char * protoName, YYLTYPE *llocp, uint32 headerIndex = 0);

set<pair<SymbolProto*,uint32> > protocolsForExtraction;

#define STORE_EXP_TEXT(e, fc, fl, lc, ll)	do{\
							string tmp_s;\
							tmp_s.assign(parserInfo->FilterString, fc, lc - fc);\
							e->SetExprText(tmp_s);\
						}while(0)

#define PFL_ERROR(l, pi, s) do{ pfl_error(l, pi, s); YYERROR; }while(0)

#line 268 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      52,    53,     2,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   196,   196,   214,   227,   243,   246,   253,   254,   260,
     269,   276,   286,   305,   325,   355,   395,   444,   453,   458,
     490,   508,   541,   575,   578,   584,   593,   600,   614,   619,
     624,   635,   636,   648,   659,   683,   710,   716,   720,   726,
     733,   742,   746,   750,   756,   757,   771,   772,   786,   793,
     812,   823,   827,   828,   853,   854,   877,   878,   882,   885,
     892,   895,   903,   906,   911,   976,  1037,  1051,  1066,  1081,
    1096,  1111,  1129,  1137,  1219,  1236,  1267,  1268,  1285,  1300,
    1315,  1323,  1330,  1331,  1346,  1364,  1365,  1380,  1398,  1399,
    1416,  1423,  1433,  1444,  1495,  1558,  1567,  1579,  1590
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PFL_RETURN_PACKET",
  "PFL_EXTRACT_FIELDS", "PFL_ON", "PFL_PORT", "PFL_NUMBER",
  "PFL_HEXNUMBER", "PFL_PROTOCOL", "PFL_PROTOFIELD", "PFL_PROTOCOL_INDEX",
  "PFL_PROTOFIELD_INDEX", "PFL_PROTOMULTIFIELD_INDEX",
  "PFL_MULTIPROTOFIELD", "PFL_PROTOMULTIFIELD", "PFL_IPV4ADDR",
  "PFL_IPV6ADDR", "PFL_MACADDR", "PFL_ADD", "PFL_ADDADD", "PFL_SUB",
  "PFL_MULMUL", "PFL_BWAND", "PFL_BWOR", "PFL_BWXOR", "PFL_BWNOT",
  "PFL_SHL", "PFL_SHR", "PFL_AND", "PFL_OR", "PFL_NOT", "PFL_EQ", "PFL_NE",
  "PFL_LT", "PFL_LE", "PFL_GT", "PFL_GE", "PFL_MATCHES", "PFL_CONTAINS",
  "PFL_SENSITIVE", "PFL_STRING", "PFL_IN", "PFL_NOTIN", "PFL_QUESTION",
  "PFL_ANY", "PFL_TUNNELED", "PFL_FULLENCAP", "PFL_NOSESSION", "PFL_NOACK",
  "PFL_MUL", "PFL_MUOLMUL", "'('", "')'", "','", "'{'", "'}'", "'['",
  "']'", "':'", "$accept", "Statement", "FullEncap", "Action",
  "ExtractFields", "FieldsList", "FieldsListItem", "ReturnPkt",
  "UnaryExpression", "Tunnel", "InExpression", "NotInExpression",
  "ProtoOrAny", "Proto", "ProtocolOrSet", "SetOfProtocol", "ElementOfSet",
  "Repeater", "SetOrExpression", "SetAndExpression", "SetUnaryExpression",
  "BoolExpression", "OrExpression", "AndExpression", "BoolOperand",
  "FlagNosession", "FlagNoack", "sensitive", "RelExpression",
  "ProtoFieldOrProtofieldIndex", "Protocol", "BitwiseExpression",
  "ShiftExpression", "AddExpression", "MulExpression", "Term",
  "GenericNumber", YY_NULLPTR
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
     305,   306,    40,    41,    44,   123,   125,    91,    93,    58
};
# endif

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      72,  -111,  -111,   -46,    19,  -111,    22,  -111,  -111,   125,
      84,  -111,    84,    26,   109,  -111,   -10,    33,    44,    40,
    -111,    79,  -111,   165,    -6,   100,    67,  -111,  -111,   131,
     -46,  -111,  -111,    -6,  -111,    46,   150,  -111,    92,    49,
    -111,  -111,  -111,   109,    84,    84,  -111,    57,    81,    87,
     125,   125,   125,   153,   153,   153,   153,   153,   153,   125,
     125,   125,   125,   125,    96,  -111,  -111,   134,    94,  -111,
      44,  -111,  -111,    82,   102,   102,    -6,    -6,    -6,   153,
      18,    18,    18,    18,    18,    18,   100,   100,    67,    67,
      67,  -111,   131,   131,  -111,  -111,  -111,  -111,  -111,   123,
    -111,  -111,   138,  -111,  -111,  -111,   -17,    98,  -111,  -111,
      94,     7,    59,  -111,  -111,   -15,   141,   149,  -111,  -111,
     -16,  -111,  -111,   152,  -111,  -111,  -111,  -111,  -111,   141,
     141,    20,   115,   129,  -111,  -111,     7,    59,    57,    40,
       7,    59,  -111,   -21,   141,  -111,   141,   141,  -111,  -111,
      82,    57,  -111,  -111,  -111,   115,   129,  -111,  -111,    82,
    -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    97,    98,    74,    93,    75,    94,    91,    92,     0,
       0,     6,     0,     0,     0,    54,     5,    51,    52,    23,
      57,     0,    56,     0,    76,    82,    85,    88,    90,     0,
       0,    93,    94,    80,    20,     0,     0,     1,     0,     0,
       3,     8,     7,     2,     0,     0,    24,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    81,     0,     0,     4,
      53,    55,    59,    60,    62,    62,    77,    78,    79,     0,
      66,    67,    70,    71,    68,    69,    83,    84,    86,    87,
      89,    95,     0,     0,    12,    15,    16,    13,    14,     0,
      10,    61,    19,    63,    64,    65,     0,     0,    17,     9,
       0,     0,     0,    96,    11,    32,     0,    21,    25,    31,
      23,    37,    36,    22,    28,    41,    43,    42,    33,     0,
       0,     0,    39,    44,    46,    50,     0,     0,    58,    23,
       0,     0,    49,     0,     0,    38,     0,     0,    26,    27,
      60,    58,    30,    29,    48,    40,    45,    47,    35,    60,
      34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,   148,   127,  -111,  -111,    56,  -111,   158,  -100,
      38,    75,    68,  -110,  -111,  -111,  -111,    76,  -106,    60,
      85,   201,  -111,   164,     0,   -98,   -72,   140,  -111,  -111,
    -111,    -7,     4,   151,    64,  -111,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    40,    41,    99,   100,    42,    15,    47,
     117,   123,   118,   119,   120,   121,   131,   128,   132,   133,
     134,    16,    17,    18,   122,    73,   102,   104,    20,    21,
      22,    23,    24,    25,    26,    27,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    64,   124,   125,   125,    36,    50,    51,    52,   146,
      19,    29,    19,    33,     1,     2,     3,     4,     5,     6,
     138,    59,    60,     7,   143,     8,    37,   124,   126,   126,
      46,   153,   154,     9,   127,   127,    66,    11,   155,   151,
     150,    50,    51,    52,    19,    19,    80,    81,    82,    83,
      84,    85,   115,   159,    76,    77,    78,   -72,   -72,    79,
     -73,   -73,   116,    44,   107,   108,     1,     2,     3,     4,
       5,     6,   106,    45,   144,     7,   145,     8,   158,     1,
       2,     3,     4,     5,     6,     9,    46,   160,     7,    63,
       8,     1,     2,     3,     4,     5,     6,    67,     9,    65,
       7,    68,     8,    10,    94,    72,    95,    96,    97,    98,
       9,    79,    38,    39,   116,    10,   135,    48,    49,    11,
      61,    62,    74,    36,    12,    88,    89,    90,    75,   135,
     135,   101,     1,     2,    30,    31,    12,    32,     1,     2,
      93,     7,   103,     8,   135,   146,   135,   135,     1,     2,
       3,     4,     5,     6,    91,    92,   113,     7,   147,     8,
       1,     2,    30,    31,    43,    32,   114,     9,    34,     7,
      69,     8,   129,    50,    51,    52,   109,   110,   152,     9,
     111,   112,    53,    54,    55,    56,    57,    58,    50,    51,
      52,   136,   137,   130,   140,   141,   139,    53,    54,    55,
      56,    57,    58,    66,   148,    79,   156,   157,    70,    71,
      86,    87,   149,    35,   142,   105
};

static const yytype_uint8 yycheck[] =
{
       0,    29,   112,    19,    19,    12,    23,    24,    25,    30,
      10,    57,    12,     9,     7,     8,     9,    10,    11,    12,
     120,    27,    28,    16,   130,    18,     0,   137,    44,    44,
      46,   141,    53,    26,    50,    50,    53,    47,   144,   139,
     138,    23,    24,    25,    44,    45,    53,    54,    55,    56,
      57,    58,    45,   151,    50,    51,    52,    38,    39,    52,
      38,    39,    55,    30,    92,    93,     7,     8,     9,    10,
      11,    12,    79,    29,    54,    16,    56,    18,   150,     7,
       8,     9,    10,    11,    12,    26,    46,   159,    16,    22,
      18,     7,     8,     9,    10,    11,    12,     5,    26,    53,
      16,    52,    18,    31,    10,    48,    12,    13,    14,    15,
      26,    52,     3,     4,    55,    31,   116,    38,    39,    47,
      20,    21,    41,   130,    52,    61,    62,    63,    41,   129,
     130,    49,     7,     8,     9,    10,    52,    12,     7,     8,
       6,    16,    40,    18,   144,    30,   146,   147,     7,     8,
       9,    10,    11,    12,    58,    59,    58,    16,    29,    18,
       7,     8,     9,    10,    16,    12,   110,    26,    10,    16,
      43,    18,    31,    23,    24,    25,    53,    54,   140,    26,
      42,    43,    32,    33,    34,    35,    36,    37,    23,    24,
      25,    42,    43,    52,    42,    43,   120,    32,    33,    34,
      35,    36,    37,    53,   136,    52,   146,   147,    44,    45,
      59,    60,   137,    12,   129,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    12,    16,    18,    26,
      31,    47,    52,    61,    62,    68,    81,    82,    83,    84,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    57,
       9,    10,    12,    92,    68,    81,    91,     0,     3,     4,
      63,    64,    67,    62,    30,    29,    46,    69,    38,    39,
      23,    24,    25,    32,    33,    34,    35,    36,    37,    27,
      28,    20,    21,    22,    96,    53,    53,     5,    52,    63,
      83,    83,    48,    85,    41,    41,    92,    92,    92,    52,
      91,    91,    91,    91,    91,    91,    93,    93,    94,    94,
      94,    58,    59,     6,    10,    12,    13,    14,    15,    65,
      66,    49,    86,    40,    87,    87,    91,    96,    96,    53,
      54,    42,    43,    58,    66,    45,    55,    70,    72,    73,
      74,    75,    84,    71,    73,    19,    44,    50,    77,    31,
      52,    76,    78,    79,    80,    84,    42,    43,    69,    77,
      42,    43,    80,    78,    54,    56,    30,    29,    72,    71,
      85,    69,    70,    73,    53,    78,    79,    79,    86,    85,
      86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    66,    66,    66,    66,    66,    67,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    70,    71,    71,
      71,    72,    72,    72,    73,    73,    74,    74,    75,    76,
      76,    77,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    93,    93,    93,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     3,     0,     1,     1,     1,     4,
       1,     3,     1,     1,     1,     1,     1,     4,     3,     4,
       2,     6,     6,     0,     1,     1,     3,     3,     1,     3,
       3,     1,     1,     2,     5,     4,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     1,     3,     3,     2,
       1,     1,     1,     3,     1,     3,     1,     1,     0,     1,
       0,     1,     0,     1,     4,     4,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       2,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     4,     6,     1,     1
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
      yyerror (&yylloc, parserInfo, YY_("syntax error: cannot back up")); \
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
                  Type, Value, Location, parserInfo); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct ParserInfo *parserInfo)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (parserInfo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct ParserInfo *parserInfo)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, parserInfo);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, struct ParserInfo *parserInfo)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , parserInfo);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, parserInfo); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, struct ParserInfo *parserInfo)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (parserInfo);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 81: /* BoolExpression  */
#line 190 "gramm.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).exp);}
#line 1306 "parser.cpp" /* yacc.c:1257  */
        break;

    case 84: /* BoolOperand  */
#line 190 "gramm.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).exp);}
#line 1312 "parser.cpp" /* yacc.c:1257  */
        break;

    case 88: /* RelExpression  */
#line 190 "gramm.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).exp);}
#line 1318 "parser.cpp" /* yacc.c:1257  */
        break;

    case 90: /* Protocol  */
#line 190 "gramm.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).exp);}
#line 1324 "parser.cpp" /* yacc.c:1257  */
        break;

    case 91: /* BitwiseExpression  */
#line 191 "gramm.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).exp);}
#line 1330 "parser.cpp" /* yacc.c:1257  */
        break;

    case 92: /* ShiftExpression  */
#line 191 "gramm.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).exp);}
#line 1336 "parser.cpp" /* yacc.c:1257  */
        break;

    case 93: /* AddExpression  */
#line 191 "gramm.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).exp);}
#line 1342 "parser.cpp" /* yacc.c:1257  */
        break;

    case 94: /* MulExpression  */
#line 191 "gramm.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).exp);}
#line 1348 "parser.cpp" /* yacc.c:1257  */
        break;

    case 95: /* Term  */
#line 190 "gramm.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).exp);}
#line 1354 "parser.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct ParserInfo *parserInfo)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

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
      yychar = yylex (&yylval, &yylloc, parserInfo);
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
#line 197 "gramm.y" /* yacc.c:1646  */
    {
									if (yynerrs > 0)
									{									
										parserInfo->Filter = NULL;
									}
									else
									{ 
										parserInfo->Filter = new PFLStatement((yyvsp[-1].exp), new PFLReturnPktAction(1), NULL,(yyvsp[0].flag));
									}
									(yyval.stmt) = parserInfo->Filter;			
									if(parserInfo->FilterString.length() != (size_t)((yyloc).last_column-(yyloc).first_column)){
										printf("Error messages:\n  1. [PFL error] syntax error\n");
										exit(-1);	
									}	
									
								}
#line 1663 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 215 "gramm.y" /* yacc.c:1646  */
    {
									if (yynerrs > 0)
									{									
										parserInfo->Filter = NULL;
									}
									else
									{ 
										parserInfo->Filter = new PFLStatement(NULL, (PFLAction*)(yyvsp[0].act), NULL,(yyvsp[-1].flag));
									}
									
									(yyval.stmt) = parserInfo->Filter;
								}
#line 1680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 228 "gramm.y" /* yacc.c:1646  */
    {
									if (yynerrs > 0)
									{									
										parserInfo->Filter = NULL;
									}
									else
									{ 
										parserInfo->Filter = new PFLStatement((yyvsp[-2].exp),(PFLAction*)(yyvsp[0].act), NULL,(yyvsp[-1].flag));
									}
									
									(yyval.stmt) = parserInfo->Filter;
								}
#line 1697 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 243 "gramm.y" /* yacc.c:1646  */
    { 
									(yyval.flag) = false;
								}
#line 1705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 247 "gramm.y" /* yacc.c:1646  */
    {
									(yyval.flag) = true;
								}
#line 1713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 255 "gramm.y" /* yacc.c:1646  */
    {
									(yyval.act) = (yyvsp[0].act);
								}
#line 1721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 261 "gramm.y" /* yacc.c:1646  */
    {
									PFLExtractFldsAction *action= new PFLExtractFldsAction();
									for(FieldsList_t::iterator i = ((yyvsp[-1].FieldsList))->begin(); i != ((yyvsp[-1].FieldsList))->end(); i++)
										action->AddField((*i));
									(yyval.act)=action;
								}
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 270 "gramm.y" /* yacc.c:1646  */
    {
									//$1->Protocol->NeedExtraction = true;
									FieldsList_t *list = new FieldsList_t();
									list->push_back((yyvsp[0].Field));
									(yyval.FieldsList) = list;
								}
#line 1743 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 277 "gramm.y" /* yacc.c:1646  */
    {
		   							//$3->Protocol->NeedExtraction = true;
									FieldsList_t *list = (yyvsp[-2].FieldsList);
									list->push_back((yyvsp[0].Field));
									(yyval.FieldsList) = list;
								}
#line 1754 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 287 "gramm.y" /* yacc.c:1646  */
    {
									//i.e. proto.field
									SymbolField *field = CheckField(parserInfo,(yyvsp[0].id), &yylloc);
									if (field == NULL)
									{
									char ErrMessage[1024];

										ssnprintf(ErrMessage, sizeof(ErrMessage), "Unknown field in extraction statement for protocol '%s'", (yyvsp[0].id));
										PFL_ERROR(&yylloc, parserInfo, ErrMessage);
//										PFL_ERROR(&yylloc, parserInfo, "Unknown field in extraction statement");
									}
									field->HeaderIndex.push_back(1);//remember that: proto.field == proto%1.field
									
									if(field->MultiProto && field->HeaderIndex.size()>0)
										PFL_ERROR(&yylloc, parserInfo, "Unallowed extraction list. You wrote something like: \"proto*.field,proto%n.field\" or \"proto*.field,proto.field\"");
										
									(yyval.Field) = field;
								}
#line 1777 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 306 "gramm.y" /* yacc.c:1646  */
    {
									//i.e. proto*.field
									string field_name((yyvsp[0].id));
									//we remove the "*" symbol from the field name, so we can check it properly
									string field_no_star = remove_chars(field_name, "*", "");
									SymbolField *field = CheckField(parserInfo, (char*)field_no_star.c_str(), &yylloc);
									if (field == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Unknown field in extraction statement");
									}
									field->MultiProto = true;
									
									if(field->MultiProto && field->HeaderIndex.size()>0)
										PFL_ERROR(&yylloc, parserInfo, "Unallowed extraction list. You wrote something like: \"proto*.field,proto%n.field\" or \"proto*.field,proto.field\"");

										
									(yyval.Field) = field;
																
								}
#line 1801 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 326 "gramm.y" /* yacc.c:1646  */
    {
									//i.e. proto.field*
									string field_name((yyvsp[0].id));
									//we remove the "*" symbol from the field name, so we can check it properly
									string field_no_star = remove_chars(field_name, "*", "");
									SymbolField *field = CheckField(parserInfo, (char*)field_no_star.c_str(), &yylloc);
									if (field == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Unknown field in extraction statement");
									}
									if(field->Name == "allfields")
									{
										PFL_ERROR(&yylloc, parserInfo, "\"proto.allfields*\" is not supported"); 
									}
																		
									field->HeaderIndex.push_back(1);

									//field->MultiField = true;
									uint32 multifield = (field->MultiProto) ? field->HeaderIndex.size()+1 : field->HeaderIndex.size();
									field->MultiFields.insert(multifield);


									if(field->MultiProto && field->HeaderIndex.size()>0)
										PFL_ERROR(&yylloc, parserInfo, "Unallowed extraction list. You wrote something like: \"proto*.field,proto%n.field\" or \"proto*.field,proto.field\"");

										
									(yyval.Field) = field;
																
								}
#line 1835 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 355 "gramm.y" /* yacc.c:1646  */
    {
									//i.e. proto%n.field
									char *fieldName, *index;
									uint32 num = 0;
									fieldName = strchr((yyvsp[0].id), '.');
									if(fieldName != NULL)
									{
										*fieldName = '\0';
										fieldName++;
									}

									index = strchr((yyvsp[0].id), '%');
									if(index != NULL)
									{
										*index = '\0';
										index++;
										str2int(index, &num, 10);
									}
									
									char *field_name((yyvsp[0].id));
									
									strcat(field_name, (char*)("."));
									strcat(field_name, fieldName);
									
									string field_ok = field_name;
									SymbolField *field = CheckField(parserInfo, (char*)field_ok.c_str(), &yylloc,num);

									if (field == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Unknown field in extraction statement");
									}
									
									field->HeaderIndex.push_back(num);
									
									if(field->MultiProto && field->HeaderIndex.size()>0)
										PFL_ERROR(&yylloc, parserInfo, "Unallowed extraction list. You wrote something like: \"proto*.field,proto%n.field\" or \"proto*.field,proto.field\"");

										
									(yyval.Field) = field;
								}
#line 1880 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 395 "gramm.y" /* yacc.c:1646  */
    {
									//i.e. proto%n.field*									
									char *element = (yyvsp[0].id);
									element[sizeof(element)] = '\0';
																	
									char *fieldName, *index;
									uint32 num = 0;
									fieldName = strchr(element, '.');
									if(fieldName != NULL)
									{
										*fieldName = '\0';
										fieldName++;
									}

									index = strchr(element, '%');
									if(index != NULL)
									{
										*index = '\0';
										index++;
										str2int(index, &num, 10);
									}
									
									char *field_name(element);
									
									strcat(field_name, (char*)("."));
									strcat(field_name, fieldName);
									
									string field_ok = field_name;
									SymbolField *field = CheckField(parserInfo, (char*)field_ok.c_str(), &yylloc,num);

									if (field == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Unknown field in extraction statement");
									}
									
									field->HeaderIndex.push_back(num);
									//field->MultiField = true;
									uint32 multifield = (field->MultiProto) ? field->HeaderIndex.size()+1 : field->HeaderIndex.size();
									field->MultiFields.insert(multifield);
									
									
									if(field->MultiProto && field->HeaderIndex.size()>0)
										PFL_ERROR(&yylloc, parserInfo, "Unallowed extraction list. You wrote something like: \"proto*.field,proto%n.field\" or \"proto*.field,proto.field\"");

									(yyval.Field) = field;			
								}
#line 1931 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 445 "gramm.y" /* yacc.c:1646  */
    {
										
										PFLReturnPktAction *action= new PFLReturnPktAction((yyvsp[0].number));
										(yyval.act)=action;
																			
									}
#line 1942 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 454 "gramm.y" /* yacc.c:1646  */
    {
									(yyval.exp) = (yyvsp[-1].exp);
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 1951 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 459 "gramm.y" /* yacc.c:1646  */
    {
							//$1 is a term expression
							//we have to create a list containing the single protocol
							list<PFLExpression*> *elementList = new list<PFLExpression*>();
							elementList->push_back((yyvsp[-3].exp));
							PFLSetExpression *setExpr = new PFLSetExpression(elementList,SET_OP,(yyvsp[-2].flag)); //DEFAULT_ROP - DEFAULT_INCLUSION
							if (setExpr == NULL)
								throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
							setExpr->SetAnyPlaceholder(false);
							list<PFLSetExpression*> *setList = new list<PFLSetExpression*>();
							setList->push_back(setExpr);
							PFLRegExpExpression *expr = new PFLRegExpExpression(setList, REGEXP_OP); 
							if (expr == NULL)
								throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
								
							//Nosession		|| NoACK					
							if ((yyvsp[-1].flag) == true || (yyvsp[0].flag) == true)
							{
									list<SymbolProto*> *protos = setExpr->GetProtocols();
									for(list<SymbolProto*>::iterator p = protos->begin(); p!=protos->end(); p++)
									{
										if((yyvsp[-1].flag))
											(*p)->NoSession=true;
										if((yyvsp[0].flag))
											(*p)->NoAck=true;										
									}
							}	
							
							(yyval.exp) = expr;
							STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
						}
#line 1987 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 491 "gramm.y" /* yacc.c:1646  */
    {
									PFLExpression *child = (yyvsp[0].exp);
									if (child->GetType() == PFL_TERM_EXPRESSION)
									{
										(yyval.exp) = MergeNotInTermNode(parserInfo, child);
									}
									else
									{
										PFLUnaryExpression *expr = new PFLUnaryExpression(child, UNOP_BOOLNOT);
										if (expr == NULL)
											throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
										
										(yyval.exp) = expr;
									}
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2008 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 508 "gramm.y" /* yacc.c:1646  */
    {

						//$1 is a PFLTermExpression
						//$6 is a list<PFLSetExpression*>*
						(*(yyvsp[0].setExpList)->begin())->SetInclusionOperator(IN_OP);
						list<PFLExpression*> *setList = new list<PFLExpression*>();
						setList->push_front((yyvsp[-5].exp));
						PFLSetExpression *setExpr = new PFLSetExpression(setList,SET_OP,(yyvsp[-4].flag));
						if (setExpr == NULL)
							throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
						setExpr->SetAnyPlaceholder(false);
						(yyvsp[0].setExpList)->push_front(setExpr);
						PFLRegExpExpression *expr = new PFLRegExpExpression((yyvsp[0].setExpList), REGEXP_OP); 
						if (expr == NULL)
							throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
							
						//Nosession		|| NoACK					
						if ((yyvsp[-3].flag) == true || (yyvsp[-2].flag) == true)
						{
								list<SymbolProto*> *protos = setExpr->GetProtocols();
								for(list<SymbolProto*>::iterator p = protos->begin(); p!=protos->end(); p++)
								{
									if((yyvsp[-3].flag))
										(*p)->NoSession=true;
									if((yyvsp[-2].flag))
										(*p)->NoAck=true;										
								}
						}														
						
						(yyval.exp) = expr;
						STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
												
					}
#line 2046 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 541 "gramm.y" /* yacc.c:1646  */
    {
						//$1 is a PFLTermExpression
						//$4 is a list<PFLSetExpression*>*
						(*(yyvsp[0].setExpList)->begin())->SetInclusionOperator(NOTIN);
						list<PFLExpression*> *setList = new list<PFLExpression*>();
						setList->push_front(static_cast<PFLExpression*>((yyvsp[-5].exp)));						
						PFLSetExpression *setExpr = new PFLSetExpression(setList,SET_OP,(yyvsp[-4].flag));
						if (setExpr == NULL)
							throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
						setExpr->SetAnyPlaceholder(false);
						(yyvsp[0].setExpList)->push_front(setExpr);
						PFLRegExpExpression *expr = new PFLRegExpExpression((yyvsp[0].setExpList), REGEXP_OP); 
						if (expr == NULL)
							throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
							
						//Nosession		|| NoACK					
						if ((yyvsp[-3].flag) == true || (yyvsp[-2].flag) == true)
						{
								list<SymbolProto*> *protos = setExpr->GetProtocols();
								for(list<SymbolProto*>::iterator p = protos->begin(); p!=protos->end(); p++)
								{
									if((yyvsp[-3].flag))
										(*p)->NoSession=true;
									if((yyvsp[-2].flag))
										(*p)->NoAck=true;										
								}
						}														
							
						(yyval.exp) = expr;
						STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
						
					}
#line 2083 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 575 "gramm.y" /* yacc.c:1646  */
    {
			(yyval.flag) = false;
		}
#line 2091 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 579 "gramm.y" /* yacc.c:1646  */
    {
			(yyval.flag) = true;
		}
#line 2099 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 584 "gramm.y" /* yacc.c:1646  */
    {
					//$1 contains a PFLSetExpression*
					//we have to create the list of sets
					list<PFLSetExpression*>* setExpList = new list<PFLSetExpression*>();
					//we add the set to the list
					setExpList->push_back((yyvsp[0].setExp));
					(yyval.setExpList) = setExpList;
				}
#line 2112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 593 "gramm.y" /* yacc.c:1646  */
    {
					//$3 contains a PFLSetExpression*
					//$1 contantains list<PFLSetExpression*>*
					(yyvsp[0].setExp)->SetInclusionOperator(IN_OP);
					(yyvsp[-2].setExpList)->push_back((yyvsp[0].setExp));
					(yyval.setExpList) = (yyvsp[-2].setExpList);
				}
#line 2124 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 600 "gramm.y" /* yacc.c:1646  */
    {
					//$1 contantains list<PFLSetExpression*>*
					//$3 contantains list<PFLSetExpression*>*
			
					//the first element of $3 is involved in a "notin" operation
					(*(yyvsp[0].setExpList)->begin())->SetInclusionOperator(NOTIN);
					for(list<PFLSetExpression*>::iterator it = (yyvsp[0].setExpList)->begin(); it != (yyvsp[0].setExpList)->end(); it++)
						(yyvsp[-2].setExpList)->push_back(*it);
					(yyvsp[0].setExpList)->clear();
					delete((yyvsp[0].setExpList));
					(yyval.setExpList) = (yyvsp[-2].setExpList);
				}
#line 2141 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 614 "gramm.y" /* yacc.c:1646  */
    {
				list<PFLSetExpression*>* setExpList = new list<PFLSetExpression*>();
				setExpList->push_back((yyvsp[0].setExp));
				(yyval.setExpList) = setExpList;
			}
#line 2151 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 619 "gramm.y" /* yacc.c:1646  */
    {
				(yyvsp[0].setExp)->SetInclusionOperator(NOTIN);
				(yyvsp[-2].setExpList)->push_back((yyvsp[0].setExp));
				(yyval.setExpList) = (yyvsp[-2].setExpList);
			}
#line 2161 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 624 "gramm.y" /* yacc.c:1646  */
    {
				//$1 contantains list<PFLSetExpression*>*
				//$3 contantains list<PFLSetExpression*>*
				(*(yyvsp[0].setExpList)->begin())->SetInclusionOperator(IN_OP);
				for(list<PFLSetExpression*>::iterator it = (yyvsp[0].setExpList)->begin(); it != (yyvsp[0].setExpList)->end(); it++)
					(yyvsp[-2].setExpList)->push_back(*it);
				(yyvsp[0].setExpList)->clear();
				delete((yyvsp[0].setExpList));
				(yyval.setExpList) = (yyvsp[-2].setExpList);
			}
#line 2176 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 636 "gramm.y" /* yacc.c:1646  */
    {
				//we have found the any placeholder.
				//we create the empty list
				list<PFLExpression*> *setList = new list<PFLExpression*>();
				//we create the set expression
				PFLSetExpression *setExpr = new PFLSetExpression(setList,SET_OP);
				if (setExpr == NULL)
					throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
				setExpr->SetAnyPlaceholder(true);
				(yyval.setExp) = setExpr;	
			}
#line 2192 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 648 "gramm.y" /* yacc.c:1646  */
    {
				list<PFLExpression*> *setList = new list<PFLExpression*>();
				PFLSetExpression *setExpr = new PFLSetExpression(setList,SET_OP,false,(yyvsp[0].repOp));//we specify the repeat operator in the constructor
				if (setExpr == NULL)
					throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
				setExpr->SetAnyPlaceholder(true);
				(yyval.setExp) = setExpr;
					
			}
#line 2206 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 660 "gramm.y" /* yacc.c:1646  */
    {
				//$1 is a list<PFLExpression>*
				//We have to create the set expression				
				PFLSetExpression *setExpr = new PFLSetExpression((yyvsp[-4].expList),SET_OP,(yyvsp[-2].flag),(yyvsp[-3].repOp));//we specify the repeat operator in the constructor
				if (setExpr == NULL)
					throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
				setExpr->SetAnyPlaceholder(false);

						//Nosession		|| NoACK					
						if ((yyvsp[-1].flag) == true || (yyvsp[0].flag) == true)
						{
								list<SymbolProto*> *protos = setExpr->GetProtocols();
								for(list<SymbolProto*>::iterator p = protos->begin(); p!=protos->end(); p++)
								{
									if((yyvsp[-1].flag))
										(*p)->NoSession=true;
									if((yyvsp[0].flag))
										(*p)->NoAck=true;										
								}
						}														
			
				(yyval.setExp) = setExpr;
			}
#line 2234 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 684 "gramm.y" /* yacc.c:1646  */
    {
				//$1 is a list<PFLExpression>*
				//We have to create the set expression
				PFLSetExpression *setExpr = new PFLSetExpression((yyvsp[-3].expList),SET_OP,(yyvsp[-2].flag));
				if (setExpr == NULL)
					throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
				setExpr->SetAnyPlaceholder(false);
				
				//Nosession		|| NoACK					
				if ((yyvsp[-1].flag) == true || (yyvsp[0].flag) == true)
				{
					list<SymbolProto*> *protos = setExpr->GetProtocols();
					for(list<SymbolProto*>::iterator p = protos->begin(); p!=protos->end(); p++)
					{
						if((yyvsp[-1].flag))
							(*p)->NoSession=true;
						if((yyvsp[0].flag))
							(*p)->NoAck=true;										
					}
				}														
		
				(yyval.setExp) = setExpr;			
			}
#line 2262 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 710 "gramm.y" /* yacc.c:1646  */
    {
				//the current element of the header chain is a single protocol, eventually with header indexing and/or predicate, and which is not within the { }
				list<PFLExpression*> *setList = new list<PFLExpression*>();
				setList->push_back((yyvsp[0].exp));
				(yyval.expList) = setList;
			}
#line 2273 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 720 "gramm.y" /* yacc.c:1646  */
    { 
			(yyval.expList) = (yyvsp[-1].expList);
			}
#line 2281 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 727 "gramm.y" /* yacc.c:1646  */
    {
				//we create a list containing the elements of the set
				list<PFLExpression*> *setList = new list<PFLExpression*>();
				setList->push_back((yyvsp[0].exp));
				(yyval.expList) = setList;
			}
#line 2292 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 733 "gramm.y" /* yacc.c:1646  */
    {
			list<PFLExpression*> *setList = new list<PFLExpression*>();
			setList->push_back((yyvsp[0].exp));
			for(list<PFLExpression*>::iterator it = (yyvsp[-2].expList)->begin(); it != (yyvsp[-2].expList)->end(); it++)
				setList->push_back(*it);
			(yyval.expList) = setList;			
			//[icerrato]		
		}
#line 2305 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 743 "gramm.y" /* yacc.c:1646  */
    {
				   (yyval.repOp)=PLUS;   
			    }
#line 2313 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 747 "gramm.y" /* yacc.c:1646  */
    {
		 		   (yyval.repOp)=STAR;
		  	    }
#line 2321 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 751 "gramm.y" /* yacc.c:1646  */
    {
				   (yyval.repOp)=QUESTION;
			    }
#line 2329 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 758 "gramm.y" /* yacc.c:1646  */
    {
                    	PFLBinaryExpression *expr = new PFLBinaryExpression((yyvsp[-2].exp), (yyvsp[0].exp), BINOP_BOOLOR);
						if (expr == NULL)
							throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
						(yyval.exp) = expr;
				
						STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
				
						//[icerrato]
					}
#line 2344 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 773 "gramm.y" /* yacc.c:1646  */
    {
				           
							PFLBinaryExpression *expr = new PFLBinaryExpression((yyvsp[-2].exp), (yyvsp[0].exp), BINOP_BOOLAND);
							if (expr == NULL)
								throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
							(yyval.exp) = expr;
							
							STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
					
							//[icerrato]
						}
#line 2360 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 787 "gramm.y" /* yacc.c:1646  */
    {
				(yyval.exp) = (yyvsp[-1].exp);
				STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
				//[icerrato]
			}
#line 2370 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 794 "gramm.y" /* yacc.c:1646  */
    {
				PFLExpression *child = (yyvsp[0].exp);
				if (child->GetType() == PFL_TERM_EXPRESSION)
				{
					(yyval.exp) = MergeNotInTermNode(parserInfo, child);
				}
				else
				{
					PFLUnaryExpression *expr = new PFLUnaryExpression(child, UNOP_BOOLNOT);
					if (expr == NULL)
						throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
					
					(yyval.exp) = expr;
				}
				STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
				
				//[icerrato]
			}
#line 2393 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 813 "gramm.y" /* yacc.c:1646  */
    {
					(yyval.exp) = (yyvsp[0].exp);
					STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
					//[icerrato]			
				}
#line 2403 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 829 "gramm.y" /* yacc.c:1646  */
    {
		                             /*
		                               * Let the automaton algorithms apply the desired optimizations; do not try
		                               * to do anything at this level about predicates.
		                               *	PFLExpression *termNode = MergeTermNodes(parserInfo, IR_ORB, $1, $3);
		                               */
		                              PFLExpression *termNode = NULL;
									if (termNode != NULL)
									{
										(yyval.exp) = termNode;
									}
									else
									{
										PFLBinaryExpression *expr = new PFLBinaryExpression((yyvsp[-2].exp), (yyvsp[0].exp), BINOP_BOOLOR);
										if (expr == NULL)
											throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
										(yyval.exp) = expr;
									}
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 855 "gramm.y" /* yacc.c:1646  */
    {
                                                                  /*
                                                                   * Let the automaton algorithms apply the desired optimizations; do not try
                                                                   * to do anything at this level about predicates.
                                                                   *	PFLExpression *termNode = MergeTermNodes(parserInfo, IR_ANDB, $1, $3);
                                                                   */
                                                                  PFLExpression *termNode = NULL;
									if (termNode != NULL)
									{
										(yyval.exp) = termNode;
									}
									else
									{
										PFLBinaryExpression *expr = new PFLBinaryExpression((yyvsp[-2].exp), (yyvsp[0].exp), BINOP_BOOLAND);
										if (expr == NULL)
											throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
										(yyval.exp) = expr;
									}
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2453 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 882 "gramm.y" /* yacc.c:1646  */
    {
					(yyval.flag) = false;	// protoSymbol->NoSession = false
				}
#line 2461 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 886 "gramm.y" /* yacc.c:1646  */
    {
					(yyval.flag) = true;	// protoSymbol->NoSession = true
				}
#line 2469 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 892 "gramm.y" /* yacc.c:1646  */
    {
					(yyval.flag) = false;	// protoSymbol->NoAck = false
				}
#line 2477 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 896 "gramm.y" /* yacc.c:1646  */
    {
					(yyval.flag) = true;	// protoSymbol->NoAck = true
				}
#line 2485 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 903 "gramm.y" /* yacc.c:1646  */
    {
				(yyval.flag) = false;
				}
#line 2493 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 906 "gramm.y" /* yacc.c:1646  */
    {
				(yyval.flag) = true;	
				}
#line 2501 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 911 "gramm.y" /* yacc.c:1646  */
    { 
									/*
									*  PFL_PROTOFIELD|PFL_PROTOFIELD_INDEX 
									*/
									
									PFLTermExpression *protoExp = static_cast<PFLTermExpression*>((yyvsp[-3].exp));
									
									Node *node = protoExp->GetIRExpr();
									
									SymbolField *fieldSym = static_cast<SymbolField*>(node->Sym);
																					
									switch(fieldSym->FieldType)
										{
											case PDL_FIELD_FIXED: 
												static_cast<SymbolFieldFixed*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_VARLEN:
												static_cast<SymbolFieldVarLen*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_TOKEND:
												cout << "PFL warning: tokenended fields are deprecated" << endl;
												static_cast<SymbolFieldTokEnd*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_LINE:
												static_cast<SymbolFieldLine*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_PATTERN:
												static_cast<SymbolFieldPattern*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_EATALL:
												static_cast<SymbolFieldEatAll*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											default:
												PFL_ERROR(&yylloc, parserInfo, "Only fixed length, variable, tokenended, line, pattern and eatall fields are supported with kweword \"matches\" and \"contains\"");
										}
										
										
										
														
 									/*
									*  PFL_STRING
									*/
									
									PFLExpression *expr=GenString(parserInfo,(yyvsp[-1].id));
									
									/*
									*  PFL_MATCHES
									*/
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_MATCH, /*protocol*/(yyvsp[-3].exp), expr); 
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}

									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
									
					}
#line 2569 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 976 "gramm.y" /* yacc.c:1646  */
    {
									/*
									*  PFL_PROTOFIELD|PFL_PROTOFIELD_INDEX 
									*/
								
									PFLTermExpression *protoExp = static_cast<PFLTermExpression*>((yyvsp[-3].exp));
									
									Node *node = protoExp->GetIRExpr();
									
									SymbolField *fieldSym = static_cast<SymbolField*>(node->Sym);
																					
									switch(fieldSym->FieldType)
										{
											case PDL_FIELD_FIXED: 
												static_cast<SymbolFieldFixed*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_VARLEN:
												static_cast<SymbolFieldVarLen*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_TOKEND:
												cout << "PFL warning: tokenended fields are deprecated" << endl;
												static_cast<SymbolFieldTokEnd*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_LINE:
												static_cast<SymbolFieldLine*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_PATTERN:
												static_cast<SymbolFieldPattern*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											case PDL_FIELD_EATALL:
												static_cast<SymbolFieldEatAll*>(fieldSym)->Sensitive = (yyvsp[0].flag);//sensitive;
												break;
											default:
												PFL_ERROR(&yylloc, parserInfo, "Only fixed length, variable, tokenended, line, pattern and eatall fields are supported with kweword \"matches\" and \"contains\"");
										}				
 									/*
									*  PFL_STRING
									*/
									
									PFLExpression *expr=GenString(parserInfo,(yyvsp[-1].id));
									
									/*
									*  PFL_CONTAINS
									*/
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_CONTAINS, /*protocol*/(yyvsp[-3].exp), expr); 
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}

									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
									
					}
#line 2633 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1038 "gramm.y" /* yacc.c:1646  */
    {
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_EQI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2651 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1052 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_NEI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2670 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1067 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_GTI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2689 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1082 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_GEI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1097 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_LTI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2727 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1112 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_LEI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2746 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1130 "gramm.y" /* yacc.c:1646  */
    {
					PFLExpression *protocol = ManagePFLProtoField((yyvsp[0].id),parserInfo, &yylloc);
						if(protocol == NULL)
							YYERROR;
					(yyval.exp) = protocol; 
					
					}
#line 2758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1138 "gramm.y" /* yacc.c:1646  */
    {
					char *index;
					uint32 num = 0;
					char *protoName = (yyvsp[0].id), *fieldName;
					GlobalSymbols &globalSymbols = *parserInfo->GlobalSyms;									
					SymbolField *fieldSym(0);
					fieldName = strchr((yyvsp[0].id), '.');
					
					index = strchr(protoName, '%');
					
					index[strlen(index)-strlen(strchr(protoName, '.'))]='\0';
					if (index != NULL)
					{
						*index = '\0';
						index++;
						str2int(index, &num, 10);
					}


					if (fieldName != NULL)
					{
						*fieldName = '\0';
						fieldName++;
					}

					SymbolProto *protoSymbol = globalSymbols.LookUpProto(protoName);
					
					if (protoSymbol == NULL)
					{
						PFL_ERROR(&yylloc, parserInfo, "Invalid PROTOCOL identifier");

					}
					fieldSym = globalSymbols.LookUpProtoFieldByName(protoName, fieldName);
					
					if (fieldSym == NULL)
					{
						PFL_ERROR(&yylloc, parserInfo, "Field not valid for the specified protocol");
					}
					
					switch(fieldSym->FieldType)
					{
						case PDL_FIELD_TOKEND:
							cout << "PFL warning: tokenended fields are deprecated" << endl;
						case PDL_FIELD_FIXED: 
						case PDL_FIELD_VARLEN:
						case PDL_FIELD_LINE:
						case PDL_FIELD_PATTERN:
						case PDL_FIELD_EATALL:
						case PDL_FIELD_BITFIELD:
							break;
						default:
							PFL_ERROR(&yylloc, parserInfo, "Only fixed length, variable, tokenended, line, pattern, eatall and bitfield fields are supported");
					}
					HIRCodeGen &codeGen = parserInfo->CodeGen;
					Node *irExpr = codeGen.TermNode(IR_FIELD, fieldSym);
					if (irExpr == NULL)
						throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");									
					(yyval.exp) = GenTermNode(protoSymbol, irExpr);
					static_cast<PFLTermExpression*>((yyval.exp))->SetHeaderIndex(num);
					STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
		
					}
#line 2825 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1220 "gramm.y" /* yacc.c:1646  */
    {
									GlobalSymbols &globalSymbols = *parserInfo->GlobalSyms;
									SymbolProto *protoSymbol = globalSymbols.LookUpProto((yyvsp[0].id));
									
									if (protoSymbol == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Invalid PROTOCOL identifier");
									}
									PFLTermExpression *expr = new PFLTermExpression(protoSymbol);
									if (expr == NULL)
										throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
									
									(yyval.exp) = expr;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2845 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1237 "gramm.y" /* yacc.c:1646  */
    {
									char *index;
									uint32 num = 0;
									GlobalSymbols &globalSymbols = *parserInfo->GlobalSyms;
									
									index = strchr((yyvsp[0].id), '%');
									if (index != NULL)
									{
										*index = '\0';
										index++;
										str2int(index, &num, 10);
									}
									
									SymbolProto *protoSymbol = globalSymbols.LookUpProto((yyvsp[0].id));
									
									if (protoSymbol == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Invalid PROTOCOL identifier");
									}
									
								
									PFLTermExpression *expr = new PFLTermExpression(protoSymbol, num);
									if (expr == NULL)
										throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
									
									(yyval.exp) = expr;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2878 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1269 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_ANDI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");

									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");

									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2899 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1286 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_ORI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2918 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1301 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_XORI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2937 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1316 "gramm.y" /* yacc.c:1646  */
    {
									PFLTermExpression *termNode = (PFLTermExpression*)(yyvsp[0].exp);
									HIRCodeGen &codeGen = parserInfo->CodeGen;
									termNode->SetIRExpr(codeGen.UnOp(IR_NOTI, static_cast<HIRNode*>(termNode->GetIRExpr())));
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2949 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1324 "gramm.y" /* yacc.c:1646  */
    {
									(yyval.exp) = (yyvsp[-1].exp);
								}
#line 2957 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1332 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_SHLI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2976 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1347 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_SHRI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 2995 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1366 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_ADDI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 3014 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1381 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_SUBI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 3033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1400 "gramm.y" /* yacc.c:1646  */
    {
									
									PFLExpression *termNode = MergeTermNodes(parserInfo, IR_MULI, (yyvsp[-2].exp), (yyvsp[0].exp));
									if (termNode == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Operations between fields of different protocols are not supported");
									}
									if (!CheckOperandTypes(parserInfo, termNode))
									{
										PFL_ERROR(&yylloc, parserInfo, "type mismatch in expression");
									}
									(yyval.exp) = termNode;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 3052 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1417 "gramm.y" /* yacc.c:1646  */
    {									
									(yyval.exp) = GenNumber(parserInfo, (yyvsp[0].number));
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 3061 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1423 "gramm.y" /* yacc.c:1646  */
    {
									uint32 add = 0;
									if (IPaddr2int((yyvsp[0].id), &add) != 0)
									{
										PFL_ERROR(&yylloc, parserInfo, "IP address not valid!");
									}
									(yyval.exp) = GenNumber(parserInfo, add);
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 3075 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1433 "gramm.y" /* yacc.c:1646  */
    {
			
									uint32 add = 0;
									if (MACaddr2int((yyvsp[0].id), &add) != 0)
									{
										PFL_ERROR(&yylloc, parserInfo, "MAC address not valid!");
									}
									(yyval.exp) = GenNumber(parserInfo, add);
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
									PFL_ERROR(&yylloc, parserInfo, "MAC address are not supported!");
								}
#line 3091 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1444 "gramm.y" /* yacc.c:1646  */
    {
									char *protoName = (yyvsp[0].id), *fieldName;
									GlobalSymbols &globalSymbols = *parserInfo->GlobalSyms;									
									SymbolField *fieldSym(0);
									fieldName = strchr((yyvsp[0].id), '.');

									if (fieldName != NULL)
									{
										*fieldName = '\0';
										fieldName++;
									}
									
									SymbolProto *protoSymbol = globalSymbols.LookUpProto(protoName);
									
									if (protoSymbol == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Invalid PROTOCOL identifier");

									}
									fieldSym = globalSymbols.LookUpProtoFieldByName(protoName, fieldName);
									
									if (fieldSym == NULL)
									{
										PFL_ERROR(&yylloc, parserInfo, "Field not valid for the specified protocol");
									}
									
									switch(fieldSym->FieldType)
									{
										case PDL_FIELD_TOKEND:
											cout << "PFL warning: tokenended fields are deprecated" << endl;
										case PDL_FIELD_FIXED: 
										case PDL_FIELD_VARLEN:
										case PDL_FIELD_LINE:
										case PDL_FIELD_PATTERN:
										case PDL_FIELD_EATALL:
										case PDL_FIELD_BITFIELD:
											break;
										default:
											PFL_ERROR(&yylloc, parserInfo, "Only fixed length, variable, tokenended, line, pattern, eatall and bitfield fields are supported");
									}
									HIRCodeGen &codeGen = parserInfo->CodeGen;
									Node *irExpr = codeGen.TermNode(IR_FIELD, fieldSym);
									if (irExpr == NULL)
										throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");									
									(yyval.exp) = GenTermNode(protoSymbol, irExpr);
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 3143 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1496 "gramm.y" /* yacc.c:1646  */
    {
								char *index;
								uint32 num = 0;
								char *protoName = (yyvsp[0].id), *fieldName;
								GlobalSymbols &globalSymbols = *parserInfo->GlobalSyms;									
								SymbolField *fieldSym(0);
								fieldName = strchr((yyvsp[0].id), '.');
								
								index = strchr(protoName, '%');
								
								index[strlen(index)-strlen(strchr(protoName, '.'))]='\0';
								if (index != NULL)
								{
									*index = '\0';
									index++;
									str2int(index, &num, 10);
								}

								if (fieldName != NULL)
								{
									*fieldName = '\0';
									fieldName++;
								}

								SymbolProto *protoSymbol = globalSymbols.LookUpProto(protoName);
								
								if (protoSymbol == NULL)
								{
									PFL_ERROR(&yylloc, parserInfo, "Invalid PROTOCOL identifier");

								}
								fieldSym = globalSymbols.LookUpProtoFieldByName(protoName, fieldName);
								
								if (fieldSym == NULL)
								{
									PFL_ERROR(&yylloc, parserInfo, "Field not valid for the specified protocol");
								}
								
								switch(fieldSym->FieldType)
								{
									case PDL_FIELD_TOKEND:
										cout << "PFL warning: tokenended fields are deprecated" << endl;
									case PDL_FIELD_FIXED: 
									case PDL_FIELD_VARLEN:
									case PDL_FIELD_LINE:
									case PDL_FIELD_PATTERN:
									case PDL_FIELD_EATALL:
									case PDL_FIELD_BITFIELD:
										break;
									default:
										PFL_ERROR(&yylloc, parserInfo, "Only fixed length, variable, tokenended, line, pattern, eatall and bitfield fields are supported");
								}
								HIRCodeGen &codeGen = parserInfo->CodeGen;
								Node *irExpr = codeGen.TermNode(IR_FIELD, fieldSym);
								if (irExpr == NULL)
									throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");									
								(yyval.exp) = GenTermNode(protoSymbol, irExpr);
								static_cast<PFLTermExpression*>((yyval.exp))->SetHeaderIndex(num);
								STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
							
							
								}
#line 3210 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1559 "gramm.y" /* yacc.c:1646  */
    {
									PFLExpression *expr = GenProtoBytesRef(&yylloc, parserInfo, (yyvsp[-3].id), (yyvsp[-1].number), 1);
									if (expr == NULL)
										YYERROR;
									(yyval.exp) = expr;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								
								}
#line 3223 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1568 "gramm.y" /* yacc.c:1646  */
    {
									PFLExpression *expr = GenProtoBytesRef(&yylloc, parserInfo, (yyvsp[-5].id), (yyvsp[-3].number), (yyvsp[-1].number));
									if (expr == NULL)
										YYERROR;
									(yyval.exp) = expr;
									STORE_EXP_TEXT((yyval.exp), (yyloc).first_column, (yyloc).first_line, (yyloc).last_column, (yyloc).last_line);
								}
#line 3235 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1580 "gramm.y" /* yacc.c:1646  */
    {
									uint32 num = 0;
									if (str2int((yyvsp[0].id), &num, 10) != 0)
									{
										PFL_ERROR(&yylloc, parserInfo, "Decimal number out of range");
									}
									
									(yyval.number) = num;
								}
#line 3249 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1591 "gramm.y" /* yacc.c:1646  */
    {
									uint32 num = 0;
									if (str2int((yyvsp[0].id), &num, 16) != 0)
									{
										PFL_ERROR(&yylloc, parserInfo, "Hexadecimal number out of range");
									}
									
									(yyval.number) = num;
								}
#line 3263 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3267 "parser.cpp" /* yacc.c:1646  */
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
      yyerror (&yylloc, parserInfo, YY_("syntax error"));
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
        yyerror (&yylloc, parserInfo, yymsgp);
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
                      yytoken, &yylval, &yylloc, parserInfo);
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
                  yystos[yystate], yyvsp, yylsp, parserInfo);
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
  yyerror (&yylloc, parserInfo, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, parserInfo);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, parserInfo);
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
#line 1601 "gramm.y" /* yacc.c:1906  */


SymbolField* CheckField(ParserInfo *parserInfo, char * protoName, YYLTYPE *llocp, uint32 headerIndex)
{
	char *fieldName;
	GlobalSymbols &globalSymbols = *parserInfo->GlobalSyms;									
	//SymbolField *fieldSym(0);
	fieldName = strchr(protoName, '.');

	if (fieldName != NULL)
	{
		*fieldName = '\0';
		fieldName++;
	}

	SymbolProto *protoSymbol = globalSymbols.LookUpProto(protoName);
	
	if (protoSymbol == NULL)
	{
		return NULL;
	}

	if(strcmp(fieldName,"allfields")==0)
   	{	
   		if(protocolsForExtraction.count(make_pair(protoSymbol,headerIndex))!=0)
   		{
   			pfl_error(llocp, parserInfo, "You cannot specify a protocol two times for the field extraction, if the second of them is on \"allfields\"");
   			return NULL;
   		}
   		SymbolField *sym = new SymbolField(fieldName,PDL_FIELD_ALLFIELDS,NULL);
       	sym->Protocol=protoSymbol;
       	globalSymbols.StoreProtoField(protoSymbol, sym);
		return sym;
   	}
    else
    {
    	protocolsForExtraction.insert(make_pair(protoSymbol,headerIndex)); //this set is needed in order to verify that the protocol with all field is not present in the extractfields yet
		return globalSymbols.LookUpProtoFieldByName(protoName, fieldName);
	}
	
}

PFLExpression *GenUnOpNode(PFLOperator op, PFLExpression *kid)
{
	PFLUnaryExpression *expr = new PFLUnaryExpression(kid, op);
	if (expr == NULL)
		throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
	return expr;
}


PFLExpression *GenBinOpNode(PFLOperator op, PFLExpression *kid1, PFLExpression *kid2)
{
	PFLBinaryExpression *expr = new PFLBinaryExpression(kid1, kid2, op);
	if (expr == NULL)
		throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
	return expr;
}

PFLExpression *GenTermNode(SymbolProto *protocol, Node *irExpr)
{
	PFLTermExpression *expr = new PFLTermExpression(protocol, irExpr);
	if (expr == NULL)
		throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
	return expr;
}

PFLExpression *MergeNotInTermNode(ParserInfo *parserInfo, PFLExpression *node1)
{
	nbASSERT(parserInfo != NULL, "parserInfo cannot be NULL");
	nbASSERT(node1 != NULL, "node1 cannot be NULL");
	nbASSERT(node1->GetType() == PFL_TERM_EXPRESSION, "node1 should be a terminal node");
	PFLTermExpression *kid1 = (PFLTermExpression*)node1;

	PFLUnaryExpression *expr = new PFLUnaryExpression(kid1, UNOP_BOOLNOT);
	if (expr == NULL)
		throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");
	return expr;
}


HIRNode *ConvToInt(ParserInfo *parserInfo, HIRNode *node)
{
	nbASSERT(parserInfo != NULL, "parserInfo cannot be NULL");
	nbASSERT(node != NULL, "Node cannot be NULL");
	if (CheckIntOperand(node))
	{
		switch(node->Op)
		{
			case IR_ICONST:
			case IR_IVAR:
				return node;
				break;
			case IR_SVAR:
			case IR_FIELD:
			{
				HIRCodeGen &codeGen = parserInfo->CodeGen;
				node->NRefs--; //otherwise it will appear as a dag and this is not the case
				return codeGen.UnOp(IR_CINT, node);
			}break;
			default:
				return node;
				break;
		}
	}
	return NULL;
}

HIRNode *StringToString(ParserInfo *parserInfo, HIRNode *node)
{
	nbASSERT(parserInfo != NULL, "parserInfo cannot be NULL");
	nbASSERT(node != NULL, "Node cannot be NULL");

	switch(node->Op)
	{
			return node;
			break;
		case IR_SVAR:
		case IR_FIELD:
		{	//SymbolField *sf=(SymbolField*)node->Sym;		
			HIRCodeGen &codeGen = parserInfo->CodeGen;
			node->NRefs--; //otherwise it will appear as a dag and this is not the case
			return codeGen.UnOp(IR_CINT, node);
		}break;
		default:
			return node;
			break;
	}
	return node;
}

bool CheckOperandTypes(ParserInfo *parserInfo, PFLExpression *expr)
{
	nbASSERT(expr->GetType() == PFL_TERM_EXPRESSION, "expression should be a terminal node");
	nbASSERT(parserInfo != NULL, "parserInfo cannot be NULL");
	nbASSERT(expr != NULL, "expr cannot be NULL");
	nbASSERT(expr->GetType() == PFL_TERM_EXPRESSION, "expr should be a terminal node");
	HIRNode *node = static_cast<HIRNode*>(((PFLTermExpression*)expr)->GetIRExpr());
	nbASSERT(node != NULL, "Contained Node cannot be NULL");
	
	if (GET_OP_TYPE(node->Op) == IR_TYPE_INT)
	{      
		HIRNode *leftChild = node->GetLeftChild();
		HIRNode *rightChild = node->GetRightChild();
		if (leftChild)
		{
			leftChild = ConvToInt(parserInfo, leftChild);
			if(leftChild == NULL)
			{
				return false;
			} 
			node->SetLeftChild(leftChild);
		}
		if (rightChild)
		{		
			rightChild = ConvToInt(parserInfo, rightChild);
			if(rightChild == NULL)
			{
				return false;
			} 
			node->SetRightChild(rightChild);
		}
			
		return true;
	}
	
	else if (GET_OP_TYPE(node->Op) == IR_TYPE_STR)
	{
	
		HIRNode *leftChild = node->GetLeftChild();
		HIRNode *rightChild = node->GetRightChild();
		if (leftChild)
		{
			leftChild = StringToString(parserInfo, leftChild);
			if(leftChild == NULL)
			{
				return false;
			} 
			node->SetLeftChild(leftChild);
		}
		if (rightChild)
		{		
			rightChild = StringToString(parserInfo, rightChild);
			if(rightChild == NULL)
			{
				return false;
			} 
			node->SetRightChild(rightChild);
		}
		
		return true; 		
	}	
	
	nbASSERT(false, "SHOULD NOT BE HERE");
	return true;
} 

PFLExpression *MergeTermNodes(ParserInfo *parserInfo, HIROpcodes op, PFLExpression *node1, PFLExpression *node2)
{
	nbASSERT(parserInfo != NULL, "parserInfo cannot be NULL");
	nbASSERT(node1 != NULL, "node1 cannot be NULL");
	nbASSERT(node2 != NULL, "node2 cannot be NULL");
	//node1 should be a terminal node
	if(node1->GetType() != PFL_TERM_EXPRESSION)
		return NULL;
	//node2 should be a terminal node
	if(node2->GetType() != PFL_TERM_EXPRESSION)	
		return NULL;
	nbASSERT(node2->GetType() == PFL_TERM_EXPRESSION, "node2 should be a terminal node");
	PFLTermExpression *kid1 = (PFLTermExpression*)node1;
	PFLTermExpression *kid2 = (PFLTermExpression*)node2;

	// save protocol information about the two terminal nodes
	SymbolProto *proto1 = kid1->GetProtocol();
	SymbolProto *proto2 = kid2->GetProtocol();
	
	// save the IR trees of the two terminal nodes
	HIRNode *irExpr1 = static_cast<HIRNode*>(kid1->GetIRExpr()); //i.e. IR_FILED
	HIRNode *irExpr2 = static_cast<HIRNode*>(kid2->GetIRExpr()); //i.e. IR_SCONST
	
	if (proto1 != proto2)
	{
		// the two terminal nodes refer to different protocols
		if (proto2 == NULL)
		{
			nbASSERT(irExpr2 != NULL, "irExpr2 cannot be NULL");
			// if the second has a NULL protocol (i.e. it contains a constant expression) we delete it
			kid2->SetIRExpr(NULL);
			delete kid2;
		}
		else if (proto1 == NULL)
		{
			nbASSERT(irExpr1 != NULL, "irExpr1 cannot be NULL");
			// if the first has a NULL protocol (i.e. it contains a constant expression) we copy the protocol 
			// information from the second, then we delete the second
			kid1->SetProtocol(proto2);
			kid2->SetIRExpr(NULL);
			delete kid2;
		}
		else
		{
			//The two terminal nodes cannot be merged in a single PFLTermExpression node
			return NULL;
		}
	}
	else
	{
			// the two terminal nodes refer to the same protocol
			// so we simply delete the second
			kid2->SetIRExpr(NULL);
			delete kid2;
	}
	
	//handle the cases such as (ip and (ip.src == 10.0.0.1)) where one operand is redundant
	
	if (irExpr1 == NULL)
	{
		kid1->SetIRExpr(irExpr2);
		return kid1;
	}
	if (irExpr2 == NULL)
	{
		kid1->SetIRExpr(irExpr1);
		return kid1;
	}
	
	// we create a new Node as an op between the two subexpressions
	// and we append it to the first terminal node

	HIRCodeGen &codeGen = parserInfo->CodeGen;
	kid1->SetIRExpr(codeGen.BinOp(op, irExpr1, irExpr2));
	return kid1;
}

PFLExpression *GenNumber(struct ParserInfo *parserInfo, uint32 value)
{
	HIRCodeGen &codeGen = parserInfo->CodeGen;
	HIRNode *irExpr = codeGen.TermNode(IR_ICONST, codeGen.ConstIntSymbol(value));
	return GenTermNode(NULL, irExpr);
}

PFLExpression *GenString(struct ParserInfo *parserInfo, string value)
{
	HIRCodeGen &codeGen = parserInfo->CodeGen;
	HIRNode *irExpr = codeGen.TermNode(IR_SCONST,codeGen.ConstStrSymbol(value));
	return GenTermNode(NULL, irExpr);

}


PFLExpression *GenProtoBytesRef(YYLTYPE *llocp, ParserInfo *parserInfo, char *protocol, uint32 offs, uint32 len)
{
	GlobalSymbols &globalSymbols = *parserInfo->GlobalSyms;
	HIRCodeGen &codeGen = parserInfo->CodeGen;
	SymbolProto *protoSymbol = globalSymbols.LookUpProto(protocol);

	if (protoSymbol == NULL)
	{
		pfl_error(llocp, parserInfo, "Invalid PROTOCOL identifier");
		return NULL;
	}

	HIRNode *irExpr = codeGen.ProtoBytesRef(protoSymbol, offs, len);

	if (irExpr == NULL)
		throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");

	return GenTermNode(protoSymbol, irExpr);
}

PFLExpression *ManagePFLProtoField(char *protoName, ParserInfo *parserInfo, YYLTYPE *llocp){ 
	char *fieldName;
	GlobalSymbols &globalSymbols = *parserInfo->GlobalSyms;									
	SymbolField *fieldSym(0);
	fieldName = strchr(protoName, '.');

	if (fieldName != NULL)
	{
		*fieldName = '\0';
		fieldName++;
	}
	
	SymbolProto *protoSymbol = globalSymbols.LookUpProto(protoName);
		
	if (protoSymbol == NULL)
	{
		pfl_error(llocp, parserInfo, "Invalid PROTOCOL identifier");
		return NULL;

	}
	fieldSym = globalSymbols.LookUpProtoFieldByName(protoName, fieldName);
										
	if (fieldSym == NULL)
	{
		pfl_error(llocp, parserInfo, "The specified field is not valid for the specified protocol");
		return NULL;
	}
			
	HIRCodeGen &codeGen = parserInfo->CodeGen;
	Node *irExpr = codeGen.TermNode(IR_FIELD, fieldSym);
							
	if (irExpr == NULL)
		throw ErrorInfo(ERR_FATAL_ERROR, "MEMORY ALLOCATION FAILURE");									
	
	return GenTermNode(protoSymbol, irExpr); 
}

int pfl_error(YYLTYPE *llocp, struct ParserInfo *parserInfo, const char *s)
{
	parserInfo->ErrRecorder->PFLError(s);
	//fprintf(stderr, "%s\n", s);
	return 1;
}


void compile(ParserInfo *parserInfo, const char *filter, int debug)
{

#ifdef YYDEBUG
#if YYDEBUG != 0
	pfl_debug = debug;
#endif
#endif
	parserInfo->FilterString = string(filter);
	parserInfo->ResetFilter();
	pflcompiler_lex_init(filter);
	pfl_parse(parserInfo);
	pflcompiler_lex_cleanup();

} 
