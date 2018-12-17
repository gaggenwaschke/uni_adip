#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct doubleNode {
    double data;
    struct doubleNode* next;
} doubleNode;

void insertFirst(doubleNode** head_ref, int new_data) {
    doubleNode* new_node = (doubleNode*) malloc(sizeof(struct doubleNode));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

doubleNode* insertLast(doubleNode** head_ref, int data) {
    doubleNode* new_node = malloc(sizeof(doubleNode));
    new_node->data = data;
    new_node->next = NULL;
    if ((*head_ref) == NULL) {
        *head_ref = new_node;
    } else {
        // scroll to last element
        doubleNode* ptr = *head_ref;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return new_node;
}

void printList(doubleNode* head) {
    doubleNode *temp = head;
	printf ("( ");

    while(temp != NULL)
    {
        printf("%lf  ", temp->data);    
        temp = temp->next;  
    }
	printf(")");

	printf("\n");
}    
 
doubleNode* reverseDoubleListCon(doubleNode* head) {
    doubleNode* before = NULL;
    doubleNode* act = head;
    doubleNode* new_node;
    while (act != NULL) {
        new_node = malloc(sizeof(doubleNode));
        new_node->data = act->data;
        new_node->next = before;
        before = new_node;
        act = act->next;
    }
    return new_node;
}

void reverseDoubleList(doubleNode** head_ref) {
    doubleNode* next;
    doubleNode* act = *head_ref;
    doubleNode* before = NULL;

    while(act != NULL) {
        next = act->next;
        act->next = before;
        before = act;
        act = next;
    }

    (*head_ref) = before;
}

double get(doubleNode* head, int index) {
    doubleNode* cursor = head;

    for (int i = 0; i < index && cursor != NULL; i++) {
        cursor = cursor->next;
    }

    if (cursor == NULL) {
        printf("Out of range on get(%d)\n", index);
        return 0.0;
    } else {
        return cursor->data;
    }
}

void delete(doubleNode** head_ref, int index) {
    doubleNode* before = NULL;
    doubleNode* cursor = (*head_ref);

    for (int i = 0; i < index && cursor != NULL; i++) {
        before = cursor;
        cursor = cursor->next;
    }

    if (cursor == NULL) {
        printf("Out of range on delete(%d)\n", index);
        return;
    } else {
        if (before == NULL) {
            (*head_ref) = cursor->next;
        } else {
            before->next = cursor->next;
        }
        free(cursor);
    }
}

doubleNode* insert(doubleNode** head_ref, int index, int data) {
    doubleNode* before = NULL;
    doubleNode* cursor = *head_ref;

    for (int i = 0; i < index && cursor != NULL; i++) {
        before = cursor;
        cursor = cursor->next;
    }

    if (before == NULL && cursor != *head_ref) {
        printf("Out of range on insert %d @ %d\n", data, index);
        return NULL;
    } else {
        doubleNode* new_node = malloc(sizeof(doubleNode));
        new_node->data = data;
        new_node->next = cursor;
        if (before == NULL) {
            (*head_ref) = new_node;
        } else {
            before->next = new_node;
        }
        return new_node;
    }
}

int main() {
	doubleNode* head = NULL;
    doubleNode* secondHead = NULL;
    insertFirst(&head, 15);
    insertFirst(&head, 3);
    insertFirst(&head, 1);
	printList(head);  
    reverseDoubleList(&head);	
	printf("reverse list \n");
    printList(head); 
	printf ("insert first 14, 18 \n");
    insertFirst(&head, 14); 
    insertFirst(&head, 18); 
    printList(head);
	printf("reverse list \n");
    reverseDoubleList(&head); 
	printList(head);   
    printf("insert last 15,19 \n");
    insertLast(&head, 15);
    insertLast(&head, 19);
    printList(head);
    printf("reverse List Con \n");
    secondHead = reverseDoubleListCon(head);
    printList(secondHead);
    printf("insert 5 @ 0 \n");
    insert(&head, 0, 5);
    printList(head);
    printf("insert 91 @ 8 \n");
    insert(&head, 8, 91);
    printList(head);
    printf("insert 11 @ 3 \n");
    insert(&head, 3, 11);
    printList(head);
    printf("delete @9, @0, @5\n");
    delete(&head, 9);
    delete(&head, 0);
    delete(&head, 5);
    printList(head);

    return 0;
}

/*
    a)
    L2 -> 14 -> 5 -> (*L1)11 -> 7 -> 3
    */