#include <stdlib.h>
#include <time.h>
#include "Queue.h"
#include "arraylist.h"

#define MAX_WAITING_CUSTOMER 20
#define MAX_ONGOING_CUSTOMER 10

CircularQueue *waiting;
ArrayList *ongoing;

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
		printf("index[%d] : arrived time : %d  serviceTime : %d\n", i, q.elements[i].arrivalTime, q.elements[i].serviceTime);
	} while (i != q.rear);
}


void printWaitingCustomers(){
  printf("Waiting List\n");
  view(*waiting);
  printf("\n\n");
}


void printStatus(int endCustomerNumber, int accumulatedTime)
{
	printf("\033[35m 방문자 수 : \033[37m%d\n", endCustomerNumber);
	printf("\033[35m 평균 대기 시간 : \033[37m%d\n", accumulatedTime / endCustomerNumber);
}

void init_rand(){
	srand(time(NULL));
}

int main()
{
	int time = 0;
	int durationTime = 50;

	init_rand();
	waiting = createCircularQueue(MAX_WAITING_CUSTOMER);
	ongoing = createArrayList(MAX_ONGOING_CUSTOMER);

	int endCustomerNumber=0;
	int accumulatedTime= 0;//상담 받다가 끝나면 넌 일을 안한거여.

	while (time < durationTime)
	{
		printf("현재 시각=%d\n", time);
		int test;
		if ((test = rand() % 10) > 5 && ! isCircularQueueFull(waiting))
		{
			printf("test : %d\n", test);
			insertCustomer(arrival, time, /*(rand() % 5) + 1*/ 3);
		}
		
		for (int i = 0; i < ongoing->currentElementCount ; ++i)
    	{
			while(ongoing->pElement[i].endTime == time)
			{
				accumulatedTime += ongoing->pElement[i].startTime - ongoing->pElement[i].arrivalTime;
				endCustomerNumber++;
				removeALElement(ongoing, i);
			}
		}
		for (int i = ongoing->currentElementCount;
    		i <  ongoing->maxElementCount && !waiting->isEmpty ; ++i)
		{
			addALElement(ongoing, i, get(waiting));
		}
		printWaitingCustomers();//대기 손님 출력
		time++;
	}
	printStatus(endCustomerNumber, accumulatedTime);//손님들이 평균적으로 대기한 시간 출력
	
}
