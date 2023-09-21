#include<stdio.h>
#include<stdlib.h>
int main(){
    char newtStr[] = "SST-Campus*&{([|$**";
    char *thrdStr = malloc (sizeof(char)*10);
    strncpy(thrdStr,newtStr, strlen(thrdStr));
    printf("strlen thrdStr (malloc by copy)=%d\n",strlen(thrdStr));
    return 0;
}
