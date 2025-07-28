#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int data;
} TreeNode;

struct TreeNode* createNode(int data) {
	struct TreeNode* newnode = malloc(sizeof(struct TreeNode));

	if (!newnode) {
		printf("Failed to allocate memory for new node");
		exit(1);
	} 

	newnode->left = NULL;
	newnode->right =  NULL;
	newnode->data = data;

	return newnode;
}

bool isValidBST(struct TreeNode* root) {
	int result[MAX_SIZE];

	struct TreeNode* stack[MAX_SIZE];
	int top = -1, count = 0;
	struct TreeNode* curr = root;

	while (curr != NULL || top >= 0) {
		while (curr != NULL) {
			stack[++top] = curr;
			curr = curr->left;
		}

		curr = stack[top--];
		result[count++] = curr->data;
		curr = curr->right;
	}

	for (int i = 0; i < count; i++) {
		if (result[i] > result[i+1]) {
			return false;
		}
	}

	return true;
}

void insertNode(struct TreeNode** root, struct TreeNode* node_to_insert) {
	if (*root == NULL) {
		*root = node_to_insert;
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*root)->data = node_to_insert->data;

		return; 
	}

	
}

int main() {
	struct TreeNode* root = createNode(3);
	root->left = createNode(2);
	root->left->left = createNode(1);
	root->right = createNode(4);
	root->right->right = createNode(6);

	bool isBST = isValidBST(root);
	
	if (isBST) {
		printf("The tree is a valid binary search tree\n");
	} else {
		printf("The tree is NOT a valid binary search tree\n");
	}
	return 0;

}
