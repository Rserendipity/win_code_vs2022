#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _BINTREE_H_
#define _BINTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 树结构

typedef struct Node {
	char data;
	struct Node* lchild;
	struct Node* rchild;

} Node;

typedef struct Tree {
	Node* root;
	int nodeNum;
} Tree;

// 方法

Tree* createTree(char* p);
Node* createNode(char data);


void preOrder(Tree* tree);
void inOrder(Tree* tree);
void postOrder(Tree* tree);
void levelOrder(Tree* tree);

int depth(Tree* tree);
int leaf(Tree* tree);

void delNode(Node* node);
void delTree(Tree* root);


#endif