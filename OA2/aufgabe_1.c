#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    int value;
} node;

//  (b)
void printList(node* head) {
    printf("(");
    while(head != NULL) {
        printf("%d", head->value);
        head = head->next;
    }
    printf(")\n");
}

//  (c)
node* insertLast(node** head, node** last, int c) {
    node* new_node = malloc(sizeof(node));
    new_node->next = NULL;
    new_node->value = c;

    if (*head == NULL) {
        *head = new_node;
        *last = new_node;
    } else {
        (*last)->next = new_node;
        *last = new_node;
    }

    return new_node;
}

//  (d)
int getFirst(node** head, node** last) {
    int value = (*head)->value;
    node* next = (*head)->next;

    if (*head == *last) *last = NULL;

    free(*head);
    *head = next;

    return value;
}

int main() {
    //  (a)
    node* head = NULL;
    node* last = NULL;

    //  (c)
    insertLast(&head, &last, 1);
    insertLast(&head, &last, 2);
    insertLast(&head, &last, 3);
    insertLast(&head, &last, 4);

    //  (b)
    printList(head);

    //  (c)
    printf("%d\n",getFirst(&head, &last));
    printf("%d\n",getFirst(&head, &last));
    printf("%d\n",getFirst(&head, &last));
    printf("%d\n",getFirst(&head, &last));
    printList(head);

    insertLast(&head, &last, 1);
    insertLast(&head, &last, 2);
    insertLast(&head, &last, 3);
    insertLast(&head, &last, 4);

    printList(head);
    return 0;
}