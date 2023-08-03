#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void deleteatend(struct Node **head, struct Node **tail) {
    struct Node *ptr;
    if (*head == NULL)
        return;
    ptr = *tail;
    if (*head == *tail) {
        *head = *tail = NULL;
    } else {
        (ptr->prev)->next = NULL;
        *tail = ptr->prev;
    }
    free(ptr);
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



    deleteatend(&node1, &node3);

    struct Node* current = node1;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");




    return 0;
}

