#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLType;

typedef struct SLNode {
	SLType data;
	struct SLNode* next;
} Node;

void SListPushBack(Node** pps, SLType val);
void SListPushFront(Node** pps, SLType val);

void SListPopBack(Node** pps);
void SListPopFront(Node** pps);

Node* SListFind(Node* ps, SLType val);

void SListInsert(Node** pps, SLType val, int pos);
void SListInsertByFind(Node** pps, SLType val, Node* pos);

void SListErase(Node** pps, int pos);

void SListDistory(Node** pps);
void SListPrint(Node* ps);