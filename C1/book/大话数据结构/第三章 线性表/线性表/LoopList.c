//#define _CRT_SECURE_NO_WARNINGS 1
//#include "LinkList.h"
//
//Node* CreateLinkListNode(LinkElemType data) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = data;
//	newNode->next = NULL;
//	return newNode;
//}
//bool AddLinkListElemByLast(Node* list, LinkElemType data) {
//	if (list == NULL)
//		return false;
//
//	while (list->next)
//		list = list->next;
//	list->next = CreateLinkListNode(data);
//	return true;
//}
//bool DelLinkListElemByValue(Node* list, LinkElemType data) {
//	if (list == NULL)
//		return false;
//	int pos = FindValue(list, data);
//	if (pos == -1)
//		return false;
//	if (pos == 0 && list->next == NULL) {
//		free(list);
//		list = NULL;
//		return true;
//	}
//
//	for (int i = 0; i < pos - 1; i++)
//		list = list->next;
//	Node* temp = list->next->next;
//	free(list->next);
//	list->next = temp;
//	return true;
//}
//bool AddLinkListElemByPos(Node** list, int pos, LinkElemType data) {
//	if (list == NULL)
//		return false;
//	if (pos == 0) {
//		Node* temp = CreateLinkListNode(data);
//		temp->next = *list;
//		*list = temp;
//		return true;
//	}
//	int i = 0;
//	for (i; i < pos - 1 && (*list)->next; i++)
//		*list = (*list)->next;
//	if ((*list)->next == NULL && i != pos - 1)
//		return false;
//
//	Node* temp = CreateLinkListNode(data);
//	temp->next = ( * list)->next;
//	(*list)->next = temp;
//	return true;
//}
//
//int FindValue(Node* list, LinkElemType data) {
//	if (list == NULL)
//		return -1;
//
//	for (int i = 0; list; i++, list = list->next) {
//		if (list->data == data)
//			return i;
//	}
//
//	return -1;
//}
//
//void PrintLinkList(Node* list) {
//	while (list) {
//		printf("%d ", list->data);
//		list = list->next;
//	}
//	printf("\n");
//}
