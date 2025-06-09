#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmptyQueue(Queue* queue) {
    return queue->front == queue->rear - 1;
}

bool isFullQueue(Queue* queue) {
    return queue->rear == MAX_SIZE;
}

void enqueue(Queue* queue, int data) {
    if (isFullQueue(queue)) {
        printf("Queue overflow warning!\n");
        return;
    }

    queue->items[queue->rear++] = data;
}

int dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue underflow warning!\n");
        return -1;
    }

    int item = queue->items[queue->front++];
    
    return item;
}