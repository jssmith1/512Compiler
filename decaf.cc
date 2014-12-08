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

const int LINESINLIB = 22;

S_class * currentClass = NULL;
S_function * currentFunction = NULL;
int sequenceNumber = 1;

void pass1(ParseTree * tree);

void semantic_error(string err, int line)
{
  cout << "Semantic error: " << err << " on line " << line - LINESINLIB << endl;
  exit(1);
}

void error_if_defined_locally(ParseTree *tree)
{
  // tree represents an identifier.  Make sure it's not already defined.
  assert(tree->type == TERMINAL and tree->token->type == IDENTIFIER);
  string var_name = tree->token->text;
  int lineno = tree->token->line;
  if (currentScope->local_lookup(var_name)){
     semantic_error(var_name + " already defined", lineno - LINESINLIB); //22 fake lines!
  }
}

int countBrackets(ParseTree * bracketLst){
	int count = 0;
	if(bracketLst){
		string brackets = bracketLst->token->text;
		for (size_t i = 0; i < brackets.size(); i++){
			if (brackets.substr(i, 1) == "[") count++;
		}
	}
	return count;
}

int get_type_dimension(ParseTree * type, ParseTree * varDecId){
	int dimension = 0;
	if (type && (type->children.size() > 1)){
		assert(type->description == "type");
		dimension += countBrackets(type->children[1]);
	}
	if(varDecId && (varDecId->children.size() > 1)){
		assert(varDecId->description == "varDecId");
		dimension += countBrackets(varDecId->children[1]);
	}
	return dimension;
}

string get_type_name(ParseTree * type){
	assert(type->description == "type");
	return type->children[0]->token->text;
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
	entry->type->dimension = get_type_dimension(type, varDeclaratorId);

	//Set up modifiers too@@@
	if(modifiers){
		//We are in field CANNOT BE STATIC and ONLY ONE ACCESS MOD

	}

	entry->parentClass = currentClass;
	entry->sequenceNumber = sequenceNumber;
	sequenceNumber++;
	currentScope->insert(varName, entry);
	cout << entry->type->name << " " << entry->ident << endl;
	return entry;
}

S_function * makeMethod(ParseTree *tree){
	assert(tree->description=="method" || tree->description=="ctor");
	//DEAL WITH MODIFIERS
	string ident = tree->children[2]->token->text;
	error_if_defined_locally(tree->children[2]);
	S_function *entry = new S_function;
	entry->ident = ident;

	entry->returnType = NULL; //Signal ctor
	if (tree->description=="method"){
		string returnTypeString = get_type_name(tree->children[1]);
		S_type * returnEntry = new S_type;
		returnEntry->name = returnTypeString;
		returnEntry->dimension = get_type_dimension(tree->children[1], NULL);
		entry->returnType = returnEntry;
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
}

S_class * makeClass(ParseTree * tree){
	assert(tree->description == "class");
	string ident = tree->children[0]->token->text;
	error_if_defined_locally(tree->children[0]);
	S_class * entry = new S_class;
	entry->ident = ident;
	currentClass = entry;
	entry->parentClass = NULL;
	if (tree->children.size() > 2){
		// We explicitly extend a class!
		string super = tree->children[2]->children[0]->token->text;
		int line = tree->children[2]->children[0]->token->line;
		semantics * tmp = currentScope->lookup(super);
		if(!tmp) semantic_error("super class " + super + " not defined", line);
		if(tmp->kind() != "S_class") semantic_error("super class " + super + " not a class", line);
		entry->parentClass = (S_class *) tmp;
	}
	else {
		if(ident != "Object"){
			int line = tree->children[0]->token->line;
			semantics * tmp = currentScope->lookup("Object");
			if(!tmp) semantic_error("Couldn't find object -- logic error", line);
			if(tmp->kind() != "S_class") semantic_error("Object not a class, logic error", line);
			entry->parentClass = (S_class *) tmp;
		}
	}//WE EXTEND OBJECT LOOK IT UP
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
  }
  else if (tree->description=="ctor"){
  	  S_function * entry = makeMethod(tree);
  	  entry->ctor = true;
  	  if(currentClass)  currentClass->fields.push_back(entry);
  }
  else if (tree->description=="field"){
	  //make fields
	  for (size_t i =0; i < tree->children[2]->children.size(); i++){
		  S_variable * entry = makeVariable(tree->children[0], tree->children[1], tree->children[2]->children[i]->children[0]);
		  if(currentClass){
			  entry->sequenceNumber = -1;
			  currentClass->fields.push_back(entry);
		  }
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
  else if (tree->type == NONTERMINAL){
	  for(size_t i = 0; i < tree->children.size(); i++){
		  pass1(tree->children[i]);
	  }
  }
}

void typeCheck(ParseTree * t, Symtab * s);


semantics * virtualLookup(string ident, S_class * curClass){
  if(!curClass) return NULL;
  for(size_t i = 0; i < curClass->fields.size(); i++){
    if(curClass->fields[i]->ident == ident) {
      return curClass->fields[i];
    }
  }
  return virtualLookup(ident, curClass->parentClass);
}


semantics * class_scope_lookup(string id, Symtab * scope, S_class * someClass){
  //Look up in class structure or in scope
  //Return the appropriate semantic object
  semantics * fromClass = virtualLookup(id, someClass);
  semantics * fromScope = scope->lookup(id);
  if(fromScope) return fromScope;
  if(fromClass) return fromClass;
  return fromScope; //null
}

bool compatible(string subtype, string supertype, Symtab * tab){
  if(subtype == supertype) return true;
  if (subtype == "null"){
    if(supertype == "null") return true;
    semantics * supclass = tab->lookup(supertype);
    if(!supclass) return false;
    if(supclass->kind() == "S_class"){
      return true;
    }
    return false;
  }
  else{
    semantics * subclass = tab->lookup(subtype);
    if(!subclass) return false;
    if(subclass->kind() != "S_class") return false;
    S_class * sub = (S_class *) subclass;
    if(!sub->parentClass) return false;
    return compatible(sub->parentClass->ident, supertype, tab);
  }
}

void checkPrimary(ParseTree * tree, Symtab * tab){
	if(tree->children[0]->type == NONTERMINAL){
		//DO MORE HERE
		typeCheck(tree->children[0], tab);
		tree->s_type = tree->children[0]->s_type;
		tree->dimension = tree->children[0]->dimension;
		cout << "Primary Type" << tree->s_type <<endl;
	}
	else{//we have a variable identifier
		//ident
		assert(tree->children[0]->token->type == IDENTIFIER);
		string ident = tree->children[0]->token->text;
		int line = tree->children[0]->token->line;
		semantics * var = class_scope_lookup(ident, tab, currentClass);
		if (!var) semantic_error(ident + " not defined", line);
		if (var->kind() != "S_variable") semantic_error(ident + " not a variable", line);
		S_variable * temp = (S_variable *) var;
		tree->s_type = temp->type->name;
		tree->dimension = temp->type->dimension;
	}
}


void checkLiteral(ParseTree * tree, Symtab * tab){
	cout << "in check literal" << endl;
	if (tree->children[0]->token->type == DECAF_NULL)
		tree->s_type = "null";
	else if (tree->children[0]->token->type == BOOLEAN_LITERAL)
		tree->s_type = "bool";
	else if (tree->children[0]->token->type == INTEGER){
		cout << "it's an int" << endl;
		tree->s_type = "int";
	}
	else if (tree->children[0]->token->type == CHARACTER)
		tree->s_type = "char";
	else if (tree->children[0]->token->type == STRING)
		tree->s_type = "String";
	tree->dimension=0;
}

void checkExpr(ParseTree * tree, Symtab * tab){
	if(tree->children[0]->type == NONTERMINAL){
		//We have a Primary. Deal with it later. Call typeCheck
		typeCheck(tree->children[0], tab);
		tree->s_type = tree->children[0]->s_type;
		tree->dimension = tree->children[0]->dimension;
	}
	else{
		string op = tree->children[0]->token->text;
		int line = tree->children[0]->token->line;
		for(size_t i = 0; i < tree->children.size(); i++){
			typeCheck(tree->children[i], tab);
		}
		cout << op << endl;
		if (op == "="){
			if ((tree->children[1]->dimension) != (tree->children[2]->dimension)){
				semantic_error("assignment different dimensions", line);
			}
			if  (!compatible(tree->children[2]->s_type, tree->children[1]->s_type, tab)){
				semantic_error("incompatible types for equality op", line);
			}
			tree->s_type = tree->children[1]->s_type;
			tree->dimension = tree->children[1]->dimension;
		}
		else if (op == "!=" or op == "=="){
			if ((tree->children[1]->dimension) != (tree->children[2]->dimension)){
				semantic_error("equality op different dimensions", line);
			}
			if  (!compatible(tree->children[1]->s_type, tree->children[2]->s_type, tab)){
				semantic_error("incompatible types for equality op", line);
			}
			tree->s_type = "bool";
			tree->dimension = 0;
		}
		else if (op == "||" or op == "&&"){
			if ((tree->children[1]->s_type != "bool") or (tree->children[1]->dimension != 0)){
				semantic_error("logical op expecting bool", line);
			}
			if ((tree->children[2]->s_type != "bool") or (tree->children[2]->dimension != 0)){
				semantic_error("logical op expecting bool", line);
			}
			tree->s_type = "bool";
			tree->dimension = 0;
		}
		else if (op == "<" or op == ">" or op == "<=" or op == ">="){
			if ((tree->children[1]->s_type != "int") or (tree->children[1]->dimension != 0)){
				semantic_error("comparison expecting int", line);
			}
			if ((tree->children.size() > 2) and ((tree->children[2]->s_type != "int") or (tree->children[2]->dimension != 0))){
				semantic_error("comparison expecting int", line);
			}
			tree->s_type = "bool";
			tree->dimension = 0;
		}
		else if (op == "*" or op == "/" or op == "%" or op == "+" or op == "-"){
			if ((tree->children[1]->s_type != "int") or (tree->children[1]->dimension != 0)){
				cout << tree->children[1]->s_type << "first" << endl;
				semantic_error("arithmetic op expecting int", line);
			}
			if ((tree->children.size() > 2) and ((tree->children[2]->s_type != "int") or (tree->children[2]->dimension != 0))){
				semantic_error("arithmetic op expecting int", line);
			}
			tree->s_type = "int";
			tree->dimension = 0;
		}
		else if (op == "!"){
			if ((tree->children[1]->s_type != "bool") or (tree->children[1]->dimension != 0)){
				semantic_error("! expecting bool", line);
			}
			tree->s_type="bool";
			tree->dimension = 0;
		}
	}

}

void typeCheck(ParseTree * tree, Symtab * tab){
	if(!tree) return;
	if(tree->symtab){
		tab = tree->symtab;
	}
	if(tree->description == "expr"){
		checkExpr(tree, tab);
	}
	else if(tree->description == "primary"){
		checkPrimary(tree, tab);
	}
	else if(tree->description == "literal_expr"){
		checkLiteral(tree, tab);
	}
	else{
		for(size_t i = 0; i < tree->children.size(); i++){
			typeCheck(tree->children[i], tab);
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
	//CONCAT EXISTING FILES THEN IGNORE IO, OBJ, etc.
	FILE * lib = fopen("lib.decaf", "r");
	if (!lib) {
		cout << "Can't open lib." << endl;
		exit(1);
	}
	FILE * input = fopen(argv[1], "r");
	if (!input) {
		cout << argv[1] << ": No such file or file can't be opened for reading." << endl;
		exit(1);
	}
	FILE * tmp = fopen("tmp", "w+");

	char ch;
	while( ( ch = fgetc(lib) ) != EOF )
		fputc(ch,tmp);
	while( ( ch = fgetc(input) ) != EOF )
		fputc(ch,tmp);
	fclose(lib);
	fclose(input);
	fclose(tmp);
	yyin = fopen("tmp", "r");
	//testLex();
	yyparse();
	openscope();
	pass1(top);
	traverseTree(top,0,0);
	//Once in symtab, clear the preDefined objects
	top->children.erase(top->children.begin(), top->children.begin()+3);
	typeCheck(top, currentScope);
	//	cout << top->children.size() << endl;
}


