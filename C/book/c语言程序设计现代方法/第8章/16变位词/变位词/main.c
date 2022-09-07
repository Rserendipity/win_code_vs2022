#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


int main()
{
	char input1[40] = { 0 };
	char input2[40] = { 0 };
	int temp[26] = { 0 };
	printf("input first word:>");
	scanf("%s", input1);
	printf("input second word:>");
	scanf("%s", input2);
	for (int i = 0; input1[i] != '\0'; i++) {
		temp[input1[i] - 'a']++;
	}
	for (int i = 0; input1[i] != '\0'; i++) {
		temp[input1[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (temp[i] != 0) {
			printf("bushi\n");
			return 0;
		}
	}
	printf("shi \n");
	return 0;
}