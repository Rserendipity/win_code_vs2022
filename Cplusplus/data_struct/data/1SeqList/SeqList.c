#include "SeqList.h"

static void CheckCapacity(SL *ps)
{
	if (ps->capacity == ps->size)
	{
		int newCap = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SeqListType* newPs = (SeqListType*)realloc(ps->array, newCap * sizeof(SeqListType));
		if (newPs == NULL)
		{
			perror("Check Capacity:");
			exit(-1);
		}
		ps->array = newPs;
		ps->capacity = newCap;
	}
}

void SLInit(SL* ps)
{
	ps->array = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLDistory(SL* ps)
{
	if (ps->array != NULL) 
	{
		free(ps->array);
		ps->capacity = ps->size = 0;
	}
}

void SLPushBack(SL* ps, SeqListType data)
{
	CheckCapacity(ps);
	ps->array[ps->size++] = data;
}

void SLPopBack(SL* ps)
{
	assert(ps->size != 0);

	ps->size--;
}

void SLPushFront(SL *ps, SeqListType data)
{
	CheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = data;
	ps->size++;
}

void SLPopFront(SL *ps)
{
	assert(ps->size != 0);

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

void SLInsert(SL *ps, SeqListType data, int pos)
{
	assert(pos >= 0 && pos <= ps->size);
	CheckCapacity(ps);

	for (int i = ps->size; i > pos; i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[pos] = data;
	ps->size++;
}

void SLErase(SL *ps, int pos)
{
	assert(pos >= 0 && pos <= ps->size - 1);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

int SLFind(SL *ps, SeqListType data)
{
	assert(ps->size);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == data)
		{
			return i;
		}
	}
	return -1;
}

void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}
