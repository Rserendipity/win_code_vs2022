#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_OP 20

typedef struct SqLink
{
	int* data;
	int length;
	int count;
	int head;
	int tail;
} SqLink;

SqLink* InitSqList(int size) {
	SqLink* newList = (SqLink*)malloc(sizeof(SqLink));
	newList->data = (int*)malloc(sizeof(int) * size);
	newList->head = 0;
	newList->tail = 0;
	newList->length = size;
	newList->count = 0;
	return newList;
}

void Push(SqLink* list, int elem) {
	if (list == NULL) return;
	if (list->count + 1 == list->length) return;
	list->data[list->tail++] = elem;
	list->count++;
	if (list->tail == list->length) list->tail = 0;
	return;
}
int Pop(SqLink* list) {
	if (list == NULL) return -1;
	if (list->head == list->tail) return -1;
	list->count--;
	int temp = list->data[list->head++];
	if (list->head == list->length) list->head = 0;
	return temp;
}

int DelSqList(SqLink* list) {
	if (list == NULL) return false;
	free(list->data);
	free(list);
	return true;
}
void Print(SqLink* list) {
	printf("now have [ ");
	for (int i = list->head;i != list->tail;) {
		printf("%d ", list->data[i]);
		i++;
		if (i == list->length) i = 0;
	}
	printf("]\n");
}

void func(int (*a)[3], int row, int low) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < low; j++) {
			printf("%d ", *(a[i]+j));
		}
		printf("\n");
	}
}

void arr(int n, int(*p)[10]) {

}


int main() {
	//SqLink* list = InitSqList(5);
	//Push(list, 10);
	//Push(list, 10);
	//Push(list, 10);

	//Print(list);

	//Pop(list);
	//Print(list);

	//Pop(list);
	//Print(list);
	//
	//Push(list, 10);
	//Print(list);
	//
	//Push(list, 10);
	//Push(list, 10);
	//Push(list, 10);
	//Push(list, 10);
	//Push(list, 10);
	//Push(list, 10);
	//Push(list, 10);
	//Print(list);
	/*int a[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };


	func(a, 3, 3);*/
	
	/*int a = 0;
	int n = 0;
	scanf("%d %d", &a, &n);
	int* p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		int temp = a;
		int count = 10;
		for (int j = 0; j < i; j++) {
			temp += count * a;
			count *= 10;
		}
		p[i] = temp;
	}

	for (int i = 0; i < n; i++) printf("%d ", p[i]);*/

	char* p = (char*)0x0000006B;
	char* p2 = "kjhkjhl";
	//printf("%c", *p);
	printf("%s", p);

}

