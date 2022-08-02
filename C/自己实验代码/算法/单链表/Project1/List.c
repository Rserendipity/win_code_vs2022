#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"


void InputInfo(Node* ps)
{
	scanf("%s", ps->data.name);
	scanf("%s", ps->data.id);
	scanf("%d", &ps->data.age);
	scanf("%d", &ps->data.math);
}
Node* CreateNode()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	return newNode;
}
Node* CreateListHead()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}
void AddInfo(Node* head)
{
	while (head->next)
	{
		head = head->next;
	}
	Node* newNode = CreateNode();
	InputInfo(newNode);
	head->next = newNode;
}
void DelInfoByName(Node*head, char* ps)
{
	Node* front = head;
	while (head->next)
	{
		head = head->next;
		if (strcmp(head->data.name, ps) == 0)
		{
			front->next = head->next;
			free(head);
			printf("删除成功!\n");
			return ;
		}
		front = front->next;
	}
	printf("删除失败,没有该人信息!\n");
}
void FindInfoByName(Node* head, char* ps)
{
	while (head->next)
	{
		head = head->next;
		if (strcmp(head->data.name, ps) == 0)
		{
			printf("%s\t", head->data.name);
			printf("%s\t", head->data.id);
			printf("%d\t", head->data.age);
			printf("%d\t\n", head->data.math);
			return;
		}
	}
	printf("未找到指定人信息\n");
}
void ReviseInfoByName(Node* head, char* ps)
{
	while (head->next)
	{
		head = head->next;
		if (strcmp(head->data.name, ps) == 0)
		{
			InputInfo(head);
			return;
		}
	}
	printf("未找到指定人信息\n");
}
void PrintInfo(Node* head)
{
	while (head->next)
	{
		head = head->next;
		printf("%s\t", head->data.name);
		printf("%s\t", head->data.id);
		printf("%d\t", head->data.age);
		printf("%d\t\n", head->data.math);
	}
}

