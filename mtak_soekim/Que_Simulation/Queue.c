#include "Queue.h"

CircularQueue *createCircularQueue(int maxElementCount)
{
	CircularQueue *queue = calloc(1, sizeof(CircularQueue));
	queue->maxElementCount = maxElementCount;
	queue->isEmpty = TRUE;
	queue->elements = (CircularQueueNode *)malloc(maxElementCount * sizeof(CircularQueueNode));
	return queue;
}

void deleteCircularQueue(CircularQueue *pQueue)
{
	free(pQueue->elements);
	free(pQueue);
}

int isCircularQueueFull(CircularQueue *pQueue)
{
	if (!pQueue)
		return FALSE;
	return (pQueue->front == (1 + pQueue->rear) % pQueue->maxElementCount);
}

void moveInCircular(int *target, int diff, int cycleLength)
{
	*target = (*target + diff) % cycleLength;
}

int put(CircularQueue *pQueue, CircularQueueNode element)
{

	if (!pQueue || isCircularQueueFull(pQueue))
		return FALSE;

	if (pQueue->isEmpty)
	{
		pQueue->isEmpty = FALSE;
	}
	else
	{
		moveInCircular(&(pQueue->rear), 1, pQueue->maxElementCount);
	}
	pQueue->elements[pQueue->rear] = element;
	return TRUE;
}

CircularQueueNode get(CircularQueue *pQueue)
{
	CircularQueueNode deletedElement = pQueue->elements[pQueue->front];

	if (getCQCurrentCount(pQueue) == 1)
	{
		pQueue->isEmpty = TRUE;
	}
	else
	{
		moveInCircular(&pQueue->front, 1, pQueue->maxElementCount);
	}

	return deletedElement;
}

void clearCircularQueue(CircularQueue *pQueue)
{

	memset(pQueue->elements, 0, pQueue->maxElementCount * sizeof(CircularQueueNode));
	pQueue->front = 0;
	pQueue->rear = 0;
	pQueue->isEmpty = TRUE;
}

int getCQCurrentCount(CircularQueue *pQueue)
{
	if (pQueue->isEmpty)
		return 0;
	return ((pQueue->rear + pQueue->maxElementCount - pQueue->front) % pQueue->maxElementCount) + 1;
}

int getCQMaxCount(CircularQueue *pQueue)
{
	return pQueue->maxElementCount;
}