#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __LOOPLIST_H__
#define __LOOPLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int LinkElemType;

typedef struct Node {
	LinkElemType data;
	struct Node* next;
}Node;

Node* CreateLinkListNode(LinkElemType data);
bool AddLoopListElemByLast(Node* list,LinkElemType data);
bool DelLoopListElemByValue(Node* list, LinkElemType data);
bool AddLoopListElemByPos(Node** list, int pos, LinkElemType data);
int FindLoopListValue(Node* list, LinkElemType data);
void PrintLoopList(Node* list);

#endif