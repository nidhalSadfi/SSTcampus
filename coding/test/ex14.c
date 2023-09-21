#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s1[11]="SST-Campus.";
    *(strlen(s1))='*';
    printf("%s",s1);
    return 0;
}