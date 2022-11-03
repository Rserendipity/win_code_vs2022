#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QueueDataType;

typedef struct QueueNode {
	QueueDataType data;
	struct QueueNode* next;
} QueueNode;

typedef struct Queue {
	struct QueueNode* head;
	struct QueueNode* tail;
} Queue;

// 初始化和销毁
void QueueInit(Queue* ps);
void QueueDestroy(Queue* ps);

// 入和出
void QueuePush(Queue* ps, QueueDataType val);
void QueuePop(Queue* ps);

// 获取头尾元素
QueueDataType QueueFront(Queue* ps);
QueueDataType QueueBack(Queue* ps);

// 其他辅助函数
bool QueueEmpty(Queue* ps);
int QueueSize(Queue* ps);