#include "deque.h"
#include <stdlib.h>

Deque *createDeque()
{
    Deque* D;
    D = (Deque *)calloc(1, sizeof(Deque));

    if(D != NULL) //메모리 할당 점검
        return D;
    return NULL;
}

void deleteDeque(Deque *deque)
{
    int cnt = deque->currentElementCount;
    while(cnt--)
        free(getDFront(deque));
    free(deque);
}
int addDFront(Deque *deque, DequeNode element)
{
    DequeNode * newNode = calloc(1,sizeof(DequeNode));
    if (!newNode)
        return FALSE;
    newNode->data = element.data;
    if (deque->currentElementCount == 0)
    {
		newNode->pNext = newNode;
		newNode->pPrev = newNode;
        deque->headerNode = newNode;
        deque->rearNode = newNode;
    }
    else
    {
        newNode->pNext = deque->headerNode;
        deque->headerNode->pPrev = newNode;
        deque->headerNode = newNode;
    }
    deque->currentElementCount++;
    return TRUE;
}
int addDRear(Deque *deque, DequeNode element)
{
    DequeNode * newNode = calloc(1,sizeof(DequeNode));
    if (!newNode)
        return FALSE;
    newNode->data = element.data;
    if (deque->currentElementCount == 0)
    {
		newNode->pNext = newNode;
		newNode->pPrev = newNode;
        deque->headerNode = newNode;
        deque->rearNode = newNode;
    }
    else
    {
        newNode->pPrev = deque->rearNode;
        deque->rearNode->pNext = newNode;
        deque->rearNode = newNode;
    }
    deque->currentElementCount++;
    return TRUE;
}

int removeDFront(Deque *deque)
{
    DequeNode * newNode = calloc(1,sizeof(DequeNode));
    if (!newNode)
        return FALSE;
    newNode =getDFront(deque);
    newNode->pNext->pPrev= deque->headerNode;
    deque->headerNode = newNode->pNext;
    free(newNode);
    deque->currentElementCount--;
    if (deque->currentElementCount == 1)
        deque->headerNode->pNext = deque->headerNode;
    return TRUE;
}

int removeDRear(Deque *deque)
{
    DequeNode * newNode = calloc(1,sizeof(DequeNode));
    if (!newNode)
        return FALSE;
    newNode =getDRear(deque);
    newNode->pPrev->pNext= deque->rearNode;
    deque->rearNode = newNode->pPrev;
    free(newNode);
    deque->currentElementCount--;
    if (deque->currentElementCount == 1)
        deque->rearNode->pPrev = deque->rearNode;
    return TRUE;
}
void displayDeque(Deque *deque){
  int i = 0;
  DequeNode *tmp = deque->headerNode;
  if (tmp != NULL)
  {
    printf("현재 원소 개수 : %d\n", deque->currentElementCount);
    for (i = 0; i < deque->currentElementCount; i++)
	{
      printf("[%d], %d\n", i, tmp->data);
      tmp = tmp->pNext;
	}
  }
  else {
    printf("원소가 없습니다.\n");
  }
}

DequeNode *getDFront(Deque *deque)
{
    return deque->headerNode;
}

DequeNode *getDRear(Deque *deque)
{
    return deque->rearNode;
}
