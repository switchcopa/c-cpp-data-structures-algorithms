#define MAX_SIZE 1000

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
} TreeNode;


struct TreeNode* createNode(int val) {
	struct TreeNode* newnode = malloc(sizeof(struct TreeNode));

	if (newnode == NULL) {
		printf("Failed to allocate memory for node");
		exit(1);
	}

	newnode->val = val;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}


int* inOrderTraversal(struct TreeNode* root, int* returnSize) {
	int* result = malloc(sizeof(int) * MAX_SIZE);

	struct TreeNode* stack[MAX_SIZE];
	int top = -1, count = 0;

	struct TreeNode* curr = root;
	while (top >= 0 || curr) {

		while (curr) {
			stack[++top] = curr;
			
			curr = curr->left;
		}

		
		curr = stack[top--];
		result[count++] = curr->val;
		curr = curr->right;
	}

	*returnSize = count;

	return result;
}


int main() {
	struct TreeNode* root = createNode(5);
	struct TreeNode* node2 = createNode(3);
	struct TreeNode* node3 = createNode(4);
	struct TreeNode* node4 = createNode(1);

	root->left = node2;
	root->left->left = node3;
	root->right = node4;

	int returnSize = 0;

	int* res = inOrderTraversal(root, &returnSize);

	for (int i = 0; i < returnSize; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}
