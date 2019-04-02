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

#ifndef YY_PDL_EXPR_GRAMMAR_TAB_H_INCLUDED
# define YY_PDL_EXPR_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int pdl_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OPERAND_NUMBER = 258,
    OPERAND_STRING = 259,
    OPERAND_BOOLEAN = 260,
    OPERAND_VARIABLE_NUMBER = 261,
    OPERAND_VARIABLE_STRING = 262,
    OPERAND_VARIABLE_LOOKUPTABLE = 263,
    FUNCTION_HASSTRING = 264,
    FUNCTION_EXTRACTSTRING = 265,
    FUNCTION_DEBUG = 266,
    FUNCTION_BUFFER2INT = 267,
    FUNCTION_INT2BUFFER = 268,
    FUNCTION_ISPRESENT = 269,
    FUNCTION_ISASN1TYPE = 270,
    FUNCTION_CHANGEBYTEORDER = 271,
    FUNCTION_ASCII2INT = 272,
    FUNCTION_CHECKLOOKUPTABLE = 273,
    FUNCTION_UPDATELOOKUPTABLE = 274,
    OPERAND_PROTOFIELD = 275,
    AND = 276,
    OR = 277,
    GE = 278,
    GT = 279,
    LE = 280,
    LT = 281,
    EQ = 282,
    NEQ = 283,
    BWAND = 284,
    BWOR = 285,
    ADD = 286,
    SUB = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    NOT = 291,
    BWNOT = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int pdl_parse (void **ParsedExpression);

#endif /* !YY_PDL_EXPR_GRAMMAR_TAB_H_INCLUDED  */
