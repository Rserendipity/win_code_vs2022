//#define _CRT_SECURE_NO_WARNINGS 1
//#include "SqList.h"
//
//void InitList(SqList* list) {
//	list->length = 0;
//}
//bool Insert(SqList* list, int pos, SqElemType data) {
//	// λ������Ƿ�
//	if (pos > list->length)
//		return false;
//	// ˳���Ϊ��
//	if (IsFull(list))
//		return false;
//
//	// ��pos���Ԫ�غ���
//	int length = list->length;
//	while (length >= pos) {
//		list->data[length + 1] = list->data[length];
//		length--;
//	}
//	// ����Ԫ��
//	list->data[pos] = data;
//	list->length++;
//	return true;
//}
//bool DelSqListElemByPosition(SqList* list, int pos) {
//	// ɾ��Ԫ���±�ȳ��Ȼ���,ֱ�ӷ���
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
