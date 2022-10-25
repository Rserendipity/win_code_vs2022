#pragma once
#include <stdio.h>
#include <stdlib.h>


// 结构定义
typedef int SeqListType;

typedef struct SeqList {
	SeqListType* array;
	int size;
	int capacity;
}SL;


// 功能函数
void SLInit(SL* ps);
void SLDistory(SL* ps);

void SLPushBack(SL* ps, SeqListType data);
void SLPopBack(SL* ps);

void SLPrint(SL* ps);