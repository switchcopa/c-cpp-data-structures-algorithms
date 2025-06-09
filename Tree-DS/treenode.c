#include <stdio.h>
#include <stdlib.h>
#include "treenode.h"

TreeNode* createTreeNode(int data, TreeNode* left, TreeNode* right, TreeNode* parent) {
    TreeNode* node = malloc(sizeof(TreeNode));

    node->left = left;
    node->right = right;
    node->parent = parent;

    return node;
}