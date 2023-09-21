#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char theStr[18] = "SST@sagemcom.com";
    theStr[10]='\10';
    theStr[11]= '\13';
    theStr[12]= '\0';
    theStr[13]= '\7';
    printf("%d",strlen(theStr));
    printf("%s",theStr);
}
