#include <stdio.h>
#include <stdlib.h>

#define PLANT(y) "placing "#y" in a string\n"

#define TRACED(y) printf("value of "#y" is %d\n",y)
#define TRACES(y) printf("value of "#y" is %s\n",y)
#define REPORT(test, ...) \
         ((test)? \
         printf("%s\n",#test): \
         printf(__VA_ARGS__))
#define EVALUATE(expression) \
        printf("%s equals to %d\n",#expression,expression)

#define BEGIN_OPE(operation) ope tabOpe[]= {{ope_ ## operation, #operation},
#define OPE(operation) {ope_ ## operation, #operation},
#define END_OPE };
/////////////////////////////////////////////////
typedef int (*operation) (int, int);

typedef struct{
   operation op;
   char sLib[6];
}ope;

int ope_add(int n1, int n2) { return n1 + n2; }
int ope_sub(int n1, int n2) { return n1 - n2; }
int ope_frac(int n1, int n2) { return n1 / n2; }
int ope_reste(int n1, int n2) { return n1 % n2; }
int ope_mult(int n1, int n2) { return n1 * n2; }
/*
ope tabOpe[]= {{add,"Add"},
               {sub,"Sub"},
               {frac,"Frac"},
               {&reste,"Mod"},
               {&mult,"Mult"}
               }; //Mapping[ev,Action]  <=> DI
*/

BEGIN_OPE(add)
 OPE(sub)
 OPE(frac)
 OPE(mult)
END_OPE

int szOpe = sizeof(tabOpe)/sizeof(*tabOpe);
///////////////////////////////////////////////////
int main(){
    char *ss = "Tunis"
               "Carthage""Marine";
    printf("ss=%s\n",ss);
    int xx = 5, yyy=2023;
    printf("value of xx is %d\n",xx);
    TRACED(xx);
    TRACED(yyy);
    TRACES(ss);

    int x1 = 4, x2 = 8;
    REPORT(x1 > x2, "x1 is %d but x2 is %d\n", x1, x2);
    x1 = 9;
    REPORT(x1 > x2, "x1 is %d but x2 is %d\n", x1, x2);

    EVALUATE(x1+5*x2);

    TRACED(szOpe);
}
