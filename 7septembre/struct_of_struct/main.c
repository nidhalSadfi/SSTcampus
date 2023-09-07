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
};

typedef struct{
   float w1, w2;
}wheight;

struct stPoint{
   struct sVector v; //a public type structure
   struct color {//a nested type structure
      char r, g ,b;
   }c1;
   struct color c2;
   short id;
   wheight wh;
};

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
    *v5 = v2;//shallow copy $$$
    printf("v5=(%d,%d,%d)\n",v5->x,v5->y,v5->z);
    free(v5);
    printf("=========================================\n");

    struct stPoint p1;
    p1.v.x=10;
    p1.v.y=20;
    p1.c1.r=255;
    p1.wh.w1 = 3.14;
    printf("p1(v(%d,%d,%d),color c1(%d,%d,%d), wheight wh.w1=%.2f)",p1.v.x,p1.v.y,p1.v.z,
                        p1.c1.r,p1.c1.g,p1.c1.b,p1.wh.w1);

    printf("sizeof .................\n");
    printf("sizeof(color)=%d \n",sizeof(p1.c1));
    printf("sizeof(wheight)=%d \n",sizeof(wheight));
    printf("sizeof(sVector)=%d \n",sizeof(struct sVector));
    printf("sizeof(stPoint)=%d \n",sizeof(struct stPoint));
    return 0;
}
