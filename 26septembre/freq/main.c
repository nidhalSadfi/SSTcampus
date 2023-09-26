#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main()
{
    printf("Hello parser world !\n");
    char szOrbits[80]; // = "365.24 29.53 3.0 12.89 21.0 21.0";
    printf("list of double values :");
    FILE *freq;
    if ((freq = fopen("freaquencies.csv", "r")) == NULL)
    {
        printf("Error! opening file why ????\n==>[code=%d]%s\n", errno, strerror(errno));
        return 0;
    }
    double flt[80][25];
    int i = 0, ln = 0;

    do
    {
        int ret = fscanf(freq, "%[^\n]", szOrbits);
        if (ret < 0)
            break;
        char *pNext = szOrbits;
        do
        {
            flt[ln][i++] = strtof(pNext, &pNext);
        } while (*pNext);
        ln++;
        fread(szOrbits, sizeof(char), 1, freq); // jump the \n character
    } while (1);                                // while(ret)

    printf("number of lines treated =>%d\n", ln);
    /*for(int j = i ; j > 0 ; j--)
      printf("%d:%.2f,",i-j, dbl[i-j]);
    printf("\n");*/

    fclose(freq);
}
