#define MAX_SIZE 100 // preprocessor directive define macro for max size of stack

#include <stdio.h> // include the preprocessor directive for output and input
#include <stdlib.h> // include the standard library
#include <stdbool.h> // standard boolean that we're going to use in our functions that return booleans

typedef struct { // Easier to write than struct Name
    int data[MAX_SIZE];
    int top; // top of the stack
} stack; // name of the structure

void initStack(stack* s) { // initialize stack
    s->top = -1; // this just means our stack is empty and has no top 
}

bool isEmpty(stack* s) {
    return s->top == -1;
}

bool isFull(stack* s) { // used to know if our stack passes MAX_SIZE
    return s->top == MAX_SIZE - 1; // -1 is just for the index of data
}

void push(int value, stack *s) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1); // raise an error and terminate
    }

    s->data[++s->top] = value; // increment the top value by 1 of the pointer data to the stack
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }

    return s->data[s->top--]; // decrement top value 
}

int peek(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }

    return s->data[s->top];
}

void printStack(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }

    for (int i = s->top; i>=0 ; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
} 

int main() {
    stack s;
    initStack(&s);

    push(5, &s);
    push(3, &s);
    push(7, &s);

    printf("Top of the stack: %d\n", peek(&s));
    printf("stack: \n");
    printStack(&s);

    printf("pop stack: %d\n", pop(&s));
    printf("pop stack: %d\n", pop(&s));

    printf("top of stack now:\n");
    printf("%d\n", peek(&s));

    return 0;
}   
