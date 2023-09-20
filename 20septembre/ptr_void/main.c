#include<stdio.h>
int main()
{
    int a[2] = {10, 20};
    void *ptr = &a;
    ptr = ptr + sizeof(int);
    printf("1. %d\n", *(int *)ptr);

    ptr = a;
    ptr = ((int*)ptr) + 1; //casting ne change la nature du pointeur !
    printf("2. %d\n", *(int *)ptr);
    int *pi = (int*)ptr;
    printf("3. %d\n", *pi);

    printf("====================================\n");
    int i = 15;
    int *p= &i; //its own address is static on stack but its content can contain diffrent addresses
    *p = 19;
    printf("*p=%d, i=%d\n",*p, i);
    printf("static addresses on the stack (RO) ==> &p=0x%x, &i=0x%x\n",&p, &i);

    p = (int*)malloc(sizeof(int)); //p caonyaint ahead address now
    *p = 17;
    printf("*p=%d\n",*p);

    int j= 67;
    p= &j; //heap address is lost !!!!
    printf("*p=%d\n",*p);

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    free(p); ///undefined beahavior !! a free on a stack memory
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    return 0;
}
