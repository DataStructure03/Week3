#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define FALSE 0
#define TRUE 1

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Customer.h"


typedef SimCustomer CircularQueueNode;

typedef struct CircularQueueType {
	int front;	//current front element index
	int rear;	//current rear element index
	int maxElementCount;
	int isEmpty;
	CircularQueueNode* elements;
} CircularQueue;

CircularQueue* createCircularQueue(int maxElementCount);
void deleteCircularQueue(CircularQueue* pQueue);
int isCircularQueueFull(CircularQueue* pQueue);
int put(CircularQueue* pQueue, CircularQueueNode element);
CircularQueueNode get(CircularQueue* pQueue);
void clearCircularQueue(CircularQueue* pQueue);
int getCQCurrentCount(CircularQueue* pQueue);
int getCQMaxCount(CircularQueue* pQueue);
void moveInCircular(int* target, int diff, int cycleLength);

#endif