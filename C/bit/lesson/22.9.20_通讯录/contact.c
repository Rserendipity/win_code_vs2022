#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

/// <summary>
/// ����һ���µı�
/// </summary>
/// <param name="p"> ��Ϣ </param>
/// <returns> �����½��ı�ĵ�ַ </returns>
static Contact* ContactAddElement(PersonInfo* p)
{
	PersonInfo* peo = calloc(1, sizeof(PersonInfo));
	Contact* newc = (Contact*)calloc(1, sizeof(Contact));
	strcpy(peo->address, p->address);
	strcpy(peo->name, p->name);
	strcpy(peo->telephone, p->telephone);
	strcpy(peo->sex, p->sex);
	newc->data = peo;
	newc->next = NULL;
	newc->size = 0;
	return newc;
}

/// <summary>
/// ��ȡ�ļ������Ϣ 
/// </summary>
/// <param name="c"> ��ȡ���ݴ�ŵ���һ������ </param>
static void ContactReadFile(Contact* c)
{
	FILE* fp = fopen("./info.txt", "r");
	if (fp == NULL)
		return;

	Contact* move = c;
	PersonInfo p_temp = { 0 };
	while (fscanf(fp, "%s%s%s%s\n", p_temp.name, p_temp.address,p_temp.sex,p_temp.telephone) != EOF)
	{
		move->next = ContactAddElement(&p_temp);
		move = move->next;
		c->size += 1;
	}
	fclose(fp);
}

/// <summary>
/// ��ϵ�˳�ʼ�������ȡ�ļ��е���Ϣ
/// </summary>
/// <returns> ���س�ʼ���õ���ϵ�˱� </returns>
Contact* ContactInit()
{
	PersonInfo* p = (PersonInfo*)calloc(1, sizeof(PersonInfo));
	Contact* c = (Contact*)calloc(1, sizeof(Contact));
	c->data = p;
	c->next = NULL;
	c->size = 0;

	ContactReadFile(c); // ��ȡ�ļ��������

	return c;
}

/// <summary>
/// ���洫������е���Ϣ���ļ���
/// </summary>
/// <param name="c"> ��Ҫ�������Ϣ��ͷָ�� </param>
void ContactSave(Contact* c)
{
	Contact* move = c;
	FILE* fp = fopen("./info.txt", "w");
	if (fp == NULL)
	{
		printf("����ʧ��\n");
		return;
	}
	
	for (int i = 0; i < c->size; i++)
	{
		PersonInfo* peo = move->data;
		fprintf(fp, "%s %s %s %s\n", peo->name, peo->address, peo->sex, peo->telephone);
		move = move->next;
	}

	fclose(fp);
}

static PersonInfo* GetPersonInfo(PersonInfo* p)
{
	printf("Input name :>");
	scanf("%s", p->name);
	printf("Input address :>");
	scanf("%s", p->address);
	printf("Input sex :>");
	scanf("%s", p->sex);
	printf("Input telephone :>");
	scanf("%s", p->telephone);
	return p;
}

void ContactAddPeople(Contact* con)
{
	PersonInfo peo;
	Contact* newCon = ContactAddElement(GetPersonInfo(&peo));
	Contact* move = con;
	for (int i = 0; i < con->size - 1; i++)
	{
		move = move->next;
	}
	move->next = newCon;
	con->size += 1;
}

static int FindPeopleByName(Contact* con, const char* name)
{
	return (strcmp(name, con->data->name) == 0);
}

void ContactDelPeople(Contact** con)
{	
	char nameBuff[MAX_NAME_LEN] = { 0 };
	printf("������Ҫɾ�����˵�����:>\n");
	scanf("%s", nameBuff);
	Contact* move = (*con)->next;
	Contact* slow = (*con);

	// ɾ��ͷ�ڵ�
	if (FindPeopleByName(*con, nameBuff))
	{
		printf("ɾ���ɹ�\n");
		move->size = (*con)->size - 1;
		free(*con);
		*con = move;
		return;
	}

	// ��ͷ�ڵ�ʱ
	while (move != NULL)
	{
		if (FindPeopleByName(move, nameBuff))
		{
			printf("ɾ���ɹ�\n");
			free(move);
			(*con)->size -= 1;
			slow->next = NULL;
			return;
		}
		move = move->next;
		slow = slow->next;
	}
	printf("û���ҵ���ϵ��\n");

}

static void PrintInfo(Contact* con)
{
	printf("%s\t%s\t%s\t%s\n", con->data->name, con->data->address, con->data->sex, con->data->telephone);
}

void ContactSearchPeople(Contact* con)
{
	char nameBuff[MAX_NAME_LEN] = { 0 };
	printf("������Ҫ��ѯ���˵�����:>\n");
	scanf("%s", nameBuff);
	Contact* move = con;
	for (int i = 0; i < con->size; i++)
	{
		if (FindPeopleByName(move, nameBuff))
		{
			printf("��Ϣ���£�\n");
			PrintInfo(move);
			return;
		}
	}
	printf("û���ҵ�����ϵ��\n");
}

void ContactModifyPeople(Contact* con)
{
	char nameBuff[MAX_NAME_LEN] = { 0 };
	printf("������Ҫ��ѯ���˵�����:>\n");
	scanf("%s", nameBuff);
	Contact* move = con;
	for (int i = 0; i < con->size; i++)
	{
		if (FindPeopleByName(move, nameBuff))
		{
			printf("�����޸���Ϣ:>\n");
			GetPersonInfo(move->data);
			return;
		}
	}
	printf("û���ҵ�����ϵ��\n");
}

void ContactShowPeople(Contact* con)
{
	Contact* move = con;
	printf("����\t\t\t�Ա�\t\tסַ\t\t\t\t�绰\n");
	for (int i = 0; i < con->size; i++)
	{
		printf("%s\t\t\t%s\t\t%s\t\t\t\t%s\n", move->data->name, move->data->sex, move->data->address, move->data->telephone);
		move = move->next;
	}
}

void ContactDestroy(Contact* con)
{
	Contact* move = con;
	for (int i = 0; i < con->size; i++)
	{

	}
}
