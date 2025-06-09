#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stacknode.h"

NodeStack* createStack(int capacity) {
    NodeStack* stack = malloc(sizeof(NodeStack));
    stack->data = malloc(sizeof(Node*) * capacity);
    stack->capacity = capacity;
    stack->top = -1;
    
    return stack;
}

bool isFullStack(NodeStack* stack) {
    return stack->capacity == stack->top - 1;
}

bool isEmptyStack(NodeStack* stack) {
    return stack->top == -1;
}

void pushNode(NodeStack* stack, Node* node) {
    if (isFull(stack)) {
        printf("Stack overflow warning!\n");
        return;
    }

    stack->data[++stack->top] = node;
}

Node* pop(NodeStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow warning!\n");
        return NULL;
    }
    Node* node = stack->data[stack->top--];

    return node;
}

void freeStack(NodeStack* stack) {
    free(stack->data);
    free(stack);
}