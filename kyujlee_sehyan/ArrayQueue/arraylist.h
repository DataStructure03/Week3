#ifndef _ARRAYLIST_
#define _ARRAYLIST_

#include <stdio.h>
#include <stdlib.h>

// ArrayList's Element
typedef struct ArrayListNodeType
{
	int data;  // Element's data
} ArrayListNode;

// ArrayList
typedef struct ArrayListType
{
	int maxElementCount;		// Element's max index
	int currentElementCount;	// Element's current index
	ArrayListNode *pElement;	// array to store data
} ArrayList;

// create arrayList
ArrayList* createArrayList(int maxElementCount);

// delete arraylist
void deleteArrayList(ArrayList* pList);

// check the array whether it is full
int isArrayListFull(ArrayList* pList);

// add element to arraylist
int addALElement(ArrayList* pList, int position, ArrayListNode element);

// remove element from arraylist
int removeALElement(ArrayList* pList, int position);

// search data from position that i want to get
ArrayListNode* getALElement(ArrayList* pList, int position);

// show arraylist's data
void displayArrayList(ArrayList* pList);

// clear arraylist's data
void clearArrayList(ArrayList* pList);

// get arraylist's length
int getArrayListLength(ArrayList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
