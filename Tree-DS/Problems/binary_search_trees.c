#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int data; } TreeNode;

struct Pair {
    struct TreeNode* first_node;
    struct TreeNode* second_node;
} Pair;

struct TreeNode* createNode(int data) {
	struct TreeNode* newnode = malloc(sizeof(struct TreeNode));

	if (!newnode) {
		printf("Failed to allocate memory for new node");
		exit(1);
	} 

	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = data;

	return newnode;
}

struct Pair* createPair(struct TreeNode* node1, struct TreeNode* node2) {
    struct Pair* pair = malloc(sizeof(struct Pair));

    if (!pair) {
        printf("Failed to allocate memory for pair\n");
        exit(1);
    }

    pair->first_node = node1;
    pair->second_node = node2;

    return pair;
}

void swapValues(struct TreeNode* node1, struct TreeNode* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
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
        } 
        if (curr->data > key) {
            curr = curr->left;
        } else curr = curr->right;

    } 

    return found_node;     
}

struct TreeNode* get_leftMostNode(struct TreeNode* node) {
    struct TreeNode* curr = node;

    while (curr->left) {
        curr = curr->left;
    } 

    return curr;
}

struct TreeNode* findSuccessor(struct TreeNode* root, struct TreeNode* node) {
    struct TreeNode* successor = NULL;
    
    if (root == NULL) return successor; 
    
    if (root->data == node->data && root->right) {
        return get_leftMostNode(root->right);
    }

    struct TreeNode* curr = root;

    while (curr) {
        if (node->data < curr->data) {
            successor = curr;
            curr = curr->left;
        }

        else if (node->data >= curr->data) {
            curr = curr->right;
        }

        else break;
    }

    return successor;
}

struct TreeNode* findPredecessor(struct TreeNode* root, struct TreeNode* node) {
    struct TreeNode* predecessor = NULL;
    struct TreeNode* curr = root;

    if (node->left) {
        node = node->left;

        while (node && node->right) {
            node = node->right;
        }
            
        predecessor = node;
    } else {
        while (curr) {
            if (curr->data < node->data) {
                  predecessor = curr;
                  curr = curr->right;
            } else {
                curr = curr->left; 
            }
        } 
    }
    
    return predecessor;
}

struct Pair* findNodeAndItsParent(struct TreeNode* root, int key) {
    struct TreeNode* curr = root;
    struct TreeNode* parent = NULL;

    while (curr) {
        if (curr->data == key) {
            break;
        }

        parent = curr;
        if (curr->data > key) {
            curr = curr->left;
        } else curr = curr->right;
    }

    struct Pair* pair = createPair(curr, parent);
    return pair;
}

void deleteNodeWithOneChild(struct TreeNode** root, struct TreeNode* node, struct TreeNode* parent) { 
    if (!node) return;

    struct TreeNode* child = node->left ? node->left : node->right;

    if (!parent) {
        *root = child;
    } else if (parent->left == node) { 
        parent->left = child;
    } else {
        parent->right = child;
    }

    free(node);
}

void deleteChildNode(struct TreeNode* parent);

void deleteNode(struct TreeNode** root, int key) {
    if (root == NULL) return;

    
    // find the node
    struct Pair* nodeAndItsParent = findNodeAndItsParent(*root, key);
    struct TreeNode* curr = nodeAndItsParent->first_node;
    struct TreeNode* last_parent = nodeAndItsParent->second_node;
    
    // case 1: the node is a leaf 
    if (!curr->left && !curr->right) {
        deleteChildNode(last_parent);
    }

    // case 2: the node has two child nodes
    if (curr->left && curr->right) {
        struct TreeNode* successor = findSuccessor(*root, curr);
            
        swapValues(curr, successor);
        deleteNode(&(curr->right), key);
    }   

    else {
        deleteNodeWithOneChild(root, curr, last_parent);
    }
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
    printf("Our Binary Search Tree: "); 
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
