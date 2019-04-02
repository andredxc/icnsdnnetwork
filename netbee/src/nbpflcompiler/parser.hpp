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
#line 44 "gramm.y" /* yacc.c:1909  */

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

#line 123 "parser.hpp" /* yacc.c:1909  */
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
