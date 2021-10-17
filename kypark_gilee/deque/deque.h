#ifndef _DEQUE_
#define _DEQUE_
#include <stdio.h>
#ifndef NULL
 #define NULL (void *)0
#endif

typedef struct DequeNodeType
{
    int data;
    struct DequeNodeType *pNext;
    struct DequeNodeType *pPrev;
} DequeNode;


typedef struct DequeType
{
	int	currentElementCount;
	DequeNode	*headerNode;
	DequeNode	*rearNode;
} Deque;

Deque *createDeque();
int addDFront(Deque *deque, DequeNode element);
int addDRear(Deque *deque, DequeNode element);
DequeNode *getDFront(Deque *deque);
DequeNode *getDRear(Deque *deque);
void displayDeque(Deque *deque);
int removeDFront(Deque *deque);
int removeDRear(Deque *deque);
void deleteDeque(Deque *deque);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
