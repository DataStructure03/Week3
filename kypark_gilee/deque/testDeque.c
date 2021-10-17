#include "deque.h"

int main(int argc, char* argv[]) {

	int i = 0;

	int arrayCount = 0;

	Deque *pList = NULL;

	DequeNode * pNode = NULL;

	DequeNode node;

	pList = createDeque();

	if (pList != NULL) {

		node.data = 1;
		addDRear(pList, node);
		removeDFront(pList);
		addDFront(pList, node);
		removeDRear(pList);
 		displayDeque(pList);
		//deleteDeque(pList);
}

	return 0;

}
