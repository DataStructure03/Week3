#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	Queue *queue = createQueue(5);
	QueueNode element;
	QueueNode *ele;

	element.data = 1;
	enQueue(queue, element);
	element.data = 2;
	enQueue(queue, element);
	element.data = 3;
	enQueue(queue, element);
	element.data = 4;
	enQueue(queue, element);
	element.data = 5;
	enQueue(queue, element);

	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	element.data = 1;
	enQueue(queue, element);
	element.data = 2;
	enQueue(queue, element);
	element.data = 3;
	enQueue(queue, element);
	element.data = 4;
	enQueue(queue, element);
	element.data = 5;
	enQueue(queue, element);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	if ((ele = deQueue(queue)))
		printf("%d\n", ele->data);
	free(ele);
	deleteQueue(queue);
	return 0;
}
