#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("failed bro\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int val, int position) {
    struct Node* newNode = createNode(val);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int val, position;

    while (1) {
        printf("Enter val for the new node or 0 to exit: ");
        scanf("%d", &val);

        if (val == 0) {
            break;
        }

        printf("Enter position for the new node: ");
        scanf("%d", &position);

        if (position < 1) {
            printf("Invalid position. Position should be greater than or equal to 1.\n");
            continue;
        }

        insertNode(&head, val, position);
        printf("Updated Linked List: ");
        printList(head);
    }
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
