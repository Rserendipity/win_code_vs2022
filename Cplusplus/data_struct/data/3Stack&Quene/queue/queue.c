#include "queue.h"

static QueueNode* GetNode(QueueDataType val)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->next = NULL;
	newNode->data = val;
	return newNode;
}

void QueueInit(Queue* ps)
{
	assert(ps);

	ps->head = NULL;
	ps->tail = NULL;
}

void QueueDestroy(Queue* ps)
{
	assert(ps);

	QueueNode* head = ps->head;
	QueueNode* next = NULL;
	
	while (head != NULL) 
	{
		next = head->next;
		free(head);
		head = next;
	}
	ps->head = NULL;
	ps->tail = NULL;
}

void QueuePush(Queue* ps, QueueDataType val)
{
	assert(ps);

	QueueNode* newNode = GetNode(val);

	if (ps->head == NULL)
	{
		ps->head = newNode;
		ps->tail = newNode;
	}
	else
	{
		ps->tail->next = newNode;
		ps->tail = newNode;
	}
}

void QueuePop(Queue* ps)
{
	assert(ps);
	assert(ps->head);

	QueueNode* save = ps->head;
	ps->head = save->next;
	free(save);
}

QueueDataType QueueFront(Queue* ps)
{
	assert(ps);
	assert(ps->head);

	return ps->head->data;
}

QueueDataType QueueBack(Queue* ps)
{
	assert(ps);
	assert(ps->head);

	return ps->tail->data;
}

bool QueueEmpty(Queue* ps)
{
	return QueueSize(ps) == 0;
}

int QueueSize(Queue* ps)
{
	assert(ps);
	int count = 0;
	QueueNode* head = ps->head;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}
