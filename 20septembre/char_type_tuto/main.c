#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>

#define MYUCHAR_MAX (unsigned char)-1

#define MYUINT_MAX (unsigned int)-1
#define MYUINT_MAXFF (unsigned int)0xFFFFFFFF

#define MYUSHORT_MAX (unsigned short)-1
#define MYSHORT_MAX (short)0x7FFF
int main()
{
    printf("Hello char type tuoto world (MYUINT_MAX=%u)\n",MYUINT_MAX);
    printf("MYUSHORT_MAX=%u , MYSHORT_MAX=%d\n",MYUSHORT_MAX,MYSHORT_MAX);
    assert(MYUINT_MAX == MYUINT_MAXFF);

    printf("blank charters ==>");
    for (int ndx=0; ndx<=UCHAR_MAX; ndx++)
      if (isblank(ndx)) printf("0x%02x(%c),", ndx, ndx);
    printf("\n");

    printf("x digits charters ==>");
    for (int ndx=0; ndx<=MYUCHAR_MAX; ndx++)
      if (isxdigit(ndx)) printf("0x%02x(%c),", ndx, ndx);
    printf("\n");
    int code;
    do{
        printf("please type the ascii char (0 to quit)=>");
        scanf("%d",&code);
        if (code == 0)
            break;
        printf("1. Isalpha(%d)=>%s =>%c\n", code, (isalpha(code)? "yes":"no"),code);
        printf("2. Islower(%d)=>%s =>%c\n", code, (islower(code)? "yes":"no"),code);
        printf("3. Isdigit(%d)=>%s =>%c\n", code, (isdigit(code)? "yes":"no"),code);
        printf("4. Isxdigit(%d)=>%s=>%c\n", code,(isxdigit(code)? "yes":"no"),code);
        printf("5. Iscntrl(%d)=>%s =>%c\n", code, (iscntrl(code)? "yes":"no"),code);
        printf("6. Isgraph(%d)=>%s =>%c\n", code, (isgraph(code)? "yes":"no"),code);
        printf("7. Isspace(%d)=>%s =>%c\n", code, (isspace(code)? "yes":"no"),code);
        printf("8. Isblank(%d)=>%s =>%c\n", code, (isblank(code)? "yes":"no"),code);
        printf("9. Isprint(%d)=>%s =>%c\n", code, (isprint(code)? "yes":"no"),code);
        printf("10.Ispunct(%d)=>%s=>%c\n",code, (ispunct(code)? "yes":"no"),code);

    }while(1);

    printf("bisslama...\n");
    return 0;
}
