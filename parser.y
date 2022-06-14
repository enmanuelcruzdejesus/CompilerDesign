%{

#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>


extern int yylex();
void yyerror(char *msg);

int current_scope = 0;
SymbolList symlist_level0(0);
SymbolList lastSymlist = symlist_level0;
Symtab symtab = Symbtab();


%}

%union {
  int    integer;
  char*  string;
}



%start program
%token  _PROGRAM 
%token  _ENDVARS 
%token _ENDPROCS 
%token _VARIABLES 
%token _NOVARIABLES 
%token _INTEGER 
%token _REAL 
%token _ECONST
%token _STRING 
%token _PROCEDURES 
%token _NOPROCEDURES 
%token _PROCEDURE 
%token _BEGIN 
%token _END 
%token _FOR 
%token _TO 
%token _DO 
%token _IF 
%token _THEN 
%token _ELSE 
%token _READ 
%token _WRITE 
%token _ID 
%token _ICONST 
%token _RCONST 
%token _LITERAL 
%token _LBRACK 
%token _RBRACK 
%token _LPAREN 
%token _RPAREN 
%token _SEMI 
%token _COLON 
%token _COMMA 
%token _ASSIGN 
%token _PLUS 
%token _MINUS 
%token _MULT 
%token _DIVIDE 
%token _EQL 
%token _LESS 
%token _GTR 
%token _LEQ 
%token _GEQ 
%token _NEQ

%type <string> _ID 


%%

program : title _SEMI block  { }
        ;

title : _PROGRAM _ID     {  createSymbTable(); }
      ;

block : vars _ENDVARS procs _ENDPROCS code    {printf(" ENTRO EN ENDVARS");}
      ;

vars : _VARIABLES varlist _SEMI     {printf(" Regla vars : _VARIABLES varlist _SEMI  \n");}
     | _NOVARIABLES               {}
     ;


varlist : varlist _SEMI vardef  {printf("Regla varlist : varlist _SEMI vardef \n");}
        | vardef              {printf("Regla varlist: vardef \n");}
        ;


vardef : _ID _COLON _INTEGER                      {printf("Regla vardef _INTEGER  \n");}
       | _ID _COLON _REAL                          {printf("Regla vardef _REAL  \n");}
       | _ID _COLON _INTEGER bnl                  {printf("Regla vardef _INTEGER bnl  \n");}
       | _ID _COLON _STRING                        {printf("Regla vardef _STRING   \n");}
       ;


bnl : _LBRACK nlist _RBRACK                        {printf("Regla bnl   \n");}
    ;

nlist : nlist _COMMA _ICONST                        {printf("Regla nlist : nlist _COMMA _ICONST      \n");}
      | _ICONST                                      {printf("Regla nlist:  _ICONST   \n");}
      ;


procs : _PROCEDURES proclist    {printf("Regla procs : _PROCEDURES proclist \n");}
      | _NOPROCEDURES           {printf("Regla procs : _NOPROCEDURES   \n");}
      ;

proclist : proclist _SEMI procdef {printf("Regla proclist : proclist _SEMI procdef  \n");}
         | procdef                 {printf("Regla proclist : procdef  \n");}
         ;

procdef : ptitle _SEMI block        {printf("Regla procdef : ptitle _SEMI block  \n");}
        ;

ptitle : _PROCEDURE _ID _LPAREN varlist _RPAREN  {printf("Regla ptitle : _PROCEDURE _ID _LPAREN varlist _RPAREN  \n");}
       | _PROCEDURE _ID _LPAREN _RPAREN           {printf("Regla ptitle: _PROCEDURE _ID _LPAREN _RPAREN    \n");}
       ;


code : _BEGIN para _END                               {printf("Regla code : _BEGIN para _END    \n");}
     | _SEMI                                            {printf("Regla code : _SEMI   \n");}
     ;

para : para _SEMI stmt                                  {printf("Regla para : para _SEMI stmt   \n");}
     | stmt                                             {printf("Regla para : stmt   \n");}
     ;

stmt : assign                                           {printf("Regla stmt assign   \n");}
     | cond                                             {printf("Regla stmt cond   \n");}
     | loop                                             {printf("Regla stmt loop   \n");}
     | input                                            {printf("Regla stmt input   \n");}
     | output                                           {printf("Regla stmt output   \n");}
     | code                                              {printf("Regla stmt code   \n");}
     ;

assign : ids _ASSIGN expr                              {printf("Regla assign : ids _ASSIGN expr   \n");}
       ;

expr : expr _PLUS term                                   {printf("Regla expr : expr _PLUS term      \n");}
     | expr _MINUS term                                  {printf("Regla expr : expr _MINUS term    \n");}
     | term                                              {printf("Regla expr : term   \n");}
     ;


term : term _MULT fac                                    {printf("Regla term : term _MULT fac     \n");}
     | term _DIVIDE fac                                  {printf("Regla term : term _DIVIDE fac     \n");}
     | fac                                               {printf("Regla term : fac   \n");}
     ;

fac : val                                               {printf("Regla fac : val   \n");}
    | _LPAREN expr _RPAREN                              {printf("Regla lparen expr rparen   \n");}
    ;

val : ids                                              {printf("Regla val ids   \n");}
    | _ID _LPAREN vallist _RPAREN                      {printf("Regla val id lparen vallist rparen    \n");}
    | _ICONST                                          {printf("Regla val _ICONST   \n");}
    | _RCONST
    ;

 
ids : _ID                                              {printf("Regla IDS ID   \n");}
    | _ID _LBRACK vallist _RBRACK                      {printf("Regla IDS _LBRACK vallist _RBRACK   \n");}
    ;

vallist : vallist _COMMA it                            {printf("Regla vallist _COMMA it   \n");}
        | it                                           {printf("Regla vallist  it   \n");}
        ;

it : _ID                           
   | _ICONST
   ;


cond : _IF expr bop expr _THEN stmt _ELSE stmt          {printf("Regla cond   \n");}
     ;

bop : _EQL                                               {printf("Regla bop _EQL   \n");}
    | _LESS                                               {printf("Regla bop _LESS   \n");}
    | _GTR                                                {printf("Regla bop _GTR   \n");}
    | _LEQ                                                {printf("Regla bop _LEQ   \n");}
    | _GEQ                                                {printf("Regla bop _GEQ   \n");}
    | _NEQ                                                {printf("Regla bop _NEQ   \n");}
    ;

loop : _FOR assign _TO expr _DO stmt                    {printf("Regla loop    \n");}
     ;


input : _READ _LPAREN _ID _RPAREN  {printf("Regla input read ( _ID )\n");}
      ;

output : _WRITE _LPAREN _ID _RPAREN {printf("Regla output write(_ID) \n");}
       | _WRITE _LPAREN _LITERAL _RPAREN {printf("Regla output write(_LITERAL) \n");}
       ;

%%

void yyerror(char *msg) {
     
    printf(stderr, "%s\n", msg);

    exit(1);
}


void createSymbTable(){
      symtab = Symtab();

}

int main() {
    yyparse();


    return 0;
}

