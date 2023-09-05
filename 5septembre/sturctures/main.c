#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
   short a;
   float y;
   long d;
} MY_STRUCTURE;

struct sVector{
   int x;
   int y;
   int z;
} ;

int main() {
    printf("Hello structure world!\n");

    MY_STRUCTURE x,y;
    x.a = 10;
    x.y = 3.14;
    x.d = 567;

    y = x; //shallow copy (copie superficielle)
    //y is indepent from x $$$
    y.a++;
    x.d--;
    printf("x=(%d,%.3f,%d)\n",x.a,x.y,x.d);
    printf("y=(%d,%.3f,%d)\n",y.a,y.y,y.d);
    printf("sizeof(x)=%d,sizeof(y)=%d, sizeof(MY_STRUCTURE)=%d,\n",sizeof(x), sizeof(y), sizeof(MY_STRUCTURE));

    MY_STRUCTURE a = {10,6.1987,9}, //take attributes by position
                 b = {20,12.1987,18};//duck ititialisation
    printf("a=(%d,%.3f,%d)\n",a.a,a.y,a.d);
    printf("b=(%d,%.3f,%d)\n",b.a,b.y,b.d);


    MY_STRUCTURE c ={.a=87, .d=7};//named attributes
    printf("c=(%d,%.3f,%d)\n",c.a,c.y,c.d);
    memset(&c,0, sizeof(MY_STRUCTURE));
    printf("c=(%d,%.3f,%d)\n",c.a,c.y,c.d);

    printf("b=(%d,%.3f,%d)\n",b.a,b.y,b.d);

    printf("anonymous structers....\n");
    struct{
        long int a;
        long int b;
    } var_1, var_2, var_3, var_4;
    var_1.a = var_1.b = 18;

    var_2 = var_1;
    printf("var_2=(%d,%d)\n",var_2.a,var_2.b);

    struct sVector v1={1,2,3}, v2 ={.z=0,.x=15};

    struct sVector v3 = v2;
    printf("v3=(%d,%d,%d)\n",v3.x,v3.y,v3.z);
    v3.x *= 100;
    printf("v3=(%d,%d,%d)\n",v3.x,v3.y,v3.z);
    printf("v2=(%d,%d,%d)\n",v2.x,v2.y,v2.z);
    return 0;
}
