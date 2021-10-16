  // this is circular queue
  #ifndef _LISTDEQUE_
  #define _LISTDEQUE_

  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h> // true or false
  #include "doublylist.h"
  //#include "list/doublylist.h"

  typedef struct ListDequeType
  {
    DoublyList *dq;
    DoublyListNode *FrontNode;
    DoublyListNode *RearNode;
  } ListDeque;


  ListDeque* createListDeque();
  void deleteListDeque(ListDeque* pDeque);
  int insertFront(ListDeque *pDeque, DoublyListNode element);
  int insertRear(ListDeque *pDeque, DoublyListNode element);
  int deleteFront(ListDeque *pDeque);
  int deleteRear(ListDeque *pDeque);
  DoublyListNode *peekDeque(ListDeque *pDeque);
  void clearListDeque(ListDeque* pDeque);
  int getListDequeLength(ListDeque* pDeque);
  void displayDeque(ListDeque* pDeque);


  #endif