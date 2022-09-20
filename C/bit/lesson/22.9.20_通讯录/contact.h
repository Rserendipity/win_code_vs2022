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
/// �˵���Ϣ
/// </summary>
typedef struct PersonInfo {
	char name[MAX_NAME_LEN];
	char address[MAX_ADDR_LEN];
	char sex[MAX_SEX_LEN];
	char telephone[MAX_TEL_LEN];
} PersonInfo;

/// <summary>
/// ��ϵ�˱�
/// </summary>
typedef struct Contact {
	PersonInfo* data;
	struct Contact* next;
	int size;
} Contact;


Contact* ContactInit(void);				// ��ʼ��
void ContactSave(Contact* con);			// �������ݵ��ļ�
void ContactAddPeople(Contact* con);    // ��
void ContactDelPeople(Contact** con);   // ɾ
void ContactSearchPeople(Contact* con); // ��
void ContactModifyPeople(Contact* con); // ��
void ContactShowPeople(Contact* con);   // ��ʾ
void ContactDestroy(Contact* con);      // ����


#endif // !_CONTECT_H_
