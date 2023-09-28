#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024
#define SIDES      2
#define TABLESIZE BUFSIZE*SIDES*NODES
#define NODES   8

#define SZ(TAB) sizeof(TAB)/sizeof(*TAB)
#define CUBE(x) ((x)*(x)*(x))
#define max(A,B) ((A) > (B) ? (A) : (B))
int cmax(int a, int b){
  return (a>b)?a:b;
}
int main()
{
    //int NODES= 10;
    printf("Hello world!\n");
    int tabMonths[TABLESIZE];
    printf("sizeof of tabMonths=%d\n",SZ(tabMonths));
    int a = 10, b = 18;
    printf("max (b,a)+100=%d\n",max(b,a)+100);
    printf("max (b,a)+100=%d\n",((b) > (a) ? (b) : (a))+100);

    int i = 2,  j = 3;
    int k = max(i+1, j+1); //could be safe in such case â€¦ but :
    printf ("5.max(i+1, j+1) i=%d,j=%d===> k=%d\n",i,j,k);
    k = max(j+1, i+1); //could be safe in such case â€¦ but :
    printf ("5.max(j+1, i+1) i=%d,j=%d===> k=%d\n",i,j,k);
//////////////////////////////////////
    int l = max(i++, j++); //result in l=3, i=3, j = 4
    printf ("6.max(i++, j++) i=%d,j=%d===> l=%d\n",i,j,l);
    /////////////////////////////////
    printf("calssic cmax==>\n");
    i = 2,  j = 3;
    l = cmax(i++, j++); //result in l=3, i=3, j = 4
    printf ("6.cmax(i++, j++) i=%d,j=%d===> l=%d\n",i,j,l);


    return 0;
}
