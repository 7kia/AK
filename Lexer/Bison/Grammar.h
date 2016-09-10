
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
     ASSIGN = 274,
     Have_sign = 275,
     REFERENCE = 276,
     COMMAND_SEPARATOR = 277,
     VARIABLE_SEPARATOR = 278,
     CHAR = 279,
     STRING = 280,
     NAME_INTEGER = 281,
     NAME_FLOAT = 282,
     NAME_CHAR = 283,
     NAME_STRING = 284,
     NAME_LOGIC = 285,
     PREFIX_SIGNED = 286,
     PREFIX_UNSIGNED = 287,
     PREFIX_LONG = 288,
     PREFIX_CONST = 289,
     IF_OPERATOR = 290,
     ELSE_OPERATOR = 291,
     SWITCH_OPERATOR = 292,
     CASE_OPERATOR = 293,
     CASE_ENUMERATOR = 294,
     WHILE_OPERATOR = 295,
     DO_OPERATOR = 296,
     FOR_OPERATOR = 297,
     BREAK_OPERATOR = 298,
     CONTINUE_OPERATOR = 299,
     LOGIC = 300,
     NAME_RETURN = 301,
     Identificator = 302,
     ARRAY_ELEMENT = 303,
     START_LIST_ARGUMENTS = 304,
     END_LIST_ARGUMENTS = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


