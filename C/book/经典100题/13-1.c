//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
////��Ŀ: ��һ�������������ֽ�
//
//int IsPrimer(int num)
//{
//	int temp = 0;
//	for (int i = 2; i < num; i++)
//	{
//		if (num % i == 0)
//		{
//			temp = 1;
//			break;
//		}
//		else continue;
//	}
//	return temp ? 0 : 1;
//}
////����һ������ָ��,ָ��һ��int����,arr[0]Ϊ����,������Ϊ��2��num������
//int* PrimerNum(int num) 
//{
//	if (num < 2)
//		return NULL;
//	int* arr = malloc(sizeof(int) * num);
//	if (arr == NULL)
//		return NULL;
//	
//
//	int size = 0;
//	for (int i = 2; i < num / 2; i++)
//	{
//		if (IsPrimer(i))
//		{
//			arr[++size] = i;
//		}
//	}
//	arr[0] = size;
//	return arr;
//}
//
//
//int main()
//{
//	int inputNum = 0;
//	scanf("%d", &inputNum);
//	int* primerArr = PrimerNum(inputNum);
//	if (primerArr == NULL)
//		return -1;
//
//	/*for (int i = 0; i < primerArr[0]; i++)
//	{
//		printf("%d ", primerArr[i + 1]);
//	}*/
//
//	int* pArr = malloc(sizeof(int) * primerArr[0]);
//	if (pArr == NULL)
//		return -1;
//
//	while (1)
//	{
//		for (int i = 0; i < primerArr[0]; i++)
//		{
//			if (inputNum % primerArr[primerArr[0] - i] == 0)
//			{
//				printf("%d ", primerArr[primerArr[0] - i]);
//				inputNum /= primerArr[primerArr[0] - i];
//				break;
//			}
//		}
//		if (inputNum == 1)
//			break;
//	}
//
//
//	return 0;
//}