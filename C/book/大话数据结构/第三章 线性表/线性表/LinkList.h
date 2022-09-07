#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int LinkElemType;

typedef struct Node {
	LinkElemType data;
	struct Node* next;
}Node;

Node* CreateLinkListNode(LinkElemType data);
bool AddLinkListElemByLast(Node* list,LinkElemType data);
bool DelLinkListElemByValue(Node* list, LinkElemType data);
bool AddLinkListElemByPos(Node** list, int pos, LinkElemType data);
int FindValue(Node* list, LinkElemType data);
void PrintLinkList(Node* list);

#endif