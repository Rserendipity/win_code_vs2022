//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//void swap(char* s1, char* s2) {
//	char temp = *s1;
//	*s1 = *s2;
//	*s2 = temp;
//}
//void reversion(char* arr, int n) {
//	int size = strlen(arr);
//	if (size < 2)
//		return;
//	if(n > size)
//		n %= size; // n����sizeʱֻ��Ҫ��תn��sizeȡģ��
//	if (n == size) // n == sizeʱֱ�ӷ�ת��ȥ�ˣ��൱�ڲ���Ҫ��ת
//		return;
//	int head = 0;
//	while (arr[n] != '\0') {
//		swap(&arr[head++], &arr[n++]);
//	}
//}
//int main() {
//	char arr[] = "ABCDEF";
//	printf("%s\n", arr);
//	reversion(arr, 7);
//	printf("%s\n", arr);
//	return 0;
//}
