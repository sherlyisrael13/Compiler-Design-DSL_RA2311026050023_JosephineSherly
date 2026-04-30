cat > README.md << 'EOF'
# 🧠 DSL Compiler using Flex, Bison & LLVM

## 👩‍💻 Author
| Field | Detail |
|---|---|
| Name | Josephine Sherly |
| Reg No | RA2311026050023 |

## 📌 Project Overview
A complete end-to-end compiler for a custom Domain-Specific Language (DSL).
Supports variable declaration, arithmetic expressions, and print statements.
Produces valid LLVM IR compiled to native executable via llc.

## ⚙️ Compiler Pipeline
DSL Source Code
↓
Lexical Analysis  (Flex  → lexer.l)
↓
Syntax Analysis   (Bison → parser.y)
↓
AST Construction  (C     → ast.c)
↓
Semantic Analysis (C     → semantic.c)
↓
LLVM IR Generation(C     → codegen.c)
↓
llc → output.s → gcc → native executable

## 🛠 Tools Used
| Tool | Purpose |
|---|---|
| Flex | Lexical Analysis |
| Bison | Parsing |
| C | AST, Semantic, Codegen |
| LLVM/llc | IR + Native Code |
| GCC | Final Executable |

## 📂 Project Structure
Compiler-Design-DSL_RA2311026050023_JosephineSherly/
├── src/
│   ├── lexer.l
│   ├── parser.y
│   ├── ast.h
│   ├── ast.c
│   ├── semantic.c
│   ├── codegen.c
│   └── main.c
├── test/
│   ├── input1.dsl
│   └── input2.dsl
├── output/
│   ├── output.ll
│   └── output.s
├── docs/
│   └── report.pdf
└── README.md

## 🚀 How to Run
```bash
cd src
bison -d parser.y
flex lexer.l
gcc lex.yy.c parser.tab.c main.c ast.c codegen.c semantic.c -o compiler
./compiler < ../test/input1.dsl
llc ../output/output.ll -o ../output/output.s
gcc ../output/output.s -o ../output/program
../output/program
```

## 📥 Sample Input (test/input1.dsl)
let x = 10
let y = 5
let z = x + y
print x
print y
print z

## 📤 Sample Output
=== DSL Compiler - Josephine Sherly RA2311026050023 ===
Generating LLVM IR...
Semantic: Variable 'x' declared.
Semantic: Variable 'y' declared.
Semantic: Variable 'z' declared.
✅ LLVM IR written to output/output.ll
10
5
15

## ✨ Key Features
- ✔ Lexical Analysis using Flex
- ✔ Syntax Parsing using Bison
- ✔ Full AST Construction
- ✔ Semantic Analysis with Symbol Table
- ✔ Real LLVM IR Generation
- ✔ Native Code via llc + gcc

## ⚠️ Limitations
- Only integer (i32) type supported
- No if/while control structures yet

## 📌 Future Enhancements
- Add if/while control flow
- Support float and string types
- Add function definitions
EOF
echo "✅ README.md created"
