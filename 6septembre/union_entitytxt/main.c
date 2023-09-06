#include <stdio.h>
#include <string.h>

#define TYPE_UNKNOWN Â 0
#define TYPE_VENDEUR  1
#define TYPE_ACHETEUR 2

typedef struct{
    short numberOfProds;
    short speed;
    short energy;
}VENDEUR;
typedef struct{
    char type_bonus[12];//MAKE IT 20 OR YOU WILL GET AN ERROR
}ACHETEUR;

typedef struct{
  short type;
  short x,y;//position
  union{
    VENDEUR buyer;
    ACHETEUR customer;
  };//anonymous
}ENTITY;

void  displayEntity(ENTITY *_ent){
   printf("position <%d,%d> \n", _ent->x, _ent->y);
   if (_ent->type == TYPE_VENDEUR){
      printf("buyer.numberOfProds>in use:%d, energy=>%d\n",
            _ent->buyer.numberOfProds,
            _ent->buyer.energy);
   }else if (_ent->type == TYPE_ACHETEUR){
      printf("value of Unions member <customer.type_bonus> in use : %s\n",
              _ent->customer.type_bonus);
   }else{
       printf("ERROR : unknown entity !!!\n");
   }
}

void main() {
    printf("sizeof VENDEUR is : %d\n",sizeof(VENDEUR));
    printf("sizeof ACHETEUR is : %d\n",sizeof(ACHETEUR));
    printf("sizeof ENTITY is : %d\n",sizeof(ENTITY));

    ENTITY _ent;
    strcpy(_ent.customer.type_bonus,"excellent");
    _ent.type = TYPE_ACHETEUR;
    displayEntity(&_ent);
    /////////////////////////////////////////
    _ent.buyer.numberOfProds = 89;
    _ent.buyer.speed = 25;
    _ent.buyer.energy = 3838;
    _ent.type = TYPE_VENDEUR;

    displayEntity(&_ent);
    printf("=====================================\n");

    ENTITY *pTab[5];//an array of 5 pointers on ENTITY
    for (int i = 0 ; i < 5 ; i++){
        pTab[i] = malloc(sizeof(ENTITY));
        if (i % 2 == 0){
          sprintf(pTab[i]->customer.type_bonus,"Excellent Acheteur%d",i);
          pTab[i]->type = TYPE_ACHETEUR;
        }else{
            pTab[i]->buyer.numberOfProds = 10*i+1;
            pTab[i]->buyer.speed = 25+i;
            pTab[i]->buyer.energy = 3838;
            pTab[i]->type = TYPE_VENDEUR;
        }
    }

    for (int i = 0; i < 5 ; i++){
        displayEntity(pTab[i]); //<=>displayEntity(pTab+i);
        free(pTab[i]);
        pTab[i] = NULL;
    }
}
