#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//Parsing and lexing functions parse calls lex
//Must call parse to get parse tree
extern int yylex(void);
extern int yyparse(void);
extern FILE * yyin;
extern const char ** token_table;


void testLex(){
	int tok;
	while ((tok=yylex()) != -1){
    	cout << token_table[tok - 258 + 3] << endl;
	}
    /* Read tokens until finished */

}

int main(int argc, char **argv){
	/* Make sure there's a given file name */
	if (argc != 2) {
		cout << "USAGE: " << argv[0] << " FILE" << endl;
		exit(1);
	}
	yyin = fopen(argv[1], "r");
	/* and that it exists and can be read */
	if (!yyin) {
		cout << argv[1] << ": No such file or file can't be opened for reading."
				<< endl;
		exit(1);
	}
	//testLex();
	yyparse();
}


