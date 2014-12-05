#include <iostream>
#include <map>
#include <cassert>
#include <vector>

using namespace std;

#include "semantics.h"

Symtab::Symtab(Symtab *p) : parent(p) {}

semantics * Symtab::lookup(string key) { 
    //return local_lookup(key) or parent and parent->lookup(key);
    // really want that to work.  But alas.
    //    if (answer) return answer;
    //if (parent) return parent->lookup(key);
    //return NULL;
    // ugly.  Simplify:
  semantics *answer;
  return 
    (answer = local_lookup(key)) ? answer : 
    parent ? parent->lookup(key) : NULL;

}

semantics * Symtab::local_lookup(string key) { 
  return dict[key];
}

void Symtab::insert(string key, semantics * item) {
  assert (dict[key] == NULL);
  dict[key] = item;
}

// TEST PROGRAM BELOW:

Symtab * currentScope = NULL;

void openscope()
{
  currentScope = new Symtab(currentScope);

}

Symtab *closescope()
{
  Symtab *v = currentScope;
  currentScope = currentScope->parent;
  return v;
}
