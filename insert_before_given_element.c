#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertBeforeElement(struct Node** head, struct Node** tail, int item, int before) {
    struct Node* loc = search(*head, before);
    if (loc == NULL)
        return;

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = item;

    if (loc->prev == NULL) {
        ptr->prev = NULL;
        loc->prev = ptr;
        ptr->next = loc;
        *head = ptr;
    } else {
        ptr->prev = loc->prev;
        ptr->next = loc;
        (loc->prev)->next = ptr;
        loc->prev = ptr;
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

    insertBeforeElement(&node1, &node4, 55, 22);

    struct Node* current = node1;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");



    return 0;
}

