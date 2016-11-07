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



#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO : YYSTYPE - it is token
//#define YYSTYPE double

extern int yylex();

#include "src/driver.h"
#include "Lexer.h"
#include "src/CalcContext.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex





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
  Parser::Parser (class Driver& driver_yyarg)
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
        case 61: /* "string" */

        { delete ((*yyvaluep).stringVal); };

        break;
      case 62: /* "char" */

        { delete ((*yyvaluep).stringVal); };

        break;
      case 63: /* "bool" */

        { delete ((*yyvaluep).boolValue); };

        break;
      case 73: /* Variable */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 74: /* Number */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 77: /* Literal */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 88: /* atomexpr */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 89: /* powexpr */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 90: /* unaryexpr */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 91: /* mulexpr */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 92: /* addexpr */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 93: /* Arithmetic_expression */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 94: /* Value */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 101: /* Left_part_assign */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 102: /* Right_part_assign */

        { delete ((*yyvaluep).calcnode); };

        break;
      case 144: /* Call_function */

        { delete ((*yyvaluep).calcnode); };

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

    { exit(0); }
    break;

  case 14:

    {
			if (!driver.calc.existsVariable(*(yysemantic_stack_[(1) - (1)].stringVal))) 
			{
				error(yyloc, std::string("Unknown variable \"") + *(yysemantic_stack_[(1) - (1)].stringVal) + "\"");
				delete (yysemantic_stack_[(1) - (1)].stringVal);
				YYERROR;
			}
			else 
			{
				(yyval.calcnode) = new CNConstant( driver.calc.getVariable(*(yysemantic_stack_[(1) - (1)].stringVal)) );
				delete (yysemantic_stack_[(1) - (1)].stringVal);
			}
		}
    break;

  case 15:

    {
				(yyval.calcnode) = new CNConstant((yysemantic_stack_[(1) - (1)].doubleValue));
			}
    break;

  case 16:

    {
				(yyval.calcnode) = new CNConstant((yysemantic_stack_[(1) - (1)].integerValue));
			}
    break;

  case 22:

    {
				(yyval.calcnode) = (yysemantic_stack_[(1) - (1)].calcnode);
			}
    break;

  case 23:

    {
				(yyval.calcnode) = new CNBool((yysemantic_stack_[(1) - (1)].boolValue));
			}
    break;

  case 24:

    {
				(yyval.calcnode) = new CNChar((yysemantic_stack_[(1) - (1)].stringVal));
			}
    break;

  case 25:

    {
				(yyval.calcnode) = new CNConstant((yysemantic_stack_[(1) - (1)].stringVal));
			}
    break;

  case 37:

    {
						driver.calc.expressions.push_back((yysemantic_stack_[(1) - (1)].calcnode));
					}
    break;

  case 51:

    {
				(yyval.calcnode) = (yysemantic_stack_[(1) - (1)].calcnode);
			}
    break;

  case 52:

    {
				(yyval.calcnode) = (yysemantic_stack_[(1) - (1)].calcnode);
			}
    break;

  case 53:

    {
				(yyval.calcnode) = (yysemantic_stack_[(3) - (2)].calcnode);
			}
    break;

  case 54:

    {
	      (yyval.calcnode) = (yysemantic_stack_[(1) - (1)].calcnode);
	  }
    break;

  case 55:

    {
	      (yyval.calcnode) = new CNPower(dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (1)].calcnode)), dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (3)].calcnode)));
	  }
    break;

  case 56:

    {
		(yyval.calcnode) = (yysemantic_stack_[(1) - (1)].calcnode);
	    }
    break;

  case 57:

    {
		(yyval.calcnode) = (yysemantic_stack_[(2) - (2)].calcnode);
	    }
    break;

  case 58:

    {
		(yyval.calcnode) = new CNNegate(dynamic_cast<CalcNode*>((yysemantic_stack_[(2) - (2)].calcnode)));
	    }
    break;

  case 59:

    {
				(yyval.calcnode) = (yysemantic_stack_[(1) - (1)].calcnode);
			}
    break;

  case 60:

    {
				(yyval.calcnode) = new CNMultiply(dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (1)].calcnode)), dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (3)].calcnode)));
			}
    break;

  case 61:

    {
				(yyval.calcnode) = new CNDivide(dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (1)].calcnode)), dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (3)].calcnode)));
			}
    break;

  case 62:

    {
				(yyval.calcnode) = new CNModulo(dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (1)].calcnode)), dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (3)].calcnode)));
			}
    break;

  case 63:

    {
				(yyval.calcnode) = (yysemantic_stack_[(1) - (1)].calcnode);
			}
    break;

  case 64:

    {
				(yyval.calcnode) = new CNAdd(dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (1)].calcnode)), dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (3)].calcnode)));
			}
    break;

  case 65:

    {
				(yyval.calcnode) = new CNSubtract(dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (1)].calcnode)), dynamic_cast<CalcNode*>((yysemantic_stack_[(3) - (3)].calcnode)));
			}
    break;

  case 66:

    {
				(yyval.calcnode) = (yysemantic_stack_[(1) - (1)].calcnode);
			}
    break;

  case 70:

    {
							driver.calc.variables[*(yysemantic_stack_[(3) - (1)].calcnode)] = (yysemantic_stack_[(3) - (3)].calcnode)->evaluate();
							yyout << "Setting variable " << *(yysemantic_stack_[(3) - (1)].calcnode)
								<< " = " << driver.calc.variables[*(yysemantic_stack_[(3) - (1)].calcnode)] << "\n";
							delete (yysemantic_stack_[(3) - (1)].calcnode);
							delete (yysemantic_stack_[(3) - (3)].calcnode);
					}
    break;

  case 77:

    { driver.m_idsFile << "\nStart Init_list_values ";  }
    break;

  case 78:

    { driver.m_idsFile << "\nEnd Init_list_values ";  }
    break;

  case 98:

    {	
				 	driver.m_idsFile << "\n End main() \n";
					
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
  const short int Parser::yypact_ninf_ = -159;
  const short int
  Parser::yypact_[] =
  {
       -13,  -159,    32,     6,   134,     5,     3,    60,  -159,  -159,
      31,  -159,  -159,    29,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,    21,    40,  -159,    40,  -159,   141,  -159,    31,
    -159,  -159,  -159,     9,   -17,    60,  -159,   -26,   -26,    98,
      43,    44,    43,    60,    46,  -159,  -159,    98,    42,  -159,
    -159,  -159,  -159,  -159,    50,   115,   141,    93,   199,   159,
    -159,  -159,  -159,   130,  -159,  -159,   119,    35,  -159,   113,
    -159,    61,  -159,    81,    68,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,   121,
      89,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
      98,    60,  -159,    98,   149,    60,   103,   -38,  -159,   105,
    -159,  -159,  -159,   -26,    42,    42,    42,    42,    42,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,    -3,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,    52,   129,  -159,  -159,    98,
    -159,   -13,  -159,  -159,   -10,   122,   132,   123,   133,  -159,
    -159,    43,  -159,  -159,   125,   153,  -159,  -159,  -159,  -159,
    -159,   119,   119,  -159,  -159,  -159,  -159,  -159,    98,   129,
     156,   121,    98,  -159,  -159,  -159,    22,  -159,  -159,  -159,
      98,   187,    60,   133,  -159,    60,    -3,    52,   163,   129,
    -159,  -159,   156,   132,  -159,  -159,   162,  -159,   133,  -159,
     133,  -159,  -159,   182,  -159,  -159,   184,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,    10,    52,   211,   101,  -159,  -159,
    -159,   184,  -159,  -159
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
        27,    28,     0,    35,     0,     0,     0,    96,   147,     2,
      27,    95,     1,     0,    94,    17,    18,    19,    31,    32,
      29,    26,    33,     0,   103,     0,   100,    27,   148,    27,
      99,    36,    34,     0,    27,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   134,     0,     0,    25,
      24,    23,    16,    15,    14,     0,    27,     0,    68,    22,
      69,     7,    38,    54,    56,    59,    63,    66,    37,    49,
       8,     0,    83,     0,     0,     9,   104,   105,    10,   122,
     123,   124,    11,    67,    12,   101,    20,    21,    30,   145,
       0,    98,    14,    52,    51,    57,    58,    68,    22,    47,
     138,     0,   107,     0,     0,     0,     0,    27,   149,     0,
       3,     4,     6,     0,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    48,    76,
      71,    72,    73,    74,    75,     0,    93,    92,    87,   138,
     146,    27,   142,   141,     0,     0,   108,     0,   116,   113,
     125,     0,    84,   130,     0,     0,    53,    55,    61,    60,
      62,    64,    65,    50,    77,    85,    86,    70,     0,    91,
     140,   145,     0,   126,   137,   136,     0,   106,   109,   114,
       0,     0,     0,   120,   127,     0,     0,     0,     0,    91,
      88,   144,   140,   108,   111,   110,     0,   115,   116,   118,
     120,   128,   131,     0,    79,    80,    82,    89,    90,   139,
     112,   121,   117,   119,    27,     0,     0,    52,   133,   132,
     129,    82,    78,    81
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -159,  -159,   -28,   168,  -159,  -159,   -27,   -21,  -159,  -159,
    -159,  -159,   222,  -159,  -159,  -159,  -159,  -159,  -159,  -114,
    -159,  -159,   -15,    20,   -63,  -159,   -47,   -35,  -104,  -159,
      91,  -159,    12,     7,  -159,  -159,   -29,  -159,    94,    45,
    -159,    37,  -159,  -159,  -159,  -159,   229,   202,   228,  -159,
      59,   -40,    47,  -159,  -159,  -159,  -159,  -159,    38,  -159,
      39,  -158,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,   164,  -159,    49,   212,  -159,    71,  -159,  -159,  -159
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     2,    28,    55,    56,    57,    97,    98,    20,    88,
      60,     3,     4,    21,    22,    33,    14,    61,   127,    62,
     128,    63,    64,    65,    66,    67,    68,    69,    70,   135,
     205,   187,   206,   216,    71,   167,    72,   137,   189,   190,
     138,    73,     6,     7,     8,     9,    29,    30,    74,    75,
      76,   101,   177,   178,   195,    77,   104,   149,   181,   182,
     199,   183,    78,    79,    80,    81,   154,   155,   203,   220,
      82,   102,   145,   174,    35,    90,   142,    83,    11,    84
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int Parser::yytable_ninf_ = -144;
  const short int
  Parser::yytable_[] =
  {
        58,   109,   105,   153,    99,    89,    59,    91,    23,     1,
      93,    93,   108,   163,    39,   106,    94,    94,   -27,    37,
      38,    93,    95,    96,   172,   200,    27,    94,    92,    58,
       1,  -102,    12,    48,     1,    59,    26,     5,    52,    53,
      92,    31,   200,  -143,   117,   118,   136,     5,    86,    87,
     173,    37,    38,     1,   161,   162,   164,     1,    49,    50,
      51,    52,    53,    54,    27,   144,     5,    32,   147,    48,
      40,    24,   202,   146,    52,    53,    92,   150,     1,   129,
     152,   130,   131,   132,   133,   134,    93,    93,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    94,   157,    34,
     165,    48,   100,   103,   170,   107,    52,    53,    92,  -103,
     219,   184,   171,    49,    50,    51,    52,    53,    54,   -84,
     110,   -84,   -84,   -84,   -84,   -84,   112,   139,   119,   120,
     114,   115,   116,   188,   158,   159,   160,   192,   121,   122,
     123,   124,   125,   126,   113,   196,    -5,    92,   193,   143,
      37,    38,   204,   148,   198,   141,   151,   201,    39,    49,
      50,    51,    52,    53,    54,   156,   168,   218,   -51,   -51,
     -51,   -51,   -51,   -51,   -13,    15,    16,    17,    18,    19,
     204,   176,   175,   179,   180,   185,   186,   217,     1,    40,
     172,    41,   197,    94,    42,    43,    44,    45,    46,    47,
      48,   207,    49,    50,    51,    52,    53,    54,   -52,   -52,
     -52,   -52,   -52,   -52,   211,   214,   222,   -84,   215,   -84,
     -84,   -84,   -84,   -84,   111,    13,   166,   221,   223,    10,
     169,    85,   -52,    25,   208,   194,   212,    36,   140,   213,
     210,   209,   191
  };

  /* YYCHECK.  */
  const unsigned char
  Parser::yycheck_[] =
  {
        27,    48,    42,   107,    39,    34,    27,    35,     3,    47,
      37,    38,    47,   127,    17,    43,    37,    38,    12,     9,
      10,    48,    37,    38,    34,   183,     4,    48,    66,    56,
      47,     0,     0,    59,    47,    56,    33,     0,    64,    65,
      66,    12,   200,    60,     9,    10,    73,    10,    39,    40,
      60,     9,    10,    47,   117,   118,     4,    47,    61,    62,
      63,    64,    65,    66,     4,   100,    29,    46,   103,    59,
      48,    66,   186,   101,    64,    65,    66,   105,    47,    18,
     107,    20,    21,    22,    23,    24,   113,   114,   115,   116,
     117,   118,   113,   114,   115,   116,   117,   118,   113,    59,
     135,    59,    59,    59,   139,    59,    64,    65,    66,    59,
     214,   151,   141,    61,    62,    63,    64,    65,    66,    18,
       5,    20,    21,    22,    23,    24,    33,    59,    15,    16,
      11,    12,    13,   168,   114,   115,   116,   172,    25,    26,
      27,    28,    29,    30,    14,   180,     5,    66,   176,    60,
       9,    10,   187,     4,   182,    34,    53,   185,    17,    61,
      62,    63,    64,    65,    66,    60,    37,   214,     9,    10,
      11,    12,    13,    14,    33,    41,    42,    43,    44,    45,
     215,    49,    60,    60,    51,    60,    33,   214,    47,    48,
      34,    50,     5,   214,    53,    54,    55,    56,    57,    58,
      59,    38,    61,    62,    63,    64,    65,    66,     9,    10,
      11,    12,    13,    14,    52,    33,     5,    18,    34,    20,
      21,    22,    23,    24,    56,     3,   135,   215,   221,     0,
     136,    29,    33,     5,   189,   176,   198,    25,    74,   200,
     193,   192,   171
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    47,    68,    78,    79,   108,   109,   110,   111,   112,
     113,   145,     0,    79,    83,    41,    42,    43,    44,    45,
      75,    80,    81,     3,    66,   115,    33,     4,    69,   113,
     114,    12,    46,    82,    59,   141,   141,     9,    10,    17,
      48,    50,    53,    54,    55,    56,    57,    58,    59,    61,
      62,    63,    64,    65,    66,    70,    71,    72,    73,    74,
      77,    84,    86,    88,    89,    90,    91,    92,    93,    94,
      95,   101,   103,   108,   115,   116,   117,   122,   129,   130,
     131,   132,   137,   144,   146,   114,    39,    40,    76,   103,
     142,    69,    66,    73,    74,    89,    89,    73,    74,    94,
      59,   118,   138,    59,   123,   118,    69,    59,    94,    93,
       5,    70,    33,    14,    11,    12,    13,     9,    10,    15,
      16,    25,    26,    27,    28,    29,    30,    85,    87,    18,
      20,    21,    22,    23,    24,    96,    73,   104,   107,    59,
     138,    34,   143,    60,    94,   139,    69,    94,     4,   124,
      69,    53,    73,    95,   133,   134,    60,    89,    90,    90,
      90,    91,    91,    86,     4,    94,    97,   102,    37,   105,
      94,   103,    34,    60,   140,    60,    49,   119,   120,    60,
      51,   125,   126,   128,   118,    60,    33,    98,    94,   105,
     106,   143,    94,    69,   117,   121,    94,     5,    69,   127,
     128,    69,    86,   135,    94,    97,    99,    38,   106,   140,
     119,    52,   125,   127,    33,    34,   100,    73,    93,    95,
     136,    99,     5,   100
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
     315,   316,   317,   318,   319,   320,   321
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    67,    68,    69,    70,    70,    71,    72,    72,    72,
      72,    72,    72,    72,    73,    74,    74,    75,    75,    75,
      76,    76,    77,    77,    77,    77,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    90,    91,
      91,    91,    91,    92,    92,    92,    93,    94,    94,    94,
      95,    96,    96,    96,    96,    96,    96,    98,    97,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   104,   105,
     106,   106,   107,   107,   108,   109,   109,   110,   111,   112,
     113,   114,   114,   115,   116,   116,   117,   118,   119,   119,
     120,   121,   121,   122,   123,   124,   125,   125,   126,   127,
     127,   128,   129,   129,   129,   130,   118,   131,   132,   133,
     134,   135,   136,   136,   137,   137,   138,   139,   139,   140,
     140,   141,   142,   142,   143,   143,   144,   145,   145,   146
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     1,     3,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     1,     1,
       3,     1,     1,     0,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     1,     1,     3,     1,     3,     1,     2,     2,     1,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     0,     5,     1,
       1,     3,     0,     1,     1,     1,     1,     2,     3,     3,
       2,     0,     1,     1,     2,     1,     1,     3,     4,     2,
       2,     2,     0,     1,     1,     1,     4,     1,     0,     1,
       2,     1,     2,     3,     3,     3,     0,     3,     2,     2,
       0,     3,     1,     1,     1,     3,     3,     4,     5,     5,
       1,     1,     1,     1,     1,     1,     3,     2,     0,     3,
       0,     3,     2,     0,     3,     0,     2,     1,     2,     2
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "NAME_MAIN_FUNCTION",
  "START_BLOCK", "END_BLOCK", "DIGIT_MORE_ZERO", "DIGIT_ZERO", "DIGIT",
  "PLUS", "MINUS", "DIVIDE", "STAR", "PERCENT", "POWER", "LESS", "MORE",
  "NEGATION", "ASSIGN", "AMPERSAND", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "PERCENT_ASSIGN", "LOGIC_AND",
  "LOGIC_OR", "LESS_EQUAL", "MORE_EQUAL", "EQUAL", "NOT_EQUAL",
  "Have_sign", "REFERENCE", "COMMAND_SEPARATOR", "VARIABLE_SEPARATOR",
  "ONLY_STRING_COMMENT", "MULTI_STRING_COMMENT", "START_IDENTIFICATION",
  "END_IDENTIFICATION", "NAME_INTEGER", "NAME_FLOAT", "NAME_CHAR",
  "NAME_STRING", "NAME_LOGIC", "PREFIX_SIGNED", "PREFIX_UNSIGNED",
  "PREFIX_LONG", "PREFIX_CONST", "IF_OPERATOR", "ELSE_OPERATOR",
  "SWITCH_OPERATOR", "CASE_OPERATOR", "CASE_ENUMERATOR", "WHILE_OPERATOR",
  "DO_OPERATOR", "FOR_OPERATOR", "BREAK_OPERATOR", "CONTINUE_OPERATOR",
  "NAME_RETURN", "START_LIST_ARGUMENTS", "END_LIST_ARGUMENTS",
  "\"string\"", "\"char\"", "\"bool\"", "\"int\"", "\"float\"", "\"Id\"",
  "$accept", "program", "commandBlock", "commands", "command",
  "commandContent", "Variable", "Number", "NAME_TYPE",
  "NAME_NUMERIC_TYPES", "Literal", "Prefix_type", "Can_have_const",
  "Name_without_const", "PREFIX_NUMERIC_TYPES", "Can_be_long",
  "DEFINITION_POINTER", "Expression", "Bool_signs", "Bool_expression",
  "Right_bool_expression_part", "atomexpr", "powexpr", "unaryexpr",
  "mulexpr", "addexpr", "Arithmetic_expression", "Value",
  "Assign_for_variable", "Assigns", "Init_list_values", "$@1",
  "Value_in_list", "Another_values_in_list", "Left_part_assign",
  "Right_part_assign", "Init_variable", "Array_element",
  "First_identification", "Other_identification", "Name_init_variable",
  "Type_initialization", "Function_imp_or_init", "Function_init",
  "Function_main", "Function_block", "Definition_function",
  "Other_function_imp_or_init", "Function_name", "Any_branching",
  "Usual_branching", "Condition_part", "Can_have_else_part", "Else_part",
  "Else_content", "Switch_branching", "Check_value", "Switch_block",
  "Body_switch", "Sequence_cases", "Other_sequence_cases", "Case_sequence",
  "Any_loop", "Loop_with_precondition", "Loop_with_postcondition",
  "Loop_with_counter", "Parameters_for", "Start_value_for",
  "Condition_end_for", "Next_value_counter", "Any_interrupt_operator",
  "List_values", "Set_values", "Other_values", "List_arguments",
  "Set_arguments", "Other_arguments", "Call_function",
  "Function_implementation", "Return_function", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        68,     0,    -1,   112,    -1,     4,    70,     5,    -1,    71,
      70,    -1,    -1,    72,    33,    -1,    84,    -1,    95,    -1,
     116,    -1,   129,    -1,   137,    -1,   146,    -1,    -1,    66,
      -1,    65,    -1,    64,    -1,    41,    -1,    42,    -1,    43,
      -1,    39,    -1,    40,    -1,    74,    -1,    63,    -1,    62,
      -1,    61,    -1,    79,    80,    -1,    -1,    47,    -1,    75,
      -1,    81,    82,    76,    -1,    44,    -1,    45,    -1,    -1,
      46,    -1,    -1,    79,    12,    -1,    93,    -1,    86,    -1,
      15,    -1,    16,    -1,    25,    -1,    26,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    17,    94,    -1,    94,
      87,    -1,    -1,    85,    86,    -1,    74,    -1,    73,    -1,
      59,    93,    60,    -1,    88,    -1,    88,    14,    89,    -1,
      89,    -1,     9,    89,    -1,    10,    89,    -1,    90,    -1,
      91,    12,    90,    -1,    91,    11,    90,    -1,    91,    13,
      90,    -1,    91,    -1,    92,     9,    91,    -1,    92,    10,
      91,    -1,    92,    -1,   144,    -1,    73,    -1,    77,    -1,
     101,    96,   102,    -1,    20,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    18,    -1,    -1,     4,    98,    99,
     100,     5,    -1,    94,    -1,    97,    -1,    34,    99,   100,
      -1,    -1,   103,    -1,    73,    -1,    94,    -1,    97,    -1,
     108,   107,    -1,    73,   105,   106,    -1,    37,    94,    38,
      -1,   105,   106,    -1,    -1,   104,    -1,    73,    -1,    78,
      83,    -1,   145,    -1,   110,    -1,   108,   115,   141,    -1,
     108,     3,   141,    69,    -1,   113,   114,    -1,   109,    33,
      -1,   113,   114,    -1,    -1,    66,    -1,   117,    -1,   122,
      -1,    48,   118,    69,   119,    -1,   138,    -1,    -1,   120,
      -1,    49,   121,    -1,   117,    -1,    69,   119,    -1,    50,
     123,   124,    -1,    59,    94,    60,    -1,     4,   125,     5,
      -1,    -1,   126,    69,   125,    -1,   128,   127,    -1,   128,
     127,    -1,    -1,    51,    94,    52,    -1,   130,    -1,   131,
      -1,   132,    -1,    53,   118,    69,    -1,    59,    94,    60,
      -1,    54,    69,    53,   118,    -1,    55,    59,   133,    60,
      69,    -1,   134,    33,   135,    33,   136,    -1,    95,    -1,
      86,    -1,    95,    -1,    93,    -1,    57,    -1,    56,    -1,
      59,   139,    60,    -1,    94,   140,    -1,    -1,    34,    94,
     140,    -1,    -1,    59,   142,    60,    -1,   103,   143,    -1,
      -1,    34,   103,   143,    -1,    -1,   115,   138,    -1,   111,
      -1,   110,    69,    -1,    58,    94,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     9,    12,    13,    16,    18,    20,
      22,    24,    26,    28,    29,    31,    33,    35,    37,    39,
      41,    43,    45,    47,    49,    51,    53,    56,    57,    59,
      61,    65,    67,    69,    70,    72,    73,    76,    78,    80,
      82,    84,    86,    88,    90,    92,    94,    96,    99,   102,
     103,   106,   108,   110,   114,   116,   120,   122,   125,   128,
     130,   134,   138,   142,   144,   148,   152,   154,   156,   158,
     160,   164,   166,   168,   170,   172,   174,   176,   177,   183,
     185,   187,   191,   192,   194,   196,   198,   200,   203,   207,
     211,   214,   215,   217,   219,   222,   224,   226,   230,   235,
     238,   241,   244,   245,   247,   249,   251,   256,   258,   259,
     261,   264,   266,   269,   273,   277,   281,   282,   286,   289,
     292,   293,   297,   299,   301,   303,   307,   311,   316,   322,
     328,   330,   332,   334,   336,   338,   340,   344,   347,   348,
     352,   353,   357,   360,   361,   365,   366,   369,   371,   374
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   221,   221,   235,   242,   242,   246,   251,   251,   251,
     251,   251,   251,   251,   255,   276,   280,   296,   296,   296,
     300,   300,   304,   308,   312,   316,   322,   323,   323,   324,
     324,   325,   325,   326,   326,   328,   328,   336,   340,   347,
     347,   347,   347,   347,   347,   347,   347,   348,   348,   358,
     358,   370,   374,   378,   383,   387,   392,   396,   400,   405,
     409,   413,   417,   422,   426,   430,   435,   463,   463,   463,
     467,   478,   478,   478,   478,   478,   478,   482,   482,   487,
     487,   489,   489,   492,   492,   493,   493,   497,   501,   502,
     503,   503,   504,   504,   508,   520,   520,   523,   526,   536,
     538,   539,   539,   541,   549,   549,   552,   554,   555,   555,
     556,   557,   557,   559,   560,   562,   563,   563,   564,   565,
     565,   566,   577,   577,   577,   579,   580,   582,   584,   586,
     587,   588,   589,   589,   592,   592,   603,   606,   606,   607,
     607,   614,   617,   617,   618,   618,   620,   622,   622,   624
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
      65,    66
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 242;
  const int Parser::yynnts_ = 80;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 12;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 67;

  const unsigned int Parser::yyuser_token_number_max_ = 321;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // example


 /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
