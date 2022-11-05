#include "heap.h"

static void CheckCapicity(Hp* ps)
{
	if (ps->capicity == ps->size) 
	{
		int newCap = ps->capicity == 0 ? 4 : ps->capicity * 2;
		HeapDataType* newArray = (HeapDataType*)realloc(ps->array, sizeof(HeapDataType)*newCap);
		if (newArray == NULL) 
		{
			printf("Realloc Fail\n");
			exit(-1);
		}
		ps->array = newArray;
		ps->capicity = newCap;
	}
}

void swap(HeapDataType* val1, HeapDataType* val2)
{
	HeapDataType temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void CheckHeapUp(HeapDataType* arr, int pos)
{
	int parent = (pos - 1) / 2;
	while (pos > 0)
	{
		if (arr[parent] < arr[pos])
		{
			swap(&arr[parent], &arr[pos]);
			pos = parent;
			parent = (pos - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void CheckHeapDown(HeapDataType* arr, int pos, int size)
{
	// 大堆
	int child = pos * 2 + 1;
	while (child < size) 
	{
		// 左右孩子中的较大的那一个
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child++;
		}
		// 交换孩子和父亲
		if (arr[child] > arr[pos])
		{
			swap(&arr[child], &arr[pos]);
			pos = child;
			child = pos * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Hp* ps)
{
	assert(ps);

	ps->array = NULL;
	ps->capicity = 0;
	ps->size = 0;
}

void HeapDestroy(Hp* ps)
{
	assert(ps);

	free(ps->array);
	ps->array = NULL;
	ps->capicity = ps->size = 0;
}

void HeapPush(Hp* ps, HeapDataType val)
{
	assert(ps);

	CheckCapicity(ps);
	ps->array[ps->size++] = val;
	CheckHeapUp(ps->array, ps->size - 1);
}

void HeapPop(Hp* ps)
{
	assert(ps);
	assert(!HeapEmpty(ps));

	swap(&ps->array[0], &ps->array[ps->size - 1]);
	ps->size--;
	CheckHeapDown(ps->array, 0, ps->size);
}

void HeapPirnt(Hp* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}

bool HeapEmpty(Hp* ps)
{
	return ps->size == 0;
}
