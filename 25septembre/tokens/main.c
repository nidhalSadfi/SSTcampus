#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char str[]="this is a sample string";
    char key[]="aeiou";
    char *pch;
    printf("Vowels in '%s' : ",str);
    pch=strpbrk(str,key);
    while (pch!=NULL){
        printf("%c[%d]",*pch,pch-str+1);
        pch=strpbrk(pch+1,key);
    }
    printf("\n");
    return 0;

}