# DSL Compiler — Flex, Bison & LLVM
### Compiler Design Project | SRM Institute of Science and Technology

---

## 👩‍💻 Team Details

| Field | Detail |
|---|---|
| Name | Josephine Sherly |
| Reg No | RA2311026050023 |
| Department | AIML | 
| Institution | SRM Institute of Science and Technology |
| Course | Compiler Design |

---

## 📌 Project Description

This project implements a complete **end-to-end compiler** for a custom **Domain-Specific Language (DSL)** built entirely in **C** using **Flex** and **Bison**. The compiler covers every classical phase of compilation: lexical analysis, syntax analysis, AST construction, semantic analysis, and LLVM IR code generation. The generated LLVM IR is then compiled to a native executable using the `llc` backend and `gcc` linker.

The DSL supports:
- Integer variable declaration (`let x = 10`)
- Arithmetic expressions (`let z = x + y`)
- Print statements (`print z`)
- Semantic checking (undeclared variable detection)

---

## ⚙️ Compiler Pipeline

```
DSL Source Code (.dsl)
        |
        v
[1] Lexical Analysis     -->  Flex   (lexer.l)
        |
        v
[2] Syntax Analysis      -->  Bison  (parser.y)
        |
        v
[3] AST Construction     -->  C      (ast.h / ast.c)
        |
        v
[4] Semantic Analysis    -->  C      (semantic.c)
        |
        v
[5] LLVM IR Generation   -->  C      (codegen.c)
        |
        v
[6] llc  -->  output.s
        |
        v
[7] gcc  -->  native executable
        |
        v
    OUTPUT: Prints results to terminal
```

---

## 🛠 Tools Used

| Tool | Version | Purpose |
|---|---|---|
| Flex | 2.6.4 | Lexical Analysis / Tokenization |
| Bison | 3.8.2 | LALR(1) Parsing |
| C (Clang) | 17.0 | AST, Semantic Analysis, Code Generation |
| LLVM / llc | 22.1.4 | IR Generation and Native Code |
| GCC | 17.0.0 | Final Executable Linking |
| Git | - | Version Control |

---

## 📂 Project Structure

```
Compiler-Design-DSL_RA2311026050023_JosephineSherly/
|
|-- src/
|   |-- lexer.l          # Flex lexer - tokenizes DSL source
|   |-- parser.y         # Bison parser - LALR(1) grammar
|   |-- ast.h            # AST node type definitions
|   |-- ast.c            # AST node constructors
|   |-- semantic.c       # Symbol table + semantic checks
|   |-- codegen.c        # LLVM IR emitter
|   `-- main.c           # Compiler entry point
|
|-- test/
|   |-- input1.dsl       # Valid DSL program (3 variables + addition)
|   `-- input2.dsl       # Valid DSL program (addition test)
|
|-- output/
|   `-- output.ll        # Generated LLVM IR
|
|-- docs/
|   `-- report.pdf       # Detailed multi-page project report
|
|-- .gitignore
`-- README.md
```

---

## 🚀 Steps to Run

### Prerequisites

```bash
# Install on macOS using Homebrew
brew install flex bison llvm
```

### Build and Run

```bash
# Step 1 - Enter source directory
cd src

# Step 2 - Generate parser files from Bison grammar
bison -d parser.y

# Step 3 - Generate lexer from Flex specification
flex lexer.l

# Step 4 - Compile all modules together
gcc lex.yy.c parser.tab.c main.c ast.c codegen.c semantic.c -o compiler

# Step 5 - Run compiler on DSL input
./compiler < ../test/input1.dsl

# Step 6 - Generate assembly from LLVM IR using llc
llc ../output/output.ll -o ../output/output.s

# Step 7 - Link assembly to native executable
gcc ../output/output.s -o ../output/program

# Step 8 - Run the final program
../output/program
```

---

## 📥 Sample Input

**test/input1.dsl**
```
let x = 10
let y = 5
let z = x + y
print x
print y
print z
```

**test/input2.dsl**
```
let a = 100
let b = 200
let c = a + b
print c
```

---

## 📤 Sample Output

**Compiler terminal output:**
```
=== DSL Compiler - Josephine Sherly RA2311026050023 ===
Generating LLVM IR...
Semantic: Variable 'x' declared.
Semantic: Variable 'y' declared.
Semantic: Variable 'z' declared.
LLVM IR written to output/output.ll
```

**Program output (after llc + gcc):**
```
10
5
15
```

**Generated LLVM IR (output/output.ll):**
```llvm
; DSL Compiler LLVM IR
; Author: Josephine Sherly RA2311026050023

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %x_ptr = alloca i32
  %t0 = add i32 0, 10
  store i32 %t0, i32* %x_ptr
  %y_ptr = alloca i32
  %t1 = add i32 0, 5
  store i32 %t1, i32* %y_ptr
  %z_ptr = alloca i32
  %t2 = load i32, i32* %x_ptr
  %t3 = load i32, i32* %y_ptr
  %t4 = add i32 %t2, %t3
  store i32 %t4, i32* %z_ptr
  %t5 = load i32, i32* %x_ptr
  %call0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.fmt0, i32 0, i32 0), i32 %t5)
  ret i32 0
}
```

---

## ✨ Key Features

- Lexical Analysis using Flex (tokenizes keywords, identifiers, numbers, operators)
- LALR(1) Syntax Parsing using Bison (shift/reduce conflict fixed with %left)
- Full AST with 5 node types: Number, Identifier, Binary, Assign, Print
- Semantic Analysis with Symbol Table (detects undeclared variables)
- Real LLVM IR generation using alloca, store, load, and printf call instructions
- Native code generation pipeline via llc and gcc
- Modular design — each compiler phase in a separate C file
- Implementation entirely in C with no external dependencies

---

## ⚠️ Known Limitations

- Only i32 integer type is supported (no floats or strings yet)
- No control flow structures (if/while) — planned for future
- Single source file input only

---

## 📌 Future Enhancements

- Add if/else and while control flow
- Support float and string data types
- Add function definitions and recursion
- Implement basic optimization passes
- Improve error recovery in parser

---

## 🏁 Conclusion

This project successfully implements a modular, end-to-end DSL compiler with full LLVM backend integration. It demonstrates the complete compilation pipeline — from DSL source code through lexical analysis, parsing, AST construction, semantic checking, and LLVM IR emission — all the way to a native executable, implemented entirely in C.
