#include "ArrayQueue.h"
#include "arraylist.h"

int main(int argc, char *argv[]) {
	ArrayQueue *q;
    ArrayListNode node;

    q = createArrayQueue(4);

    node.data = 10;
    addAQElement(q, node);
    node.data = 11;
    addAQElement(q, node);
    node.data = 12;
    addAQElement(q, node);
    node.data = 13;
    addAQElement(q, node);

    displayArrayQueue(q);

    removeAQElement(q);
    removeAQElement(q);
    removeAQElement(q);
    displayArrayQueue(q);


    node.data = 5;
    addAQElement(q, node);
    displayArrayQueue(q);
    ArrayListNode *n;

    n = peekAQElement(q);
    printf(">> %d\n", n->data);
	return 0;
}