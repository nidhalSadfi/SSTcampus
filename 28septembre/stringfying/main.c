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
}
