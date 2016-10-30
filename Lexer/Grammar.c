
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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


/* First part of user declarations.  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO : YYSTYPE - it is token
#define YYSTYPE double

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;
extern FILE *yyOutId;





#include "Grammar.h"

/* User implementation prologue.  */



#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

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
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)



namespace yy {

#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
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

#endif

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
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
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


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
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval);
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
	if (yyn == 0 || yyn == yytable_ninf_)
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

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

    {	
							fclose(yyOutId);
							return;
						}
    break;

  case 3:

    {   fprintf_s(yyOutId, "\n==Start block code==\n");   }
    break;

  case 4:

    { 	fprintf_s(yyOutId, "==End block code==\n"); }
    break;

  case 72:

    { fprintf_s(yyOutId, "\nStart Init_list_values ");  }
    break;

  case 73:

    { fprintf_s(yyOutId, "\nEnd Init_list_values ");  }
    break;

  case 93:

    {	
				 	fprintf_s(yyOutId, "\n End main() \n");
					fclose(yyOutId);
					return;
				}
    break;



	default:
          break;
      }
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
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate));
      }

    yyerror_range[0] = yylloc;
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

    yyerror_range[0] = yylocation_stack_[yylen - 1];
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
	if (yyn != yypact_ninf_)
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

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int yystate)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int parser::yypact_ninf_ = -153;
  const short int
  parser::yypact_[] =
  {
       -29,  -153,    28,    19,   149,     1,    -4,    33,  -153,  -153,
      12,  -153,  -153,    18,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,    -9,   -21,  -153,   -21,  -153,  -153,  -153,    12,
    -153,  -153,  -153,   -14,   -31,    33,  -153,   108,  -153,  -153,
    -153,  -153,     9,   -16,   -13,  -153,  -153,  -153,    15,  -153,
    -153,  -153,  -153,   -11,   -10,   -11,    33,    -6,  -153,  -153,
    -153,    15,     8,    69,   108,    43,   112,  -153,  -153,  -153,
    -153,  -153,   161,  -153,   160,  -153,    22,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,   -29,  -153,  -153,
      41,  -153,  -153,  -153,  -153,  -153,    15,    33,  -153,    15,
      84,    33,    26,   -27,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,    15,  -153,    -2,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,     5,    15,  -153,     9,    15,    41,   -23,    24,    39,
      31,    44,  -153,  -153,   -11,  -153,  -153,    35,    59,  -153,
     187,  -153,    78,  -153,  -153,  -153,  -153,    62,  -153,    63,
      41,  -153,    15,  -153,  -153,  -153,     6,  -153,  -153,  -153,
      15,   105,    33,    44,  -153,    33,    -2,     5,  -153,  -153,
      62,    39,  -153,  -153,    56,  -153,    44,  -153,    44,  -153,
    -153,    81,  -153,  -153,    77,  -153,  -153,  -153,  -153,  -153,
      40,     5,   111,  -153,  -153,  -153,    77,  -153,  -153
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  parser::yydefact_[] =
  {
        28,    29,     0,    36,     0,     0,     0,    91,   142,     2,
      28,    90,     1,     0,    89,    18,    19,    20,    32,    33,
      30,    27,    34,     0,    98,     0,    95,     3,   143,    28,
      94,    37,    35,     0,    28,     0,    92,    28,    96,    21,
      22,    31,   140,     0,     0,    93,    39,    38,     0,     7,
       8,    25,    26,     0,     0,     0,     0,     0,   130,   129,
      24,     0,    17,     0,    28,     0,    63,    64,    23,    10,
      40,    41,    48,    11,     0,    78,     0,    12,    99,   100,
      13,   117,   118,   119,    14,    62,    15,    28,   137,    17,
      88,    87,    82,   136,    63,    58,   133,     0,   102,     0,
       0,     0,     0,    28,   144,     4,     5,     9,    42,    43,
      45,    44,    46,    50,    51,    52,    53,    54,    55,    56,
      57,     0,    47,     0,    59,    71,    66,    67,    68,    69,
      70,     0,   133,   141,   140,     0,    86,     0,     0,   103,
       0,   111,   108,   120,     0,    79,   125,     0,     0,    49,
      48,    61,    60,    72,    80,    81,    65,   135,   139,     0,
      86,    83,     0,   121,   132,   131,     0,   101,   104,   109,
       0,     0,     0,   115,   122,     0,     0,     0,    84,    85,
     135,   103,   106,   105,     0,   110,   111,   113,   115,   123,
     126,     0,    74,    75,    77,   134,   107,   116,   112,   114,
      28,     0,     0,   128,   127,   124,    77,    73,    76
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -153,  -153,   -33,  -153,    57,  -153,  -153,   -37,  -153,  -153,
    -153,  -153,   117,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -114,  -153,  -153,  -105,  -153,   -47,  -100,  -153,    -7,  -153,
     -79,   -81,  -153,  -153,   -15,  -153,    36,   -32,  -153,    32,
    -153,  -153,  -153,  -153,   131,   115,   135,  -153,   -25,   -51,
     -34,  -153,  -153,  -153,  -153,  -153,   -38,  -153,   -36,  -152,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,    75,
    -153,   -24,   130,  -153,    23,  -153,  -153,  -153
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,     2,    28,    37,    63,    64,    65,    94,    20,    41,
      67,     3,     4,    21,    22,    33,    14,    68,    69,   121,
      70,   122,   123,    71,   124,    72,    73,   131,   193,   177,
     194,   202,    74,   156,    75,    91,   160,   161,    92,    43,
       6,     7,     8,     9,    29,    30,    76,    77,    78,    97,
     167,   168,   183,    79,   100,   142,   171,   172,   187,   173,
      80,    81,    82,    83,   147,   148,   191,   205,    84,    98,
     138,   164,    35,    44,    88,    85,    11,    86
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int parser::yytable_ninf_ = -139;
  const short int
  parser::yytable_[] =
  {
        66,    95,    45,   146,   101,    23,    90,   149,    46,    47,
     153,    27,   -97,   162,   104,    46,    47,    48,   151,    42,
       1,   188,     1,   102,     1,    46,    47,    66,    12,    39,
      40,    26,     5,    31,   -28,  -138,   188,    89,    27,    51,
      52,    32,     5,   163,    34,    87,    51,    52,    89,   137,
      46,    47,   140,    93,    96,    99,    51,    52,    53,   103,
      60,     5,    62,     1,   139,    24,   145,    60,   143,    62,
       1,   190,   134,   -98,   150,   105,   152,    60,   107,    62,
     135,    51,    52,   144,   154,   157,   203,   132,   159,   141,
     165,     1,   166,   174,   176,   113,   114,   169,   162,   170,
     204,   175,    60,   178,    62,   115,   116,   117,   118,   119,
     120,   185,   197,   201,    -6,   180,   200,   207,    46,    47,
      13,   106,   206,   184,   155,   208,   136,    48,   179,   152,
     192,    10,   -79,   181,   -79,   -79,   -79,   -79,   -79,   186,
      25,   182,   189,   -16,    38,    49,    50,   196,   198,    51,
      52,   133,   199,   150,   192,    36,   195,   158,     0,     1,
      53,     0,    54,    66,     0,    55,    56,    57,    58,    59,
      60,    61,    62,   108,   109,   110,   111,   112,   113,   114,
     125,     0,   126,   127,   128,   129,   130,     0,   115,   116,
     117,   118,   119,   120,    15,    16,    17,    18,    19,   108,
     109,   110,   111,   112
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
        37,    48,    35,   103,    55,     4,    43,   121,    10,    11,
       5,     5,     0,    36,    61,    10,    11,    19,   123,    34,
      51,   173,    51,    56,    51,    10,    11,    64,     0,    43,
      44,    35,     0,    15,    15,    66,   188,    64,     5,    41,
      42,    50,    10,    66,    65,    36,    41,    42,    64,    96,
      10,    11,    99,    66,    65,    65,    41,    42,    52,    65,
      62,    29,    64,    51,    97,    64,   103,    62,   101,    64,
      51,   176,    87,    65,   121,     6,   123,    62,    35,    64,
      39,    41,    42,    57,   131,   132,   200,    65,   135,     5,
      66,    51,    53,   144,    35,    17,    18,    66,    36,    55,
     200,    66,    62,    40,    64,    27,    28,    29,    30,    31,
      32,     6,    56,    36,     6,   162,    35,     6,    10,    11,
       3,    64,   201,   170,   131,   206,    90,    19,   160,   176,
     177,     0,    20,   166,    22,    23,    24,    25,    26,   172,
       5,   166,   175,    35,    29,    37,    38,   181,   186,    41,
      42,    76,   188,   200,   201,    25,   180,   134,    -1,    51,
      52,    -1,    54,   200,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    12,    13,    14,    15,    16,    17,    18,
      20,    -1,    22,    23,    24,    25,    26,    -1,    27,    28,
      29,    30,    31,    32,    45,    46,    47,    48,    49,    12,
      13,    14,    15,    16
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,    51,    68,    78,    79,   106,   107,   108,   109,   110,
     111,   143,     0,    79,    83,    45,    46,    47,    48,    49,
      75,    80,    81,     4,    64,   113,    35,     5,    69,   111,
     112,    15,    50,    82,    65,   139,   139,    70,   112,    43,
      44,    76,   101,   106,   140,    69,    10,    11,    19,    37,
      38,    41,    42,    52,    54,    57,    58,    59,    60,    61,
      62,    63,    64,    71,    72,    73,    74,    77,    84,    85,
      87,    90,    92,    93,    99,   101,   113,   114,   115,   120,
     127,   128,   129,   130,   135,   142,   144,    36,   141,    64,
      74,   102,   105,    66,    74,    92,    65,   116,   136,    65,
     121,   116,    69,    65,    92,     6,    71,    35,    12,    13,
      14,    15,    16,    17,    18,    27,    28,    29,    30,    31,
      32,    86,    88,    89,    91,    20,    22,    23,    24,    25,
      26,    94,    65,   136,   101,    39,   103,    92,   137,    69,
      92,     5,   122,    69,    57,    74,    93,   131,   132,    87,
      92,    90,    92,     5,    92,    95,   100,    92,   141,    92,
     103,   104,    36,    66,   138,    66,    53,   117,   118,    66,
      55,   123,   124,   126,   116,    66,    35,    96,    40,   104,
      92,    69,   115,   119,    92,     6,    69,   125,   126,    69,
      90,   133,    92,    95,    97,   138,   117,    56,   123,   125,
      35,    36,    98,    87,    93,   134,    97,     6,    98
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
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
  parser::yyr1_[] =
  {
         0,    67,    68,    70,    69,    71,    71,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    75,
      75,    76,    76,    77,    77,    77,    77,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    86,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    93,    94,    94,    94,    94,
      94,    94,    96,    95,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   102,   103,   104,   104,   105,   105,   106,
     107,   107,   108,   109,   110,   111,   112,   112,   113,   114,
     114,   115,   116,   117,   117,   118,   119,   119,   120,   121,
     122,   123,   123,   124,   125,   125,   126,   127,   127,   127,
     128,   116,   129,   130,   131,   132,   133,   134,   134,   135,
     135,   136,   137,   137,   138,   138,   139,   140,   140,   141,
     141,   142,   143,   143,   144
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     1,     0,     4,     2,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     3,     1,     1,     0,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     0,     5,     1,     1,     3,     0,     1,     1,
       1,     1,     2,     3,     3,     2,     0,     1,     1,     2,
       1,     1,     3,     4,     2,     2,     2,     0,     1,     1,
       1,     4,     1,     0,     1,     2,     1,     2,     3,     3,
       3,     0,     3,     2,     2,     0,     3,     1,     1,     1,
       3,     3,     4,     5,     5,     1,     1,     1,     1,     1,
       1,     3,     2,     0,     3,     0,     3,     2,     0,     3,
       0,     2,     1,     2,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "$end", "error", "$undefined", "BYE", "NAME_MAIN_FUNCTION",
  "START_BLOCK", "END_BLOCK", "DIGIT_MORE_ZERO", "DIGIT_ZERO", "DIGIT",
  "INT", "FLOAT", "PLUS", "MINUS", "DIVIDE", "STAR", "PERCENT", "LESS",
  "MORE", "NEGATION", "ASSIGN", "AMPERSAND", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "PERCENT_ASSIGN", "LOGIC_AND",
  "LOGIC_OR", "LESS_EQUAL", "MORE_EQUAL", "EQUAL", "NOT_EQUAL",
  "Have_sign", "REFERENCE", "COMMAND_SEPARATOR", "VARIABLE_SEPARATOR",
  "ONLY_STRING_COMMENT", "MULTI_STRING_COMMENT", "START_IDENTIFICATION",
  "END_IDENTIFICATION", "CHAR", "STRING", "NAME_INTEGER", "NAME_FLOAT",
  "NAME_CHAR", "NAME_STRING", "NAME_LOGIC", "PREFIX_SIGNED",
  "PREFIX_UNSIGNED", "PREFIX_LONG", "PREFIX_CONST", "IF_OPERATOR",
  "ELSE_OPERATOR", "SWITCH_OPERATOR", "CASE_OPERATOR", "CASE_ENUMERATOR",
  "WHILE_OPERATOR", "DO_OPERATOR", "FOR_OPERATOR", "BREAK_OPERATOR",
  "CONTINUE_OPERATOR", "LOGIC", "NAME_RETURN", "Identificator",
  "START_LIST_ARGUMENTS", "END_LIST_ARGUMENTS", "$accept", "program",
  "commandBlock", "$@1", "commands", "command", "commandContent",
  "Variable", "NAME_TYPE", "NAME_NUMERIC_TYPES", "Literal", "Prefix_type",
  "Can_have_const", "Name_without_const", "PREFIX_NUMERIC_TYPES",
  "Can_be_long", "DEFINITION_POINTER", "Number", "Expression",
  "Arithmetic_signs", "Arithmetic_expression",
  "Right_arithmetic_expression_part", "Bool_signs", "Bool_expression",
  "Right_bool_expression_part", "Value", "Assign_for_variable", "Assigns",
  "Init_list_values", "$@2", "Value_in_list", "Another_values_in_list",
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
  "Return_function", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        68,     0,    -1,   110,    -1,    -1,     5,    70,    71,     6,
      -1,    72,    71,    -1,    -1,    37,    -1,    38,    -1,    73,
      35,    -1,    85,    -1,    93,    -1,   114,    -1,   127,    -1,
     135,    -1,   144,    -1,    -1,    64,    -1,    45,    -1,    46,
      -1,    47,    -1,    43,    -1,    44,    -1,    84,    -1,    62,
      -1,    41,    -1,    42,    -1,    79,    80,    -1,    -1,    51,
      -1,    75,    -1,    81,    82,    76,    -1,    48,    -1,    49,
      -1,    -1,    50,    -1,    -1,    79,    15,    -1,    11,    -1,
      10,    -1,    87,    -1,    90,    -1,    12,    -1,    13,    -1,
      15,    -1,    14,    -1,    16,    -1,    92,    88,    -1,    -1,
      86,    87,    -1,    17,    -1,    18,    -1,    27,    -1,    28,
      -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,    19,
      92,    -1,    92,    91,    -1,    -1,    89,    90,    -1,   142,
      -1,    74,    -1,    77,    -1,    99,    94,   100,    -1,    22,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,    20,
      -1,    -1,     5,    96,    97,    98,     6,    -1,    92,    -1,
      95,    -1,    36,    97,    98,    -1,    -1,   101,    -1,    74,
      -1,    92,    -1,    95,    -1,   106,   105,    -1,    74,   103,
     104,    -1,    39,    92,    40,    -1,   103,   104,    -1,    -1,
     102,    -1,    74,    -1,    78,    83,    -1,   143,    -1,   108,
      -1,   106,   113,   139,    -1,   106,     4,   139,    69,    -1,
     111,   112,    -1,   107,    35,    -1,   111,   112,    -1,    -1,
      64,    -1,   115,    -1,   120,    -1,    52,   116,    69,   117,
      -1,   136,    -1,    -1,   118,    -1,    53,   119,    -1,   115,
      -1,    69,   117,    -1,    54,   121,   122,    -1,    65,    92,
      66,    -1,     5,   123,     6,    -1,    -1,   124,    69,   123,
      -1,   126,   125,    -1,   126,   125,    -1,    -1,    55,    92,
      56,    -1,   128,    -1,   129,    -1,   130,    -1,    57,   116,
      69,    -1,    65,    92,    66,    -1,    58,    69,    57,   116,
      -1,    59,    65,   131,    66,    69,    -1,   132,    35,   133,
      35,   134,    -1,    93,    -1,    90,    -1,    93,    -1,    87,
      -1,    61,    -1,    60,    -1,    65,   137,    66,    -1,    92,
     138,    -1,    -1,    36,    92,   138,    -1,    -1,    65,   140,
      66,    -1,   101,   141,    -1,    -1,    36,   101,   141,    -1,
      -1,   113,   136,    -1,   109,    -1,   108,    69,    -1,    63,
      92,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
  {
         0,     0,     3,     5,     6,    11,    14,    15,    17,    19,
      22,    24,    26,    28,    30,    32,    34,    35,    37,    39,
      41,    43,    45,    47,    49,    51,    53,    55,    58,    59,
      61,    63,    67,    69,    71,    72,    74,    75,    78,    80,
      82,    84,    86,    88,    90,    92,    94,    96,    99,   100,
     103,   105,   107,   109,   111,   113,   115,   117,   119,   122,
     125,   126,   129,   131,   133,   135,   139,   141,   143,   145,
     147,   149,   151,   152,   158,   160,   162,   166,   167,   169,
     171,   173,   175,   178,   182,   186,   189,   190,   192,   194,
     197,   199,   201,   205,   210,   213,   216,   219,   220,   222,
     224,   226,   231,   233,   234,   236,   239,   241,   244,   248,
     252,   256,   257,   261,   264,   267,   268,   272,   274,   276,
     278,   282,   286,   291,   297,   303,   305,   307,   309,   311,
     313,   315,   319,   322,   323,   327,   328,   332,   335,   336,
     340,   341,   344,   346,   349
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   159,   159,   176,   176,   183,   183,   187,   187,   187,
     191,   191,   191,   191,   191,   191,   191,   195,   209,   209,
     209,   213,   213,   218,   219,   220,   221,   224,   225,   225,
     226,   226,   227,   227,   228,   228,   230,   230,   237,   237,
     243,   243,   245,   245,   245,   245,   245,   246,   248,   248,
     250,   250,   250,   250,   250,   250,   250,   250,   251,   251,
     261,   261,   285,   285,   285,   289,   292,   292,   292,   292,
     292,   292,   296,   296,   301,   301,   303,   303,   306,   306,
     307,   307,   311,   315,   316,   317,   317,   318,   318,   322,
     334,   334,   337,   340,   351,   353,   354,   354,   356,   364,
     364,   367,   369,   370,   370,   371,   372,   372,   374,   375,
     377,   378,   378,   379,   380,   380,   381,   392,   392,   392,
     394,   395,   397,   399,   401,   402,   403,   404,   404,   407,
     407,   418,   421,   421,   422,   422,   429,   432,   432,   433,
     433,   435,   437,   437,   439
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
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
  parser::token_number_type
  parser::yytranslate_ (int t)
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

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 203;
  const int parser::yynnts_ = 78;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 12;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 67;

  const unsigned int parser::yyuser_token_number_max_ = 321;
  const parser::token_number_type parser::yyundef_token_ = 2;



} // yy



