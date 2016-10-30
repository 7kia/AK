flex -L -olexer.cpp lexer.l 
bison --no-lines --defines=Grammar.h --output=Grammar.cpp --graph=grammar.dot Grammar.y