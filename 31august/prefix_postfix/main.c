#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello prefix/postfix world!\n");

    //prefix
    int v = 18;
    int m = ++v;
    printf("v=%d, m=%d\n",v,m);

    //postfix
    v= 18;
    m = v++;
    printf("v=%d, m=%d\n",v,m);

    return 0;
}
