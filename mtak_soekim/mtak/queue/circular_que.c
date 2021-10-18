#include "circular_que.h"

int error(char *msg)
{
	printf("\033[31n%s\033[37n\n", msg);
	// exit(1);
	return -1;
}

void initCircularQue(CircularQue* q)
{
	q->front = 0;
	q->rear = 0;
}

int isCircularQueEmpty(CircularQue *q)
{
	return q->front == q->rear;
}

int isCircularQueFull(CircularQue *q)
{
	return (q->rear + 1) % MAX_QUE_SIZE == q->front;
}

int enqueCircularQue(CircularQue *q, Data data)
{
	if (isCircularQueFull(q))
		return error("que가 포화 상태임");
	q->rear = (q->rear + 1) % MAX_QUE_SIZE;
	q->que[q->rear] = data;
	return 0;
}

int dequeCircularQue(CircularQue *q)
{
	if (isCircularQueEmpty(q))
		return error("que가 비어있는 상태임");
	q->front = (q->front + 1) % MAX_QUE_SIZE;
	q->que[q->front];
	return 0;
}

Data peekCircularQue(CircularQue *q)
{
	if (isCircularQueEmpty(q))
		return error("que가 비어있는 상태임");
	return q->que[q->front + 1];
}

CircularQue *createCircularQue()
{
	return malloc(sizeof(CircularQue));
}