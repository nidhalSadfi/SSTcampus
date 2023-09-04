#include <stdio.h>

// A space optimized representation of date
struct classic_date
{
   unsigned int d;
   unsigned int m;
   unsigned int y;
};
struct date {
   // d has value between 1 and 31, so 5 bits
   // are sufficient
   unsigned int d: 5;
   // m has value between 1 and 12, so 4 bits
   // are sufficient
   unsigned int m: 4;

   unsigned int y:12; //impose 4 bytes as size
};

int main()
{
   printf("Size of classic date is %d bytes\n",
                   sizeof(struct classic_date)); //12 bytes
   printf("Size of date is %d bytes\n",
                          sizeof(struct date)); //8 bytes


   struct date dt = {31, 12, 2014};
   printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
   return 0;
}
