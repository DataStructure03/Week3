// this is circular queue
#ifndef _ARRAYQUEUE_
#define _ARRAYQUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // true or false
#include "arraylist.h"
//#include "list/arraylist.h"


typedef struct ArrayQueueType
{
    ArrayList *qList;
    int front;
    int rear;
} ArrayQueue;

// create ArrayQueue
ArrayQueue* createArrayQueue(int maxElementCount);

// delete ArrayQueue
void deleteArrayQueue(ArrayQueue* pQueue);

// check the array whether it is full
int isArrayQueueFull(ArrayQueue* pQueue);

// add element to ArrayQueue
int addAQElement(ArrayQueue* pQueue, ArrayListNode element);

// remove element from ArrayQueue
int removeAQElement(ArrayQueue* pQueue);

ArrayListNode *peekAQElement(ArrayQueue* pQueue);
// show ArrayQueue's data
void displayArrayQueue(ArrayQueue* pQueue);

// clear ArrayQueue's data
void clearArrayQueue(ArrayQueue* pQueue);

// get ArrayQueue's length
int getArrayQueueLength(ArrayQueue* pQueue);

#endif