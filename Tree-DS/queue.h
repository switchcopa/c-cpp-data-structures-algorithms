#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 10000
#include <stdbool.h>

typedef struct {
    int items[MAX_SIZE];
    int rear;
    int front;
} Queue;

void initQueue(Queue* queue);
void enqueue(int data);
int dequeue(Queue* queue);
bool isEmptyQueue(Queue* queue);
bool isFullQueue(Queue* queue);

#endif