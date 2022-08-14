#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include <stdio.h>
#include <stdlib.h>

typedef int BinTreeType;

typedef struct BinTree
{
	BinTreeType elem;
	struct BinTree* leftTree;
	struct BinTree* rightTree;
}BinTree;

BinTree* CreateTree();
void PrePrintTree(BinTree* tree);
void InPrintTree(BinTree* tree);
void LastPrintTree(BinTree* newTree);

#endif