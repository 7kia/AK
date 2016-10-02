
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;

%}

%token BYE

/* 
	%left, %right, %nonassoc и %precedence управл€ют разрешением
	приоритета операторов и правил ассоциативности
*/



%%

program: 
        "Hellow" { fprintf_s(yyout, "\n Hellow ");  fclose(yyout); } A "what do!" {	fclose(yyout);
												return;
												}
        ;


/*
////////////////////////////////////////////////////////////////////
//
//
//		ќснова
//
//
////////////////////////////////////////////////////////////////////
*/
A : "Oh" A { fprintf_s(yyout, "\n Oh A ");  }| "Oh" B { fprintf_s(yyout, "\n Oh B ");  } ;

												
B : "ny and ny" B { fprintf_s(yyout, "\n ny and ny B ");  } | "WHAT" { fprintf_s(yyout, "\n WHAT ");  };
