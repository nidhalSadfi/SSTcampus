#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello init arrays world!\n");
    int days1[6]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("sizeof(days1)=%d=> number of entries=%d\n",sizeof(days1),sizeof(days1)/sizeof(*days1));
    int days2[]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("sizeof(days2)=%d=> number of entries=%d\n",sizeof(days2),sizeof(days2)/sizeof(*days2));
    int days3[20]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("sizeof(days3)=%d=> number of entries=%d\n",sizeof(days3),sizeof(days3)/sizeof(*days3));
    char pattern1[] = { 'o', 'u', 'l', 0x54, 0, 'd', '\0' };
    printf("sizeof(pattern1)=%d=> number of entries=%d\n",sizeof(pattern1),sizeof(pattern1)/sizeof(*pattern1));
    printf("pattern1=%s, strlen(pattern1)=%d\n",pattern1,strlen(pattern1));
    char pattern2[] = "ould"; //a shorthand
    printf("sizeof(pattern2)=%d=> number of entries=%d\n",sizeof(pattern2),sizeof(pattern2)/sizeof(*pattern2));
    printf("pattern2=%s, strlen(pattern2)=%d\n",pattern2, strlen(pattern2));

    return 0;
}
