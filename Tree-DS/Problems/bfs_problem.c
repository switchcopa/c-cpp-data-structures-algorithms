/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 2000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode** queue = malloc(sizeof(struct TreeNode *) * MAX_SIZE); 

    int** result = malloc(sizeof(int *) * MAX_SIZE);
    *returnColumnSizes = malloc(sizeof(int) * MAX_SIZE);
    *returnSize = 0;

    int rear = 0, front = 0, numOfNodes = 0;
    queue[rear++] = root;

    while (rear > front) {
        int levelSize = rear - front;
        
        result[*returnSize] = malloc(sizeof(int) * levelSize);
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[front++];

            result[*returnSize][i] = curr->val;

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        (*returnSize)++;
    }

    free(queue);

    return result;
}   
