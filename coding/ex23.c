#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int a = 0xABCDEF;
    a++;a++;
    printf("%X",a);
    return 0;
}