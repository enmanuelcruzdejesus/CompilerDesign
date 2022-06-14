Q.  if I declare a procedure Foo with 3 variables how the symbol table would look like
A. 
```
# Take the function params as the member of the variables in the nesting level.
# In otherword, in the following example,
#  fooPar1, LocalStr, LocalReal, LocalInt
# are the identifiers in this nestlevel bloack.
#
Procedure FooBarProc(fooPar1 : Integer);
	
	Variables 
		LocalInt  : Integer;
		LocalStr  : String;
		LocalReal : Real;
	EndVars


---On parsing
  Encountered "Pocedure FooBarProc"
    then
      g_nestlevel++;  // global var to track the nesting level
      Create a new SymbolList and add it to Symtab.
      Add "FooBarProc" as the block_name to the SymbolList
      
      Add fooPar1, LocalStr, LocalReal, LocalInt to the newly created SymbolList
        as you parse and encounter them.
Symtab
+-----+
|  0     |->Global SymbolList [GlobalInt,GlobalStr,GlobalReal]
+-----+
|  1     |->Procedures
+-----+
|  2     |->Procedure "FooBarProc" SymbolList {fooPar1, LocalStr, LocalReal, LocalInt}
+-----+
|  3     |->Pocedures
+-----+
|  4     |->Procedire FooBarChild ....

```
