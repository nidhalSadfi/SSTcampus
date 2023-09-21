#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    const char *s1="SSTCampus";
    char *s2="Megrine";
    s1=s2;
    printf("<%s>",s1);
    return 0;
}