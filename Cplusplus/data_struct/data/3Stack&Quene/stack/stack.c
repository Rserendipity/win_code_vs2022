#include "stack.h"

static void CheckCapcity(ST* ps)
{
	if (ps->capicity == ps->top)
	{
		int newCap = ps->capicity * 2;
		STDataType* newArray = (STDataType*)realloc(ps->array, sizeof(STDataType) * newCap);
		assert(newArray);
		ps->array = newArray;
		ps->capicity = newCap;
	}
}

void StackInit(ST* ps)
{
	assert(ps);

	ps->array = (STDataType*)malloc(sizeof(STDataType) * 4);
	ps->capicity = 4;
	ps->top = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);

	free(ps->array);
	ps->array = NULL;
	ps->capicity = 0;
	ps->top = 0;
}

void StackPush(ST* ps, STDataType val)
{
	assert(ps);

	CheckCapcity(ps);
	ps->array[ps->top] = val;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->array[ps->top - 1];
}

int StackSize(ST* ps)
{
	return ps->top;
}

bool StackEmpty(ST* ps)
{
	return ps->top == 0;
}
