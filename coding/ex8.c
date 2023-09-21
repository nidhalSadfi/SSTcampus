#include <stdio.h>
int main() {
    printf("Hello world!\n");
    int num = 1500;
    if (num >= 0)
        if (num >= 1600)
            printf("*");
        else if (num >= 1500)
            printf("*");
        else if (num >= 1000)
            printf("*");
        else if (num >= 100)
            printf("*");
        else if (num >= 10)
            printf("*");
        else
            printf("#");
    else
        printf("!");
}