#include <stdio.h>
#include <stdlib.h>
int main() {
    int x=5;
    char ch[10];
    gets(ch);
    printf("%x\n",ch);
    printf("%x\n",&x);
    printf("%d",x);
    return 0;
}
