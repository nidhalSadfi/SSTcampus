#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char expectation[32];
static int val;
char *weatherforecast_global (int day) {
    strcpy(expectation,"this day will be rainy...\n");
    //printf ("to return :%s",expectation);
    return expectation;
}
char *weatherforecast_static (int day)
{
    static char expectation[32];//array of char => RW Memory$$$
    strcpy(expectation,"this day will be rainy...\n");
    //printf ("to return :%s",expectation);
    return expectation;
}

char *weatherforecast_romemory (int day) {
    char *expectation = "This day won't be rainy...\n"; //RO memory
    printf("addres of the constant strint .text=0x%x\n",
                              "This day won't be rainy...\n");
    printf("read from  <%c> first char .text=0x%x\n",
                              "This day won't be rainy...\n"[0]);
    //printf ("to return :%s",expectation);
    return expectation;
}
int *valboursiere_global (char *site)
{
    val *= 10;
    printf ("to return :%d\n",val);
    return &val;
}
int *valboursiere_static (char *site)
{
    static int val = 19;
    val *= 10;
    printf ("to return :%d\n",val);
    return &val;
}


char *weatherforecast_heap (int day)
{
    char *expectation = malloc(sizeof(char)*32);
    strcpy(expectation,"this day will be rainy...\n");
    //printf ("to return :%s",expectation);
    return expectation;
}
int *valboursiere_heap (char *site)
{
    int *val = malloc (sizeof(int));
    *val = 19;
    *val *= 10;
    printf ("to return :%d\n",*val);
    return val;
}


int main(int argc, char * argv[]) {
    int d = 15;
    char *s0 =weatherforecast_romemory(d);
    printf("1. annouce : %s[0x%x]\n",s0,s0) ;
    //s0[0]="W"; //RO MEMORY !!!!!!
    printf("2. annouce : %s[0x%x]\n",s0,s0) ;

    d = 15;
    char *s =weatherforecast_static(d);
    printf("annouce : %s[0x%x]\n",s,s) ;

    char site[26] = "Megrine";
    int *v =valboursiere_static(site);
    printf("display : %d[0x%x]\n",*v,v) ;

printf("======================================\n");
    char *ss =weatherforecast_heap(d);
    printf("annouce : %s[0x%x]\n",ss,ss) ;
    free(ss);
    char ssite[26] = "Megrine";
    int *vv =valboursiere_heap(ssite);
    printf("display : %d[0x%x]\n",*vv,vv) ;
    free(vv);

    return 0;
}
