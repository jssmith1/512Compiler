#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include "semantics.h"
#include "decaf.tab.h"
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

void pass1(ParseTree * tree);

void semantic_error(string err, int line)
{
  cout << "Semantic error: " << err << " on line " << line << endl;
  exit(1);
}

void error_if_defined_locally(ParseTree *tree)
{
  // tree represents an identifier.  Make sure it's not already defined.
  assert(tree->type == TERMINAL and tree->token->type == IDENTIFIER);
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
//	cout << "in makeVariable with " << varName << endl;
	error_if_defined_locally(varDeclaratorId->children[0]);
	string type_name = get_type_name(type);
	S_variable *entry = new S_variable;
	entry->ident = varName;
	entry->type = new S_type;
	entry->formal = false;


	//Set up the type using type tree
	entry->type->name = type_name;
	entry->type->dimension = 0;
	entry->type->name = type_name;

	//Set up modifiers too@@@
	entry->parentClass = currentClass;
	entry->sequenceNumber = sequenceNumber;
	sequenceNumber++;
	currentScope->insert(varName, entry);
	return entry;
}

S_function * makeMethod(ParseTree *tree){
	assert(tree->description=="method" || tree->description=="ctor");
	//DEAL WITH MODIFIERS
	string ident = tree->children[2]->token->text;
	error_if_defined_locally(tree->children[2]);
	S_function *entry = new S_function;
	entry->ident = ident;

	if (tree->description=="method"){
		string returnTypeString = get_type_name(tree->children[1]);
		if (returnTypeString == "void"){ //HOW TO REPRESENT TYPES???
			entry->returnType = NULL;
		}
		else{
			S_type * returnEntry = new S_type;
			returnEntry->name = returnTypeString;
			entry->returnType = returnEntry;
			//SET UP DIMENSION
		}
	}

	openscope();
	currentFunction = entry;
	sequenceNumber = 0;
	for(size_t i = 0; i < tree->children[3]->children.size(); i ++){
		S_variable * formal = makeVariable(NULL, tree->children[3]->children[i]->children[0], tree->children[3]->children[i]->children[1]);
//		cout << "formal ident: " << formal->ident << endl;
		formal->formal = true;
		entry->formals.push_back(formal);
	}
	pass1(tree->children[4]);
	tree->symtab = closescope();
	currentFunction = NULL;
	sequenceNumber = 0;
	currentScope->insert(ident, entry);
	return entry;
	//ADD TO CLASS??
}

S_class * makeClass(ParseTree * tree){
	assert(tree->description == "class");
	string ident = tree->children[0]->token->text;
	error_if_defined_locally(tree->children[0]);
	S_class * entry = new S_class;
	entry->ident = ident;
	currentClass = entry;
	entry->parentClass = NULL;
	//MORE HERE
	if (tree->children.size() > 2){
		// We explicitly extend a class!
		string super = tree->children[2]->children[0]->token->text;
		int line = tree->children[2]->children[0]->token->line;
		semantics * tmp = currentScope->lookup(super);
		if(!tmp) semantic_error("super class " + super + " not defined", line);
		if(tmp->kind() != "S_class") semantic_error("super class " + super + " not a class", line);
		entry->parentClass = (S_class *) tmp;
	}
	else {}//WE EXTEND OBJECT LOOK IT UP
	openscope();
	pass1(tree->children[1]);
	tree->symtab = closescope();
	currentScope->insert(ident, entry);
	currentClass = NULL;
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
  else if (tree->description=="method"){
	  S_function * entry = makeMethod(tree);
	  entry->ctor = false;
	  if(currentClass)  currentClass->fields.push_back(entry);
	  else cout << "METHOD OUTSIDE CLASS LOGIC ERROR" << endl;
  }
  else if (tree->description=="ctor"){
  	  S_function * entry = makeMethod(tree);
  	  entry->ctor = true;
  	  if(currentClass)  currentClass->fields.push_back(entry);
  	  else cout << "CTOR OUTSIDE CLASS LOGIC ERROR" << endl;
  }
  else if (tree->description=="field"){
	  //make fields
	  for (size_t i =0; i < tree->children[2]->children.size(); i++){
		  S_variable * entry = makeVariable(tree->children[0], tree->children[1], tree->children[2]->children[i]->children[0]);
		  if(currentClass){
			  entry->sequenceNumber = -1;
			  currentClass->fields.push_back(entry);
		  }
		  else cout << "FIELD OUTSIDE CLASS LOGIC ERROR" << endl;
	  }
  }
  else if (tree->description=="declStmt"){
	  for (size_t i =0; i < tree->children[1]->children.size(); i++){
		  S_variable * entry = makeVariable(NULL, tree->children[0], tree->children[1]->children[i]->children[0]);
	  }
  }
  else if (tree->description=="class"){
	  S_class * entry = makeClass(tree);
  }
  //CLASS, COULD SET UP Parent CLASS HERE (PROBABLY SHOULD)

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
	//MAYBE CONCAT EXISTING FILES THEN IGNORE IO, OBJ, etc.
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
	//put stuff into the scope OBJECT, STRING, IO
	pass1(top);
}


