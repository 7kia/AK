%token NAME_MAIN_FUNCTION
%token BYE

%%

program: 
         myProgram
        ;

myProgram:
		NAME_MAIN_FUNCTION  bye
		;

bye:    
        BYE    { printf("Bye World\n"); exit(0); }
         ;