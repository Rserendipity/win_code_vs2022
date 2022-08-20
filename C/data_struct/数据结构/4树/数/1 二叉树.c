#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

int main()
{
	BinTree* newTree = NULL;
	newTree = CreateTree();

	PrePrintTree(newTree);
	printf("\n");
	InPrintTree(newTree);
	printf("\n");
	LastPrintTree(newTree);
	printf("\n");

	return 0;
}





