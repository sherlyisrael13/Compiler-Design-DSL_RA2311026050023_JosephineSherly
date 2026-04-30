%{
#include "ast.h"
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%
"let"       { return LET; }
"print"     { return PRINT; }
[0-9]+      { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z]+   { yylval.id = strdup(yytext); return IDENTIFIER; }
"+"         { return PLUS; }
"="         { return EQUAL; }
[ \t\n]     ;
.           { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
