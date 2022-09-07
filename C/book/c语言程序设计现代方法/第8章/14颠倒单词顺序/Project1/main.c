#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


int main()
{
	char* p = "you can cage a swallow can't you?";
	char arr[40] = { 0 };
	int end = 0;
	int temp = 0;
	int index = 0;
	while (p[end] != '?' && p[end] != '.') {
		end++;
	}

	while (end >= 0) {
		while (p[end] != ' ' && end >= 0) {
			end--;
		}
		temp = end + 1;
		while (p[temp] != '?' && p[temp] != '.' && p[temp] != ' ') {
			arr[index++] = p[temp];
			temp++;
		}
		arr[index++] = ' ';
		end--;
	}
	printf("%s", arr);

	return 0;
}