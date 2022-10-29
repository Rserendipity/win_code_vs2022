#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

static Node* GetNode(SLType val)
{
	Node* ps = (Node*)malloc(sizeof(Node));
	ps->data = val;
	ps->next = NULL;
}

void SListPushBack(Node** pps, SLType val)
{
	Node* newNode = GetNode(val);

	if (*pps == NULL)
	{
		*pps = newNode;
		return;
	}

	Node* temp = *pps;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void SListPushFront(Node** pps, SLType val)
{
	Node* newNode = GetNode(val);

	newNode->next = *pps;
	*pps = newNode;
}

void SListPopBack(Node** pps)
{
	assert(*pps);

	if ((*pps)->next == NULL)
	{
		free(*pps);
		*pps = NULL;
		return;
	}

	Node* temp = *pps;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void SListPopFront(Node** pps)
{
	assert(*pps);

	Node* temp = (*pps)->next;
	free(*pps);
	*pps = temp;
}

void SListInsert(Node** pps, SLType val, int pos)
{
	assert(pos >= 0);

	if (pos == 0)
	{
		SListPushFront(pps, val);
		return;
	}


	Node* temp = *pps;
	while (pos--)
	{
		temp = temp->next;
		assert(temp);
	}
	Node* newNode = GetNode(val);
	newNode->next = temp->next;
	temp->next = newNode;
}

void SListErase(Node** pps, int pos)
{
	assert(pos >= 0);
	if (pos == 0)
	{
		SListPopFront(pps);
		return;
	}

	Node* temp = *pps;
	while (--pos)
	{
		temp = temp->next;
		assert(temp && temp->next);
	}

	Node* popNode = temp->next;
	temp->next = temp->next->next;
	free(popNode);
}

void SListDistory(Node* ps)
{
	Node* temp = NULL;
	while (ps != NULL)
	{
		temp = ps->next;
		free(ps);
		ps = temp;
	}
}

void SListPrint(Node* ps)
{
	while (ps != NULL)
	{
		printf("%d -> ", ps->data);
		ps = ps->next;
	}
	printf("NULL\n");
}
