//#define _CRT_SECURE_NO_WARNINGS 1
//#include "List.h"
//
///*
// * 使用快慢指针,只用遍历一次链表就可以了
// * 先让快指针走n-1步,然后快慢指针同时移动,快指针移动到尾时,慢指针指向的就是要找的倒数第n个数
// */
//
//int main()
//{
//	CreatNode(1);
//	CreatNode(2);
//	CreatNode(3);
//	CreatNode(4);
//	CreatNode(5);
//	CreatNode(6);
//	CreatNode(7);
//	CreatNode(8);
//	Node* temp = FindLast(head, 3);
//	if (temp == NULL)
//	{
//		printf("error position\n");
//		return -1;
//	}
//	printf("the data of last 3th position is %d", temp->data);
//
//	return 0;
//}
//
//
