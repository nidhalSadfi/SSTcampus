#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(){
    char newtabStr[] = "SST-Campus*&{([|$**";
    char secStr[12];
    strncpy(secStr,newtabStr, sizeof(secStr));
    printf("strlen secStr ([12] by copy)=%d\n",strlen(secStr));
}