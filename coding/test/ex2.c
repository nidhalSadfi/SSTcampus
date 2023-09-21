#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s1[]="Tunis";
    *s1='\0';
    printf("<%d>\n",sizeof(s1));
    return 0;
}