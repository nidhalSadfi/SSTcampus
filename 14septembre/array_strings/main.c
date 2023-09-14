#include <stdio.h>
#include <stdlib.h>

const char * line[] ={
    "SST-Campus",
    "the boy stood on the burning deck",
    "his hearts was all a quiver",
    "he gave a cough, his leg fell off",
    "and floated down the river"
};

const char text[][40] ={
    "SST-Campus",
    "the boy stood on the burning deck",
    "his hearts was all a quiver",
    "he gave a cough, his leg fell off",
    "and floated down the river"
};


int main()
{
    printf("Hello world!\n");
    printf("size of the global array = %d\n",sizeof(line) );
    printf("size of the firqt element int the array = %d\n",sizeof(*line) );
    int NBSTR = sizeof(line)/ sizeof(*line);

    printf("nb string on the array = %d\n",NBSTR);
    for (int i = 0; i < NBSTR ; i++){
        printf("sizeof the line[%d] =%d => ",i, sizeof(line[i]));
        printf("len of the line[%d] =%d\n",i, strlen(line[i]));
    }
   printf("=====================================\n");
    printf("size of the global array = %d\n",sizeof(text) );
    printf("size of the firqt element int the array = %d\n",sizeof(*text) );
    NBSTR = sizeof(text)/ sizeof(*text);

    printf("nb string on the array = %d\n",NBSTR);
    for (int i = 0; i < NBSTR ; i++){
        printf("sizeof the line[%d] =%d => ",i, sizeof(text[i]));
        printf("len of the line[%d] =%d\n",i, strlen(text[i]));
    }

}
