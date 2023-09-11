#include <stdio.h>
#include <stdlib.h>

typedef unsigned int UINT;

// Structure pour un nÅ“ud de la liste chaÃ®nÃ©e
struct lnode {
    char id;
    int value;
    struct lnode* next;
};

void  display(const struct lNode *pHead){
   printf("1. Affichage de la liste :\n");
    struct lnode* pWalker = pHead;

    while (pWalker != NULL) {
        printf("[%d,%d] ", pWalker->id, pWalker->value);
        pWalker = pWalker->next;
    }
    printf("\n");
}

void insertAtTheEnd(struct lnode **pLast,const int lval){
    struct lnode* lNewNode = malloc(sizeof(struct lnode));
    lNewNode->value = lval;
    lNewNode->id = (*pLast)->id + 1;
    lNewNode->next = NULL;
    (*pLast)->next = lNewNode;
    *pLast = lNewNode;
}
void insertAtTheHead(struct lnode **pHead,const int lval){
    struct lnode* lNewNode = malloc(sizeof(struct lnode));
    lNewNode->value = lval;
    lNewNode->id = (*pHead)->id - 1;
    lNewNode->next = *pHead;
    *pHead = lNewNode;
}

int main() {
    printf("Hello world!\n");

    // Initialisation de la tÃªte de la liste
    struct lnode* lhead = malloc(sizeof(struct lnode));
    lhead->id = 100;
    lhead->value = 1234;
    lhead->next = NULL;

    int lval;
    struct lnode* pLast = lhead;
    struct lnode* HEAD = lhead;

    // Ajout de nÅ“uds Ã  la fin de la liste
    do {
        printf("Entrez la valeur du nouveau nÅ“ud Ã  la FIN de la liste (0 pour terminer) : ");
        scanf("%d", &lval);
        if (lval == 0)
            break;
        insertAtTheEnd(&pLast,lval);
    } while (1);

    // Retour Ã  la tÃªte de la liste
    struct lnode*pHead = lhead;

    // Ajout de nÅ“uds au dÃ©but de la liste
    do {
        printf("Entrez la valeur du nouveau nÅ“ud au DÃ‰BUT de la liste (0 pour terminer) : ");
        scanf("%d", &lval);
        if (lval == 0)
            break;
        insertAtTheHead(&pHead,lval);
          // Mettre Ã  jour la tÃªte de la liste
    } while (1);
    lhead = pHead;
    char rep;
    int pos;

    printf("Voulez-vous ajouter un nÅ“ud ? (y/n) : ");
    scanf(" %c", &rep); // Ajoutez un espace avant %c pour Ã©viter les problÃ¨mes avec le caractÃ¨re prÃ©cÃ©dent

    display(lhead);
    return 0;

    if (rep == 'y') {
        printf("Ã€ quelle position voulez-vous ajouter un nÅ“ud : ");
        scanf("%d", &pos);

        if (pos < 1) {
            printf("La position doit Ãªtre un nombre positif.\n");
        } else {
            struct lnode* lNewNode = malloc(sizeof(struct lnode));
            printf("Entrez la valeur du nouveau nÅ“ud : ");
            scanf("%d", &lval);

            lNewNode->value = lval;

            if (pos == 1) {
                // InsÃ©rer le nouveau nÅ“ud en tÃªte de la liste
                lNewNode->id = lhead->id - 1;
                lNewNode->next = lhead;
                lhead = lNewNode;
            } else {
                struct lnode* pPrev = lhead;
                struct lnode* pCurrent = lhead;
                int currentPos = 1;

                // Parcourez la liste jusqu'Ã  atteindre la position souhaitÃ©e
                while (pCurrent != NULL && currentPos < pos) {
                    pPrev = pCurrent;
                    pCurrent = pCurrent->next;
                    currentPos++;
                }

                if (currentPos == pos) {
                    // InsÃ©rer le nouveau nÅ“ud Ã  la position donnÃ©e
                    lNewNode->id = pPrev->id + 1;
                    pPrev->next = lNewNode;
                    lNewNode->next = pCurrent;
                } else {
                    printf("La position spÃ©cifiÃ©e est hors de portÃ©e.\n");
                    free(lNewNode);
                }
            }
        }
    }

    // mettre tous les noeuds a null sauf le head

    if (lhead == NULL) {
        return; // La liste est vide, rien Ã  faire
    }

    struct lnode *pCurrent = lhead->next; // Commencez Ã  partir du deuxiÃ¨me nÅ“ud

    while (pCurrent != NULL) {
        struct lnode* temp = pCurrent; // Sauvegardez le nÅ“ud actuel
        pCurrent = pCurrent->next; // Passez au nÅ“ud suivant
        free(temp); // LibÃ©rez le nÅ“ud actuel
    }

    display(lhead);


    printf("3. Affichage de la liste apres liberation de tous les neouds sauf head :\n");


    printf("LibÃ©ration de la mÃ©moire :\n");
    struct lnode* pSave;
    struct lnode*pWalker = lhead;
    int nb = 0;
    while (pWalker != NULL) {
        pSave = pWalker->next;
        free(pWalker);
        nb++;
        pWalker = pSave;
    }
    printf("on a liberer %d noeud  ",nb);
    display(lhead);

    return 0;
}
