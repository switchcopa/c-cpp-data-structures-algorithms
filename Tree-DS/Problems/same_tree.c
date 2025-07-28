#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 2000


// struct definition
struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
} TreeNode;


// create node function 
struct TreeNode* createNode(int val) {
	struct TreeNode* newnode = malloc(sizeof(struct TreeNode));

	if (newnode == NULL) {
		printf("Failed to allocate memory for node");
		exit(1);
	}

	newnode->left = NULL;
	newnode->right = NULL;
	newnode->val = val;

	return newnode;
}


// same tree function

bool isSameTree(struct TreeNode* root1, struct TreeNode* root2) {
	struct TreeNode** stack1 = malloc(sizeof(struct TreeNode *) * MAX_SIZE);
	struct TreeNode** stack2 = malloc(sizeof(struct TreeNode *) * MAX_SIZE);

	int top1 = -1, top2 = -1;
	stack1[++top1] = root1;
	stack2[++top2] = root2;

	while (top1 >= 0 && top2 >=0) {
		struct TreeNode* temp1 = stack1[top1--];
		struct TreeNode* temp2 = stack2[top2--];

		if (!temp1 && !temp2) continue;
		if (!temp1 || !temp2 || temp1->val != temp2->val) return false;

		stack1[++top1] = temp1->left;
		stack1[++top1] = temp1->right;

		stack2[++top2] = temp2->left;
		stack2[++top2] = temp2->right;

	}
	
	free(stack1);
	free(stack2);

	return top1 == top2;
}


int main() {
	struct TreeNode* root1 = createNode(1);
	
	root1->left = createNode(2);
	root1->right = createNode(3);
	root1->left->left = createNode(4);
	root1->left->right = createNode(5);

	struct TreeNode* root2 = createNode(1);
	root2->left = createNode(2);
	root2->left->left = createNode(4);
	root2->right = createNode(3);

	bool same = isSameTree(root1, root2);

	if (same) {
		printf("Both trees are identically the same.\n");
	} else {
		printf("Both trees are unidentical\n");
	}

	return 0;
}
