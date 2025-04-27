#define MAX 100 // the max size for our stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // import the preprocessor directives for input, output, booleans and the standard library

typedef struct { // simpler write than struct Stack because you have to define the data type
    int data[MAX]; // the max size of our stack
    int top; // the top of our stack
} Stack;

void init_stack(Stack* s) { // this function initializes an empty stack // we use Stack to declare the struct type of our following variable/pointer, * means you want a pointer, *s means a pointer s to a Stack, and allow access to whatever is inside that stack
    s->top = -1; // the beginning index -1 means our stack is empty
}

bool is_empty(Stack* s) { // returns whether the stack is empty
    return s->top == -1;
}

bool is_full(Stack *s) { // returns whether the stack is full (reached its max size, 100)
    return s->top == MAX - 1; // this just means that the max index we can access is 99 since C arrays start with 0
}

void push(int value, Stack *s) { // this function inserts data to the end of our stack
    if (is_full(s)) { // we use this condition to see if our stack is full and we can't insert anymore
        printf("Stack Overflow\n");
        exit(1); // terminate the run completely
    }

    if (s->top == -1) s->top = 0;

    s->data[s->top++] = value; // we're basically saying, for our pointer to data, take its index of the top and add 1, and make it to its corresponding value
};

int pop(Stack *s) { // removes the last element added from our stack, this is because the linear data structure stacks follow a LIFO principle
    if (is_empty(s)) { // see if the stack is empty
        printf("Stack Underflow\n");
        exit(1);
    }

    return s->data[--s->top]; // decrement the value top, and return the data that we removed of the corresponding index
};

void print_stack(Stack *s) {
    printf("Stack:\n");
    for (int i = s->top; i>=0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
};


int main() {
    Stack *s = (Stack *)malloc(sizeof(Stack));// we use Stack to declare the struct type of our following variable/pointer, * means you want a pointer, *s means a pointer s to a Stack, and allow access to whatever is inside that stack
    if (s == NULL) {printf("Memory allocation failed!"); exit(1);}
    init_stack(s);

    push(5, s);
    push(3, s);
    push(2, s);
    pop(s);
    print_stack(s);
    return 0;
}


