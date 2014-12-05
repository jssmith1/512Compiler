decaf: lex.yy.o decaf.tab.o  semantics.o parsetree.o decaf.o
	g++ -o decaf lex.yy.o decaf.tab.o semantics.o parsetree.o decaf.o 

decaf.o: decaf.cc
	g++ -c decaf.cc

semantics.o: semantics.h semantics.cc parsetree.h
	g++ -c semantics.cc
	
parsetree.o: parsetree.h parsetree.cc
	g++ -c parsetree.cc

decaf.tab.o: decaf.tab.c
	g++ -c decaf.tab.c

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

decaf.tab.h: decaf.y
	bison --defines -v decaf.y

decaf.tab.c: decaf.y
	bison --defines -v decaf.y

lex.yy.c: decaf.l decaf.tab.h
	flex decaf.l
	
clean:
	rm -rf *~ lex.yy.* *.o decaf.tab.* decaf a.out decaf.output
	