#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int assign(int*p,int v){
    printf("p=0x%x\n",p);
    *p = v;
    return *p;
}

int main() {
    printf("Hello itoa world!\n");

    int i = 17, j = 10;

    int z = (i = j);
    printf("i=%d,j=%d,z=%d\n",i,j,z);
    printf("value of the assignement =%d\n", z = 89);
    printf("z=%d\n",z);
    z = assign(&i,j);
    printf("i=%d,j=%d,z=%d\n",i,j,z);
    int k = z = i = j = 47; //a stream operation
    printf("1. i=%d,j=%d,z=%d, k=%d\n",i,j,z,k);
    printf("1. &i=%x,&j=%x,&z=%x, &k=%x\n",&i,&j,&z,&k);
    //call by reverse from roight to left in order to eva;uate parameters before any call
    assign(&k,assign(&z,assign(&i,assign(&j,49))));
    printf("2. i=%d,j=%d,z=%d, k=%d\n",i,j,z,k);

     return 0;
}


