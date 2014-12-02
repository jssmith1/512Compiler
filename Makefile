decaf: lex.yy.o decaf.tab.o  decaf.o
	g++ -o decaf lex.yy.o decaf.tab.o decaf.o

decaf.o: decaf.cc
	g++ -c decaf.cc

decaf.tab.o: decaf.tab.c
	g++ -c decaf.tab.c

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

decaf.tab.h: decaf.y
	bison -Wall -d -v decaf.y

decaf.tab.c: decaf.y
	bison -W -d -v decaf.y

lex.yy.c: decaf.l decaf.tab.h
	flex decaf.l
	
clean:
	rm -rf *~ lex.yy.* *.o decaf.tab.* decaf a.out decaf.output
	