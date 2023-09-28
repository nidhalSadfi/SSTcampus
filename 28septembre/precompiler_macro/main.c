#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024
#define SIDES      2
#define TABLESIZE BUFSIZE*SIDES*NODES
#define NODES   8

#define SZ(TAB) sizeof(TAB)/sizeof(*TAB)
#define CUBE(x) ((x)*(x)*(x))
#define max(A,B) (A) > (B) ? (A) : (B)


int main()
{
    //int NODES= 10;
    printf("Hello world!\n");
    int tabMonths[TABLESIZE];
    printf("sizeof of tabMonths=%d\n",SZ(tabMonths));
    int a = 10, b = 18;
    printf("max (b,a)+100=%d\n",max(b,a)+100);
    return 0;
}
