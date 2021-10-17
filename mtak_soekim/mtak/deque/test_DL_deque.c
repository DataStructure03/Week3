#include "DL_deque.h"

int main()
{
	Deque dq;
	
	initDeque(&dq);
	printf("\033[34maddFront 10\033[37m\n");
	addFront(&dq, 10);
	view(&dq);
	printf("\033[34maddFront 20\033[37m\n");
	addFront(&dq, 20);
	view(&dq);
	printf("\033[34maddRear 30\033[37m\n");
	addRear(&dq, 30);
	view(&dq);

	printf("\033[34mdeleteFront\033[37m\n");
	deleteFront(&dq);
	view(&dq);
	printf("\033[34mdeleteRear\033[37m\n");
	deleteRear(&dq);
	view(&dq);
}