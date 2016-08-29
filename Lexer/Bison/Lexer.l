%{

#include <stdlib.h>
#include "y.tab.h"

%}

%%

("main")       { return NAME_MAIN_FUNCTION;  }

("tchau"|"bye")"\n"   { return BYE; }
.                     { yyerror();  }

%%

int main(void)
{
   yyparse();
   return 0;
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
