#include "circularQueue.h"

int error(char *msg)
{
	printf("\033[31n%s\033[37n\n", msg);
	exit(1);
	return -1;
}

CircularQueue* createCircularQueue(int maxElementCount) {
	CircularQueue* queue = calloc(1, sizeof(CircularQueue));
	queue->maxElementCount = maxElementCount;
	queue->elements =(int *) malloc(maxElementCount);
	return queue;
}

void deleteCircularQueue(CircularQueue* pQueue) {
	free(pQueue->elements);
	free(pQueue);
}

int isCircularQueueFull(CircularQueue* pQueue) {
	if (!pQueue)
		return FALSE;
	return (pQueue->front == (1 + pQueue->rear) % pQueue->maxElementCount);
}

void moveInCircular(int* target, int diff, int cycleLength) {
	*target = (*target + diff) % cycleLength;
}

int put(CircularQueue* pQueue, CircularQueueNode element) {

	if (!pQueue || isCircularQueueFull(pQueue))
		return FALSE;
	moveInCircular(&pQueue->rear, 1, pQueue->maxElementCount);
	if (getCQCurrentCount(pQueue) == 0)
		pQueue->front = pQueue->rear;
	pQueue->elements[pQueue->rear] = element;
	return TRUE;
}

int get(CircularQueue* pQueue) {
	
	if (!pQueue || getCQCurrentCount(pQueue) == 0)
		return FALSE;

	int deletedElement = pQueue->front;
	
	pQueue->elements[pQueue->front] = 0;
	if (pQueue->front != pQueue->rear) //when only 1 element exists front == rear, and front should not move 그래도 없을 것 같아용..
		moveInCircular(&pQueue->front, 1, pQueue->maxElementCount);
	return deletedElement;
}

void clearCircularQueue(CircularQueue* pQueue) {

	memset(pQueue->elements, 0, pQueue->maxElementCount * sizeof(CircularQueueNode));
	pQueue->front = 0;
	pQueue->rear = 0;
}

int getCQCurrentCount(CircularQueue* pQueue) {
	return ((1 + pQueue->rear + pQueue->maxElementCount - pQueue->front)
		% pQueue->maxElementCount);
}

int getCQMaxCount(CircularQueue* pQueue) {
	return pQueue->maxElementCount;
}