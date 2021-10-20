#include <stdlib.h>
#include <time.h>
#include "Queue.h"
#include "arraylist.h"

#define MAX_WAITING_CUSTOMER 20
#define MAX_ONGOING_CUSTOMER 3

CircularQueue* waiting;
ArrayList* ongoing;

/*
SimStatus status;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
*/



// typedef enum SimStatusType
// {
// 	arrival, start, end
// }	SimStatus;

#define TIME_UNDECIDED  -1;

void insertCustomer(SimStatus status, int arrivalTime, int serviceTime)
{
	SimCustomer newCustomer;

	newCustomer.status = status;
	newCustomer.arrivalTime = arrivalTime;
	newCustomer.serviceTime = serviceTime;
	newCustomer.startTime = TIME_UNDECIDED;
	newCustomer.endTime = TIME_UNDECIDED;
	put(waiting, newCustomer);
}

void view(CircularQueue q)
{
	if (q.isEmpty)
	{
		printf("Empty queue\n\n");
		return;
	}
	int i = q.front - 1;
	do
	{
		moveInCircular(&i, 1, q.maxElementCount);
		printf(" arrived time : %d  serviceTime : %d\n",
     q.elements[i].arrivalTime, q.elements[i].serviceTime);
	} while (i != q.rear);
}

void printWaitingCustomers() {
	printf("Waiting List\n");
	view(*waiting);
	printf("\n\n");
}

void printOngoingCustomers() {
	printf("Ongoing List\n");
	for (int i = 0;i < ongoing->currentElementCount;++i) {
		SimCustomer customer =  ongoing->pElement[i];
		printf("arrived %d, started %d, will end %d\n", customer.arrivalTime, customer.startTime, customer.endTime);
	}
}

void printCustomerStatus() {
	printWaitingCustomers();
	printOngoingCustomers();
	printf("\n\n");
}


void printAverageWaiting(int endCustomerNumber, int accumulatedTime)
{
	printf("\n\033[31mnumber of visitors : %d\033[37m\n", endCustomerNumber);
	printf("\033[31maverage waiting time : %f\033[37m\n", (float)accumulatedTime / (float)endCustomerNumber);
}



void init_rand() {
	srand(time(NULL));
}

int main()
{
	int time = 0;
	int durationTime = 30;

	init_rand();
	waiting = createCircularQueue(MAX_WAITING_CUSTOMER);
	ongoing = createArrayList(MAX_ONGOING_CUSTOMER);

	int endCustomerNumber = 0;
	int accumulatedTime = 0;

	while (time < durationTime)
	{
		printf("\033[32mTime of Now = %d\033[37m\n", time);
		if ((rand() % 10) > 1 && !isCircularQueueFull(waiting))
		{
			// int newCustomerNum = rand() % 5 + 1;
			// for (int i = 0; i < newCustomerNum; ++i)
				insertCustomer(arrival, time, (rand() % 8) + 1);
		}

		for (int i = 0; i < ongoing->currentElementCount; ++i)
		{
			while (ongoing->pElement[i].endTime == time)
			{
				accumulatedTime += ongoing->pElement[i].startTime - ongoing->pElement[i].arrivalTime;
				printf("\033[34maccumulatedTime : %d\033[37m\n", accumulatedTime);
				endCustomerNumber++;
				removeALElement(ongoing, i);
			}
		}
		for (int i = ongoing->currentElementCount;
			i < ongoing->maxElementCount && !waiting->isEmpty; ++i)
		{
			printf("\033[31m 손님 오셨음 \033[37m\n");
			SimCustomer nextToService = get(waiting);
			nextToService.startTime = time;
			nextToService.endTime = nextToService.startTime + nextToService.serviceTime;
			addALElement(ongoing, i, nextToService);
		
		}
		printCustomerStatus();
		time++;
	}
	printAverageWaiting(endCustomerNumber, accumulatedTime);
}
