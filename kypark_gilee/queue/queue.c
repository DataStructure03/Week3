#include "queue.h"
#include <stdlib.h>

Queue*	createQueue(int max)
{
	Queue *tmp;

	tmp = (Queue *)calloc(1, sizeof(Queue));
	tmp->maxElementCount = max + 1;
	tmp->arr = (QueueNode *)calloc(max + 1, sizeof(QueueNode));
	tmp->front = 0;
	tmp->rear = 0;

	// -1로 시작하는 경우도 보기

	return tmp;
}
int		enQueue(Queue *queue, QueueNode element)
{
	int	rear = (queue->rear + 1) % queue->maxElementCount;
	
	if (isFull(queue))
		return FALSE;
	queue->arr[rear] = element;
	queue->rear = rear;

	return TRUE;
}
QueueNode	*deQueue(Queue *queue)
{
	int front = (queue->front + 1) % queue->maxElementCount;

	if (isEmpty(queue))
		return NULL;
	QueueNode *tmp = (QueueNode *)calloc(1, sizeof(QueueNode));
	tmp->data = queue->arr[front].data;
	queue->front = front;

	return tmp;
}
QueueNode	*peekQueue(Queue *queue)
{
	return queue->arr + queue->front;
}

void	deleteQueue(Queue *queue)
{
	free(queue->arr);
	free(queue);
}

int isFull(Queue *queue)
{
	if((queue->rear + 1) % queue->maxElementCount == queue->front)
		return (TRUE);
	return (FALSE);
}

int isEmpty(Queue *queue)
{
	if(queue->front == queue->rear)
		return (TRUE);
	else
		return (FALSE);
	//return queue->front == queue->rear ? TRUE : FALSE;
}
/*
	arr /QueueNode *
	maxElementCount /int
	front /int
	rear /int
*/
