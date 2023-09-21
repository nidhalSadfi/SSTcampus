#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s1[10]={'M','e','g','r','i','n','e'};
    *(s1+6)=0;
    printf("<%d>\n",sizeof(s1));
    return 0;
}