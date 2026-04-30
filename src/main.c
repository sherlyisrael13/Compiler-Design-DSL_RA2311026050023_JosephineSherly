#include <stdio.h>
#include "ast.h"

int yyparse(void);
extern FILE *out;

int main(void) {
    printf("=== DSL Compiler - Josephine Sherly RA2311026050023 ===\n");
    printf("Generating LLVM IR...\n");

    out = fopen("../output/output.ll", "w");
    if (!out) {
        fprintf(stderr, "Error: cannot open output/output.ll\n");
        return 1;
    }

    fprintf(out, "; DSL Compiler LLVM IR\n");
    fprintf(out, "; Author: Josephine Sherly RA2311026050023\n\n");
    fprintf(out, "@.fmt0 = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\"\n");
    fprintf(out, "@.fmt1 = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\"\n");
    fprintf(out, "@.fmt2 = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\"\n");
    fprintf(out, "@.fmt3 = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\"\n");
    fprintf(out, "@.fmt4 = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\"\n\n");
    fprintf(out, "declare i32 @printf(i8*, ...)\n\n");
    fprintf(out, "define i32 @main() {\n");
    fprintf(out, "entry:\n");

    yyparse();

    fprintf(out, "  ret i32 0\n");
    fprintf(out, "}\n");

    fclose(out);
    printf("✅ LLVM IR written to output/output.ll\n");
    return 0;
}
