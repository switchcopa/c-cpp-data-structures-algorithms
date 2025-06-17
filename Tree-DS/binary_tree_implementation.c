#include <stdio.h>
#include <stdlib.h>

// node struct for the binary tree 
struct Node {
    // left and right pointers
    struct Node* left;
    struct Node* right;
    int data; // data container
    // or more fields here 
} Node;

// create function to return a pointer to a node 
struct Node* createNode(int data) {
    // allocate memory for the node
    struct Node* node = malloc(sizeof(struct Node));

    // fill in its fields
    node->left = NULL;
    node->right = NULL;
    node->data = data;

    return node;
}


// recursive Depth First Search algorithms for binary trees

void preOrder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root) {
    if (root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}


// iterative DFS 

void iterative_preOrder(struct Node* root) {
    // base-case, the tree is empty
    if (root == NULL) return;

    // initialize an auxiliary queue 
    struct Node* queue[100];
    // rear and front pointers
    int front = 0, rear = 0;
    // enqueue the root node
    queue[rear++] = root;

    // main loop
    while (front < rear) {
        // dequeue node from the left of the queue
        struct Node* temp = queue[front++];
        // print the current node
        printf("%d ", temp->data);

        // enqueue left and right child nodes
        if (temp->left) {
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }
}

void iterative_preOrder(struct Node* root) {
    // base case, the tree is empty 
    if (root == NULL) return;

    // initialize an empty stack 
    struct Node* stack[100];
    // pointer to the top of the stack
    int top = -1;
    // current node to backtrack to once you hit the bottom node in a branch
    struct Node* curr = root;

    while (curr != NULL || top != -1) {
        // explore down the left branch
        while (curr != NULL) {
            // push node to the stack
            stack[++top] = curr;
            curr = curr->left;
        }

        // pop node and print it
        curr = stack[top--];
        printf("%d ", curr->data);

        // go to the right node
        curr = curr->right;     
    }
}


void iterative_postOrder(struct Node* root) {
    // base case
    if (root == NULL) return;

    // initialize two stacks, one for printing and one for exploring
    struct Node* stack1[100];
    struct Node* stack2[100];
    // pointers for the top nodes in the stacks
    int top1 = -1, top2 = -1;

    // push root node to the first stack
    stack1[++top1] = root;

    while (top1 != -1) {
        // pop node from first stack and push it to the second stack
        struct Node* curr = stack1[top1--];
        stack2[++top2] = curr;

        // push the right and left nodes of the current node
        if (curr->left) {
            stack1[++top1] = curr->left; 
        }

        if (curr->right) {
            stack1[++top1] = curr->right;
        }
    }

    // by the end, we will have every node to print in our second stack, so we just pop 
    // every node from the stack, and print it

    while (top2 != -1) {
        struct Node* curr = stack2[top2--];
        printf("%d ", curr->data);
    }
}

// implement BFS algorithm 
// to get a level order traversal, we're going to use a queue for this case
struct Node** BFS(struct Node* root) {    
    // result array 
    struct Node* result[100];
    int n = 0;

    // base case 
    if (root == NULL) return result;

    // initialize empty queue 
    struct Node* queue[100];
    int front = 0, rear = 0;
    // enqueue root node 
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        result[n++] = temp;

        if (temp->left) {
            result[n++] = temp;
        }
        if (temp->right) {
            result[n++] = temp;
        }
    }

    return result;
}


int insertNode(struct Node* node, struct Node* root) {
    // the idea over here is to find the first empty spot in the 
    // tree and insert the node there 

    if (root == NULL) {
        root = node;
        return 1;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (!temp->left) {
            temp->left = node;
            return 1;
        } else {
            queue[front++] = temp->left;
        }

        if (!temp->right) {
            temp->right = node;
            return 1;
        } else {
            queue[front++] = temp->right;
        }
    }

    return 0;
}


int searchNode(int target, struct Node* root) {
    if (root == NULL) return 0; // base case 

    // use level order, or BFS for this operation 
    struct Node* queue[100];    
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->data == target) {
            return 1; // the node with the target value was found 
        }

        if (temp->left) {
            queue[rear++] = temp->left;
        }

        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }

    return 0; // no node was found 

}

int deleteNode(int val, struct Node* root) {
    if (root == NULL) return;

    // use BFS for this operation
    struct Node* queue[100];
    int rear = 0, front = 0;
    queue[rear++] = root; // always, this enqueues the root node

    // this target node is going to be the node we want to remove
    struct Node* target = NULL;

    // loop until we found the node with the target value "val"
    while (rear > front) {
        struct Node* curr = queue[front++];

        if (curr->data == val) {
            target = curr;
            break;
        }

        if (curr->left) {
            queue[front++] = curr->left;
        } else if (curr->right) {
            queue[front++] = curr->right;
        }
    }

    // no node with val was found 
    if (target == NULL) return root;

    // get the deepest node and its parent  
    struct Node* lastnode = NULL;
    struct Node* lastparent = NULL;
    struct Node* queue1[100];
    rear = 0, front = 0;

    // enqueue the second queue with the root node
    queue1[rear++] = root;
    // this array is going to store the parents of every node in the tree
    // because we want to store them separately instead of a pair 
    struct Node* parents[100];
    // the parent of the root node is NULL
    parents[rear - 1] = NULL;

    // loop until we find the last node along with its parent 
    while (front < rear) {
        struct Node* curr = queue[front];
        struct Node* parent = parents[front++];
    
        lastnode = curr;
        lastparent = parent;
        
        // add the left and right children nodes and their parent node 
        if (curr->left) { 
            queue1[rear] = curr->left;
            parents[rear++] = curr;
        }
        if (curr->right) { 
            queue1[rear] = curr->right;
            parents[rear++] = curr;
        }
    }

    /// replace the target node's value with the last node's value 
    target->data = lastnode->data;

    // remove the last node 
    if (lastparent) { 
        if (lastparent->left == lastnode) lastparent->left = NULL;
        else lastparent->right = NULL;
        free(lastnode);
    } else {
        free(lastnode);
        return NULL;
    }

    return root;
}


int getNodeLevel(struct Node* key, struct Node* root) { 
    if (root == NULL) return -1; // tree is empty
    
    // current level
    int lvl = 0;
    // use BFS for this task 
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) { 
        struct Node* curr = queue[front++];
        
        lvl++;

        // return current level of node if the data is matching
        if (curr->data == key->data) { 
            return lvl;
        } 

        // enqueue the right and left children nodes
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }

    // no node was found 
    return -1;
}

// get the number of nodes present in the binary tree
int getTreeSize(struct Node* root) { 
    if (root == NULL) return 0;

    int size = 0;
    struct Node* queue[100]; 
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (rear > front) { 
        struct Node* curr = queue[front++];
        size++;

        if (curr->left) { 
            queue[rear++] = curr->left;
        } 
        if (curr->right) {
            queue[rear++] = curr->right;
        }
    }
}


// get the height of tree, or basically the maximum depth
int getTreeHeight(struct Node* root) { 
    if (!root) return 0;

    // initilize queue to traverse the tree level by level 
    struct Node* queue[200];
    int front = 0, rear = 0, depth = 0;
    // enqueue the root node
    queue[rear++] = root;

    // loop until the queue is empty 
    while (front < rear) {
        // get the number of the nodes present in the current level 
        int lvlsize = rear - front;

        for (int i = 0; i < lvlsize; i++) {
            struct Node* curr = queue[front++];

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        depth++;
    }

    return depth - 1;
}


int recursive_treeHeight(struct Node* root) { 
    if (root == NULL) return -1;

    // get the height of the right and left subtrees
    int leftHeight = recursive_treeHeight(root->left);
    int rightHeight = recursive_treeHeight(root->right);

    return __max(leftHeight, rightHeight) + 1;
}


// use for testing 
int main(void) {


    return 0;
}