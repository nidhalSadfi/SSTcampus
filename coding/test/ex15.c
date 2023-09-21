#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s1[]="1998";
    (*s1)+=3;
    printf("%d",atoi(s1));
    return 0;
}