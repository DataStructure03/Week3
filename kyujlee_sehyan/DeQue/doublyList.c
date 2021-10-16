#include "doublylist.h"

DoublyList* createDoublyList(void){
  DoublyList* D;
  D = (DoublyList*)malloc(sizeof(DoublyList));
  if(D != NULL) //메모리 할당 점검
    memset(D,0, sizeof(DoublyList)); //구조체 초기화 
  else
    return NULL;
  return D;
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element){
    int i = -1;
    DoublyListNode* preNode = NULL;
    DoublyListNode* newNode = NULL;
    DoublyListNode* nextNode = NULL;

    if (pList != NULL){
        if (0<= position && position <= pList->currentElementCount){
            newNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
            if (newNode != NULL){
                //set each node
                preNode = getDLElement(pList, position);
                *newNode = element;
                if (preNode->pRLink)
                    nextNode = preNode->pRLink;
                // add element
                preNode->pRLink = newNode;
                newNode->pLLink = preNode;
                if (nextNode){
                    newNode->pRLink = nextNode;
                    nextNode->pLLink = newNode;
                }
                // set List info

                pList->currentElementCount++;
                return TRUE;
            }
        }
    }
    return FALSE;
}


DoublyListNode* getDLElement(DoublyList* pList, int position){
  int i = -1;
  DoublyListNode* Node;
  if(pList){
    Node = &(pList->headerNode);
    while(++i < position)
      Node = Node->pRLink; //해당 노드 위치로 이동
    return Node;
  }
  else 
    return NULL;
}

int removeDLElement(DoublyList* pList, int position){
  DoublyListNode* preNode;
  DoublyListNode* DeleteNode;
  if(pList){
    if(0<=position && position<=pList->currentElementCount)
    {
      preNode = getDLElement(pList, position);
      DeleteNode = preNode->pRLink;
      preNode->pRLink=DeleteNode->pRLink;
      if (DeleteNode->pRLink)
        DeleteNode->pRLink->pLLink= preNode;
      free(DeleteNode);
      pList->currentElementCount--;
      return true;
    }
  }
  return false;
}//삭제

void clearDoublyList(DoublyList* pList){
  if (pList){
    while(pList->currentElementCount > 0){
      removeDLElement(pList, 0);
    }
  }
}// 노드제거

void deleteDoublyList(DoublyList* pList){
  int i = -1;
  DoublyListNode* Node;
  if (pList){
    clearDoublyList(pList);
    free(pList);
  }
}//리스트 삭제

int getDoublyListLength(DoublyList* pList){
  if (pList)
    return(pList->currentElementCount);
  else
    return false;
}//현재 리스트 길이 가져오기

void displayDoublyList(DoublyList* pList){
  int i = 0;
  if (pList != NULL) {
    printf("현재 원소 개수 : %d\n", pList->currentElementCount);
    for (i = 0; i < pList->currentElementCount; i++)
      printf("[%d], %d\n", i, getDLElement(pList, i + 1)->data);
    }
  else {
    printf("원소가 없습니다.\n");
  }
}


void reverse(DoublyList **pList)
{
     DoublyListNode *tmp = NULL;
     DoublyListNode *node = (*pList)->headerNode.pRLink;

     while (node !=  NULL)
     {
       tmp = node->pLLink;
       node->pLLink = node->pRLink;
       node->pRLink = tmp;
       node = node->pLLink;
     }

     if(tmp != NULL )
        (*pList)->headerNode.pRLink = tmp->pLLink;
}
