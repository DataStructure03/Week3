
#include "DL_deque.h"

void error(char *msg)
{
	printf("%s", msg);
	exit(1);
}

void initDeque(Deque *dq)
{
	dq->head = NULL;
	dq->tail = NULL;
}

int isDLEmpty(Deque *dq)
{
	if (!dq->head)
		return 1;
	return 0;
}

DLNode *createNode(DLNode *llink, DLNode *rlink, Data data)
{
	DLNode *node = malloc(sizeof(DLNode));
	if (!node)
		error("멤 할당 실패");
	node->llink = llink;
	node->rlink = rlink;
	node->data = data;
	return node;
}

void addRear(Deque *dq, Data data)
{
	DLNode *newNode = createNode(dq->tail, NULL, data);
	if (isDLEmpty(dq))
		dq->head = newNode;
	else
		dq->tail->rlink = newNode;
	dq->tail = newNode;
}

void addFront(Deque *dq, Data data)
{
	DLNode *newNode = createNode(NULL, dq->head, data);
	if (isDLEmpty(dq))
		dq->tail = newNode;
	else
		dq->head->llink = newNode;
	dq->head = newNode;
}

Data deleteFront(Deque *dq)
{
	Data data;
	DLNode *node2Remove;

	if (isDLEmpty(dq))
		error("빈 덱에서 노드 삭제는 불가하다");
	else{
		node2Remove = dq->head;
		data = node2Remove->data;
		dq->head = dq->head->rlink;
		free(node2Remove);
		if (!dq->head)
			dq->tail = NULL;
		else
			dq->head->llink = NULL;
	}
	return data;
}

Data deleteRear(Deque *dq)
{
	Data data;
	DLNode *node2Remove;

	if (isDLEmpty(dq))
		error("빈 덱에서 노드 삭제는 불가하다");
	else{
		node2Remove = dq->tail;
		data = node2Remove->data;
		dq->tail = dq->tail->llink;
		free(node2Remove);
		if (!dq->tail)
			dq->head = NULL;
		else
			dq->tail->rlink = NULL;
	}
	return data;
}

void view(Deque *dq)
{
	DLNode *itr;

	for (itr = dq->head; itr; itr = itr->rlink)
		printf("%d\n", itr->data);
}

