#ifndef SCANNER
#define SCANNER


#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef YYSTYPE
#define YYSTYPE char*
#endif

struct Token {
	int type;
	string text;
	int line;
	Token() {} // leave uninitialized
	Token(int type, string text, int line) : type(type), text(text), line(line) {}
 /* string toString() {
    // convert line to a C string
    char lineStr[200];
    sprintf(lineStr,"%d",line);
    return string(TokenNames[type]) + '(' + text + ',' + lineStr + ')';
  }
  void print() {
    cout << toString() << endl;
  }
  */
};


#endif
