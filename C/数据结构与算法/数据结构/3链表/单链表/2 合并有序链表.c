//#define _CRT_SECURE_NO_WARNINGS 1
//#include "List.h"
//
///*
// * ���µ�ָ�봮��ڵ�
// * �Ƚ�ԭ����������ֵ,�µ�ָ��ָ���С��,����,ֱ��һ������Ϊ��,����ʣ�����ļ���
// */
//int main()
//{
//	Node* list1 = NULL;
//	Node* list2 = NULL;
//	Node* p = NULL;
//	Node* q = NULL;
//
//	CreatNode(1);
//	CreatNode(14);
//	CreatNode(18);
//	CreatNode(50);
//	list1 = head;
//	PrintList(list1);
//
//	head = NULL;
//	CreatNode(4);
//	CreatNode(8);
//	CreatNode(17);
//	CreatNode(60);
//	CreatNode(80);
//	CreatNode(90);
//	list2 = head;
//	PrintList(list2);
//
//	head = NULL;
//	p = list1;
//	q = list2;
//	while (p && q)
//	{
//		if (p->data <= q->data)
//		{
//			if (head == NULL)
//				head = p;
//			else
//				tail->next = p;
//			tail = p;
//			p = p->next;
//		}
//		else
//		{
//			if (head == NULL)
//				head = q;
//			else
//				tail->next = q;
//			tail = q;
//			q = q->next;
//		}
//	}
//	tail->next = q ? q : p;
//	PrintList(head);
//
//	return 0;
//}
//
