Bison.exe Syntax\Loops.txt OutputSyntax\OutputLoops.txt OutputSyntax\OutputIdLoops.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputLoops.txt RightSyntax\OutputLoops.txt
FC /b OutputSyntax\OutputIdLoops.txt RightSyntax\OutputIdLoops.txt

Bison.exe Syntax\Numbers.txt OutputSyntax\OutputNumbers.txt OutputSyntax\OutputIdNumbers.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputNumbers.txt RightSyntax\OutputNumbers.txt
FC /b OutputSyntax\OutputIdNumbers.txt RightSyntax\OutputIdNumbers.txt

Bison.exe Syntax\Conditions.txt OutputSyntax\OutputConditions.txt OutputSyntax\OutputIdConditions.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputConditions.txt RightSyntax\OutputConditions.txt
FC /b OutputSyntax\OutputIdConditions.txt RightSyntax\OutputIdConditions.txt

Bison.exe Syntax\OneSymbolOperations.txt OutputSyntax\OutputOneSymbolOperations.txt OutputSyntax\OutputIdOneSymbolOperations.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputOneSymbolOperations.txt RightSyntax\OutputOneSymbolOperations.txt
FC /b OutputSyntax\OutputIdOneSymbolOperations.txt RightSyntax\OutputIdOneSymbolOperations.txt

Bison.exe Syntax\Comments.txt OutputSyntax\OutputComments.txt OutputSyntax\OutputIdComments.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputComments.txt RightSyntax\OutputComments.txt
FC /b OutputSyntax\OutputIdComments.txt RightSyntax\OutputIdComments.txt

Bison.exe Syntax\Arrays.txt OutputSyntax\OutputArrays.txt OutputSyntax\OutputIdArrays.txt
IF ERRORLEVEL 1 GOTO err
FC /b OutputSyntax\OutputArrays.txt RightSyntax\OutputArrays.txt
FC /b OutputSyntax\OutputIdArrays.txt RightSyntax\OutputIdArrays.txt
#=======================================================

Bison.exe Identifier.txt Output\OutputIdentifier.txt Output\OutputIdIdentifier.txt
IF ERRORLEVEL 1 GOTO err
FC /b Output\OutputIdentifier.txt Right\OutputIdentifier.txt
FC /b Output\OutputIdIdentifier.txt Right\OutputIdIdentifier.txt

Bison.exe Types.txt Output\OutputTypes.txt Output\OutputIdTypes.txt
IF ERRORLEVEL 1 GOTO err
FC /b Output\OutputTypes.txt Right\OutputTypes.txt
FC /b Output\OutputIdTypes.txt Right\OutputIdTypes.txt

Bison.exe Functions.txt Output\OutputFunctions.txt Output\OutputIdFunctions.txt
IF ERRORLEVEL 1 GOTO err
FC /b Output\OutputFunctions.txt Right\OutputFunctions.txt
FC /b Output\OutputIdFunctions.txt Right\OutputIdFunctions.txt
####################################################

ECHO Program testing succeeded :-) 
PAUSE
EXIT
  
:err
ECHO Program testing failed :-( 
PAUSE
EXIT