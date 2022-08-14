#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

int main()
{
	Node* head = CreateListHead();

	AddInfo(head);
	DelInfoByName(head, "cjj");
	FindInfoByName(head, "cj");
	ReviseInfoByName(head, "cj");
	
	PrintInfo(head);
	return 0;
}


