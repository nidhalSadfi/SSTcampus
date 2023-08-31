#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello C Syntax world!\n");

    //MOdulo=============================
    short subs[] = {156,189,678,434,600, 879};
    printf("sizeof of subs array = %d\n", sizeof(subs));
    int nb_subs = sizeof(subs) /sizeof(subs[0]);
    for (int i = 0 ; i < 20 ; i++){
        printf("subs[%d]=%d ",i%nb_subs,  subs[i%nb_subs]);
    }
    printf("\n");
    /////////////////////////////////////////
    //AFFECTTAION
    int leftValue;
    int rightValue = 190;
    leftValue = rightValue;
    leftValue = 190; //rightValue could be a constant
    // 190 = leftValue; //impossible =>leftValue must be a memmory content
    printf("1. leftValue =%d \n", leftValue);

    printf("assign result =%d\n", leftValue = 120);
    printf("2. leftValue =%d \n", leftValue);

    int aValue = (leftValue = 160); //set the assign result
    printf("3. leftValue =%d \n", leftValue);
    printf("aValue =%d \n", aValue);
    int x,y,z,t;
    x = y = z = t = 500; //stream of assignments
    printf("x =%d, y=%d \n",x,y);

    int *p = malloc(sizeof(int)); //Assign
    if (p==NULL){
        printf("problem to obtain memory !!!\n");
        exit(1);
    }
    printf("*p=%d\n", *p = 300);
    free(p);
    if ((p = malloc(4))==NULL){
        printf("problem to obtain memory !!!\n");
        exit(2);
    }
    printf("*p=%d\n", *p = 500);
    free(p);
    /////////////////////////////////////////////

    return 0;
}
