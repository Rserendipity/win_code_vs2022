//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	// ����ָ��,������ָ��,ָ��ָ�������������
//	int arr[10] = { 0 };
//	arr;		// ��Ԫ�ص�ַ
//	&arr;		// ����������ȡ��ַ,ȡ��������������ĵ�ַ,�ڼӼ�����������������������
//	
//	int* p1 = arr;			// ��������Ԫ�ص�ַ,���� arr ������ int* ���������
//	int(*p2)[10] = &arr;	// ��������������ĵ�ַ,���� &arr Ҫ������ָ�������
//
//
//	printf("%p\n", arr);
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1);
//
//	printf("\n");
//
//	printf("%p\n", p1);
//	printf("%p\n", p1 + 1);
//	printf("%p\n", p2);
//	printf("%p\n", p2 + 1);
//
//
//	return 0;
//}