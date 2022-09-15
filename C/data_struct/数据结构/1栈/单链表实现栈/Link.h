#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct List {
	int val;
	struct List* next;
	int size;
} List;

List* ListInit();
void ListPushHead(List* list, int val);
int ListPopHead(List* list);
