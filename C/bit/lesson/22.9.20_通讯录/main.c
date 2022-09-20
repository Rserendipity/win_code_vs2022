#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("******************************************\n");
	printf("*****   1. add      2. del           *****\n");
	printf("*****   3. search   4. modify        *****\n");
	printf("*****   5. show     6. sort(failed)  *****\n");
	printf("*****   0. exit                      *****\n");
	printf("******************************************\n");
}

int main()
{
	int input = 0;
	Contact* con = ContactInit();
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ContactAddPeople(con);
			break;
		case 2:
			ContactDelPeople(&con);
			break;
		case 3:
			ContactSearchPeople(con);
			break;
		case 4:
			ContactModifyPeople(con);
			break;
		case 5:
			ContactShowPeople(con);
			break;
		//case 6:
		//	ContactSortPeople(con);
		//	break;
		case 0:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
		ContactSave(con);
	} while (input);
	ContactDestroy(con);
	return 0;
}