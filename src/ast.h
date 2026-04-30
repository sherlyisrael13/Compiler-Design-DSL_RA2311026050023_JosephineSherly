#ifndef AST_H
#define AST_H

typedef enum {
    NODE_NUMBER,
    NODE_IDENTIFIER,
    NODE_BINARY,
    NODE_ASSIGN,
    NODE_PRINT
} NodeType;

typedef struct ASTNode {
    NodeType type;
    int value;
    char* name;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

ASTNode* createNumberNode(int value);
ASTNode* createIdentifierNode(char* name);
ASTNode* createBinaryNode(ASTNode* left, ASTNode* right);
ASTNode* createAssignNode(char* name, ASTNode* expr);
ASTNode* createPrintNode(ASTNode* expr);

#endif
