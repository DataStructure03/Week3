#include "./ListDeque.h"

//kyujlee
ListDeque* createListDeque(){
  ListDeque * ret;

  ret = (ListDeque *)malloc(sizeof(ListDeque));
  ret->dq = createDoublyList();
  ret->FrontNode = ret->dq->headerNode.pRLink;
  ret->RearNode = ret->dq->headerNode.pRLink;

  return ret;
}

//sehyan
void deleteListDeque(ListDeque* pDeque)
{
  deleteDoublyList(pDeque->dq);
  free(pDeque);
}

//kyujlee
int insertFront(ListDeque *pDeque, DoublyListNode element){
  if (!addDLElement(pDeque->dq, 0, element))
    return false;
  pDeque->FrontNode = getDLElement(pDeque->dq, 0);
  return true;
}


//sehyan
int insertRear(ListDeque *pDeque, DoublyListNode element)
{
  if (!addDLElement(pDeque->dq, pDeque->dq->currentElementCount, element))
    return false;
  pDeque->RearNode = getDLElement(pDeque->dq, pDeque->dq->currentElementCount - 1);
  return true;
}

//kyujlee
int deleteFront(ListDeque *pDeque){
  if (!removeDLElement(pDeque->dq, 0))
    return false;
  pDeque->RearNode = getDLElement(pDeque->dq, 0);
  return true;
}

//sehyan
int deleteRear(ListDeque *pDeque)
{
  if (!removeDLElement(pDeque->dq, pDeque->dq->currentElementCount-1))
    return false;
  pDeque->RearNode = getDLElement(pDeque->dq, pDeque->dq->currentElementCount - 1);
  return true;
}

//kyujlee
DoublyListNode *peekDeque(ListDeque *pDeque){
  return (getDLElement(pDeque->dq, 1));
}

//sehyan
void clearListDeque(ListDeque* pDeque)
{
  clearDoublyList(pDeque->dq);
  pDeque->FrontNode = pDeque->dq->headerNode.pRLink;
  pDeque->RearNode = pDeque->dq->headerNode.pRLink;
}

//kyujlee
int getListDequeLength(ListDeque* pDeque){
  return (pDeque->dq->currentElementCount);
}

//sehyan
void displayDeque(ListDeque* pDeque)
{
  displayDoublyList(pDeque->dq);
}