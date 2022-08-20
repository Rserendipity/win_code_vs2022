#pragma once
#ifndef __DOUBLELOOPLIST_H__
#define __DOUBLELOOPLIST_H__
#include <stdio.h>
#include <stdlib.h>

extern struct Node* head;
extern struct Node* tail;

typedef struct Node
{
	struct Node* pre;
	int data;
	struct Node* next;
}Node;

void CreatNode(int data);
void InsertNode(int pos, int data);
void DeleteNode(int pos);
int  Search(int data);
void PrintList(Node* list);
void DeleteRepeat(Node* list);
Node* FindCenter(Node* list);
Node* FindLast(Node* list, int pos);
Node* Inversion(Node* list);
void PrintInversionList(Node* list);

#endif

