#ifndef PARSETREE
#define PARSETREE

#include <vector>
#include <stack>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

#include <cstdio>
#include <iostream>

#include "tokenType.h"
//#include "decaf.tab.h"

  /* we are building parse trees */


  /* prototype for yyerror, needed on my linux laptop */
int yyerror(const char * s);

using namespace std;

enum PTtype {TERMINAL, NONTERMINAL};

struct Symtab;

struct ParseTree {
  Symtab *symtab;
  PTtype type;
  string description;
  Token * token;
  string s_type; //Type assigned in type checking
  int dimension; //Assigned in type checking
  vector<ParseTree *> children;
  ParseTree(string description);
  ParseTree(Token * tokp);
  void addChild(ParseTree * tree);
  string toString();
};

void traverseTree(ParseTree * tree, int depth, int seq);


#endif
