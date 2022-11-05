#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HeapDataType;
typedef struct HeapNode {
	HeapDataType* array;
	int size;
	int capicity;
} Hp;

void HeapInit(Hp* ps);
void HeapDestroy(Hp* ps);
void HeapPush(Hp* ps, HeapDataType val);
void HeapPop(Hp* ps);
void HeapPirnt(Hp* ps);
bool HeapEmpty(Hp* ps);

void CheckHeapUp(HeapDataType* arr, int pos);
void CheckHeapDown(HeapDataType* arr, int pos, int size);
void swap(HeapDataType* val1, HeapDataType* val2);
