#define N 100

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data[N];
    int front;
    int rear;
} Queue;

void init_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool is_empty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

bool is_full(Queue *q) {
    return ((q->rear + 1) % N == q->front);
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        return;
    } else if (is_empty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % N;
    }
    q->data[q->rear] = value;
}

void dequeue(Queue *q) {
    if (is_empty(q)) {
        return;
    } else if (q->rear == q->front) {
        q->rear = q->front = -1;
    } else {
        q->front = (q->front + 1) % N;
    }
}

void print(Queue *q) {
    if (is_empty(q)) return;

    printf("Queue:\n");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", q->data[q->rear]);
}

int main(){
    Queue q;
    init_queue(&q);
    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 3);
    dequeue(&q);
    dequeue(&q);
    print(&q);
    return 0;
}
