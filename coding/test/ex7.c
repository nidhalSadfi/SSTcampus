#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *s1="SSTCampus";
    s1[3]=0;
    printf("<%d>\n",strlen(s1));
    return 0;
}