#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __SQLIST_H__
#define __SQLIST_H__

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef int SqElemType;

typedef struct SqList
{
	SqElemType data[MAX_SIZE];
	int length;
}SqList;

void InitList(SqList* list);
bool Insert(SqList* list, int pos, SqElemType data);
bool DelSqListElemByPosition(SqList* list, int pos);
bool DelSqListElemByValue(SqList* list, SqElemType data);
void Print(SqList* list);
bool IsEmpty(SqList* list);
bool IsFull(SqList* list);



#endif // !__LIST_H__

