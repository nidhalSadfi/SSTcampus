#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Hello pointers !!!!\n");
    printf("<<1>>. reserve static Stack addresses on int and leyt content variable!\n");
    int i = 19, j = 90;
    printf("i = %d [address of i = 0x%p]\n",i,&i);
    printf("j = %d [address of j = 0x%p]\n",j,&j);
    i = 45;
    printf("i = %d [address of i = 0x%p]\n",i,&i);
    printf("<<2>>. reserve static stack address on float and let content variable!\n");
    float f = 19.7;
    printf("f = %f [address of i = 0x%p]\n",f,&f);

    int *pi ;// = &f;
    printf("[1. address of pi = %p]\n",pi);
    pi = malloc(sizeof(int));
    *pi = 16;
    printf("[2. address of pi = %p]\n",pi);
    printf("now the content of *pi = %d\n",*pi);
    free(pi);
    pi = NULL;

    printf("[3. address of pi = %p]\n",pi);
    //*pi= 17; //!!!!!!Plantage

    int * px = malloc(sizeof(int));
    *px = 89;
    printf("now the content of [px=%p] *px = %d\n",px, *px);

    pi = malloc(sizeof(int));
    if (pi == NULL){
        printf("mallos returns NULL pointer=> no remain memory !!!");
        exit(1);
    }

    printf("[4. address of pi = %p]\n",pi);
    *pi = 17;
    printf("now the content of *pi = %d\n",*pi);
    free(pi);
    pi = NULL;

    free(px);
    px = NULL;
}
