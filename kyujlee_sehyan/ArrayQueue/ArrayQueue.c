#include "ArrayQueue.h"
#include "arraylist.h"


// create ArrayQueue
ArrayQueue* createArrayQueue(int maxElementCount){
    ArrayQueue *q;

    q = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    q->qList = createArrayList(maxElementCount);
    q->front = -1;
    q->rear = -1;

    return q;
}
// delete ArrayQueue
void deleteArrayQueue(ArrayQueue* pQueue)
{
    deleteArrayList(pQueue->qList);
    free(pQueue);
}

// check the array whether it is full
int isArrayQueueFull(ArrayQueue* pQueue){
    if (abs(pQueue->rear - pQueue->front) ==pQueue->qList->maxElementCount)
        return true;
    else 
        return false;
}

// add element to ArrayQueue
int addAQElement(ArrayQueue* pQueue, ArrayListNode element){
    if (pQueue->qList->currentElementCount == 0){
        pQueue->front++;
    }
    pQueue->rear = (pQueue->rear + 1) % pQueue->qList->maxElementCount;
    if (!(addALElement(pQueue->qList, pQueue->rear, element)) ||
            isArrayQueueFull(pQueue))
        return false;
    return true;
}

// remove element from ArrayQueue
int removeAQElement(ArrayQueue* pQueue){
    if (pQueue->qList->currentElementCount == 0)
        return false;
    pQueue->front = (pQueue->front + 1) % pQueue->qList->maxElementCount;
    pQueue->qList->currentElementCount--;
    return true;
}

ArrayListNode *peekAQElement(ArrayQueue* pQueue)
{
    return ((pQueue->qList->pElement + pQueue->front));
}

// show ArrayQueue's data
void displayArrayQueue(ArrayQueue* pQueue){
    int idx = pQueue->front;
    int i = 0;
    while (i < pQueue->qList->currentElementCount){
        printf("idx[%d] {%d}\n", idx, pQueue->qList->pElement[idx].data);
        idx++;
        if (idx == pQueue->qList->maxElementCount)
            idx = 0;
        i++;
    }
    printf("\n");
}

// clear ArrayQueue's data
void clearArrayQueue(ArrayQueue* pQueue){
    clearArrayList(pQueue->qList);
    pQueue->front = 0;
    pQueue->rear = 0;
}

// get ArrayQueue's length
int getArrayQueueLength(ArrayQueue* pQueue)
{
    return (getArrayListLength(pQueue->qList));
}