#ifndef TREEQUEUE_H
#define TREEQUEUE_H
#define MAX_SIZE 10000

#include "treenode.h"


typedef struct {
    TreeNode** data;
    int front;
    int rear;
} TreeQueue;

void initTQueue(TreeQueue* queue);
void treeEnqueue(TreeQueue* queue, TreeNode* treenode);
TreeNode* treeDequeue(TreeQueue* queue, TreeNode* treenode);
bool isEmptyTQueue(TreeQueue* queue);
bool isFullTQueue(TreeQueue* queue);

#endif 
