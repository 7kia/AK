/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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

/**
 ** \file Grammar.h
 ** Define the example::parser class.
 */

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef YY_EXAMPLE_GRAMMAR_H_INCLUDED
# define YY_EXAMPLE_GRAMMAR_H_INCLUDED



#include <string>
#include <iostream>
#include "stack.hh"
#include "location.hh"
#include "src/AST/ASTNodes.h"
#include "src/ScannerPrivate.h"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace example {


  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {



    int  				integerValue;
    double 				doubleValue;
	bool				boolValue;
    std::string*		stringVal;// TODO : see need separately char
	unsigned int		stringId;

	std::vector<int>*	intVector;
	std::vector<float>*	floatVector;
	std::vector<bool>*	boolVector;

	IFunctionAST*		pFunction;
	IStatementAST*		pStatetment;
	IExpressionAST*		pExpression;
	CParameterDeclAST*  pParameterDecl;

	ExpressionList*		pExpressionList;
	StatementsList*		pStatementList;
	FunctionList*		pFunctionList;
	ParameterDeclList*  pParameterDeclList;



    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;
    /// Tokens.
    struct token
    {
      /* Tokens.  */
   enum yytokentype {
     END = 0,
     NEWLINE = 258,
     BLOCK_END = 259,
     FUNCTION = 260,
     PRINT = 261,
     START_BLOCK = 262,
     END_BLOCK = 263,
     DIGIT_MORE_ZERO = 264,
     DIGIT_ZERO = 265,
     DIGIT = 266,
     PLUS = 267,
     MINUS = 268,
     DIVIDE = 269,
     STAR = 270,
     PERCENT = 271,
     POWER = 272,
     LESS = 273,
     MORE = 274,
     NEGATION = 275,
     ASSIGN = 276,
     AMPERSAND = 277,
     PLUS_ASSIGN = 278,
     MINUS_ASSIGN = 279,
     MULTIPLY_ASSIGN = 280,
     DIVIDE_ASSIGN = 281,
     PERCENT_ASSIGN = 282,
     LOGIC_AND = 283,
     LOGIC_OR = 284,
     LESS_EQUAL = 285,
     MORE_EQUAL = 286,
     EQUAL = 287,
     NOT_EQUAL = 288,
     Have_sign = 289,
     REFERENCE = 290,
     COMMAND_SEPARATOR = 291,
     VARIABLE_SEPARATOR = 292,
     ONLY_STRING_COMMENT = 293,
     MULTI_STRING_COMMENT = 294,
     START_IDENTIFICATION = 295,
     END_IDENTIFICATION = 296,
     NAME_INTEGER = 297,
     NAME_FLOAT = 298,
     NAME_CHAR = 299,
     NAME_STRING = 300,
     NAME_LOGIC = 301,
     PREFIX_SIGNED = 302,
     PREFIX_UNSIGNED = 303,
     PREFIX_LONG = 304,
     PREFIX_CONST = 305,
     IF_OPERATOR = 306,
     ELSE_OPERATOR = 307,
     SWITCH_OPERATOR = 308,
     CASE_OPERATOR = 309,
     CASE_ENUMERATOR = 310,
     WHILE_OPERATOR = 311,
     DO_OPERATOR = 312,
     FOR_OPERATOR = 313,
     BREAK_OPERATOR = 314,
     CONTINUE_OPERATOR = 315,
     NAME_RETURN = 316,
     START_LIST_ARGUMENTS = 317,
     END_LIST_ARGUMENTS = 318,
     EQUALS = 319,
     NOT = 320,
     OR = 321,
     AND = 322,
     STRING = 323,
     FLOAT = 324,
     INT = 325,
     CHAR = 326,
     BOOL = 327,
     ID = 328
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    Parser (class CCompilerDriver& driver_yyarg);
    virtual ~Parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the lookahead token.
    virtual std::string yysyntax_error_ (int yystate, int tok);

#if YYDEBUG
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
					 const semantic_type* yyvaluep,
					 const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
				   const semantic_type* yyvaluep,
				   const location_type* yylocationp);
#endif


    /// State numbers.
    typedef int state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    /// Internal symbol numbers.
    typedef unsigned char token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const signed char yypact_ninf_;

    /// For a state, default reduction number.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned char yydefact_[];

    static const signed char yypgoto_[];
    static const signed char yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const signed char yytable_[];
    static const signed char yytable_ninf_;

    static const signed char yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned char yystos_[];

    /// For a rule, its LHS.
    static const unsigned char yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[]; 

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef signed char rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned char yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned short int yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    ///                     If null, do not display the symbol, just free it.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
			     int yytype,
			     semantic_type* yyvaluep,
			     location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

    /* User arguments.  */
    class CCompilerDriver& driver;
  };

} // example




#endif /* !YY_EXAMPLE_GRAMMAR_H_INCLUDED  */