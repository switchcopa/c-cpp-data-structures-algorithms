#ifndef TREENODE_H
#define TREENODE_H

typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
    int data;
} TreeNode;

TreeNode* createTreeNode(int data, TreeNode* left, TreeNode* right, TreeNode* parent);

#endif 