D [0-9]
A [a-zA-Z_]
S "_"
WS  [ \t\n]+
P \"
C [a-zA-Z0-9_]


%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%option noyywrap
%option case-insensitive

%%
program                          { return _PROGRAM;}
endvars                          { return _ENDVARS;}
endprocs                         { return _ENDPROCS;}
variables                        { return _VARIABLES;}
novariables                      { return _NOVARS;}
procedures                       { return _PROCEDURES;}
noprocedures                     { return _NOPROCEDURES;}
procedure                        { return _PROCEDURE;}
integer                          { return _INTEGER;}
real                             { return _REAL;}
string                           { return _STRING;}
begin                            { return _BEGIN;}
end                              { return _END;}
for                              { return _FOR;}
to                               { return _TO;}
do                               { return _DO;}
if                               { return _IF;}
then                             { return _THEN;}
else                             { return _ELSE;}
read                             { return _READ;}
write                            { return _WRITE;}
{D}+                             { return _ICONST;}
{D}+("."{D}+)	                 { return _RCONST;}
\"(\\.|[^"\\])*\"                { return _LITERAL;}
[a-zA-Z]{C}*                     { return _ID;}
"["                              { return _LBRACK;}
"]"                              { return _RBRACK;}
"("                              { return _LPAREN;}
")"                              { return _RPAREN;}
";"                              { return _SEMI;}
":"                              { return _COLON;}
","                              { return _COMMA;}
":="                             { return _ASSIGN;}
"+"                              { return _PLUS;}
"-"                              { return _MINUS;}
"*"                              { return _MULT;}
"/"                              { return _DIVIDE;}
"="                              { return _EQL;}
"<"                              { return _LESS;}
">"                              { return _GTR;}
"<="                             { return _LEQ;}
">="                             { return _GEQ;}
"<>"                             { return _NEQ;}
[ \t\f\v\n]                      { ; }
%%