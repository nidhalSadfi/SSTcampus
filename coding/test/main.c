#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s1[]="Tunis";
    *s1='\0';
    printf("<%d>\n",s1[0]);
    return 0;
}