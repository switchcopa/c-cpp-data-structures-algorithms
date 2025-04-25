#include <stdio.h>
#include <stdlib.h> // import the preprocessor directive for output, and the standard library

struct Node
{
     int data;
     struct Node *next;
};

struct Node *createNode(int value)
{
     struct Node *node = (struct Node *)malloc(sizeof(struct Node));
     node->next = NULL;
     node->data = value;
     return node;
}

void insertAtBeginning(int value, struct Node **head)
{
     struct Node *node = createNode(value);
     node->next = *head;
     node->data = value;
     *head = node;
}

void insertAtEnd(int value, struct Node **head)
{
     struct Node *node = createNode(value);

     if (*head == NULL)
     {
          *head = node;
          return;
     }

     struct Node *current = *head;
     while (current->next != NULL)
     {
          current = current->next;
     }

     current->next = node;
}

void output(struct Node **head)
{
     if (*head == NULL)
     {
          printf("NULL");
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

int getLength(struct Node **head)
{
     if (*head == NULL)
          return 0;

     int count = 0;
     struct Node *curr = *head;
     while (curr != NULL)
     {
          curr = curr->next;
          count++;
     }
     return count;
}

void deleteNodeAt(int index, struct Node **head)
{
     // Error cases
     if (index < 0 || *head == NULL || getLength(head) <= index)
          return;

     // Special cases
     if (index == 0)
     {
          struct Node *temp = *head;
          *head = (*head)->next;
          free(temp);
          return;
     }

     // Traversal
     int count = 0;
     struct Node *curr = *head;
     while (curr != NULL && count < index - 1)
     {
          curr = curr->next;
          count++;
     }

     // Invalid Index
     if (curr == NULL || curr->next == NULL)
          return;

     // Node to delete (use temporary pointer)
     struct Node *temp = curr->next;
     curr->next = curr->next->next;
     free(temp);
}

void freeList(struct Node **head)
{
     if (*head == NULL)
          return;

     struct Node *curr = *head;
     while (curr != NULL)
     {
          struct Node *temp = curr->next;
          free(curr);
          curr = temp;
     }
     *head = NULL; // Mark the list as empty
}

void reverseList(struct Node **head)
{
     if (*head == NULL)
          return;

     struct Node *prev = NULL;
     struct Node *curr = *head;
     while (curr != NULL)
     {
          struct Node *temp = curr->next;
          curr->next = prev;
          prev = curr;
          curr = temp;
     }

     *head = prev;
}

int main()
{
     struct Node *head = NULL;
     insertAtBeginning(10, &head);
     insertAtBeginning(20, &head);
     insertAtBeginning(30, &head);
     printf("After inserting at beginning:\n");
     output(&head);

     // Insert at the end
     insertAtEnd(40, &head);
     insertAtEnd(50, &head);
     printf("After inserting at end:\n");
     output(&head);

     // Delete a node at index 2
     deleteNodeAt(2, &head);
     printf("After deleting node at index 2:\n");
     output(&head);

     // Reverse the list
     reverseList(&head);
     printf("After reversing the list:\n");
     output(&head);

     // Free the list
     freeList(&head);
     printf("After freeing the list:\n");
     output(&head);

     return 0;
}