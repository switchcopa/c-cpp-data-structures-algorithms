#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <stdbool.h>

typedef struct {
    Node** data;
    int top;
    int capacity;
} NodeStack;

NodeStack* createStack(int capacity);
void pushNode(NodeStack* stack, Node* node);
Node* pop(NodeStack* stack);
bool isEmpty(NodeStack* stack);
bool isFull(NodeStack* stack);
void freeStack(NodeStack* stack);

#endif 