#include <stdio.h>
#include <stdlib.h>
typedef int (*operation) (int, int);
int add(int n1, int n2) { return n1 + n2; }
int sub(int n1, int n2) { return n1 - n2; }
int frac(int n1, int n2) { return n1 / n2; }
int reste(int n1, int n2) { return n1 % n2; }
int arithmetic(int n1, int n2, operation op) {//holder function
   return op(n1, n2);
}
int main() {
   int number1 = 5, number2 = 6;
   operation anOp = &add;
   operation tabOpe[4]={&add,&sub,&frac,&reste};
   int nb1,nb2;
   int op;
   printf ("give numbers n1 n2 =>");
   scanf("%d %d",&nb1,&nb2);
   do{
        printf ("the opÃ©ration (1:add,2:sub,3:div,4:mod 0: to quit)=====>");
        scanf("%d",&op); if(op == 0) break;
        printf("the result is :%d",arithmetic(nb1,nb2,tabOpe[op-1]));
   }while(1);
}
