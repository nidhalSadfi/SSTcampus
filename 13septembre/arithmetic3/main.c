#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*operation) (int, int);

typedef struct{
   operation op;
   char sLib[20];
}ope;

int add(int n1, int n2) { return n1 + n2; }
int sub(int n1, int n2) { return n1 - n2; }
int frac(int n1, int n2) { return n1 / n2; }
int reste(int n1, int n2) { return n1 % n2; }
int mult(int n1, int n2) { return n1 * n2; }

ope tabOpe[]= {{add,"Addition"},
               {sub,"Substraction"},
               {frac,"Fraction"},
               {&reste,"Modulation"},
               {&mult,"Multipilcation"}
               }; //Mapping[ev,Action]  <=> DI
int szOpe = sizeof(tabOpe)/sizeof(*tabOpe);

int arithmetic(int n1, int n2, operation op) {//holder function
   return op(n1, n2);//generic call <=> IoC
}

void getMenu(char *menu){
   menu[0] = '\0';
   char sentry[20];
   for (int i = 0 ; i < szOpe ; i++){
      sprintf(sentry," %d:%s",i+1,tabOpe[i].sLib);
      strcat(menu,sentry);
   }
}
int main() {
   int number1 = 5, number2 = 6;
   int nb1,nb2;
   int op;
   printf ("give numbers n1 n2 =>");
   scanf("%d %d",&nb1,&nb2);
   char sMenu[80];
   getMenu(sMenu);
   do{
        printf ("%s 0:to quit =====>",sMenu);
        scanf("%d",&op);
        if(op == 0)
            break;
        if ((op < 0) || (op > szOpe))
            printf("please choose between 1 and %d\n", szOpe);
        else
            printf("the result of %s is :%d\n",tabOpe[op-1].sLib,arithmetic(nb1,nb2,tabOpe[op-1].op));
   }while(1);
}
