#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s1[12]="SSTCampus";
    s1[5]='\0';
    printf("%d",sizeof(s1));
    return 0;
}