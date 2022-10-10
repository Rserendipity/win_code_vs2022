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

//��ʾ����Ϣ
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	char addr[MAX_ADDR];
};

//ͨѶ¼
struct Contact
{
	struct PeoInfo* data;
	int sz;
	int cap;
};

//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc);

//�����˵���Ϣ��ͨѶ¼
void AddContact(struct Contact* pc);

//��ʾͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(struct Contact* pc);

//����ָ����ϵ��
void SearchContact(const struct Contact* pc);

//�޸�ָ����ϵ�˵���Ϣ
void ModifyContact(struct Contact* pc);

//����ͨѶ¼�е���Ϣ - ����
void SortContact(struct Contact* pc);

// д���ļ�
void SaveContact(struct Contact* pc);
