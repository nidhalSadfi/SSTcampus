/* Test Function Pointers (TestFunctionPointer.cpp) */
#include <stdio.h>
#include <stdlib.h>


int add(int n1, int n2) { return n1 + n2; }
int sub(int n1, int n2) { return n1 - n2; }

// Take 3 arguments, 2 int's and a function pointer
//   int (*)(int, int), which takes two int's and return an int
typedef int (*operation) (int, int);
int arithmetic(int n1, int n2, operation op) {
   return op(n1, n2);
}
int main() {
   int number1 = 5, number2 = 6;
   // add
   printf("arithmetic -add => %d\n", arithmetic(number1, number2, add));
   // subtract
   printf("arithmetic-sub => %d\n", arithmetic(number1, number2, sub));
}
