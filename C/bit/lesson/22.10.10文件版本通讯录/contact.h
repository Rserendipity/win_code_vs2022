#pragma once

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define INC 3
#define ADD_CAP 2

//表示人信息
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	char addr[MAX_ADDR];
};

//通讯录
struct Contact
{
	struct PeoInfo* data;
	int sz;
	int cap;
};

//初始化通讯录
void InitContact(struct Contact* pc);

//增加人的信息到通讯录
void AddContact(struct Contact* pc);

//显示通讯录中的信息
void ShowContact(const struct Contact* pc);

//删除指定联系人
void DelContact(struct Contact* pc);

//查找指定联系人
void SearchContact(const struct Contact* pc);

//修改指定联系人的信息
void ModifyContact(struct Contact* pc);

//排序通讯录中的信息 - 年龄
void SortContact(struct Contact* pc);

// 写入文件
void SaveContact(struct Contact* pc);
