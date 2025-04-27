#define SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data[SIZE];
    int front;
    int rear;

} queue ;

void initQueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isFull(queue *q) {
    return q->rear == SIZE - 1;    
}

bool isEmpty(queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow");
        exit(1);
    }

    if (q->front == -1) q->front = 0;
    q->rear++;  
    q->data[q->rear] = value;
    printf("Enqueue %d\n", value);
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow");
        exit(1);
    }

    int removed = q->data[q->front];
    q->front++;
    return removed;
}   

int main() {
    queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    int a = dequeue(&q);
    printf("Dequeued %d\n", a);
    int b = dequeue(&q);
    printf("Dequeued %d\n", b);
    int c = dequeue(&q);
    printf("Dequeued %d\n", c);
    int d = dequeue(&q); // will show "Queue is empty!"

    return 0;
}
