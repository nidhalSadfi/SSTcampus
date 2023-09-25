#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char szOrbits[]="365.24 29.53 14.25";
    char *pEnd;
    double d1,d2,d3;
    printf("szOrbits=0x%x\n",szOrbits);
    d1=strtod(szOrbits,&pEnd);
    printf("1.pend=0x%x\n",pEnd);
    d2=strtod(pEnd,&pEnd);
    printf("2.pend=0x%x\n",pEnd);
    d3=strtod(pEnd,NULL);
    printf("3.pend=0x%x\n",pEnd);
    printf("the moon completes %.2f orbites per earth year .(half =%.2f)",d2,d3);
    return 0;
}