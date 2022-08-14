#include "queun.h"
extern int head = 0, tail = 0;

void enqueun(QueunType data)
{
	queun[tail++] = data;
}

QueunType dequeun(void)
{
	return queun[head++];
}

int is_empty()
{
	return tail == head;
}