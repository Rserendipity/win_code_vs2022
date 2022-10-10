#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"
static int ChackCap(struct Contact* pc);

void LoadContact(struct Contact* pc)
{
	FILE* pf = fopen("./data.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact:");
		return;
	}
	struct PeoInfo temp = { 0 };
	while (fread(&temp, sizeof(struct PeoInfo), 1, pf))
	{
		ChackCap(pc);
		pc->data[pc->sz++] = temp;
	}

	fclose(pf);
	pf == NULL;
}

void InitContact(struct Contact* pc)
{
	assert(pc);
	pc->data = (struct PeoInfo*)malloc(sizeof(struct PeoInfo) * INC);
	pc->sz = 0;
	pc->cap = INC;
	memset(pc->data, 0, INC * sizeof(struct PeoInfo));

	LoadContact(pc);
}

static int ChackCap(struct Contact* pc)
{
	if (pc->sz == pc->cap)
	{
		struct PeoInfo* temp = (struct PeoInfo*)realloc(pc->data, sizeof(struct PeoInfo) * (pc->sz + ADD_CAP));
		if (temp != NULL)
		{
			printf("���ݳɹ�\n");
			pc->data = temp;
			pc->cap += ADD_CAP;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

void AddContact(struct Contact* pc)
{
	assert(pc);

	if (0 == ChackCap(pc))
	{
		printf("ͨѶ¼�������޷��������\n");
		return;
	}

	//�����˵���Ϣ
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("�ɹ�������ϵ��\n");
}

void ShowContact(const struct Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n", pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

static int FindByName(const struct Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}


void DelContact(struct Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//����һ��ָ�������Ƿ����
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("Ҫɾ�����˲�����\n");
	else
	{
		//ɾ��
		int j = 0;
		for (j = ret; j < pc->sz-1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("�ɹ�ɾ��ָ����ϵ��\n");
	}
}

void SearchContact(const struct Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ��˵�����:>");
	scanf("%s", name);
	//����һ��ָ�������Ƿ����
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("Ҫ���ҵ��˲�����\n");
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n", pc->data[ret].name,
				pc->data[ret].sex,
				pc->data[ret].age,
				pc->data[ret].tele,
				pc->data[ret].addr);
	}
}

void ModifyContact(struct Contact* pc)
{
	printf("������Ҫ�޸��˵�����:>");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("Ҫ�޸ĵ��˲�����\n");
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[ret].name);
		printf("�������Ա�:>");
		scanf("%s", pc->data[ret].sex);
		printf("����������:>");
		scanf("%d", &(pc->data[ret].age));
		printf("������绰:>");
		scanf("%s", pc->data[ret].tele);
		printf("�������ַ:>");
		scanf("%s", pc->data[ret].addr);

		printf("�޸ĳɹ�\n");
	}
}

//int CmpByAge(const void* e1, const void* e2)
//{
//	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
//}
//
////��������������
//void SortContact(struct Contact* pc)
//{
//	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpByAge);
//}

int CmpByName(const void* e1, const void* e2)
{
	return strcmp( ((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

//��������������
void SortContact(struct Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpByName);
}

// д���ļ�
void SaveContact(struct Contact* pc)
{
	FILE* pf = fopen("./data.txt", "wb");
	if (pf == NULL)
	{
		perror("Save:");
		return;
	}
	fwrite(pc->data, sizeof(struct PeoInfo), pc->sz, pf);
	
	fclose(pf);
	pf == NULL;
}
