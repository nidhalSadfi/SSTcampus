
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    //Ox désigne un nombre écrit en Héxa
    int a = 0x8;
    int b = 2, c = 4;
    int d = a & b & c ;
    printf("%x",d);
    return 0;
}