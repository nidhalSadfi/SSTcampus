#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char path[250];
    
    do{
        printf("give me your file path sir\n");
        scanf("%s",path);
        if(!strcmp(path,"0"))
            break;
        printf("this is your path %s \n",path);
        char *lastchar = strrchr(path,'/');
        char *pbasename= lastchar? lastchar+1:path;
        printf("base name: %s \n",pbasename);
        char *plastdot= strchr(pbasename,'.');
        if (plastdot){
            strcpy(plastdot,".log");
        }else{
            strcat(pbasename,".log");
        }
        printf("new name : %s \n",pbasename);
        FILE *fptr;
        if((fptr=fopen(path,"w"))==NULL){
            printf("error opening the file %s code number %d",strerror(errno),errno);
            exit(1);
        }
        fprintf(fptr,"%d-%s",19,"YOOOOOOO");
        fclose(fptr);
    }while(1);
    return 0;
}