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
DIGIT_MORE_ZERO			([1-9])+ /* TODO : see need these + */
DIGIT_ZERO				"0"
DIGIT					DIGIT_ZERO | DIGIT_MORE_ZERO

/* Need for grammar */
One_or_more_digits		(DIGIT)+
/**/
COMMAND_SEPARATOR		";"
VARIABLE_SEPARATOR		","

/**/

CHAR \'.\'
STRING					\".\"

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


{One_or_more_digits}		{ return One_or_more_digits; }

";"				{ return COMMAND_SEPARATOR; }
","				{ return VARIABLE_SEPARATOR; }

{CHAR}			{ return CHAR; }
{STRING}		{ return STRING; }


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
}


int yywrap(void)
{
   return 0;
}

int yyerror(void)
{
    printf("Error\n");
    exit(1);
}
