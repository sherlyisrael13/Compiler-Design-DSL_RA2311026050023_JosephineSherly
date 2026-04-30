; DSL Compiler LLVM IR
; Author: Josephine Sherly RA2311026050023

@.fmt0 = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@.fmt1 = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@.fmt2 = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@.fmt3 = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@.fmt4 = private unnamed_addr constant [4 x i8] c"%d\0A\00"

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
  %t6 = load i32, i32* %y_ptr
  %call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.fmt1, i32 0, i32 0), i32 %t6)
  %t7 = load i32, i32* %z_ptr
  %call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.fmt2, i32 0, i32 0), i32 %t7)
  ret i32 0
}
