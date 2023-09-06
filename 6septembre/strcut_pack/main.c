#include <stdio.h>
#include <stdlib.h>

//use with -fpack-struct

struct A1 {
 char a;
 int b;
 char c;
}; /*sizeof (A) == 12*/

struct B {
 char a;
 char c;
 int b;
}; /*sizeof (B) == 8*/

struct A2 {
 char a;
 int b;
 char c;} __attribute__((packed));


int main()
{
    printf("Hello packed structures world!\n");
    printf("sizeof(A1)=%d\n",sizeof(struct A1));
    printf("sizeof(B)=%d\n",sizeof(struct B));
    printf("sizeof(A2)=%d\n",sizeof(struct A2));
    return 0;
}
