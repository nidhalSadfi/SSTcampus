#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
   short a;
   float y;
   long d;
} MY_STRUCTURE;

struct sVector{
   short x;
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
    printf("&v2.x=0x%x, &v2.y=0x%x, &v2.z=0x%x\n", &v2.x, &v2.y,&v2.z);

    assert((&v2)->x == v4->x);
    assert(v2.y == v4->y);
    assert(v2.z == (*v4).z);
    //assert((&v2)->x == v4->x && v2.z == (*v4).z && v2.z == (*v4).z);

    struct sVector *v5 = malloc(sizeof(struct sVector));
    printf("&v5=0x%x\n", &v5);
    printf("v5=0x%x\n", v5);
    memset(v5,0, sizeof(struct sVector));
    printf("v5=(%d,%d,%d)\n",v5->x,v5->y,v5->z);
    *v5 = v2;
    printf("v5=(%d,%d,%d)\n",v5->x,v5->y,v5->z);

    free(v5);
    return 0;
}
