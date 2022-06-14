#include <iostream>
using namespace std;

extern int yyparse (void);
extern int yylex (void);
extern  void yyerror (char *);
extern char* yytext;

int main()
{
    int verf = yyparse();

    return 0;
}