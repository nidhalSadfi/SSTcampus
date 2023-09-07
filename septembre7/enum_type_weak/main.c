#include <stdio.h>
#include <assert.h>

enum day {sunday = 1, Monday=2, tuesday = 4,
          Wednesday=8, thursday=16, Friday=32, Saturday=64};
char *sDay[]= {"sunday", "Monday", "tuesday",
          "Wednesday","thursday","Friday","Saturday"};
enum article {baguette, tomate=10, beure, fromage};

struct vst{
  int val;
};

struct wst{
  int val;
};

int main() {
    int daysOpened = Monday|thursday|Saturday;

    printf("BinaryValue = %d\n", daysOpened);
    printf ("the grocery is Opened on :");
    printf("sizeof(enuym day)=%d\n",sizeof(enum day));
    printf("sizeof(Wednesday)=%d\n",sizeof(Wednesday));
    printf("sizeof(Friday)=%d\n",sizeof(Friday));
    int i;
    for (enum day d = sunday , i = 0; d <= Saturday ; d <<= 1,i++) {
        if (daysOpened & d)
           printf ("%s-",sDay[i]);
    }

    printf("\n=======================\n");
    printf("baguette=%d, beure=%d\n", baguette,beure);

    enum day jour = fromage; //weak typed enum
    enum day ferie = 1998; //weak typed enum
    //jour 0.. 6 ==> in t sizeof(jour) =b 4 bytes  !!!!!
    printf("jour=%d\n",jour);

    struct vst v1 = {9};;
    struct wst w1 ={19};;
    //v1 = w1; ==> strong typed
    struct vst *pv1;
    pv1 = (struct vst*)&w1; //hard casting
    printf("*pv1=%d\n", pv1->val);
    assert (pv1->val == w1.val);

    int *pi;
    float *pf;
    pf = (float*)pi;
    return 0;
}
