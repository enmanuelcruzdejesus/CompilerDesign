
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
using namespace std;


typedef int TypeID;




class Type {

 public:
  struct CompareTypes {
    bool operator()(const Type& lhs, const Type& rhs) {
      return lhs.get_typename().compare(rhs.get_typename());
    }
  };  
  static int _id_;
  static set<Type, CompareTypes> typelist;  // singleton

  string  type_name; 
  int     type_id;
  
  Type(string name, int id) {
    this->type_name = name;
    this->type_id = id;
  }
  Type(string name) {
    this->type_name = name;
    this->type_id = -1;  
  }  
  string get_typename() const { return this->type_name; }
  
  static int add(string name);

};


//class Symtab;  

class Symbol {
  string identifier;
  TypeID type;
 public:
  string get_identifier() { return identifier; }
  TypeID get_type() { return type; }  

  Symbol(string identifier, TypeID tid) {
    this->identifier = identifier;
    this->type = tid;
    //this->nestlevel = nest;
  }

  void print() {
    cout << " identifier= " << this->identifier << " " << " typeid= " << this->type;
  }
};

// Una buena manera de manejar el scope es crear una nueva tabla de símbolos para él
// por lo que para cada new scope se tendra un hash map diferente
class SymbolList {
  int    nestlevel;  // last parsed symbol comes at the top of the list.
  string block_name;  // If any. Function name is a block name.
  map<string, Symbol> symbol_list;  // 1 per every nestlevel
  
 public:
  SymbolList(int nl) {
    this->symbol_list = map<string, Symbol>();
  }
  int add(string identifier, TypeID tid);
  int add(Symbol sym);
  int get_nestlevel() { return nestlevel; }
  bool find(string identifier);


  void print() {
    map<string, Symbol>::iterator it;

    for (it = this->symbol_list.begin(); it != this->symbol_list.end(); it++) {
      std::cout << it->first;    // identificador
      it->second.print();   // valor 
      cout << std::endl;
    }
  
  }
};

/*
 Imp de tabla de symbolo con stack de
 */
class Symtab {
  stack<SymbolList> symlist_stack;
public:
  Symtab() {
    this->symlist_stack = stack<SymbolList>();
  }

  const SymbolList& top() {
    return symlist_stack.top();
  }
  void pop() {
    symlist_stack.pop();  
  }

  void push(SymbolList sl) {
    symlist_stack.push(sl);
  }

  bool find(string identifier){

     stack<SymbolList> temp =  symlist_stack;
     
     while(!temp.empty()){

       SymbolList currentTable = temp.top();

       if(currentTable.find(identifier)){
          return true;
       }

       temp.pop();
       

     }
    return false;
  }


  void print(){

    stack<SymbolList> temp =  symlist_stack;
     
     while(!temp.empty()){

       SymbolList currentTable = temp.top();

        currentTable.print();

        temp.pop();
     }
  }
};

