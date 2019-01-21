#include <stdio.h>
#include <stdlib.h>

typedef struct t_node {
    int data;
    struct t_node* left;
    struct t_node* right;
} t_node;

void printInorder(t_node* head) {
    if (head == NULL) return;
    printInorder(head->left);
    printf("%d,", head->data);
    printInorder(head->right);
}

void printPreorder(t_node* head) {
    if (head == NULL) return;
    printf("%d,", head->data);
    printPreorder(head->left);
    printPreorder(head->right);
}

void printPostorder(t_node* head) {
    if (head == NULL) return;
    printPostorder(head->left);
    printPostorder(head->right);
    printf("%d,", head->data);
}

//  print Levelorder

typedef struct queue_node {
    t_node* to_print;
    struct queue_node* next;
} queue_node;

queue_node* newQueueNode(t_node* to_print) {
    queue_node* new_node = malloc(sizeof(queue_node));
    new_node->to_print = to_print;
    return new_node;
}

void push(queue_node** head, queue_node** last, t_node* node_to_print) {

    queue_node* new_node = newQueueNode(node_to_print);
    if (*head == NULL) {
        *head = new_node;
        *last = new_node;
    } else {
        (*last)->next = new_node;
        *last = new_node;
    }
}

t_node* pop(queue_node** head, queue_node** last) {
    if (head == NULL) return NULL;

    t_node* value = (*head)->to_print;

    if ((*head)->next == NULL) {
        *last = NULL;
    }

    queue_node* next = (*head)->next;
    free(*head);
    *head = next;

    return value;
}

void printLevelorder(t_node* head) {
    queue_node* queue_head = NULL;
    queue_node* queue_last = NULL;
    if (head == NULL) return;

    push(&queue_head, &queue_last, head);

    while(queue_head != NULL) {
        t_node* to_print = pop(&queue_head, &queue_last);
        printf("%d,", to_print->data);
        if (to_print->left != NULL) push(&queue_head, &queue_last, to_print->left);
        if (to_print->right != NULL) push(&queue_head, &queue_last, to_print->right);
    }
}

t_node* newNode (int value) {
    t_node* new_node = malloc(sizeof(t_node));
    new_node->data = value;

    return new_node;
}

int main() {
    // Baum aufbauen
    t_node* head = newNode(1);
    head->left = newNode(2);
    head->right = newNode(3);
    head->left->left = newNode(4);
    head->left->right = newNode(5);
    head->right->left = newNode(6);
    head->right->right = newNode(7);

    printf("Inorder\n");
    printInorder(head);
    printf("\n\nPreorder\n");
    printPreorder(head);
    printf("\n\nPostorder\n");
    printPostorder(head);
    printf("\n\nLevelorder\n");
    printLevelorder(head);
    printf("\n\n");


    return 0;
}