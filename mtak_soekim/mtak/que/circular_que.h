#ifndef CIRCULAR_QUE
# define CIRCULAR_QUE

#include <stdlib.h>
#include <stdio.h>

#define MAX_QUE_SIZE 10

typedef char Data;

typedef struct {
	Data que[MAX_QUE_SIZE];
	int front;
	int rear;	
}	CircularQue;

int error(char *msg);

void initCircularQue(CircularQue* q);

int isCircularQueEmpty(CircularQue *q);

int isCircularQueFull(CircularQue *q);

int enqueCircularQue(CircularQue *q, Data data);

int dequeCircularQue(CircularQue *q);

Data peekCircularQue(CircularQue *q);

CircularQue *createCircularQue();

#endif