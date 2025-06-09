#ifndef NODE_H
#define NODE_H

typedef struct Node {
    struct Node* next;
    int data;
} Node;

Node* createNode(int data);

#endif