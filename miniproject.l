%{
#include "mini.tab.h"
#include <stdio.h>
%}

%%

"int"       { return INT; }
"float"     { return FLOAT; }
"char"      { return CHAR; }
"double"    { return DOUBLE; }
[a-zA-Z_][a-zA-Z0-9_]*  { return IDENTIFIER; }
[0-9]+      { return NUMBER; }
";"         { return SEMICOLON; }
","         { return COMMA; }
"="         { return ASSIGN; }
[ \t\n]     ; /* ignore whitespace */
.           { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
