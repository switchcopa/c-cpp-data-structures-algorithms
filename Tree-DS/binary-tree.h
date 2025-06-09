#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "treenode.h"

void recur_preOrderDFS(TreeNode* root);
void recur_inOrderDFS(TreeNode* root);
void recur_postOrderDFS(TreeNode* root);
void iter_preOrderDFS(TreeNode* root);
void iter_preOrderDFS(TreeNode* root);
void iter_postOrderDFS(TreeNode* root);
void BFS(TreeNode* root);
void insertNode(TreeNode* root, TreeNode* treenode);
void deleteNode(TreeNode* root, int data);
int searchBFS(TreeNode* root, int data);
int searchDFS(TreeNode* root, int data);
int getTreeHeight(TreeNode* root);
int getNodelvl(TreeNode* root, int data);
int getTreeSize(TreeNode* root);
int getNodeDepth(TreeNode* root, int data);

#endif 