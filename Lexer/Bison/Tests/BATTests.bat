Bison.exe Syntax\Loops.txt OutputSyntax\OutputLoops.txt
IF ERRORLEVEL 1 GOTO err

Bison.exe Syntax\Numbers.txt OutputSyntax\OutputNumbers.txt
IF ERRORLEVEL 1 GOTO err

####################################################

Bison.exe Identifier.txt Output\OutputIdentifier.txt
IF ERRORLEVEL 1 GOTO err

Bison.exe Types.txt Output\OutputTypes.txt
IF ERRORLEVEL 1 GOTO err

Bison.exe Functions.txt Output\OutputFunctions.txt
IF ERRORLEVEL 1 GOTO err

Bison.exe Conditions.txt Output\OutputConditions.txt
IF ERRORLEVEL 1 GOTO err
####################################################
# >> Degenerate1.txt
Triangle.exe -1 2 3
IF ERRORLEVEL 1 GOTO err
FC /b Degenerate1.txt CheckData/degenerate1.txt


# >> Obtuse2.txt
Triangle.exe 3 5.19615 3
IF ERRORLEVEL 1 GOTO err
FC /b Obtuse2.txt CheckData/Obtuse2.txt

ECHO Program testing succeeded :-) 
PAUSE
EXIT
  
:err
ECHO Program testing failed :-( 
PAUSE
EXIT