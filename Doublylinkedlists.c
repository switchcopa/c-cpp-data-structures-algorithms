
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int value)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insertAtBeginning(int value, struct Node **head)
{
    struct Node *node = createNode(value);
    node->next = *head;
    
    if (*head != NULL) {
        (*head)->prev = node;
    }

    *head = node;
}

void insertAtEnd(int value, struct Node** head)
{
    struct Node* node = createNode(value);
    if (*head == NULL) {
        *head = node;
        return;
    }

    struct Node* curr = *head;
    while (curr->next != NULL) 
    {   
        curr = curr->next;
    }

    curr->next = node;
    node->prev = curr;
}

int getLength(struct Node** head) 
{   
    int count = 0;
    struct Node* curr = *head;

    while (curr != NULL) 
    {
        curr = curr->next;
        count++;
    }
    return count;
}

void delNodeAt(int index, struct Node** head)
{
    if (index < 0 || getLength(head) <= index || *head == NULL) return;

    if (index == 0) 
    {
        struct Node* temp = *head;
        (*head) = (*head)->next;
        if (*head != NULL) 
        {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    struct Node* curr = *head;
    int count = 0;
    while (count < index - 1 && curr != NULL) 
    {
        count++;
        curr = curr->next;
    }
    if (curr == NULL || curr->next == NULL) return;

    struct Node* temp = curr->next;
    struct Node* p = temp->next;
    curr->next = p;
    if (p != NULL) {
        p->prev = curr;
    }
    free(temp);
}

void outputFront(struct Node **head)
{
    if (*head == NULL)
    {
        printf("NULL\n");
        return;
    }

    struct Node *curr = *head;
    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void outputBack(struct Node **head) 
{
    if (*head == NULL)
    {
        printf("NULL\n");
        return;
    }

    struct Node* curr = *head;
    while (curr->next != NULL) 
    {
        curr = curr->next;
    }

    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->prev;
    }
    printf("NULL\n");
}

void freeList(struct Node** head) 
{
    if (*head == NULL) return;

    struct Node* curr = *head;
    while (curr != NULL) 
    {
        struct Node* temp = curr->next;
        free(curr);
        curr = temp;
    }
    *head = NULL;
}


int main() {   
    struct Node* head = NULL;

    insertAtBeginning(5, &head);
    insertAtBeginning(10, &head);
    insertAtBeginning(15, &head);
    insertAtEnd(2, &head);
    insertAtEnd(3, &head);
    delNodeAt(2, &head);

    outputFront(&head);
    outputBack(&head);

    printf("After free list:\n");
    freeList(&head);
    outputFront(&head);

    return 0;
}