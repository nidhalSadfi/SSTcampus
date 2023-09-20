#include <stdio.h>
#include <stdlib.h>


int main()
{
    char sMem[256];
    int code , len;
    printf("Hello search all chareters in a memory ...\n");
    do{
        printf("please type the char to search for (0 to quit)=>");
        scanf("%d",&code);
        if (code == 0)
            break;
        printf("please type the string memory to search in the %c =>",code);
        scanf("%s",&sMem);
        len = strlen(sMem);
        printf("all positions of the %c code in (in len %d) of memory:\n",code, len);

    }while(1);
    return 0;
}
