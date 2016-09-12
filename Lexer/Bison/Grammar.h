
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BYE = 258,
     NAME_MAIN_FUNCTION = 259,
     START_BLOCK = 260,
     END_BLOCK = 261,
     DIGIT_MORE_ZERO = 262,
     DIGIT_ZERO = 263,
     DIGIT = 264,
     INT = 265,
     FLOAT = 266,
     PLUS = 267,
     MINUS = 268,
     DIVIDE = 269,
     STAR = 270,
     PERCENT = 271,
     LESS = 272,
     MORE = 273,
     NEGATION = 274,
     ASSIGN = 275,
     AMPERSAND = 276,
     PLUS_ASSIGN = 277,
     MINUS_ASSIGN = 278,
     MULTIPLY_ASSIGN = 279,
     DIVIDE_ASSIGN = 280,
     PERCENT_ASSIGN = 281,
     LOGIC_AND = 282,
     LOGIC_OR = 283,
     LESS_EQUAL = 284,
     MORE_EQUAL = 285,
     EQUAL = 286,
     NOT_EQUAL = 287,
     Have_sign = 288,
     REFERENCE = 289,
     COMMAND_SEPARATOR = 290,
     VARIABLE_SEPARATOR = 291,
     ONLY_STRING_COMMENT = 292,
     MULTI_STRING_COMMENT = 293,
     START_IDENTIFICATION = 294,
     END_IDENTIFICATION = 295,
     CHAR = 296,
     STRING = 297,
     NAME_INTEGER = 298,
     NAME_FLOAT = 299,
     NAME_CHAR = 300,
     NAME_STRING = 301,
     NAME_LOGIC = 302,
     PREFIX_SIGNED = 303,
     PREFIX_UNSIGNED = 304,
     PREFIX_LONG = 305,
     PREFIX_CONST = 306,
     IF_OPERATOR = 307,
     ELSE_OPERATOR = 308,
     SWITCH_OPERATOR = 309,
     CASE_OPERATOR = 310,
     CASE_ENUMERATOR = 311,
     WHILE_OPERATOR = 312,
     DO_OPERATOR = 313,
     FOR_OPERATOR = 314,
     BREAK_OPERATOR = 315,
     CONTINUE_OPERATOR = 316,
     LOGIC = 317,
     NAME_RETURN = 318,
     Identificator = 319,
     START_LIST_ARGUMENTS = 320,
     END_LIST_ARGUMENTS = 321
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


