#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello C Syntax world!\n");
    //Test expression logique
    int a = 1;
    if (a == 1){
        printf("1. positive condition\n");
    }else{
        printf("1. neagative condition\n");
    }
    if (a){
        printf("2. positive condition\n");
    }else{
        printf("2. neagative condition\n");
    }
    a = -2;
    if (a){
        printf("3. positive condition\n");
    }else{
        printf("3. neagative condition\n");
    }
    a = 0;
    if (a){
        printf("4. positive condition\n");
    }else{
        printf("4. neagative condition\n");
    }
   //==> False is 0; True is not False
    if (!a){
        printf("5. positive condition\n");
    }else{
        printf("5. neagative condition\n");
    }
    a = 10;
    if (!a){
        printf("6. positive condition\n");
    }else{
        printf("6. neagative condition\n");
    }
    /////////////////////////
}
