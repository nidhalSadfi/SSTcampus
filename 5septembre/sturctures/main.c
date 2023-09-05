#include <stdio.h>
#include <stdlib.h>

typedef struct {
   short a;
   float y;
   long d;
} MY_STRUCTURE;


int main()
{
    printf("Hello structure world!\n");

    MY_STRUCTURE x,y;
    x.a = 10;
    x.y = 3.14;
    x.d = 567;

    y = x; //shallow copy (copie superficielle)
    //y is indepent from x $$$
    y.a++;
    x.d--;
    printf("x=(%d,%.3f,%d)",x.a,x.y,x.d);
    printf("y=(%d,%.3f,%d)",y.a,y.y,y.d);
    return 0;
}
