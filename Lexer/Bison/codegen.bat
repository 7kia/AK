flex -L -olexer.c lexer.l
bison --no-lines --defines=Grammar.h --output=Grammar.c --graph=grammar.dot Grammar.y