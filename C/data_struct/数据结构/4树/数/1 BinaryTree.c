#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

BinTree* CreateTree()
{
	BinTree* newTree = (BinTree*)malloc(sizeof(BinTree));
	char flag = 0;
	printf("输入你要存储的数据:>");
	while ((newTree->elem = getchar()) == '\n');
	printf("你要为元素 %c 创建左树吗(Y/N):>", newTree->elem);
	while ((flag = getchar()) == '\n');
	if (flag == 'Y')
		newTree->leftTree = CreateTree();
	else
		newTree->leftTree = NULL;

	printf("你要为元素 %c 创建右树吗(Y/N):>", newTree->elem);
	while ((flag = getchar()) == '\n');
	if (flag == 'Y')
		newTree->rightTree = CreateTree();
	else
		newTree->rightTree = NULL;
	return newTree;
}
void PrePrintTree(BinTree* tree)
{
	if (tree != NULL)
	{
		printf("%c ", tree->elem);
		PrePrintTree(tree->leftTree);
		PrePrintTree(tree->rightTree);
	}
}
void InPrintTree(BinTree* tree)
{
	if (tree != NULL)
	{
		InPrintTree(tree->leftTree);
		printf("%c ", tree->elem);
		InPrintTree(tree->rightTree);
	}
}
void LastPrintTree(BinTree* tree)
{
	if (tree != NULL)
	{
		InPrintTree(tree->leftTree);
		InPrintTree(tree->rightTree);
		printf("%c ", tree->elem);
	}
}