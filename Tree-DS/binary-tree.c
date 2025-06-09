#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary-tree.h"
#include "treestack.h"
#include "treequeue.h"

void recur_preOrderDFS(TreeNode* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    recur_preOrderDFS(root->left);
    recur_preOrderDFS(root->right);
}

void recur_inOrderDFS(TreeNode* root) {
    if (root == NULL) return;

    recur_inOrderDFS(root->left);
    printf("%d ", root->data);
    recur_inOrderDFS(root->right);
}

void recur_postOrderDFS(TreeNode* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    recur_postOrderDFS(root->left);
    recur_postOrderDFS(root->right);
}

void iter_preOrderDFS(TreeNode* root) {
    if (root == NULL) return;

    TreeStack* stack = createTreeStack(100);
    TS_pushNode(stack, root);

    while (!TS_isEmpty(stack)) {
        TreeNode* curr = TS_popNode(stack);
        printf("%d ", curr->data);

        if (curr->left != NULL) {
            TS_pushNode(stack, curr->left);
        }
        if (curr->right != NULL) {
            TS_pushNode(stack, curr->right);
        }
    }
}