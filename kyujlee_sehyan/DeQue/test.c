#include "./ListDeque.h"

int main(){
  ListDeque *dq;
  DoublyListNode tmp;


  dq = createListDeque();
  
  tmp.pRLink = NULL;
  tmp.pLLink = NULL;

  tmp.data =5;
  insertFront(dq, tmp);
  tmp.data =6;
  insertFront(dq, tmp);
  tmp.data =7;
  insertFront(dq, tmp);
  
  tmp.data = 10;
  insertRear(dq, tmp);
  
  displayDeque(dq);

  deleteFront(dq);
  deleteRear(dq);
  displayDeque(dq);

  printf(">>>>>%d\n", peekDeque(dq)->data);
  clearListDeque(dq);
  printf("====\n");
  displayDeque(dq);
  deleteListDeque(dq);

}