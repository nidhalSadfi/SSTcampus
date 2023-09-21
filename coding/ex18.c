#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int i = 10;
    i++;
    int *p = &i;
    i+= 15;
    printf("%d\n",*p);
    return 0;
}
