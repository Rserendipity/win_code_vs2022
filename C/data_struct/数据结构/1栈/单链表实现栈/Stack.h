#pragma once
#include "Link.h"
typedef struct Stack {
	List* l;
	int size;
} Stack;

Stack* StackInit();
void StackPush(Stack* s, int val);
int StackPop(Stack* s);
int StackGetSize(Stack* s);
