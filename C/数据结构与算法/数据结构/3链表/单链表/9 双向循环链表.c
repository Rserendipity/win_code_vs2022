#define _CRT_SECURE_NO_WARNINGS 1
#include "DoubleLoopList.h"

/*
 * 
 * 
 */
int main()
{
	CreatNode(0);
	CreatNode(1);
	CreatNode(2);
	CreatNode(3);
	CreatNode(4);
	CreatNode(5);
	PrintList(head);
	Inversion(head);
	PrintList(head);
	CreatNode(6);
	CreatNode(7);
	PrintList(head);
	Inversion(head);
	PrintList(head);

	return 0;
}


