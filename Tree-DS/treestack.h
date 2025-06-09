#ifndef TREESTACK_H
#define TREESTACK_H

#include "treenode.h"

typedef struct {
    TreeNode** data;
    int top;
    int capacity;
} TreeStack;

TreeStack* createTreeStack(int capacity);
bool TS_isEmpty(TreeStack* stack);
bool TS_isFull(TreeStack* stack);
void TS_pushNode(TreeStack* stack, TreeNode* treenode);
TreeNode* TS_popNode(TreeStack* stack);
void TS_freeStack(TreeStack* stack);

#endif 
