#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    printf("Hello pointers on structure world!\n");

    struct sVector v1={1,2,3}, v2 ={.z=0,.x=15};
    struct sVector v3 = v2; //v2 and v3 are indepentnet memories
    printf("v3=(%d,%d,%d)\n",v3.x,v3.y,v3.z);
    v3.x *= 100;
    printf("v3=(%d,%d,%d)\n",v3.x,v3.y,v3.z);
    printf("v2=(%d,%d,%d)\n",v2.x,v2.y,v2.z);

    struct sVector *v4 = &v2;
    printf("v4=(%d,%d,%d)\n",v4->x,v4->y,v4->z);
    v4->x *=10;
    printf("v4=(%d,%d,%d)\n",v4->x,v4->y,v4->z);
    printf("v2=(%d,%d,%d)\n",v2.x,v2.y,v2.z);

    printf("&v2=0x%x, v4=0x%x\n", &v2, v4);

    assert((&v2)->x == v4->x);
    assert(v2.y == v4->y);
    assert(v2.z == (*v4).z);

    return 0;
}
