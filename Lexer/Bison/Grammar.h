
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
     START_BLOCK = 259,
     END_BLOCK = 260,
     DIGIT_MORE_ZERO = 261,
     DIGIT_ZERO = 262,
     DIGIT = 263,
     INT = 264,
     FLOAT = 265,
     PLUS = 266,
     MINUS = 267,
     DIVIDE = 268,
     STAR = 269,
     ASSIGN = 270,
     Have_sign = 271,
     REFERENCE = 272,
     COMMAND_SEPARATOR = 273,
     VARIABLE_SEPARATOR = 274,
     CHAR = 275,
     STRING = 276,
     NAME_INTEGER = 277,
     NAME_FLOAT = 278,
     NAME_CHAR = 279,
     NAME_STRING = 280,
     NAME_LOGIC = 281,
     PREFIX_SIGNED = 282,
     PREFIX_UNSIGNED = 283,
     PREFIX_LONG = 284,
     PREFIX_CONST = 285,
     LOGIC = 286,
     NAME_RETURN = 287,
     Identificator = 288,
     ARRAY_ELEMENT = 289,
     START_LIST_ARGUMENTS = 290,
     END_LIST_ARGUMENTS = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


