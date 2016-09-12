Bison.exe Syntax\Loops.txt OutputSyntax\OutputLoops.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputLoops.txt RightSyntax\OutputLoops.txt

Bison.exe Syntax\Numbers.txt OutputSyntax\OutputNumbers.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputNumbers.txt RightSyntax\OutputNumbers.txt

Bison.exe Syntax\Conditions.txt OutputSyntax\OutputConditions.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputConditions.txt RightSyntax\OutputConditions.txt

Bison.exe Syntax\OneSymbolOperations.txt OutputSyntax\OutputOneSymbolOperations.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputOneSymbolOperations.txt RightSyntax\OutputOneSymbolOperations.txt

Bison.exe Syntax\Comments.txt OutputSyntax\OutputComments.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputComments.txt RightSyntax\OutputComments.txt

Bison.exe Syntax\Arrays.txt OutputSyntax\OutputArrays.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputArrays.txt RightSyntax\OutputArrays.txt
#=======================================================

Bison.exe Identifier.txt Output\OutputIdentifier.txt
IF ERRORLEVEL 1 GOTO err
FC /b Output\OutputIdentifier.txt Right\OutputIdentifier.txt

Bison.exe Types.txt Output\OutputTypes.txt
IF ERRORLEVEL 1 GOTO err
FC /b Output\OutputTypes.txt Right\OutputTypes.txt

Bison.exe Functions.txt Output\OutputFunctions.txt
IF ERRORLEVEL 1 GOTO err
FC /b Output\OutputFunctions.txt Right\OutputFunctions.txt
####################################################

ECHO Program testing succeeded :-) 
PAUSE
EXIT
  
:err
ECHO Program testing failed :-( 
PAUSE
EXIT