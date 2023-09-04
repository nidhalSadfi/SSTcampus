#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    printf("Hello world!\n");

    int c1 = -1; //by dzfault it is signed !
    signed int c2 =  -1;

    printf("c1 = %d ", c1);
    printf("the uint max c1 = %u\n", c1);
    printf("the uint Max from limits.h = %u\n", UINT_MAX);
    printf("the uchar Max from limits.h = %u\n", UCHAR_MAX);
    printf("the char Max from limits.h = %u\n", CHAR_MAX);


    return 0;
}
