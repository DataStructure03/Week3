#include "circular_que.h"

void view(CircularQue q)
{
	for (int i = q.front + 1; i != (q.rear + 1)% MAX_QUE_SIZE;)
	{
		printf("q[%d] : %c\n", i, q.que[i]);
		i = (i + 1) % MAX_QUE_SIZE;
	}
}

int main()
{
	CircularQue q;

	initCircularQue(&q);
	peekCircularQue(&q);
	printf("[enque 9 번]\n");
	for (char data = 'a'; data < 'a'+ 9; data++)
		enqueCircularQue(&q, data);
	view(q);
	if (isCircularQueFull(&q))
		error("que가 포화 상태임");
	printf("[deque 1 번]\n");
	dequeCircularQue(&q);
	view(q);
	printf("[enque 2 번]\n");
	enqueCircularQue(&q, 'x');
	enqueCircularQue(&q, 'y');
	view(q);
	return 1;
}