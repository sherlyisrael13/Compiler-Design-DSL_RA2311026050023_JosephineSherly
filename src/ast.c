#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode* createNumberNode(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_NUMBER;
    node->value = value;
    node->name = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode* createIdentifierNode(char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_IDENTIFIER;
    node->name = strdup(name);
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode* createBinaryNode(ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_BINARY;
    node->name = NULL;
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* createAssignNode(char* name, ASTNode* expr) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ASSIGN;
    node->name = strdup(name);
    node->left = expr;
    node->right = NULL;
    return node;
}

ASTNode* createPrintNode(ASTNode* expr) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_PRINT;
    node->name = NULL;
    node->left = expr;
    node->right = NULL;
    return node;
}
