#include "DoubleLoopList.h"

Node* head = NULL;
Node* tail = NULL;

void CreatNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->pre = NULL;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->pre = tail;
		tail = newNode;
	}
	tail->next = head;
	head->pre = tail;
}
void InsertNode(int pos, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (pos == 0)
	{
		newNode->next = head;
		head->pre = newNode;
		head = newNode;
	}
	else
	{
		Node* pre = head;
		for (int i = 0; i < pos - 1; i++)
		{
			if (pre->next == NULL)
			{
				printf("下标已超出范围,自动写入到链表最后\n");
				pre->next = newNode;
				newNode->next = NULL;
				tail = newNode;
				return;
			}
			pre = pre->next;
		}
		newNode->next = pre->next;
		pre->next = newNode;
	}
}
void DeleteNode(int pos)
{
	if (pos < 0)
	{
		printf("输入非法\n");
		return;
	}
	else if (pos == 0)
	{
		Node* delNode = head;
		head = head->next;
		free(delNode);
		return;
	}
	else
	{
		Node* pre = head;
		for (int i = 0; i < pos - 1; i++)
		{
			if (pre->next == NULL)
			{
				printf("该下标元素不存在!\n");
				return;
			}
			pre = pre->next;
		}
		Node* temp = pre->next->next;
		free(pre->next);
		pre->next = temp;
		if (pre->next == NULL)
			tail = pre;
		return;
	}
}
int Search(int data)
{
	for (Node* temp = head; temp; temp = temp->next)
	{
		if (temp->data == data)
			return 1;
	}
	return 0;
}
void PrintList(Node* list)
{
	Node* temp = list;
	do
	{
		printf("%-3d", temp->data);
		temp = temp->next;
	} while (temp != head);
	printf("\n");
}
void DeleteRepeat(Node* list)
{
	int map[10] = { 0 };
	Node* p = list;
	Node* temp = NULL;

	if (p == NULL || p->next == NULL)
	{
		return;
	}
	map[p->data] = 1;
	p = p->next;

	while (p->next != NULL)
	{
		if (map[p->next->data] == 0)
		{
			map[p->next->data] = 1;
			p = p->next;
		}
		else
		{
			temp = p->next;
			p->next = temp->next;
			free(temp);
		}
	}
}
Node* FindCenter(Node* list)
{
	Node* pfast = list;
	Node* pslow = list;
	while (pfast && pfast->next)
	{
		pfast = pfast->next->next;
		pslow = pslow->next;
	}
	return pslow;
}
Node* FindLast(Node* list, int pos)
{
	Node* pfast = list;
	Node* pslow = list;

	for (int i = 0; i < pos - 1; i++)
	{
		if (pfast->next == NULL)
		{
			return NULL;
		}
		pfast = pfast->next;
	}
	while (pfast->next)
	{
		pfast = pfast->next;
		pslow = pslow->next;
	}
	return pslow;
}

Node* Inversion(Node* list)
{
	Node* temp = head;
	tail = head;
	do
	{
		head = head->next;
		temp->next = temp->pre;
		temp->pre = head;
		temp = temp->pre;
	} while (temp != tail);
	head = temp->next;
}
void PrintInversionList(Node* list)
{
	Node* temp = list;
	do
	{
		temp = temp->pre;
		printf("%-3d", temp->data);
	} while (temp != head);
	printf("\n");
}
