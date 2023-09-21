#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s1[]={'S','S','T','.','c','o','m'};
    *(s1+6)=0;
    printf("%s \n",s1);
    return 0;
}