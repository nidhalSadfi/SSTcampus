#include <stdio.h>
#include <stdlib.h>
//by mayssa
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
// �  allouer de la mémoire
    struct lnode *lhead;
    lhead = malloc(sizeof(struct lnode));
    lhead->id = 100;
    lhead->value = 1234;
    lhead->next = NULL;

    int lval;
    struct lnode *first=malloc(sizeof(struct lnode));
    first=lhead;

    do {
        printf("set the value of new node on your list at the head (0 to break):");
        scanf("%d",&lval);
        if (lval == 0)
            break;

        struct lnode *lNewNode=malloc(sizeof(struct lnode));
        //prepare the new element
        lNewNode->value = lval;
        lNewNode->id = first->id-1;//<=>(*lhead).id+1
        lNewNode->next = first;
        //////////////////////////

        //chain the new element :
        first=lNewNode;
    }while(1);
 struct lnode *last=malloc(sizeof(struct lnode));
    last=lhead;

    do {
        printf("set the value of new node on your list at the end (0 to break):");
        scanf("%d",&lval);
        if (lval == 0)
            break;
        struct lnode *lNewNode=malloc(sizeof(struct lnode));

        //prepare the new element
        lNewNode->value = lval;
        lNewNode->id = last->id+1;//<=>(*lhead).id+1
        lNewNode->next =NULL;
         //////////////////////////
last->next=lNewNode;
last=lNewNode;
        //chain the new element :
     }while(1);

    int pos;

    //ajouter a une position donner

        printf("set the position of new node on your list  ");
        scanf("%d",&pos);
        printf("set the value of new node :");
        scanf("%d",&lval);
        //why lval is not an int

        struct lnode *lNewNodepos=malloc(sizeof(struct lnode));
        struct lnode *temp=malloc(sizeof(struct lnode));
        temp = first;
        int i=0;
        while(i<pos-1){
                temp = temp->next;
                i++;
        }
          //prepare the new element

        lNewNodepos->value = lval;
        lNewNodepos->id = temp->id+1;//<=>(*lhead).id+1

        lNewNodepos->next =temp->next;
        temp->next=lNewNodepos;
        //////////////////////////
 //boucle pour incrememter l'id

        struct lnode *garde=malloc(sizeof(struct lnode));
        garde=first;
        while(garde->next != NULL){
                garde->id=garde->id+1;
                garde=garde->next;
        }
        garde->id=garde->id+1;

    printf("display the list..\n");
    struct lnode *pWalker;
    pWalker =first;
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
    pWalker = first;

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
