#include <stdio.h>
#include <stdlib.h>

typedef unsigned int UINT; //delay the definition of the type at he end $$$

//Chained list
struct lnode{
   char id;
   int value;
   struct lnode *next;
};





int main()
{
    printf("Hello world!\n");
// Ã  allouer de la mÃ©moire
    struct lnode *lhead;
    lhead = malloc(sizeof(struct lnode));
    lhead->id = 100;
    lhead->value = 1234;
    lhead->next = NULL;
    int lval;
    struct lnode *holder=NULL;
    do {
        printf("set the value of new node on your list at the head (0 to break):");
        scanf("%d",&lval);
        if (lval == 0)
            break;
        struct lnode *lNewNode=malloc(sizeof(struct lnode));
        //prepare the new element
        lNewNode->value = lval;
        lNewNode->id = lhead->id+1;//<=>(*lhead).id+1
        lNewNode->next = lhead->next;
        //////////////////////////

        //chain the new element :
        lhead->next = lNewNode;
    }while(1);
    do {
        printf("set the value of new node on your list at the end (0 to break):");
        scanf("%d",&lval);
        if (lval == 0)
            break;
        struct lnode *lNewNode=malloc(sizeof(struct lnode));

        //prepare the new element
        lNewNode->value = lval;
        lNewNode->id = lhead->id+1;//<=>(*lhead).id+1
        lNewNode->next =holder;
        holder=lNewNode;
        //////////////////////////

        //chain the new element :
        lhead->next = lNewNode;
    }while(1);
    printf("display the list..\n");
    struct lnode *pWalker;
    pWalker = lhead;
    do{
      printf("[%d,%d]",pWalker->id, pWalker->value);
      if (pWalker->next == NULL)
        break;
      //now go to the next :
      pWalker = pWalker->next;
    }while(1);
    printf("\n");
    printf("libererate the memory !\n");
    struct tnode *pSave;
    pWalker = lhead;
    int nb = 0;
    do{
      if (pWalker == NULL)
        break;
      pSave = pWalker->next;
      free(pWalker);
      nb++;
      pWalker = pSave;
    }while(1);
    printf("liberate %d element on the list \n",nb);
    return 0;
}
