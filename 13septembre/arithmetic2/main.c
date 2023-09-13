#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int (*operation) (int, int);

typedef struct{
    operation op;
   char sLib[6];
}ope;

int add(int n1, int n2) { return n1 + n2; }
int sub(int n1, int n2) { return n1 - n2; }
int frac(int n1, int n2) { return n1 / n2; }
int reste(int n1, int n2) { return n1 % n2; }

ope tabOpe[]= {{add,"Add"},
               {sub,"Sub"},
               {frac,"Frac"},
               {reste,"Mod"}
               };
                //Mapping[ev,Action]  <=> DI

int arithmetic(int n1, int n2, operation op) {//holder function
   return op(n1, n2);//generic call <=> IoC
}
int szOpe = sizeof(tabOpe)/sizeof(*tabOpe);
void getMenu(char *menu){
   menu[0] = '\0';
   char slib[10];
   for (int i=0;i<szOpe;i++ ){
    sprintf(menu,"%s %d: %s \n" , menu , i+1 ,tabOpe[i].sLib);
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
        //printf ("the opÃ©ration (1:add,2:sub,3:div,4:mod 0: to quit)=====>");
        printf ("%s 0: to quit =====>",sMenu);
        scanf("%d",&op);
        if(op == 0)
            break;
        printf("the result is :%d\n",arithmetic(nb1,nb2,tabOpe[op-1].op));
   }while(1);
}
