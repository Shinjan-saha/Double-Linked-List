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

void insertAfterElement(struct Node** head, struct Node** tail, int item, int after) {
    struct Node* loc = search(*head, after);
    if (loc == NULL)
        return;

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = item;

    if (loc->next == NULL) {
        ptr->next = NULL;
        loc->next = ptr;
        ptr->prev = loc;
        *tail = ptr;
    } else {
        ptr->next = loc->next;
        ptr->prev = loc;
        (loc->next)->prev = ptr;
        loc->next = ptr;
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

    insertAfterElement(&node1, &node4, 55, 22);

    struct Node* current = node1;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");



    return 0;
}
