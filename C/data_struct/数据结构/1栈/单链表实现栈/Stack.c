#include "Stack.h"

Stack* StackInit()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->l = ListInit();
	s->size = 0;
	return s;
}

void StackPush(Stack* s, int val)
{
	ListPushHead(s->l, val);
}

int StackPop(Stack* s)
{
	return ListPopHead(s->l);
}

int StackGetSize(Stack* s)
{
	return s->size;
}
