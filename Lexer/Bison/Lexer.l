%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;
#include "Lexer.h"
#include "Grammar.h"

%}

/*
////////////////////////////////////////////////////////////////////
//
//
//		Основа
//
//
////////////////////////////////////////////////////////////////////
*/
START_BLOCK				"{"
END_BLOCK				"}"


/*
////////////////////////////////////////////////////////////////////
//
//
//		Алфавит
//
//
////////////////////////////////////////////////////////////////////
*/

/*
	 Цифры
*/
DIGIT_MORE_ZERO			([1-9]) /* TODO : see need these + */
DIGIT_ZERO				"0"
DIGIT					([0-9])

/* Need for grammar */
Have_sign				("+"|"-")?
INT						{Have_sign}([0-9]+)
/*
{Have_sign}  ( {DIGIT_ZERO} | ( {DIGIT_MORE_ZERO} ({DIGIT})* ) )
*/
Expotential_part		{Have_sign}"e"|"E"
FLOAT {Have_sign}((([0-9]+)"."([0-9]*))|("."([0-9]+)))
/* ({INT})"."({DIGIT})+ ({Have_sign} "e" | "E")? */
		
/**/
COMMAND_SEPARATOR		";"
VARIABLE_SEPARATOR		","

/**/

CHAR					\'.\'
STRING					\"(.)*\"

/*\" (CHAR)+ \"*/

START_LIST_ARGUMENTS	"("
END_LIST_ARGUMENTS		")"
CASE_ENUMERATOR			":"
UNDERSCORE_SYMBOL		"_"

LOGIC					true|false


%%

("main")       { return NAME_MAIN_FUNCTION;  }

"{"				{ return START_BLOCK; }
"}"				{ return END_BLOCK; }

{INT}			{ fprintf_s(yyout, "Integer "); return INT; }
{FLOAT}			{ fprintf_s(yyout, "Float "); return FLOAT; }


";"				{ fprintf_s(yyout, "Command separator "); return COMMAND_SEPARATOR; }
","				{ fprintf_s(yyout, "Variable separator ");  return VARIABLE_SEPARATOR; }

{CHAR}			{ fprintf_s(yyout, "Char "); return CHAR; }
{STRING}		{ fprintf_s(yyout, "String "); return STRING; }


{LOGIC}			{ fprintf_s(yyout, "Bool ");   return LOGIC; }

("tchau"|"bye")"\n"   { return BYE; }
.                     { yyerror();  }

%%

void ParseFile(const char* inputFileName, const char* outputFileName)
{
	fopen_s(&yyout, outputFileName, "w");

	fopen_s(&yyin, inputFileName, "r");
	yyparse();
	fclose(yyout);
}

int main(void)
{
	ParseFile("text1.txt", "out1.txt");
	ParseFile("Literal1.txt", "outLiteral1.txt");
}


int yywrap(void)
{
   return 0;
}

int yyerror(void)
{
    fprintf_s(yyout, "Error\n");
}
