#ifndef DL_DEQUE_H
# define DL_DEQUE_H

#include <stdlib.h>
#include <stdio.h>
typedef char Data;

typedef struct DLNode{
	Data data;
	struct DLNode *llink;
	struct DLNode *rlink;
}	DLNode;

typedef struct {
	DLNode *head;
	DLNode *tail;
}	Deque;


void error(char *msg);

void initDeque(Deque *dq);

int isDLEmpty(Deque *dq);

DLNode *createNode(DLNode *llink, DLNode *rlink, Data data);

void addRear(Deque *dq, Data data);

void addFront(Deque *dq, Data data);

Data deleteFront(Deque *dq);

Data deleteRear(Deque *dq);

void view(Deque *dq);

#endif