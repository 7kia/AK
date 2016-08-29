%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;
#include "Grammar.h"

%}

/*
	 Цифры
*/
DIGIT_MORE_ZERO			([1-9])
DIGIT_ZERO				"0"
DIGIT					DIGIT_ZERO | DIGIT_MORE_ZERO

START_BLOCK				"{"
END_BLOCK				"}"
START_LIST_ARGUMENTS	"("
END_LIST_ARGUMENTS		")"
CASE_ENUMERATOR			":"
UNDERSCORE_SYMBOL		"_"
CHAR					\'.\'  /* Планируется добавить поддержку unicode , чтобы русские символы отображались */
STRING					\" (CHAR)+ \"

LOGIC_TRUE				"true"
LOGIC_FALSE				"false"


%%

("main")       { return NAME_MAIN_FUNCTION;  }


"{"				{ return START_BLOCK; }
"}"				{ return END_BLOCK; }

";"				{ return COMMAND_SEPARATOR; }
","				{ return VARIABLE_SEPARATOR; }




("tchau"|"bye")"\n"   { return BYE; }
.                     { yyerror();  }

%%


int main(void)
{
   	fopen_s(&yyin, "text1.txt", "r");
	yyparse();
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
