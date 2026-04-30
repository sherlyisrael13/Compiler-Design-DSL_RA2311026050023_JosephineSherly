#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100

typedef struct {
    char name[64];
} Symbol;

static Symbol symbolTable[MAX_SYMBOLS];
static int symbolCount = 0;

void declareVariable(char* name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Semantic Warning: Variable '%s' already declared.\n", name);
            return;
        }
    }
    if (symbolCount >= MAX_SYMBOLS) {
        printf("Semantic Error: Symbol table full.\n");
        exit(1);
    }
    strncpy(symbolTable[symbolCount].name, name, 63);
    symbolTable[symbolCount].name[63] = '\0';
    symbolCount++;
    printf("Semantic: Variable '%s' declared.\n", name);
}

void checkVariable(char* name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0)
            return;
    }
    printf("Semantic Error: Variable '%s' not declared.\n", name);
    exit(1);
}
