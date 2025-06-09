#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "treestack.h"

TreeStack* createTreeStack(int capacity) {
    TreeStack* stack = malloc(sizeof(TreeStack));
    stack->data = malloc(sizeof(TreeNode*) * capacity);
    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

bool TS_isEmpty(TreeStack* stack) {
    return stack->top == -1;
}

bool TS_isFull(TreeStack* stack) {
    return stack->top - 1 == stack->capacity;
}

void TS_pushNode(TreeStack* stack, TreeNode* treenode) {
    if (TS_isFull(stack)) {
        printf("Stack overflow warning!\n");
        return;
    }

    stack->data[++stack->top] = treenode;
}

TreeNode* TS_popNode(TreeStack* stack) {
    if (TS_isEmpty(stack)) {
        printf("Stack underflow warning!\n");
        return NULL;
    }

    TreeNode* treenode = stack->data[stack->top--];

    return treenode;
}

void TS_freeStack(TreeStack* stack) {
    free(stack->data);
    free(stack);
}