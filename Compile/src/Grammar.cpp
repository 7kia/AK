/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
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

// Take the name prefix into account.
#define yylex   examplelex

/* First part of user declarations.  */


#pragma warning( disable : 4065 603 )  

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO : YYSTYPE - it is token
//#define YYSTYPE double

extern int yylex();

#include "src/driver.h"
#include "src/scanner.h"
// TODO : transfer to Grammar.h
#include "src/AST/ASTNodes.h"
#include "src/ScannerPrivate.h"

// TODO : transfer after Grammar.h
using namespace scanner_private;
/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer.lex





#include "Grammar.h"

/* User implementation prologue.  */




# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace example {


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (class CCompilerDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 68: /* "string" */

        { delete ((*yyvaluep).stringVal); };

        break;
      case 71: /* "char" */

        { delete ((*yyvaluep).stringVal); };

        break;
      case 75: /* constant */

        { delete ((*yyvaluep).pExpression); };

        break;
      case 76: /* variable */

        { delete ((*yyvaluep).pExpression); };

        break;
      case 77: /* function_call */

        { delete ((*yyvaluep).pExpression); };

        break;
      case 78: /* expression */

        { delete ((*yyvaluep).pExpression); };

        break;
      case 79: /* expression_list */

        { delete ((*yyvaluep).pExpressionList); };

        break;
      case 81: /* statement */

        { delete ((*yyvaluep).pStatetment); };

        break;
      case 82: /* statement_line */

        { delete ((*yyvaluep).pStatetment); };

        break;
      case 83: /* statement_list */

        { delete ((*yyvaluep).pStatementList); };

        break;
      case 84: /* block */

        { delete ((*yyvaluep).pStatementList); };

        break;
      case 85: /* parameter_decl */

        { delete ((*yyvaluep).pParameterDecl); };

        break;
      case 86: /* parameter_list */

        { delete ((*yyvaluep).pParameterDeclList); };

        break;
      case 87: /* function_declaration */

        { delete ((*yyvaluep).pFunction); };

        break;
      case 88: /* parenthesis_parameter_list */

        { delete ((*yyvaluep).pParameterDeclList); };

        break;

	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


/* User initialization code.  */

{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval, &yylloc);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:

    {
				EmplaceAST<CLiteralAST>((yyval.pExpression), CLiteralAST::Value((yysemantic_stack_[(1) - (1)].boolValue)));
			}
    break;

  case 3:

    {
			EmplaceAST<CLiteralAST>((yyval.pExpression), CLiteralAST::Value((yysemantic_stack_[(1) - (1)].integerValue)));
		}
    break;

  case 4:

    {
			EmplaceAST<CLiteralAST>((yyval.pExpression), CLiteralAST::Value((yysemantic_stack_[(1) - (1)].doubleValue)));
		}
    break;

  case 5:

    {
			EmplaceAST<CLiteralAST>((yyval.pExpression), CLiteralAST::Value(*(yysemantic_stack_[(1) - (1)].stringVal)));
		}
    break;

  case 6:

    {
				EmplaceAST<CVariableRefAST>((yyval.pExpression), (yysemantic_stack_[(1) - (1)].stringId));
			}
    break;

  case 7:

    {
					EmplaceAST<CCallAST>((yyval.pExpression), (yysemantic_stack_[(3) - (1)].stringId), ExpressionList());
				}
    break;

  case 8:

    {
					auto pList = Take((yysemantic_stack_[(4) - (3)].pExpressionList));
					EmplaceAST<CCallAST>((yyval.pExpression), (yysemantic_stack_[(4) - (1)].stringId), std::move(*pList));
				}
    break;

  case 12:

    {
			MovePointer((yysemantic_stack_[(3) - (2)].pExpression), (yyval.pExpression));
		}
    break;

  case 13:

    {
			EmplaceAST<CUnaryExpressionAST>((yyval.pExpression), UnaryOperation::Plus, Take((yysemantic_stack_[(2) - (2)].pExpression)));
		}
    break;

  case 14:

    {
			EmplaceAST<CUnaryExpressionAST>((yyval.pExpression), UnaryOperation::Minus, Take((yysemantic_stack_[(2) - (2)].pExpression)));
		}
    break;

  case 15:

    {
			EmplaceAST<CBinaryExpressionAST>((yyval.pExpression), Take((yysemantic_stack_[(3) - (1)].pExpression)), BinaryOperation::Less, Take((yysemantic_stack_[(3) - (3)].pExpression)));
		}
    break;

  case 16:

    {
			EmplaceAST<CBinaryExpressionAST>((yyval.pExpression), Take((yysemantic_stack_[(3) - (1)].pExpression)), BinaryOperation::Equals, Take((yysemantic_stack_[(3) - (3)].pExpression)));
		}
    break;

  case 17:

    {
			EmplaceAST<CBinaryExpressionAST>((yyval.pExpression), Take((yysemantic_stack_[(3) - (1)].pExpression)), BinaryOperation::Add, Take((yysemantic_stack_[(3) - (3)].pExpression)));
		}
    break;

  case 18:

    {
			EmplaceAST<CBinaryExpressionAST>((yyval.pExpression), Take((yysemantic_stack_[(3) - (1)].pExpression)), BinaryOperation::Substract, Take((yysemantic_stack_[(3) - (3)].pExpression)));
		}
    break;

  case 19:

    {
			EmplaceAST<CBinaryExpressionAST>((yyval.pExpression), Take((yysemantic_stack_[(3) - (1)].pExpression)), BinaryOperation::Multiply, Take((yysemantic_stack_[(3) - (3)].pExpression)));
		}
    break;

  case 20:

    {
			EmplaceAST<CBinaryExpressionAST>((yyval.pExpression), Take((yysemantic_stack_[(3) - (1)].pExpression)), BinaryOperation::Divide, Take((yysemantic_stack_[(3) - (3)].pExpression)));
		}
    break;

  case 21:

    {
			EmplaceAST<CBinaryExpressionAST>((yyval.pExpression), Take((yysemantic_stack_[(3) - (1)].pExpression)), BinaryOperation::Modulo, Take((yysemantic_stack_[(3) - (3)].pExpression)));
		}
    break;

  case 22:

    {
					CreateList((yyval.pExpressionList), (yysemantic_stack_[(1) - (1)].pExpression));
				}
    break;

  case 23:

    {
					ConcatList((yyval.pExpressionList), (yysemantic_stack_[(3) - (1)].pExpressionList), (yysemantic_stack_[(3) - (3)].pExpression));
				}
    break;

  case 24:

    {
					(yyval.integerValue) = static_cast<int>(ExpressionType::Float);
				}
    break;

  case 25:

    {
				// TODO : add
					(yyval.integerValue) = static_cast<int>(ExpressionType::Integer);
				}
    break;

  case 26:

    {
					(yyval.integerValue) = static_cast<int>(ExpressionType::String);
				}
    break;

  case 27:

    {
					(yyval.integerValue) = static_cast<int>(ExpressionType::Boolean);
				}
    break;

  case 28:

    {
			// TODO : see need instead expression expression_list
				EmplaceAST<CPrintAST>((yyval.pStatetment), Take((yysemantic_stack_[(4) - (3)].pExpression)));
			}
    break;

  case 29:

    {
				EmplaceAST<CAssignAST>((yyval.pStatetment), (yysemantic_stack_[(4) - (2)].stringId), Take((yysemantic_stack_[(4) - (4)].pExpression)));// TODO : not use type_reference
			}
    break;

  case 30:

    {
				EmplaceAST<CReturnAST>((yyval.pStatetment), Take((yysemantic_stack_[(2) - (2)].pExpression)));
			}
    break;

  case 31:

    {
			// TODO : see need exmpty
				auto pThenBody = Take((yysemantic_stack_[(5) - (5)].pStatementList));
				EmplaceAST<CIfAst>((yyval.pStatetment), Take((yysemantic_stack_[(5) - (3)].pExpression)), std::move(*pThenBody));
			}
    break;

  case 32:

    {
				auto pThenBody = Take((yysemantic_stack_[(7) - (5)].pStatementList));
				auto pElseBody = Take((yysemantic_stack_[(7) - (7)].pStatementList));
				EmplaceAST<CIfAst>((yyval.pStatetment), Take((yysemantic_stack_[(7) - (3)].pExpression)), std::move(*pThenBody), std::move(*pElseBody));
			}
    break;

  case 33:

    {
				auto pBody = Take((yysemantic_stack_[(5) - (5)].pStatementList));
				EmplaceAST<CWhileAst>((yyval.pStatetment), Take((yysemantic_stack_[(5) - (3)].pExpression)), std::move(*pBody));
			}
    break;

  case 34:

    {
				auto pBody = Take((yysemantic_stack_[(6) - (2)].pStatementList));
				EmplaceAST<CRepeatAst>((yyval.pStatetment), Take((yysemantic_stack_[(6) - (5)].pExpression)), std::move(*pBody));
			}
    break;

  case 35:

    {
				EmplaceAST<CRepeatAst>((yyval.pStatetment), Take((yysemantic_stack_[(5) - (4)].pExpression)));
			}
    break;

  case 36:

    {
				// TODO : see need COMMAND_SEPARATOR
				(yyval.pStatetment) = nullptr;
				}
    break;

  case 37:

    {
					MovePointer((yysemantic_stack_[(2) - (1)].pStatetment), (yyval.pStatetment));
				}
    break;

  case 38:

    {
						CreateList((yyval.pStatementList), (yysemantic_stack_[(1) - (1)].pStatetment));
					}
    break;

  case 39:

    {
						ConcatList((yyval.pStatementList), (yysemantic_stack_[(2) - (1)].pStatementList), (yysemantic_stack_[(2) - (2)].pStatetment));
					}
    break;

  case 40:

    {
	(yyval.pStatementList) = (yysemantic_stack_[(3) - (2)].pStatementList);
}
    break;

  case 41:

    {
	(yyval.pStatementList) = nullptr;
}
    break;

  case 42:

    {
						EmplaceAST<CParameterDeclAST>((yyval.pParameterDecl), (yysemantic_stack_[(2) - (2)].stringId), static_cast<ExpressionType>((yysemantic_stack_[(2) - (1)].integerValue)));
					}
    break;

  case 43:

    {
						CreateList((yyval.pParameterDeclList), (yysemantic_stack_[(1) - (1)].pParameterDecl));
					}
    break;

  case 44:

    {
					ConcatList((yyval.pParameterDeclList), (yysemantic_stack_[(3) - (1)].pParameterDeclList), (yysemantic_stack_[(3) - (3)].pParameterDecl));
				}
    break;

  case 45:

    {
							auto pParameters = Take((yysemantic_stack_[(4) - (3)].pParameterDeclList));
							auto pBody = Take((yysemantic_stack_[(4) - (4)].pStatementList));
							ExpressionType returnType = static_cast<ExpressionType>((yysemantic_stack_[(4) - (1)].integerValue));
							EmplaceAST<CFunctionAST>((yyval.pFunction), (yysemantic_stack_[(4) - (2)].stringId), returnType, std::move(*pParameters), std::move(*pBody));
						}
    break;

  case 46:

    {
								(yyval.pParameterDeclList) = Make<ParameterDeclList>().release();
							}
    break;

  case 47:

    {
								MovePointer((yysemantic_stack_[(3) - (2)].pParameterDeclList), (yyval.pParameterDeclList));
							}
    break;

  case 48:

    {
					// TODO : see can it simplify
						 driver.lexer.m_pProgram->AddFunction(Take((yysemantic_stack_[(1) - (1)].pFunction)));
					}
    break;



      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -54;
  const short int
  Parser::yypact_[] =
  {
       164,   -17,   -54,   -54,   -54,   -54,   -54,   -53,   -54,    -4,
     -54,   150,    33,   -54,   -27,   -54,   -54,   -54,    50,    37,
     -54,   -36,   -54,   -29,    30,   -54,   -54,    83,   -54,     9,
     -16,   -54,   -13,   -12,    22,    -2,    -8,    17,   -54,    76,
     -54,   -54,    -2,    -2,    -2,    -6,    23,    -2,    -2,    -2,
     -54,   -54,   -54,   -54,    18,   -54,   -54,   -54,    10,    62,
     -54,   -54,   -54,    -9,     0,    85,    -2,    26,    25,    25,
     141,   -11,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
     -54,    37,    37,   148,    -2,   -54,   -54,    10,   -20,    25,
      25,   -54,   -54,   -54,    92,    92,    10,    38,   -54,   -54,
     158,    -2,   -54,    37,   -54,    10,   -54
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,    49,    25,    24,    26,    27,     0,    48,     0,
      52,     0,     0,    51,     0,    50,    53,     1,     0,     0,
      46,     0,    43,     0,     0,    45,    42,     0,    47,     0,
       0,    41,     0,     0,     0,     0,     0,     0,    38,     0,
      44,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     4,     3,     2,     6,     9,    11,    10,    30,     0,
      37,    40,    39,     0,     0,     0,     0,     0,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     0,    12,     7,    22,     0,    17,
      18,    20,    19,    21,    15,    16,    29,    31,    33,    35,
       0,     0,     8,     0,    34,    23,    32
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
       -54,   -54,   -54,   -54,    68,   -54,     3,   -54,    46,   -54,
     -34,    67,   -54,   -54,   -54,   -54,    78,   -54,   -54
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,    55,    56,    57,    58,    88,     7,    37,    38,    39,
      25,    22,    23,     8,    19,     9,    10,    11,    12
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Parser::yytable_ninf_ = -55;
  const signed char
  Parser::yytable_[] =
  {
        46,    47,    48,    72,    73,    74,    75,    76,    27,    77,
      47,    48,    72,    73,    74,    75,    76,   101,    77,    13,
      14,    21,    72,    73,    74,    75,    76,    36,    77,    24,
      21,    29,    15,    17,    28,    18,    30,    26,    31,    74,
      75,    76,    36,   102,    24,    41,    42,    97,    98,    43,
      44,    49,    86,    60,    80,    78,    66,    50,    51,    52,
      49,    53,    54,    81,    78,    59,    50,    51,    52,   106,
      53,    54,     3,     4,    78,     5,     6,    29,    45,    67,
      71,    32,    30,    79,    61,    62,    33,    34,    84,    16,
     103,    35,     3,     4,    40,     5,     6,    72,    73,    74,
      75,    76,     0,    77,    72,    73,    74,    75,    76,     0,
      63,    64,    65,    20,     0,    68,    69,    70,     3,     4,
       0,     5,     6,     0,     0,     3,     4,    32,     5,     6,
       0,     0,    33,    34,    83,     0,     0,    35,     0,    87,
      89,    90,    91,    92,    93,    94,    95,    96,    82,    78,
     -54,     1,   100,    72,    73,    74,    75,    76,     0,    77,
      72,    73,    74,    75,    76,     1,    77,     0,     0,   105,
      72,    73,    74,    75,    76,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     3,     4,     0,     5,     6,     0,     0,     0,
       2,     0,     0,     0,    85,    78,     3,     4,     0,     5,
       6,    99,    78,     0,     0,     0,     0,     0,     0,     0,
       0,   104,    78
  };

  /* YYCHECK.  */
  const signed char
  Parser::yycheck_[] =
  {
        34,    12,    13,    12,    13,    14,    15,    16,    37,    18,
      12,    13,    12,    13,    14,    15,    16,    37,    18,    36,
      73,    18,    12,    13,    14,    15,    16,    24,    18,     7,
      27,     1,    36,     0,    63,    62,     6,    73,     8,    14,
      15,    16,    39,    63,     7,    36,    62,    81,    82,    62,
      62,    62,    63,    36,    63,    64,    62,    68,    69,    70,
      62,    72,    73,    63,    64,    73,    68,    69,    70,   103,
      72,    73,    42,    43,    64,    45,    46,     1,    56,    56,
      62,    51,     6,    21,     8,    39,    56,    57,    62,    11,
      52,    61,    42,    43,    27,    45,    46,    12,    13,    14,
      15,    16,    -1,    18,    12,    13,    14,    15,    16,    -1,
      42,    43,    44,    63,    -1,    47,    48,    49,    42,    43,
      -1,    45,    46,    -1,    -1,    42,    43,    51,    45,    46,
      -1,    -1,    56,    57,    66,    -1,    -1,    61,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    63,    64,
       0,     1,    84,    12,    13,    14,    15,    16,    -1,    18,
      12,    13,    14,    15,    16,     1,    18,    -1,    -1,   101,
      12,    13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    45,    46,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    63,    64,    42,    43,    -1,    45,
      46,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     1,    36,    42,    43,    45,    46,    80,    87,    89,
      90,    91,    92,    36,    73,    36,    90,     0,    62,    88,
      63,    80,    85,    86,     7,    84,    73,    37,    63,     1,
       6,     8,    51,    56,    57,    61,    80,    81,    82,    83,
      85,    36,    62,    62,    62,    56,    84,    12,    13,    62,
      68,    69,    70,    72,    73,    75,    76,    77,    78,    73,
      36,     8,    82,    78,    78,    78,    62,    56,    78,    78,
      78,    62,    12,    13,    14,    15,    16,    18,    64,    21,
      63,    63,    63,    78,    62,    63,    63,    78,    79,    78,
      78,    78,    78,    78,    78,    78,    78,    84,    84,    63,
      78,    37,    63,    52,    63,    78,    84
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    74,    75,    75,    75,    75,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    80,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    86,    86,    87,    88,    88,    89,    90,
      90,    90,    91,    91,    92
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     1,     1,     3,     4,     1,
       1,     1,     3,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     4,     4,
       2,     5,     7,     5,     6,     5,     2,     2,     1,     2,
       3,     2,     2,     1,     3,     4,     2,     3,     1,     1,
       2,     2,     1,     2,     1
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"end of line\"", "\"end\"",
  "\"def\"", "\"print\"", "START_BLOCK", "END_BLOCK", "DIGIT_MORE_ZERO",
  "DIGIT_ZERO", "DIGIT", "PLUS", "MINUS", "DIVIDE", "STAR", "PERCENT",
  "POWER", "LESS", "MORE", "NEGATION", "ASSIGN", "AMPERSAND",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN",
  "PERCENT_ASSIGN", "LOGIC_AND", "LOGIC_OR", "LESS_EQUAL", "MORE_EQUAL",
  "EQUAL", "NOT_EQUAL", "Have_sign", "REFERENCE", "COMMAND_SEPARATOR",
  "VARIABLE_SEPARATOR", "ONLY_STRING_COMMENT", "MULTI_STRING_COMMENT",
  "START_IDENTIFICATION", "END_IDENTIFICATION", "NAME_INTEGER",
  "NAME_FLOAT", "NAME_CHAR", "NAME_STRING", "NAME_LOGIC", "PREFIX_SIGNED",
  "PREFIX_UNSIGNED", "PREFIX_LONG", "PREFIX_CONST", "IF_OPERATOR",
  "ELSE_OPERATOR", "SWITCH_OPERATOR", "CASE_OPERATOR", "CASE_ENUMERATOR",
  "WHILE_OPERATOR", "DO_OPERATOR", "FOR_OPERATOR", "BREAK_OPERATOR",
  "CONTINUE_OPERATOR", "NAME_RETURN", "START_LIST_ARGUMENTS",
  "END_LIST_ARGUMENTS", "EQUALS", "NOT", "OR", "AND", "\"string\"",
  "\"float\"", "\"int\"", "\"char\"", "\"bool\"", "\"Id\"", "$accept",
  "constant", "variable", "function_call", "expression", "expression_list",
  "type_reference", "statement", "statement_line", "statement_list",
  "block", "parameter_decl", "parameter_list", "function_declaration",
  "parenthesis_parameter_list", "toplevel_statement", "toplevel_line",
  "toplevel_list", "program", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        92,     0,    -1,    72,    -1,    70,    -1,    69,    -1,    68,
      -1,    73,    -1,    73,    62,    63,    -1,    73,    62,    79,
      63,    -1,    75,    -1,    77,    -1,    76,    -1,    62,    78,
      63,    -1,    12,    78,    -1,    13,    78,    -1,    78,    18,
      78,    -1,    78,    64,    78,    -1,    78,    12,    78,    -1,
      78,    13,    78,    -1,    78,    15,    78,    -1,    78,    14,
      78,    -1,    78,    16,    78,    -1,    78,    -1,    79,    37,
      78,    -1,    43,    -1,    42,    -1,    45,    -1,    46,    -1,
       6,    62,    78,    63,    -1,    80,    73,    21,    78,    -1,
      61,    78,    -1,    51,    62,    78,    63,    84,    -1,    51,
      62,    78,    63,    84,    52,    84,    -1,    56,    62,    78,
      63,    84,    -1,    57,    84,    56,    62,    78,    63,    -1,
      57,    56,    62,    78,    63,    -1,     1,    36,    -1,    81,
      36,    -1,    82,    -1,    83,    82,    -1,     7,    83,     8,
      -1,     7,     8,    -1,    80,    73,    -1,    85,    -1,    86,
      37,    85,    -1,    80,    73,    88,    84,    -1,    62,    63,
      -1,    62,    86,    63,    -1,    87,    -1,    36,    -1,    89,
      36,    -1,     1,    36,    -1,    90,    -1,    91,    90,    -1,
      91,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    11,    13,    17,    22,
      24,    26,    28,    32,    35,    38,    42,    46,    50,    54,
      58,    62,    66,    68,    72,    74,    76,    78,    80,    85,
      90,    93,    99,   107,   113,   120,   126,   129,   132,   134,
     137,   141,   144,   147,   149,   153,   158,   161,   165,   167,
     169,   172,   175,   177,   180
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   244,   246,   250,   255,   259,   264,   269,   273,   279,
     280,   281,   282,   286,   290,   294,   298,   302,   306,   310,
     314,   318,   330,   334,   345,   349,   361,   365,   374,   379,
     383,   388,   395,   401,   406,   411,   417,   422,   427,   431,
     436,   441,   446,   451,   455,   462,   471,   475,   481,   487,
     488,   489,   491,   492,   494
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 222;
  const int Parser::yynnts_ = 19;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 17;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 74;

  const unsigned int Parser::yyuser_token_number_max_ = 328;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // example


 /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
