#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcpy (char dst[], const char src[]) {
  int at = 0;
  while ((dst[at] = src[at]))  at++;
  return dst;
}


int main()
{
    printf("Hello mystrcpy world!\n");
    const char *s5="Salam Alykom";//aalocation statoque de strlen("Salam")+'\0'
    printf("sizeof(s5)=%d, strlen(s5)=%d\n",sizeof(s5), strlen(s5));


    const char s4[]="Salam";//aalocation statoque de strlen("Salam")+'\0'
    printf("sizeof(s4)=%d, strlen(s4)=%d\n",sizeof(s4), strlen(s4));

    char s3[strlen(s4)+1];
    char s2[strlen(s4)+1];
    char s1[strlen(s4)+1];
    char s0[sizeof(s4)];
    mystrcpy(s1,mystrcpy(s2,mystrcpy(s3,"Salam")));
    printf("s1=%s, s2=%s, s3=%s, s4=%s\n",s1,s2,s3,s4);
    return 0;
}
