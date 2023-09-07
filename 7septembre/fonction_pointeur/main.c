#include <stdio.h>
#include <stdlib.h>

void PassageParPointeur (int *var){
    printf(" =>value introduced is :%d\n",*var);
    printf(" =>its pointer is :0x%x\n",var);
    int k = 56;
    *var = k;
    printf(" =>value to be returned :%d\n",*var);
}

int main() {
    int i = 17;
    printf("1. Value of i =%d\n ",i);
    printf(" =>the pointer of is :0x%x\n",&i);
    PassageParPointeur(&i);
    printf("2. Value of i =%d\n ",i);
    return 0;
}
