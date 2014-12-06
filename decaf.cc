#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include "semantics.h"
using namespace std;

//Parsing and lexing functions parse calls lex
//Must call parse to get parse tree
extern int yylex(void);
extern int yyparse(void);
extern FILE * yyin;
extern const char * const* token_table;
extern Symtab * currentScope;

S_class * currentClass = NULL;
S_function * currentFunction = NULL;
int sequenceNumber = 1;

void semantic_error(string err, int line)
{
  cout << "Semantic error: " << err << " on line " << line << endl;
  exit(1);
}

void error_if_defined_locally(ParseTree *tree)
{
  // tree represents an identifier.  Make sure it's not already defined.
  assert(tree->type == TERMINAL and tree->token->type == T_Identifier);
  string var_name = tree->token->text;
  int lineno = tree->token->line;
  if (currentScope->local_lookup(var_name)){
     semantic_error(var_name + " already defined", lineno);
  }
}


string get_type_name(ParseTree * type){
	assert(type->description == "type");
	return "FIX ME";

}

S_variable * makeVariable(ParseTree * modifiers, ParseTree * type, ParseTree * varDeclaratorId){
	if (modifiers) assert(modifiers->description == "modifiers");
	assert(type->description == "type");
	assert(varDeclaratorId->description == "varDecId");
	string varName = varDeclaratorId->children[0]->token->text;
	cout << "in makeVariable with " << varName << endl;
	error_if_defined_locally(varDeclaratorId->children[0]);
	string type_name = get_type_name(type);
	S_variable *entry = new S_variable;
	entry->ident = var_name;
	entry->type = new S_type;
	entry->formal = false;


	//Set up the type using type tree
	entry->type->name = type_name;
	entry->type-dimension = 0;
	entry->type->name = type_name;

	//Set up modifiers too@@@
	entry->parentClass = currentClass;
	if(currentClass){
		entry->sequenceNumber = -1;
	}
	else{
		entry->sequenceNumber = sequenceNumber;
		sequenceNumber++;
	}
	currentScope->insert(var_name, entry);
	return entry;
}

void pass1(ParseTree * tree)
{
  if (!tree) return;
  if (tree->type==TERMINAL) return;
  if (tree->description=="statements") {
	  openscope();
	  for(size_t i = 0; i < tree->children.size(); i++){
		  pass1(tree->children[i]);
	  }
	  tree->symtab = closescope();
  }
  else if (tree->description=="field"){
	  //make fields
  }
  else if (tree->description=="formalArg"){
	  S_variable * entry = makeVariable(NULL, tree->children[0], tree->children[1]);
	  entry->formal = true;
  }
  else if (tree->type == NONTERMINAL){
	  for(size_t i = 0; i < tree->children.size(); i++){
		  pass1(tree->children[i]);
	  }
  }
}


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
	traverseTree(top,0,0);
	openscope();
	//put stuff into the scope
	pass1(top);
}


