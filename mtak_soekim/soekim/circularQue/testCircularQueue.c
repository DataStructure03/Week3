#include "circularQueue.h"

void view(CircularQueue q)
{
	for (int i = q.front; i != (q.rear + 1)% q.maxElementCount;)
	{
		printf("q[%d] : %c\n", i, q.elements[i]);
		i = (i + 1) % q.maxElementCount;
	}
}

int main() {
	CircularQueue* q = createCircularQueue(10);

	printf("[enque 10 번]\n");
	for (char data = 'a'; data < 'a'+ 11; data++)
		put(q, data);
	view(*q);
	if (isCircularQueueFull(q))
		error("que가 포화 상태임");
	printf("[deque 1 번]\n");
	get(q);
	view(*q);
	printf("[enque 2 번]\n");
	put(q, 'x');
	put(q, 'y');
	view(*q);
	deleteCircularQueue(q);
	return 1;
}

// CircularQueue* createCircularQueue(int maxElementCount);
// void deleteCircularQueue(CircularQueue* pQueue);
// int isCircularQueueFull(CircularQueue* pQueue);

// int put(CircularQueue* pQueue, CircularQueueNode element);
// int get(CircularQueue* pQueue);
// void clearCircularQueue(CircularQueue* pQueue);

// int getCQCurrentCount(CircularQueue* pQueue);
// int getCQMaxCount(CircularQueue* pQueue);
