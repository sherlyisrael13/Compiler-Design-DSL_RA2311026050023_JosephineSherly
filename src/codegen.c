#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

FILE *out;
static int tempCount = 0;
static int fmtCount = 0;

static int emitExpr(ASTNode* node) {
    if (!node) return -1;
    switch (node->type) {
        case NODE_NUMBER: {
            int t = tempCount++;
            fprintf(out, "  %%t%d = add i32 0, %d\n", t, node->value);
            return t;
        }
        case NODE_IDENTIFIER: {
            int t = tempCount++;
            fprintf(out, "  %%t%d = load i32, i32* %%%s_ptr\n", t, node->name);
            return t;
        }
        case NODE_BINARY: {
            int l = emitExpr(node->left);
            int r = emitExpr(node->right);
            int t = tempCount++;
            fprintf(out, "  %%t%d = add i32 %%t%d, %%t%d\n", t, l, r);
            return t;
        }
        default: return -1;
    }
}

void generateLLVM(ASTNode* node) {
    if (!node) return;
    switch (node->type) {
        case NODE_ASSIGN: {
            fprintf(out, "  %%%s_ptr = alloca i32\n", node->name);
            int r = emitExpr(node->left);
            fprintf(out, "  store i32 %%t%d, i32* %%%s_ptr\n", r, node->name);
            break;
        }
        case NODE_PRINT: {
            int r = emitExpr(node->left);
            int fc = fmtCount++;
            fprintf(out, "  %%call%d = call i32 (i8*, ...)", fc);
            fprintf(out, " @printf(i8* getelementptr inbounds");
            fprintf(out, " ([4 x i8], [4 x i8]* @.fmt%d,", fc);
            fprintf(out, " i32 0, i32 0), i32 %%t%d)\n", r);
            break;
        }
        default: break;
    }
}
