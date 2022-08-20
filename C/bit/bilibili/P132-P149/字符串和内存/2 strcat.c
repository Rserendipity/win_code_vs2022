//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//
//char* myStrcat(char* dest, const char* souse) {
//	assert(dest && souse);
//	char* mv = dest;
//	while (*mv) mv++;
//
//	while (*souse) {
//		*mv = *souse;
//		mv++;
//		souse++;
//	}
//	return mv;
//}
//
//int main()
//{
//	char str[10] = "abcd";
//	char* p = "efg";
//	printf("%s", myStrcat(str, p));
//}