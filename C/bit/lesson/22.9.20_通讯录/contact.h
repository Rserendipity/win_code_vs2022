#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _CONTECT_H_
#define _CONTECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NAME_LEN 32
#define MAX_ADDR_LEN 32
#define MAX_SEX_LEN 5
#define MAX_TEL_LEN 15

/// <summary>
/// 人的信息
/// </summary>
typedef struct PersonInfo {
	char name[MAX_NAME_LEN];
	char address[MAX_ADDR_LEN];
	char sex[MAX_SEX_LEN];
	char telephone[MAX_TEL_LEN];
} PersonInfo;

/// <summary>
/// 联系人表
/// </summary>
typedef struct Contact {
	PersonInfo* data;
	struct Contact* next;
	int size;
} Contact;


Contact* ContactInit(void);				// 初始化
void ContactSave(Contact* con);			// 保存数据到文件
void ContactAddPeople(Contact* con);    // 增
void ContactDelPeople(Contact** con);   // 删
void ContactSearchPeople(Contact* con); // 查
void ContactModifyPeople(Contact* con); // 改
void ContactShowPeople(Contact* con);   // 显示
void ContactDestroy(Contact* con);      // 销毁


#endif // !_CONTECT_H_
