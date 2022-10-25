#include "SeqList.h"

void CheckCapacity(SL* ps)
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
	if (ps->size > 0)
	{
		ps->size--;
	}
	else
	{
		perror("Pop:");
	}
}

void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}
