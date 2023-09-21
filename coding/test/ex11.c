#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *s1="Afrique";
    *s1='\0';
    printf("<%d>",s1[0]);
    return 0;
}