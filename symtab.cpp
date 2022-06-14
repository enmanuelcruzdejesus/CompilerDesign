#include <iostream>
#include "symtab.h"


int Type::_id_ = 0;
set<Type, Type::CompareTypes> Type::typelist; // = set<Type, CompareTypes>;



int Type::add(string name) {
  // Look up type-list for duplicate.
  // Return the typeid if it already exists in the list
  const Type tt(name);

  set<Type, Type::CompareTypes>::iterator it;

  it = Type::typelist.find(tt);
  if (it != Type::typelist.end())
    return (*it).type_id;

  const Type t(name, Type::_id_++);
  Type::typelist.insert(t);  // check persistence

  return t.type_id;  // t.type_id;
}


struct id_comp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};


int SymbolList::add(string identifier, TypeID tid) {
  Symbol sym(identifier, tid);
  this->add(sym);
  return 0;
}

int SymbolList::add(Symbol sym) {
  this->symbol_list.insert(std::pair<string, Symbol>(sym.get_identifier(), sym));
  return 0;
}

  bool SymbolList::find(string identifier)
  {
    std::map<string, Symbol>::iterator iter = this->symbol_list.find(identifier);
    if(iter!= this->symbol_list.end())
     return true;
    else
     return false;

  }


int main(int argc, char** argv) {
  
  string s("Integer");
  int tid0 = Type::add(s);
  string s1("Real");
  int tid1 = Type::add(s1);
  string s2("Double");
  int tid2 = Type::add(s2);
  string s3("String");
  int tid3 = Type::add(s3);
  string s4("Float");
  int tid4 = Type::add(s4);

  string s5("Procedure");
  int tid5 = Type::add(s5);
  


Symtab st = Symtab();
SymbolList globalScope = SymbolList(0);


//adding global variables
globalScope.add("",tid0);
globalScope.add("B",tid0);
globalScope.add("C",tid0);

//adding first proceudre
globalScope.add("Mary",tid5);

st.push(globalScope);

globalScope.print();


SymbolList maryScope = SymbolList(1);
maryScope.add("A",tid0);
maryScope.add("Q",tid1);
maryScope.add("X",tid1);
maryScope.add("Ch",tid3);
maryScope.add("Snort",tid5);

st.push(maryScope);


cout<<"*****PRINTING CURRENT TABLE******* "<<endl;
maryScope.print();


//sub routine define inside of mary
SymbolList snortScope = SymbolList(2);
snortScope.add("W",tid0);
snortScope.add("X",tid0);
st.push(snortScope);

cout<<"*****PRINTING CURRENT TABLE******* "<<endl;
//printing table
snortScope.print();


// X := A + C; code inside of snort function
//checking if variables are declared 
if(!st.find("X")){
  cout<<"X variable is not declared"<<endl;
  return 0;
}
if(!st.find("A")){
  cout<<"A variable is not declared"<<endl;
  return 0;
}
if(!st.find("C")){
  cout<<"C variable is not declared"<<endl;
  return 0;
}

// //At this point we are done parsing function Snort.
// //  The action taken is to remove Snort's symbol table 
// //(i.e., pop it off the stack)
st.pop();

cout<<"*****PRINTING ENTIRE TABLE******* "<<endl;
//printing current table
st.print();




// //entering inside mary's body
// //    Write (Snort(C));

if(!st.find("Snort")){
  cout<<"Snort identifier is not declared"<<endl;
  return 0;
}
if(!st.find("C")){
  cout<<"C identifier is not declared"<<endl;
  return 0;
}




}
// #endif
