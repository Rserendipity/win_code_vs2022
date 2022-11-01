#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//typedef struct PeoInfo
//{
//	char name[32];
//	int age;
//}ListType;

typedef int ListType;

typedef struct List {
	ListType data;
	struct List* pre;
	struct List* next;
} Node;

Node* ListInit();
void ListPushBack(Node* ps, ListType val);
void ListPushFront(Node* ps, ListType val);

void ListPopBack(Node* ps);
void ListPopFront(Node* ps);

Node* ListFind(Node* ps, ListType val);
void ListErase(Node* ps, Node* pos);
void ListInsert(Node* ps, Node* pos, ListType val);

void ListPrint(Node* ps);
void ListDestroy(Node* ps);