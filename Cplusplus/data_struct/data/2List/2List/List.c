#include "List.h"

static Node* GetNode(ListType val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->pre = NULL;
	newNode->next = NULL;
	return newNode;
}

Node* ListInit()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = -1;
	newNode->pre = newNode;
	newNode->next = newNode;
	return newNode;
}

void ListPushBack(Node* ps, ListType val)
{
	assert(ps);
	Node* newNode = GetNode(val);

	Node* tail = ps->pre;
	tail->next = newNode;
	newNode->pre = tail;
	newNode->next = ps;
	ps->pre = newNode;
}

void ListPushFront(Node* ps, ListType val)
{
	assert(ps);

	Node* newNode = GetNode(val);
	newNode->next = ps->next;
	newNode->pre = ps;
	ps->next->pre = newNode;
	ps->next = newNode;
}

void ListPopBack(Node* ps)
{
	assert(ps);
	assert(ps != ps->pre);

	Node* save = ps->pre;
	ps->pre = save->pre;
	save->pre->next = ps;
	free(save);
}

void ListPopFront(Node* ps)
{
	assert(ps);
	assert(ps != ps->next);

	Node* save = ps->next;
	ps->next = save->next;
	save->next->pre = ps;
	free(save);
}

Node* ListFind(Node* ps, ListType val)
{
	assert(ps);
	assert(ps != ps->next);

	Node* cur = ps->next;
	while (cur != ps) {
		if (cur->data == val) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListErase(Node* ps, Node* pos)
{
	assert(ps);
	assert(pos);
	assert(ps != pos);

	Node* pre = pos->pre;
	pre->next = pos->next;
	pos->next->pre = pre;
	free(pos);
}

void ListInsert(Node* ps, Node* pos, ListType val)
{
	assert(ps);
	assert(pos);
	assert(ps != pos);
	Node* newNode = GetNode(val);
	newNode->next = pos;
	newNode->pre = pos->pre;
	pos->pre->next = newNode;
	pos->pre = newNode;
}
void ListPrint(Node* ps)
{
	assert(ps);

	Node* cur = ps->next;
	while (cur != ps) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListDestroy(Node* ps)
{
	assert(ps);

	Node* cur = ps->next;
	while (cur != ps) {
		Node* save = cur->next;
		free(cur);
		cur = save;
	}
	free(ps);
}
