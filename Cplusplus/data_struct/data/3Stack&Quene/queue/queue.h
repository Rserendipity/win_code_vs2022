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

// ��ʼ��������
void QueueInit(Queue* ps);
void QueueDestroy(Queue* ps);

// ��ͳ�
void QueuePush(Queue* ps, QueueDataType val);
void QueuePop(Queue* ps);

// ��ȡͷβԪ��
QueueDataType QueueFront(Queue* ps);
QueueDataType QueueBack(Queue* ps);

// ������������
bool QueueEmpty(Queue* ps);
int QueueSize(Queue* ps);