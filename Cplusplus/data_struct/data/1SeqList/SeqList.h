#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// �ṹ����
typedef int SeqListType;

typedef struct SeqList {
	SeqListType* array;
	int size;
	int capacity;
}SL;


// ���ܺ���
void SLInit(SL* ps);
void SLDistory(SL* ps);

void SLPushBack(SL* ps, SeqListType data);
void SLPopBack(SL* ps);

void SLPushFront(SL *ps, SeqListType data);
void SLPopFront(SL *ps);

void SLInsert(SL *ps, SeqListType data, int pos);
void SLErase(SL *ps, int pos);
int SLFind(SL *ps, SeqListType data);

void SLPrint(SL *ps);