#include <stdio.h>
#include <stdbool.h>
#include "treequeue.h"

void initTQueue(TreeQueue* queue) {
    queue->front = -1;
    queue->rear = 0;
};

bool isEmptyTQueue(TreeQueue* queue) {
    return queue->front == queue->rear - 1;
};

bool isFullTQueue(TreeQueue* queue) {
    return queue->rear == MAX_SIZE;
};

void treeEnqueue(TreeQueue* queue, TreeNode* treenode) {
    if (isFullTQueue(queue)) {
        printf("Tree Queue overflow warning!\n");
        return;
    }

    queue->data[queue->rear++] = treenode;
};

TreeNode* treeDequeue(TreeQueue* queue) {
    if (isEmptyTQueue(queue)) {
        printf("Tree Queue underflow warning!\n");
        return NULL;
    }

    TreeNode* node = queue->data[queue->front++];
    
    return node;
};