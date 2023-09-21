#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *s1=malloc(17);
    strcpy(s1,"SSTCampus");
    const char *s2="Sagemcom";
    s1=s2;
    printf("<%s>",s1);
    free(s1);
    return 0;
}