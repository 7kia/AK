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
        case 64: /* "string" */

        { delete ((*yyvaluep).stringVal); };

        break;
      case 65: /* "char" */

        { delete ((*yyvaluep).stringVal); };

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

  case 69:

    { driver.m_idsFile << "\nStart Init_list_values ";  }
    break;

  case 70:

    { driver.m_idsFile << "\nEnd Init_list_values ";  }
    break;

  case 90:

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
  const short int Parser::yypact_ninf_ = -148;
  const short int
  Parser::yypact_[] =
  {
       -28,  -148,    21,     1,   153,    11,    -3,    19,  -148,  -148,
       8,  -148,  -148,    18,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,    -8,   -22,  -148,   -22,  -148,    86,  -148,     8,
    -148,  -148,  -148,   -11,   -26,    19,  -148,  -148,  -148,    25,
     -17,   -15,   -17,    19,   -12,  -148,  -148,  -148,    25,   -10,
    -148,  -148,    37,    86,     9,   133,  -148,  -148,  -148,  -148,
    -148,   150,  -148,   169,  -148,    -7,    -9,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,    22,    -5,  -148,  -148,  -148,    25,    19,  -148,    25,
      65,    19,    16,   -20,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,    25,  -148,    15,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,     3,  -148,    33,  -148,  -148,    25,  -148,   -28,  -148,
    -148,   -19,    24,    27,    30,    26,  -148,  -148,   -17,  -148,
    -148,    31,    47,  -148,   189,  -148,   156,  -148,  -148,  -148,
    -148,    25,    33,    50,    22,    25,  -148,  -148,  -148,    14,
    -148,  -148,  -148,    25,    77,    19,    26,  -148,    19,    15,
       3,    58,    33,  -148,  -148,    50,    27,  -148,  -148,    49,
    -148,    26,  -148,    26,  -148,  -148,    66,  -148,  -148,    68,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,    51,     3,   100,
    -148,  -148,  -148,    68,  -148,  -148
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
        25,    26,     0,    33,     0,     0,     0,    88,   139,     2,
      25,    87,     1,     0,    86,    15,    16,    17,    29,    30,
      27,    24,    31,     0,    95,     0,    92,    25,   140,    25,
      91,    34,    32,     0,    25,     0,    89,    36,    35,     0,
       0,     0,     0,     0,     0,   127,   126,    21,     0,    14,
      23,    22,     0,    25,     0,    60,    61,    20,     7,    37,
      38,    45,     8,     0,    75,     0,     0,     9,    96,    97,
      10,   114,   115,   116,    11,    59,    12,    93,    18,    19,
      28,   137,     0,    90,    60,    55,   130,     0,    99,     0,
       0,     0,     0,    25,   141,     3,     4,     6,    39,    40,
      42,    41,    43,    47,    48,    49,    50,    51,    52,    53,
      54,     0,    44,     0,    56,    68,    63,    64,    65,    66,
      67,     0,    14,    85,    84,    79,   130,   138,    25,   134,
     133,     0,     0,   100,     0,   108,   105,   117,     0,    76,
     122,     0,     0,    46,    45,    58,    57,    69,    77,    78,
      62,     0,    83,   132,   137,     0,   118,   129,   128,     0,
      98,   101,   106,     0,     0,     0,   112,   119,     0,     0,
       0,     0,    83,    80,   136,   132,   100,   103,   102,     0,
     107,   108,   110,   112,   120,   123,     0,    71,    72,    74,
      81,    82,   131,   104,   113,   109,   111,    25,     0,     0,
     125,   124,   121,    74,    70,    73
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -148,  -148,   -32,    54,  -148,  -148,   -27,  -148,  -148,  -148,
    -148,   105,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -105,
    -148,  -148,  -104,  -148,   -38,   -91,  -148,    -2,  -148,   -89,
     -92,  -148,  -148,   -30,  -148,    -1,   -58,  -148,    17,  -148,
    -148,  -148,  -148,   118,    92,   119,  -148,   -36,   -37,   -50,
    -148,  -148,  -148,  -148,  -148,   -53,  -148,   -54,  -147,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,    64,  -148,
      -6,   113,  -148,    20,  -148,  -148,  -148
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     2,    28,    52,    53,    54,    84,    20,    80,    56,
       3,     4,    21,    22,    33,    14,    57,    58,   111,    59,
     112,   113,    60,   114,    61,    62,   121,   188,   170,   189,
     199,    63,   150,    64,   124,   172,   173,   125,    65,     6,
       7,     8,     9,    29,    30,    66,    67,    68,    87,   160,
     161,   178,    69,    90,   136,   164,   165,   182,   166,    70,
      71,    72,    73,   141,   142,   186,   202,    74,    88,   132,
     157,    35,    82,   129,    75,    11,    76
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int Parser::yytable_ninf_ = -136;
  const short int
  Parser::yytable_[] =
  {
        55,    85,   140,    83,    81,    91,   143,   147,   -94,   145,
      94,    92,    37,    38,    23,   -25,   155,     5,    27,   183,
       1,    12,     1,    27,    37,    38,    55,     5,     1,    78,
      79,    26,    31,    39,    37,    38,   183,  -135,   123,    32,
      34,   122,    95,    97,   156,    86,     5,    89,   131,     1,
      93,   134,   -95,   126,   122,   133,     1,   128,   130,   137,
      37,    38,    47,    40,    49,   185,   139,    50,    51,   135,
     138,   151,    24,   144,    47,   146,    49,   159,   163,    50,
      51,   169,   180,   148,    47,   155,    49,   158,   153,    50,
      51,    -5,   200,   162,   168,    37,    38,   190,   154,     1,
     197,   167,   194,   198,    39,   204,   201,    96,    13,   203,
      47,   205,    49,   171,   191,    50,    51,   175,    10,   149,
     -13,    77,   152,   177,    25,   179,   193,   176,   195,   196,
     127,   146,   187,   181,     1,    40,   184,    41,    36,     0,
      42,    43,    44,    45,    46,    47,    48,    49,     0,     0,
      50,    51,   -76,     0,   -76,   -76,   -76,   -76,   -76,   144,
     187,    98,    99,   100,   101,   102,   103,   104,     0,   192,
      55,     0,   103,   104,   174,     0,   105,   106,   107,   108,
     109,   110,   105,   106,   107,   108,   109,   110,   115,     0,
     116,   117,   118,   119,   120,    15,    16,    17,    18,    19,
      98,    99,   100,   101,   102
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        27,    39,    93,    35,    34,    42,   111,     4,     0,   113,
      48,    43,     9,    10,     3,    14,    35,     0,     4,   166,
      48,     0,    48,     4,     9,    10,    53,    10,    48,    40,
      41,    34,    14,    18,     9,    10,   183,    63,    65,    47,
      62,    61,     5,    34,    63,    62,    29,    62,    86,    48,
      62,    89,    62,    62,    61,    87,    48,    35,    63,    91,
       9,    10,    59,    49,    61,   169,    93,    64,    65,     4,
      54,    38,    61,   111,    59,   113,    61,    50,    52,    64,
      65,    34,     5,   121,    59,    35,    61,    63,   126,    64,
      65,     5,   197,    63,    63,     9,    10,    39,   128,    48,
      34,   138,    53,    35,    18,     5,   197,    53,     3,   198,
      59,   203,    61,   151,   172,    64,    65,   155,     0,   121,
      34,    29,   123,   159,     5,   163,   176,   159,   181,   183,
      66,   169,   170,   165,    48,    49,   168,    51,    25,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      64,    65,    19,    -1,    21,    22,    23,    24,    25,   197,
     198,    11,    12,    13,    14,    15,    16,    17,    -1,   175,
     197,    -1,    16,    17,   154,    -1,    26,    27,    28,    29,
      30,    31,    26,    27,    28,    29,    30,    31,    19,    -1,
      21,    22,    23,    24,    25,    42,    43,    44,    45,    46,
      11,    12,    13,    14,    15
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    48,    67,    76,    77,   104,   105,   106,   107,   108,
     109,   141,     0,    77,    81,    42,    43,    44,    45,    46,
      73,    78,    79,     3,    61,   111,    34,     4,    68,   109,
     110,    14,    47,    80,    62,   137,   137,     9,    10,    18,
      49,    51,    54,    55,    56,    57,    58,    59,    60,    61,
      64,    65,    69,    70,    71,    72,    75,    82,    83,    85,
      88,    90,    91,    97,    99,   104,   111,   112,   113,   118,
     125,   126,   127,   128,   133,   140,   142,   110,    40,    41,
      74,    99,   138,    68,    72,    90,    62,   114,   134,    62,
     119,   114,    68,    62,    90,     5,    69,    34,    11,    12,
      13,    14,    15,    16,    17,    26,    27,    28,    29,    30,
      31,    84,    86,    87,    89,    19,    21,    22,    23,    24,
      25,    92,    61,    72,   100,   103,    62,   134,    35,   139,
      63,    90,   135,    68,    90,     4,   120,    68,    54,    72,
      91,   129,   130,    85,    90,    88,    90,     4,    90,    93,
      98,    38,   101,    90,    99,    35,    63,   136,    63,    50,
     115,   116,    63,    52,   121,   122,   124,   114,    63,    34,
      94,    90,   101,   102,   139,    90,    68,   113,   117,    90,
       5,    68,   123,   124,    68,    88,   131,    90,    93,    95,
      39,   102,   136,   115,    53,   121,   123,    34,    35,    96,
      85,    91,   132,    95,     5,    96
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
     315,   316,   317,   318,   319,   320
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    66,    67,    68,    69,    69,    70,    71,    71,    71,
      71,    71,    71,    71,    72,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    91,    92,    92,    92,    92,    92,    92,    94,
      93,    95,    95,    96,    96,    97,    97,    98,    98,    99,
     100,   101,   102,   102,   103,   103,   104,   105,   105,   106,
     107,   108,   109,   110,   110,   111,   112,   112,   113,   114,
     115,   115,   116,   117,   117,   118,   119,   120,   121,   121,
     122,   123,   123,   124,   125,   125,   125,   126,   114,   127,
     128,   129,   130,   131,   132,   132,   133,   133,   134,   135,
     135,   136,   136,   137,   138,   138,   139,   139,   140,   141,
     141,   142
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     1,     3,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     1,     1,     3,     1,
       1,     0,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     2,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     0,
       5,     1,     1,     3,     0,     1,     1,     1,     1,     2,
       3,     3,     2,     0,     1,     1,     2,     1,     1,     3,
       4,     2,     2,     2,     0,     1,     1,     1,     4,     1,
       0,     1,     2,     1,     2,     3,     3,     3,     0,     3,
       2,     2,     0,     3,     1,     1,     1,     3,     3,     4,
       5,     5,     1,     1,     1,     1,     1,     1,     3,     2,
       0,     3,     0,     3,     2,     0,     3,     0,     2,     1,
       2,     2
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "NAME_MAIN_FUNCTION",
  "START_BLOCK", "END_BLOCK", "DIGIT_MORE_ZERO", "DIGIT_ZERO", "DIGIT",
  "INT", "FLOAT", "PLUS", "MINUS", "DIVIDE", "STAR", "PERCENT", "LESS",
  "MORE", "NEGATION", "ASSIGN", "AMPERSAND", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "PERCENT_ASSIGN", "LOGIC_AND",
  "LOGIC_OR", "LESS_EQUAL", "MORE_EQUAL", "EQUAL", "NOT_EQUAL",
  "Have_sign", "REFERENCE", "COMMAND_SEPARATOR", "VARIABLE_SEPARATOR",
  "ONLY_STRING_COMMENT", "MULTI_STRING_COMMENT", "START_IDENTIFICATION",
  "END_IDENTIFICATION", "NAME_INTEGER", "NAME_FLOAT", "NAME_CHAR",
  "NAME_STRING", "NAME_LOGIC", "PREFIX_SIGNED", "PREFIX_UNSIGNED",
  "PREFIX_LONG", "PREFIX_CONST", "IF_OPERATOR", "ELSE_OPERATOR",
  "SWITCH_OPERATOR", "CASE_OPERATOR", "CASE_ENUMERATOR", "WHILE_OPERATOR",
  "DO_OPERATOR", "FOR_OPERATOR", "BREAK_OPERATOR", "CONTINUE_OPERATOR",
  "LOGIC", "NAME_RETURN", "Identificator", "START_LIST_ARGUMENTS",
  "END_LIST_ARGUMENTS", "\"string\"", "\"char\"", "$accept", "program",
  "commandBlock", "commands", "command", "commandContent", "Variable",
  "NAME_TYPE", "NAME_NUMERIC_TYPES", "Literal", "Prefix_type",
  "Can_have_const", "Name_without_const", "PREFIX_NUMERIC_TYPES",
  "Can_be_long", "DEFINITION_POINTER", "Number", "Expression",
  "Arithmetic_signs", "Arithmetic_expression",
  "Right_arithmetic_expression_part", "Bool_signs", "Bool_expression",
  "Right_bool_expression_part", "Value", "Assign_for_variable", "Assigns",
  "Init_list_values", "$@1", "Value_in_list", "Another_values_in_list",
  "Left_part_assign", "Right_part_assign", "Init_variable",
  "Array_element", "First_identification", "Other_identification",
  "Name_init_variable", "Type_initialization", "Function_imp_or_init",
  "Function_init", "Function_main", "Function_block",
  "Definition_function", "Other_function_imp_or_init", "Function_name",
  "Any_branching", "Usual_branching", "Condition_part",
  "Can_have_else_part", "Else_part", "Else_content", "Switch_branching",
  "Check_value", "Switch_block", "Body_switch", "Sequence_cases",
  "Other_sequence_cases", "Case_sequence", "Any_loop",
  "Loop_with_precondition", "Loop_with_postcondition", "Loop_with_counter",
  "Parameters_for", "Start_value_for", "Condition_end_for",
  "Next_value_counter", "Any_interrupt_operator", "List_values",
  "Set_values", "Other_values", "List_arguments", "Set_arguments",
  "Other_arguments", "Call_function", "Function_implementation",
  "Return_function", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        67,     0,    -1,   108,    -1,     4,    69,     5,    -1,    70,
      69,    -1,    -1,    71,    34,    -1,    83,    -1,    91,    -1,
     112,    -1,   125,    -1,   133,    -1,   142,    -1,    -1,    61,
      -1,    42,    -1,    43,    -1,    44,    -1,    40,    -1,    41,
      -1,    82,    -1,    59,    -1,    65,    -1,    64,    -1,    77,
      78,    -1,    -1,    48,    -1,    73,    -1,    79,    80,    74,
      -1,    45,    -1,    46,    -1,    -1,    47,    -1,    -1,    77,
      14,    -1,    10,    -1,     9,    -1,    85,    -1,    88,    -1,
      11,    -1,    12,    -1,    14,    -1,    13,    -1,    15,    -1,
      90,    86,    -1,    -1,    84,    85,    -1,    16,    -1,    17,
      -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,    30,
      -1,    31,    -1,    18,    90,    -1,    90,    89,    -1,    -1,
      87,    88,    -1,   140,    -1,    72,    -1,    75,    -1,    97,
      92,    98,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    19,    -1,    -1,     4,    94,    95,    96,
       5,    -1,    90,    -1,    93,    -1,    35,    95,    96,    -1,
      -1,    99,    -1,    72,    -1,    90,    -1,    93,    -1,   104,
     103,    -1,    72,   101,   102,    -1,    38,    90,    39,    -1,
     101,   102,    -1,    -1,   100,    -1,    72,    -1,    76,    81,
      -1,   141,    -1,   106,    -1,   104,   111,   137,    -1,   104,
       3,   137,    68,    -1,   109,   110,    -1,   105,    34,    -1,
     109,   110,    -1,    -1,    61,    -1,   113,    -1,   118,    -1,
      49,   114,    68,   115,    -1,   134,    -1,    -1,   116,    -1,
      50,   117,    -1,   113,    -1,    68,   115,    -1,    51,   119,
     120,    -1,    62,    90,    63,    -1,     4,   121,     5,    -1,
      -1,   122,    68,   121,    -1,   124,   123,    -1,   124,   123,
      -1,    -1,    52,    90,    53,    -1,   126,    -1,   127,    -1,
     128,    -1,    54,   114,    68,    -1,    62,    90,    63,    -1,
      55,    68,    54,   114,    -1,    56,    62,   129,    63,    68,
      -1,   130,    34,   131,    34,   132,    -1,    91,    -1,    88,
      -1,    91,    -1,    85,    -1,    58,    -1,    57,    -1,    62,
     135,    63,    -1,    90,   136,    -1,    -1,    35,    90,   136,
      -1,    -1,    62,   138,    63,    -1,    99,   139,    -1,    -1,
      35,    99,   139,    -1,    -1,   111,   134,    -1,   107,    -1,
     106,    68,    -1,    60,    90,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     9,    12,    13,    16,    18,    20,
      22,    24,    26,    28,    29,    31,    33,    35,    37,    39,
      41,    43,    45,    47,    49,    52,    53,    55,    57,    61,
      63,    65,    66,    68,    69,    72,    74,    76,    78,    80,
      82,    84,    86,    88,    90,    93,    94,    97,    99,   101,
     103,   105,   107,   109,   111,   113,   116,   119,   120,   123,
     125,   127,   129,   133,   135,   137,   139,   141,   143,   145,
     146,   152,   154,   156,   160,   161,   163,   165,   167,   169,
     172,   176,   180,   183,   184,   186,   188,   191,   193,   195,
     199,   204,   207,   210,   213,   214,   216,   218,   220,   225,
     227,   228,   230,   233,   235,   238,   242,   246,   250,   251,
     255,   258,   261,   262,   266,   268,   270,   272,   276,   280,
     285,   291,   297,   299,   301,   303,   305,   307,   309,   313,
     316,   317,   321,   322,   326,   329,   330,   334,   335,   338,
     340,   343
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   206,   206,   220,   227,   227,   231,   236,   236,   236,
     236,   236,   236,   236,   240,   254,   254,   254,   258,   258,
     263,   264,   265,   266,   269,   270,   270,   271,   271,   272,
     272,   273,   273,   275,   275,   282,   282,   288,   288,   290,
     290,   290,   290,   290,   291,   293,   293,   295,   295,   295,
     295,   295,   295,   295,   295,   296,   296,   306,   306,   330,
     330,   330,   334,   337,   337,   337,   337,   337,   337,   341,
     341,   346,   346,   348,   348,   351,   351,   352,   352,   356,
     360,   361,   362,   362,   363,   363,   367,   379,   379,   382,
     385,   395,   397,   398,   398,   400,   408,   408,   411,   413,
     414,   414,   415,   416,   416,   418,   419,   421,   422,   422,
     423,   424,   424,   425,   436,   436,   436,   438,   439,   441,
     443,   445,   446,   447,   448,   448,   451,   451,   462,   465,
     465,   466,   466,   473,   476,   476,   477,   477,   479,   481,
     481,   483
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
      65
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 204;
  const int Parser::yynnts_ = 77;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 12;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 66;

  const unsigned int Parser::yyuser_token_number_max_ = 320;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // example


 /*** Additional Code ***/

void example::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
