#ifndef SCANNER
#define SCANNER


#include <iostream>
#include <cstdlib>
#include "decaf.tab.h"
using namespace std;

extern const char * const* token_table;

struct Token {
	int type;
	string text;
	int line;
	Token() {} // leave uninitialized
	Token(int type, string text, int line) : type(type), text(text), line(line) {}
	string toString() {
    // convert line to a C string
    char lineStr[200];
    sprintf(lineStr,"%d",line);
    return string(token_table[type - 258 + 3]) + '(' + text + ',' + lineStr + ')';
  }
  void print() {
    cout << toString() << endl;
  }

};


#endif
