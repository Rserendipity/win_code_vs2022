//#define _CRT_SECURE_NO_WARNINGS 1
//#include "List.h"
//#include <stdlib.h>
//
//Node* head = NULL;
//Node* tail = NULL;
//
//void CreatNode(int data)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->next = NULL;
//	if (head == NULL)
//		head = newNode;
//	else
//		tail->next = newNode;
//	tail = newNode;
//}
//void InsertNode(int pos, int data)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	if (pos == 0)
//	{
//		newNode->next = head;
//		head = newNode;
//	}
//	else
//	{
//		Node* pre = head;
//		for (int i = 0; i < pos - 1; i++)
//		{
//			if (pre->next == NULL)
//			{
//				printf("下标已超出范围,自动写入到链表最后\n");
//				pre->next = newNode;
//				newNode->next = NULL;
//				tail = newNode;
//				return;
//			}
//			pre = pre->next;
//		}
//		newNode->next = pre->next;
//		pre->next = newNode;
//	}
//}
//void DeleteNode(int pos)
//{
//	if (pos < 0)
//	{
//		printf("输入非法\n");
//	}
//	else if (pos == 0)
//	{
//		Node* temp = head->next;
//		free(head);
//		head = temp;
//	}
//	else
//	{
//		Node* pre = head;
//		for (int i = 0; i < pos - 1; i++)
//		{
//			if (pre->next == NULL)
//			{
//				printf("该下标元素不存在!\n");
//				return;
//			}
//			pre = pre->next;
//		}
//		Node* temp = pre->next->next;
//		free(pre->next);
//		pre->next = temp;
//		if (pre->next == NULL)
//			tail = pre;
//	}
//}
//int Search(int data)
//{
//	for (Node* temp = head; temp; temp = temp->next)
//	{
//		if (temp->data == data)
//			return 1;
//	}
//	return 0;
//}
//void PrintList()
//{
//	/*Node* temp = head;*/
//	//while (temp)
//	//{
//	//	printf("%d ", temp->data);
//	//	temp = temp->next;
//	//}
//	//for(参数1;参数2;参数3)
//	//参数1:初始化
//	//参数2:循环停止条件
//	//参数3:变量的自增等
//	for (Node* temp = head; temp; temp = temp->next)
//	{
//		printf("%d ", temp->data);
//	}
//	printf("\n");
//}
//
//
//int main()
//{
//	
//
//
//	return 0;
//}
//
//
//
