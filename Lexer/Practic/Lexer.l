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



%%

[ \t\n]+	/* skip */;


%%

void ParseFile(const char* inputFileName, const char* outputFileName)
{
	fopen_s(&yyout, outputFileName, "w");

	fopen_s(&yyin, inputFileName, "r");
	yyparse();

	fclose(yyin);
	fclose(yyout);
}

static const int AMOUNT_ARGUMENTS = 3;


int main(int argc, char *argv[])
{

	if (argc != AMOUNT_ARGUMENTS)
	{
		return 1;
	}
	//ParseFile("text1.txt", "out1.txt");
	//ParseFile("Literal1.txt", "outLiteral1.txt");

	//ParseFile("Tests\\Identifier.txt", "Tests\\Output\\OutputIdentifier.txt");
	//ParseFile("Tests\\Types.txt", "Tests\\Output\\OutputTypes.txt");
	//ParseFile("Tests\\Functions.txt", "Tests\\Output\\OutputFunctions.txt");
	//ParseFile("Tests\\Conditions.txt", "Tests\\Output\\OutputConditions.txt");

	//ParseFile("Tests\\Syntax\\Numbers.txt", "Tests\\OutputSyntax\\OutputNumbers.txt");
	//ParseFile("Tests\\Syntax\\Loops.txt", "Tests\\OutputSyntax\\OutputLoops.txt");
	ParseFile(argv[1], argv[2]);

	return 0;
}


int yywrap(void)
{
   return 0;
}

void yyerror (const char *s)  /* вызывается yyparse в случае ошибки */
{
    fprintf_s(yyout, s);
}