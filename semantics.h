#include "parsetree.h"
#include <map>

extern int yyparse(void);
extern ParseTree * top;

void openscope();
Symtab *closescope();

struct semantics {
  // pure virtual function:
  virtual string kind() = 0;
  // at least one pure virtual function makes the class abstract 
  // (not instantiable.)
  string ident;

};
struct S_class;

struct S_type : public semantics {
  virtual string kind() { return "S_type"; }
  string name; // usually a decaf symbol, but sometimes 
  // campbell's funky idea for types.  FIXME.
  // S_type's name can't be void.
};

struct S_primitive : public semantics {
  virtual string kind() {return "S_primitive"; }
};

struct S_variable : public semantics {
  S_type * type;
  virtual string kind() { return "S_variable"; }
  int sequenceNumber;
  bool formal;
  S_class * parentClass;
  bool global;
};

struct S_function : public semantics {
  virtual string kind() { return "S_function"; }
  vector<S_variable *> formals;
  S_type * returnType;  // NULL for a void function
  bool global;
};

struct S_interface : public semantics {
  virtual string kind() { return "S_interface"; }
  vector<S_function *> functions;
  //string name;  /// curious:  does this override?
};

struct S_class : public semantics {
  virtual string kind() { return "S_class"; }
  S_class * parentClass;  // extends 
  vector<S_interface *> interfaces;
  vector<semantics *> fields;  // have to be S_function or S_variable
};

typedef map <string, semantics *> Dictionary;

struct Symtab {
  // A class to represent symbol tables
  // Chained togeher to represent nested scopes.
 public:
  Dictionary dict;
  Symtab(Symtab *p);
  semantics * lookup(string key);
  semantics * local_lookup(string key);
  
  void insert(string key, semantics * item);

  Symtab * parent;  // outer scope
};


