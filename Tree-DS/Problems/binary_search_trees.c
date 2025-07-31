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
		return; 
	}
    
    struct TreeNode* curr = *root; // ???      
    struct TreeNode* parent = NULL;

    while (curr) {
        parent = curr; 

        if (curr->data > node_to_insert->data) {
            curr = curr->left;

        } else {
            curr = curr->right;
        }
    }

   if (parent->data > node_to_insert->data) {
        parent->left = node_to_insert;
    } else {
        parent->right = node_to_insert;
    }
}

void insertNode_recursive(struct TreeNode** root, struct TreeNode* node_to_insert) {
    if (*root == NULL) {
        *root = node_to_insert;
        return; 
    } 

    if ((*root)->data == node_to_insert->data) return;

    if ((*root)->data < node_to_insert->data) {
        insertNode_recursive(&(*root)->right, node_to_insert); 
    } else {
        insertNode_recursive(&(*root)->left, node_to_insert);
    }
}

struct TreeNode* searchNode(struct TreeNode* root, int key) {
    struct TreeNode* found_node = NULL;
    struct TreeNode* curr = root;

    while (curr) {
        if (curr->data == key) {
            found_node = curr; 
            break;
    
        if (curr->data > key) {
            curr = curr->left;
        } else curr = curr->right;

    } 

    return found_node;     
}

void deleteNode(struct TreeNode** root, int key) {
    if (root == NULL) return;

    struct TreeNode* curr = *root;
    struct TreeNode* last_parent = curr;
    struct TreeNode* successor = NULL;
    
     
}

int* returnTree(struct TreeNode* root, int* returnSize) {
    int* result = malloc(sizeof(int) * MAX_SIZE);  
    
    if (root == NULL) {
        *returnSize = 0;
        return result;
    }

    struct TreeNode* stack[MAX_SIZE];
    int top = -1, count = 0;
    struct TreeNode* curr = root;

    while (curr || top >= 0) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        result[count++] = curr->data;
        curr = curr->right;

    }

    *returnSize = count;
    return result;
}

void printTree(struct TreeNode* root) {
    printf("Our Binary Search Tree:\n"); 
    int returnSize = 0;
    int* tree_result = returnTree(root, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", tree_result[i]);
    }

    printf("\n");
}

int main() {
	struct TreeNode* root = createNode(3);
	root->left = createNode(2);
	root->left->left = createNode(1);
	root->right = createNode(4);
	root->right->right = createNode(6);
    
    printTree(root);

	bool isBST = isValidBST(root);
	
	if (isBST) {
		printf("The tree is a valid binary search tree\n");
	} else {
		printf("The tree is NOT a valid binary search tree\n");
	}
    
    struct TreeNode* newnode = createNode(5);
    printf("Inserting node iteratively with data: %d\n", newnode->data);
    
    insertNode_recursive(&root, newnode);
    printTree(root); 
     
	return 0;

}
