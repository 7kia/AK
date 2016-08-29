%token NAME_MAIN_FUNCTION "Function main"
%token BYE

%token START_BLOCK
%token END_BLOCK
%token COMMAND_SEPARATOR
%token VARIABLE_SEPARATOR


%%

program: 
         myProgram
        ;

myProgram:
		NAME_MAIN_FUNCTION  commandBlock
		;


/*
		Основа
*/
commandBlock:
		START_BLOCK							{ printf("START_BLOCK \n");   }
		commands
		END_BLOCK							{ printf("END_BLOCK \n");   }		
		;


commands:
		command commands | /* nothing */
		;

command:
		COMMAND_SEPARATOR /*  TODO : see Rule.txt */
		;
