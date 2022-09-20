#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

/// <summary>
/// 创建一个新的表
/// </summary>
/// <param name="p"> 信息 </param>
/// <returns> 返回新建的表的地址 </returns>
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
/// 读取文件里的信息 
/// </summary>
/// <param name="c"> 读取数据存放到哪一个表中 </param>
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
/// 联系人初始化，会读取文件中的信息
/// </summary>
/// <returns> 返回初始化好的联系人表 </returns>
Contact* ContactInit()
{
	PersonInfo* p = (PersonInfo*)calloc(1, sizeof(PersonInfo));
	Contact* c = (Contact*)calloc(1, sizeof(Contact));
	c->data = p;
	c->next = NULL;
	c->size = 0;

	ContactReadFile(c); // 获取文件里的内容

	return c;
}

/// <summary>
/// 保存传入参数中的信息到文件中
/// </summary>
/// <param name="c"> 需要保存的信息的头指针 </param>
void ContactSave(Contact* c)
{
	Contact* move = c;
	FILE* fp = fopen("./info.txt", "w");
	if (fp == NULL)
	{
		printf("保存失败\n");
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
	printf("输入你要删除的人的姓名:>\n");
	scanf("%s", nameBuff);
	Contact* move = (*con)->next;
	Contact* slow = (*con);

	// 删除头节点
	if (FindPeopleByName(*con, nameBuff))
	{
		printf("删除成功\n");
		move->size = (*con)->size - 1;
		free(*con);
		*con = move;
		return;
	}

	// 非头节点时
	while (move != NULL)
	{
		if (FindPeopleByName(move, nameBuff))
		{
			printf("删除成功\n");
			free(move);
			(*con)->size -= 1;
			slow->next = NULL;
			return;
		}
		move = move->next;
		slow = slow->next;
	}
	printf("没有找到联系人\n");

}

static void PrintInfo(Contact* con)
{
	printf("%s\t%s\t%s\t%s\n", con->data->name, con->data->address, con->data->sex, con->data->telephone);
}

void ContactSearchPeople(Contact* con)
{
	char nameBuff[MAX_NAME_LEN] = { 0 };
	printf("输入你要查询的人的姓名:>\n");
	scanf("%s", nameBuff);
	Contact* move = con;
	for (int i = 0; i < con->size; i++)
	{
		if (FindPeopleByName(move, nameBuff))
		{
			printf("信息如下：\n");
			PrintInfo(move);
			return;
		}
	}
	printf("没有找到该联系人\n");
}

void ContactModifyPeople(Contact* con)
{
	char nameBuff[MAX_NAME_LEN] = { 0 };
	printf("输入你要查询的人的姓名:>\n");
	scanf("%s", nameBuff);
	Contact* move = con;
	for (int i = 0; i < con->size; i++)
	{
		if (FindPeopleByName(move, nameBuff))
		{
			printf("输入修改信息:>\n");
			GetPersonInfo(move->data);
			return;
		}
	}
	printf("没有找到该联系人\n");
}

void ContactShowPeople(Contact* con)
{
	Contact* move = con;
	printf("姓名\t\t\t性别\t\t住址\t\t\t\t电话\n");
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
