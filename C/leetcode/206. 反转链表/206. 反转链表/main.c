#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		return head;
	}
	else {
		struct ListNode* temp = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return temp;
	}
}
int main()
{

    system("pause");
    return 0;
}
