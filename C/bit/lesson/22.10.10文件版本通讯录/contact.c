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
			printf("增容成功\n");
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
		printf("通讯录已满，无法添加数据\n");
		return;
	}

	//增加人的信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("成功增加联系人\n");
}

void ShowContact(const struct Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
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
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//查找一下指定的人是否存在
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("要删除的人不存在\n");
	else
	{
		//删除
		int j = 0;
		for (j = ret; j < pc->sz-1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("成功删除指定联系人\n");
	}
}

void SearchContact(const struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要查找的人的名字:>");
	scanf("%s", name);
	//查找一下指定的人是否存在
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("要查找的人不存在\n");
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n", pc->data[ret].name,
				pc->data[ret].sex,
				pc->data[ret].age,
				pc->data[ret].tele,
				pc->data[ret].addr);
	}
}

void ModifyContact(struct Contact* pc)
{
	printf("请输入要修改人的名字:>");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("要修改的人不存在\n");
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[ret].name);
		printf("请输入性别:>");
		scanf("%s", pc->data[ret].sex);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[ret].age));
		printf("请输入电话:>");
		scanf("%s", pc->data[ret].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[ret].addr);

		printf("修改成功\n");
	}
}

//int CmpByAge(const void* e1, const void* e2)
//{
//	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
//}
//
////按照年龄来排序
//void SortContact(struct Contact* pc)
//{
//	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpByAge);
//}

int CmpByName(const void* e1, const void* e2)
{
	return strcmp( ((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

//按照年龄来排序
void SortContact(struct Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpByName);
}

// 写入文件
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
