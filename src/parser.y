%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

void yyerror(const char *s);
int yylex();

extern void generateLLVM(ASTNode* node);
extern FILE *out;
extern void declareVariable(char* name);
extern void checkVariable(char* name);
%}

%union {
    int num;
    char* id;
    ASTNode* node;
}

%token LET PRINT
%token <num> NUMBER
%token <id> IDENTIFIER
%token PLUS EQUAL
%left PLUS
%type <node> expression

%%

program:
    program statement
    | statement
;

statement:
    LET IDENTIFIER EQUAL expression {
        declareVariable($2);
        ASTNode* n = createAssignNode($2, $4);
        generateLLVM(n);
    }
    | PRINT expression {
        ASTNode* n = createPrintNode($2);
        generateLLVM(n);
    }
;

expression:
    expression PLUS expression { $$ = createBinaryNode($1, $3); }
    | NUMBER                   { $$ = createNumberNode($1); }
    | IDENTIFIER {
        checkVariable($1);
        $$ = createIdentifierNode($1);
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse Error: %s\n", s);
}
