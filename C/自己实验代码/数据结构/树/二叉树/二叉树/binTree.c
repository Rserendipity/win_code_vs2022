#define _CRT_SECURE_NO_WARNINGS 1
#include "binTree.h"
#define MAX_SIZE 100
// 创建结点和树
Node* createNode(char data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	return newNode;
}
void addElem(Node** node, char* p, int* index, int* treeNum)
{
	if (p == NULL) return;
	char ch = p[*index];
	*index += 1;
	if (ch == '#')
		*node = NULL;
	else
	{
		*node = (Node*)malloc(sizeof(Node));
		(*node)->data = ch;
		*treeNum += 1;
		addElem(&(*node)->lchild, p, index, treeNum);
		addElem(&(*node)->rchild, p, index, treeNum);
	}
}
Tree* createTree(char* p)
{
	Tree* newTree = (Tree*)malloc(sizeof(Tree));
	newTree->nodeNum = 0;
	newTree->root = NULL;
	int index = 0;
	addElem(&newTree->root, p, &index, &newTree->nodeNum);
	return newTree;
}


// 前中后遍历 
void prePrint(Node* node)
{
	if (node)
	{
		printf("%c ", node->data);
		prePrint(node->lchild);
		prePrint(node->rchild);
	}
}
void preOrder(Tree* tree)
{
	prePrint(tree->root);
	printf("\n");
}

void inPrint(Node* node)
{
	if (node)
	{
		inPrint(node->lchild);
		printf("%c ", node->data);
		inPrint(node->rchild);
	}
}
void inOrder(Tree* tree)
{
	inPrint(tree->root);
	printf("\n");
}

void postPrint(Node* node)
{
	if (node)
	{
		postPrint(node->lchild);
		postPrint(node->rchild);
		printf("%c ", node->data);
	}
}
void postOrder(Tree* tree)
{
	postPrint(tree->root);
	printf("\n");
}

// 层序遍历
void levelOrder(Tree* tree)
{
	if (tree == NULL) return;
	Node* p[MAX_SIZE] = { 0 };
	int head = 0;
	int tail = 0;
	p[tail++] = tree->root;
	do
	{
		Node* temp = p[head++];
		printf("%c ", temp->data);
		if (temp->lchild != NULL)
			p[tail++] = temp->lchild;
		if (temp->rchild != NULL)
			p[tail++] = temp->rchild;
		if (tail == MAX_SIZE - 1)
			tail = 0;
		if (head == MAX_SIZE - 1)
			head = 0;
	} while (head != tail);
	printf("\n");
}


// 寻找二叉树的深度
int nodeDepth(Node* node)
{
	if (node == NULL)
		return 0;
	else 
	{
		int l = nodeDepth(node->lchild);
		int r = nodeDepth(node->rchild);
		return l > r ? l + 1 : r + 1;
	}
}
int depth(Tree* tree)
{
	if (tree == NULL)
		return 0;
	else
		return nodeDepth(tree->root);
}
int nodeLeaf(Node* node)
{
	if (node == NULL)
		return 0;
	else if (node->lchild == NULL && node->rchild == NULL)
		return 1;
	else 
		return nodeLeaf(node->lchild) + nodeLeaf(node->rchild);
}
int leaf(Tree* tree)
{
	if (tree == NULL)
		return 0;
	else
		return nodeLeaf(tree->root);
}



// 树的销毁
void delNode(Node* node)
{
	if (node == NULL) return;
	delNode(node->lchild);
	delNode(node->rchild);
	free(node);
}
void delTree(Tree* tree)
{
	if (tree == NULL) return;
	delNode(tree->root);
	free(tree);
}
