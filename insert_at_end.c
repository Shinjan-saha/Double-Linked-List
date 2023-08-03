#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertatend(struct Node **head, struct Node **tail, int item) {
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = item;
    ptr->next = NULL;
    ptr->prev = *tail;

    if (*head == NULL) {
        *head = *tail = ptr;
    } else {
        (*tail)->next = ptr;
        *tail = ptr;
    }
}

int main() {
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));


    node1->data = 11;
    node2->data = 22;
    node3->data = 33;
    node4->data = 44;


    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;

    insertatend(&node1, &node4, 55);

    struct Node* current = node1;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");




    return 0;
}
