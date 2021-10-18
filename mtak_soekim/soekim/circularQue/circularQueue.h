#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define FALSE 0
#define TRUE 1

typedef int CircularQueueNodeType;
typedef CircularQueueNodeType CircularQueueNode ;

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct CircularQueueType {
	int front;	//current front element index
	int rear;	// current rear element index
	int maxElementCount;
	CircularQueueNode* elements;
} CircularQueue;

CircularQueue* createCircularQueue(int maxElementCount);
void deleteCircularQueue(CircularQueue* pQueue);
int isCircularQueueFull(CircularQueue* pQueue);
int put(CircularQueue* pQueue, CircularQueueNode element);
int get(CircularQueue* pQueue);
void clearCircularQueue(CircularQueue* pQueue);
int getCQCurrentCount(CircularQueue* pQueue);
int getCQMaxCount(CircularQueue* pQueue);
int error(char *msg);

#endif