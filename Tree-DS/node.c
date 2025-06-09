#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* createNode(int data) {
    Node* newnode = malloc(sizeof(Node));
    newnode->data = data;

    return newnode; 
}