#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 2000

struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
} TreeNode;


struct TreeNode* createNode(int val) {
	struct TreeNode* newnode = malloc(sizeof(struct TreeNode));

	if (!newnode) {
		printf("Failed to allocate memory for node");
		exit(0);
	} 

	newnode->val = val;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}


bool isSymmetricTree(struct TreeNode* root) {
	struct TreeNode** queue1 = malloc(sizeof(struct TreeNode*) * MAX_SIZE);
	struct TreeNode** queue2 = malloc(sizeof(struct TreeNode*) * MAX_SIZE);

	int rear1 = 0, rear2 = 0, front1 = 0, front2 = 0;
	queue1[rear1++] = root->left;
	queue2[rear2++] = root->right;

	while (rear1 > front1 && rear2 > front2) {
		struct TreeNode* temp1 = queue1[front1++];
		struct TreeNode* temp2 = queue2[front2++];
	
		if (!temp1 && !temp2) continue;
		if (!temp1 || !temp2 || temp1->val != temp2->val) return false;

		queue1[rear1++] = temp1->left;
		queue1[rear1++] = temp1->right;

		queue2[rear2++] = temp2->right;
		queue2[rear2++] = temp2->left;

	}

	return rear1 == rear2;
}


int main() {
	struct TreeNode* root1 = createNode(5);
	root1->left = createNode(4);
	root1->right = createNode(4);
	root1->left->left = createNode(3);
	root1->right->right = createNode(2);

	bool is_symmetric = isSymmetricTree(root1);

	if (is_symmetric) {
		printf("Both right and left sub-trees are symmetric");
	} else {
		printf("Both right and left sub-trees are not symmetric");
	}

	return 0;
}
