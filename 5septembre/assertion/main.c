#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MYASSERT(e,msg) (e)?(void)0:\
                     printf("in %s function - %s [expression:%s]",\
                     __FUNCTION__,msg,#e);\
                     assert(e)
char *sMonths[] = {"Jan","Feb","Mar","","","","","","","","",""};
int main() {
    printf("Hello Assertion!\n");
   // printf("I am in %s file at %d line (function: %s)\n", __FILE__, __LINE__, __FUNCTION__);
    int m = 4;
    assert(m != 5);
    int op = 12*365/(m-5);
    printf("%d",op);

    printf("enter the monthe number (please between 1&12):");
    scanf("%d",&m);
    MYASSERT((m > 0) && m <= 12, "the condition on month is bad !!");
    printf("the month is %s\n",sMonths[m-1]);
}
