#include "Link.h"

List* ListInit()
{
	List* node = (List*)malloc(sizeof(List));
	node->val = 0;
	node->next = NULL;
	node->size = 0;
	return node;
}

static List* NewList(int val)
{
	List* node = (List*)malloc(sizeof(List));
	node->next = NULL;
	node->val = val;
	return node;
}

void ListPushHead(List* list, int val)
{
	List* temp = NewList(val);
	temp->next = list->next;
	list->next = temp;
	list->size += 1;
}

int ListPopHead(List* list)
{
	if (list->size >= 1)
	{
		List* pfree = list->next;
		list->next = pfree->next;
		
		int temp = pfree->val;
		free(pfree);
		list->size -= 1;
		return temp;
	}
	else
	{
		return -1;
	}
}
