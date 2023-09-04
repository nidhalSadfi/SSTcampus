#include <stdio.h>
const int gnbMois=12;
int main(void) {
    //gnbMois--;
    //const is considered only as a static constrinat (in the code, no impatc in runtime)
    int const i = 10;    /* i is stored in common memory */
    const int  i2 = 10;    /* i is stored in common memory */
    //i = 12; //=> error
    //i2++;


    int *ptr = &i; //NO constraint applyed on ptr $$$
    printf("ptr=0x%x, &i=0x%x\n",ptr,&i);
    printf("const i: %d\n", i);
    *ptr = 100;        /* No error */
    printf("*ptr=%d, i=%d\n",*ptr,i);


    printf("1.===================================\n");
    const int j = 20;
    const int *q = &j; //declare a pointer on a const Integer !
    //j++;
    //*q = 200; //It is forbidden to change the content!
    int *r = q;
    *r = 600;
    printf("*r=%d,*q=%d, j=%d\n",*r,*q,j);
    printf("2.===================================\n");
    q = &i; //as q is apoiter ariable
    printf("const i=%d: now q is pointing to &i=> *q=%d\n", i, *q);

    printf("3.===================================\n");
    const int k = 56;
    //k = 23;
    int * const s = &k;//s is const pointer on int (varaible con tent)
    *s = 23;
    printf("k=%d,*s=%d\n",k,*s);
    //s = &j; //c'ant changfe the addres !!!!!

    printf("4.===================================\n");
    int m = 900;
    //define a const pointer on a const int (the conetnt is also const)!
    int const * const t = &m;
    //*t = 224;
    //t = &j;

    return 0;
}
