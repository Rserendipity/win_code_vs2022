#pragma once
#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PeoInfo
{
	char name[24];
	char id[10];
	int age;
	int math;
}PeoInfo;

typedef struct Node
{
	PeoInfo data;
	struct Node* next;
}Node;

Node* CreateListHead();
void AddInfo(Node* head);
void DelInfoByName(Node* head, char*ps);
void FindInfoByName(Node* head, char* ps);
void ReviseInfoByName(Node* head, char* ps);
void PrintInfo(Node* head);


#endif 
