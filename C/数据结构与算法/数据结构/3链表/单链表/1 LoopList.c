//#include "LoopList.h"
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
//	tail->next = head;
//}
//void InsertNode(int pos, int data)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	if (pos < 0)
//	{
//		printf("输入非法\n");
//		free(newNode);
//		return;
//	}
//	else if (pos == 0)
//	{
//		if (head == NULL)
//		{
//			CreatNode(data);
//			free(newNode);
//			return;
//		}
//		newNode->next = head;
//		head = newNode;
//		tail->next = head;
//	}
//	else
//	{
//		Node* pre = head;
//		for (int i = 0; i < pos - 1; i++)
//		{
//			if (pre->next == head)
//			{
//				printf("下标已超出范围,自动写入到链表最后\n");
//				pre->next = newNode;
//				newNode->next = head;
//				tail = newNode;
//				return;
//			}
//			pre = pre->next;
//		}
//		newNode->next = pre->next;
//		pre->next = newNode;
//		if (newNode->next == head)
//			tail = newNode;
//	}
//}
//void DeleteNode(int pos)
//{
//	if (pos < 0)
//	{
//		printf("输入非法\n");
//		return;
//	}
//	else if (head == NULL)
//	{
//		printf("链表为空,无法删除\n");
//		return;
//	}
//	else if (pos == 0)
//	{
//		if (head->next == NULL)
//		{
//			free(head);
//			head = NULL;
//			tail = NULL;
//			return;
//		}
//		Node* temp = head->next;
//		free(head);
//		head = temp;
//		tail->next = head;
//	}
//	else
//	{
//		Node* pre = head;
//		for (int i = 0; i < pos - 1; i++)
//		{
//			if (pre->next == head)
//			{
//				printf("该下标元素不存在,删除失败\n");
//				return;
//			}
//			pre = pre->next;
//		}
//		if (pre->next == head)
//		{
//			printf("该下标元素不存在,删除失败\n");
//			return;
//		}
//		Node* temp = pre->next->next;
//		free(pre->next);
//		pre->next = temp;
//		if (pre->next == head)
//			tail = pre;
//	}
//}
//int Search(int data)
//{
//	//for (Node* temp = head; temp; temp = temp->next)
//	//{
//	//	if (temp->data == data)
//	//		return 1;
//	//}
//	//return 0;
//	Node* p = head;
//	if (p == NULL)
//		return -1;
//	do
//	{
//		if (p->data == data)
//			return 1;
//		p = p->next;
//	} while (p != head);
//	return 0;
//}
//void PrintList(Node* list)
//{
//	//for (Node* temp = list; temp; temp = temp->next)
//	//{
//	//	printf("%d ", temp->data);
//	//}
//	Node* p = list;
//	if (p == NULL)
//		return;
//	do
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	} while (p != head);
//	printf("\n");
//}
//void DeleteRepeat(Node* list)
//{
//	int map[10] = { 0 };
//	Node* p = list;
//	Node* temp = NULL;
//
//	if (p == NULL || p->next == p)
//	{
//		return;
//	}
//
//	map[p->data] = 1;
//
//	while (p->next != head)
//	{
//		if (map[p->next->data] == 0)
//		{
//			map[p->next->data] = 1;
//			p = p->next;
//		}
//		else
//		{
//			temp = p->next;
//			p->next = temp->next;
//			if (p->next == head)
//				tail = p;
//			free(temp);
//		}
//	}
//}
//Node* FindCenter(Node* list)
//{
//	if (list == NULL)
//		return NULL;
//	Node* pfast = list;
//	Node* pslow = list;
//	do
//	{
//		pfast = pfast->next->next;
//		pslow = pslow->next;
//	} while (pfast != list && pfast->next != list);
//	return pslow;
//}
//Node* FindLast(Node* list, int pos)
//{
//	Node* pfast = list;
//	Node* pslow = list;
//
//	for (int i = 0; i < pos - 1; i++)
//	{
//		if (pfast->next == list)
//		{
//			return NULL;
//		}
//		pfast = pfast->next;
//	}
//	while (pfast->next != head)
//	{
//		pfast = pfast->next;
//		pslow = pslow->next;
//	}
//	return pslow;
//}
//
//Node* Inversion(Node* list)
//{
//	if (list == NULL || list->next == list)
//		return NULL;
//	
//	Node* p = list;
//	Node* n = p->next;
//
//	head->next = tail;
//	tail = head;
//	while (n!=tail)
//	{
//		p = n;
//		n = n->next;
//		p->next = head;
//		head = p;
//	}
//	return p;
//}
