//#define _CRT_SECURE_NO_WARNINGS 1
//#include "LoopList.h"
//
///*
// * �ܹ���n���� �ӵ�m���˿�ʼ���� ����k
// * �ӵ�m���˿�ʼ��,����k���˳�����,ֱ������Ϊ��
// */
//int main()
//{
//	int n = 0, m = 0, k = 0;
//	printf("��������:>");
//	scanf("%d", &n);
//	if (n < 1)
//		return -1;
//	for (int i = 1; i <= n; i++) CreatNode(i);
//
//	printf("�ӵڼ����˿�ʼ����:>");
//	scanf("%d", &m);
//	if (m > n)
//		return -1;
//
//	printf("����Ϊ:>");
//	scanf("%d", &k);
//	if (k > n)
//		return -1;
//
//	PrintList(head);
//	Node* pre = head;
//	
//	if (m < 1)
//	{
//		return -1;
//	}
//	else if(m == 1)
//	{
//		while (pre != tail)
//			pre = pre->next;
//	}
//	else
//	{
//		--m;
//		while (--m)
//			pre = pre->next;
//	}
//	//printf("%d", pre->next->data);
//	
//	if (k < 1)
//	{
//		return -1;
//	}
//	else
//	{
//		while (n--)
//		{
//			for (int i = 0; i < k - 1; i++)
//			{
//				pre = pre->next;
//			}
//			printf("%d ", pre->next->data);
//			Node* temp = pre->next->next;
//			free(pre->next);
//			pre->next = temp;
//		}
//	}
//
//	return 0;
//}
//
//
