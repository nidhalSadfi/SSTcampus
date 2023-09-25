#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtod */
int main ()
{
  char szOrbits[] = "365.24 29.53 14.25";
  char* pEnd;
  double d1, d2, d3;
  printf("szOrbits=0x%x\n",szOrbits);
  d1 = strtod (szOrbits, &pEnd);
  printf("1.pend=0x%x\n",pEnd);
  d2 = strtod (pEnd, &pEnd);
  printf("2.pend=0x%x\n",pEnd);
  d3 = strtod (pEnd, NULL);
  printf("3.pend=0x%x\n",pEnd);
  printf ("The moon completes %.2f orbits per Earth year. (half=%.2f)\n", d1/d2,d3);
  return 0;
}
