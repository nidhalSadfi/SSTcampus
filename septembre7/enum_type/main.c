#include <stdio.h>
enum day {sunday = 1, Monday=2, tuesday = 4,
          Wednesday=8, thursday=16, Friday=32, Saturday=64};
char *sDay[]= {"sunday", "Monday", "tuesday",
          "Wednesday","thursday","Friday","Saturday"};
int main()
{
    int daysOpened = Monday|thursday|Saturday;

    printf("BinaryValue = %d\n", daysOpened);
    printf ("the grocery is Opened on :");
    /*for (enum day d = sunday , i = 0; d <= Saturday ; d <<= 1,i++) {
        if (daysOpened & d)
           printf ("%s-",sDay[i]);
    }*/
    enum day d = sunday,i=0;
    while (d<=Saturday){
         d <<= 1;

         if (daysOpened & d)
           printf ("%s-",sDay[i]);
        i++;

    }
    return 0;
}
