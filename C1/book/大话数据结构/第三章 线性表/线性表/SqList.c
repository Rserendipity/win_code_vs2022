//#define _CRT_SECURE_NO_WARNINGS 1
//#include "SqList.h"
//
//void InitList(SqList* list) {
//	list->length = 0;
//}
//bool Insert(SqList* list, int pos, SqElemType data) {
//	// 位置输入非法
//	if (pos > list->length)
//		return false;
//	// 顺序表为满
//	if (IsFull(list))
//		return false;
//
//	// 将pos后的元素后移
//	int length = list->length;
//	while (length >= pos) {
//		list->data[length + 1] = list->data[length];
//		length--;
//	}
//	// 放置元素
//	list->data[pos] = data;
//	list->length++;
//	return true;
//}
//bool DelSqListElemByPosition(SqList* list, int pos) {
//	// 删除元素下表比长度还大,直接返回
//	if (pos > list->length)
//		return false;
//	
//	for (int i = pos; i < list->length; i++) {
//		list->data[i] = list->data[i + 1];
//	}
//
//	list->length--;
//	return true;
//}
//bool DelSqListElemByValue(SqList* list, SqElemType data) {
//	return false;
//}
//void Print(SqList* list) {
//	for (int i = 0; i < list->length; i++) {
//		printf("%d ", list->data[i]);
//	}
//	printf("\n");
//}
//bool IsEmpty(SqList* list) {
//	return list->length == 0;
//}
//bool IsFull(SqList* list) {
//	return list->length == MAX_SIZE - 1;
//}
//
//
//
