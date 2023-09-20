#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sMem[256];
    int code , len;
    printf("Hello search all chareters in a memory ...\n");
    do{
        printf("please type the char to earch for (0 to quit)=>");
        scanf("%d",&code);
        if (code == 0)
            break;
        printf("please type the string memory to search the <%c> =>",code);
        scanf("%s",&sMem);
        len = strlen(sMem);
        printf("all positions of the <%c> code in (in len %d) of memory:\n",code, len);
        char *pMem = sMem;
        int i = 0;
        do {
            pMem = (char*)memchr(pMem,code,len-(pMem-sMem));
            if (pMem){
                printf("[%d]=>%d,",i+1,pMem-sMem+1);
                pMem++;
                i++;
            }else
               break;
        }while (1);
        if (i)
           printf("=> found %d %d<%c> code in the memory\n",i,code,code);
        else
           printf("=> %d<%c> not found in memory !\n",code,code);

    }while(1);
    return 0;
}
