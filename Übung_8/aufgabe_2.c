#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void push(node** head, int value) {
    node* new_node = malloc(sizeof(node));
    new_node->data = value;
    new_node->next = *head;

    *head = new_node;
}

int pop(node** head) {
    if (*head == NULL) {
        printf("stack is empty\n");
        return 0;
    }

    int value = (*head)->data;
    node* next = (*head)->next;

    free(*head);
    *head = next;

    return value;
}

int peek(node* head) {
    if (head == NULL) {
        printf("stack is empty\n");
        return 0;
    }

    return head->data;
}

bool isEmpty(node* head) {
    if (head == NULL) return true;
    return false;
} 

void print(node* head) {
    // hier kann head als runtime variable benutzt werden,
    // da es bei value übergeben wurde.
    printf("[");
    while(head != NULL) {
        printf("%d,", head->data);
        head = head->next;
    }
    printf("]\n");
}

int main() {
    node* head = NULL;
    push(&head, 4);
    push(&head, 2);
    push(&head ,1);
    printf("Ergebnis von peek: %d\n", peek(head));
    print(head);
    printf("Ergebnis von pop: %d\n", pop(&head));
    print(head);
    printf("IsEmpty: %s\n", isEmpty(head) ? "true" : "false");
    pop(&head);
    pop(&head);
    printf("IsEmpty: %s\n", isEmpty(head) ? "true" : "false");


    return 0;
}

/*
Änderungen um dies zur Queue zu machen:
-   Queue ist FIFO, also muss bei pop das letzte Element ausgegeben werden
-   dazu ist die Verwendung eines last pointers sinnvoll
*/