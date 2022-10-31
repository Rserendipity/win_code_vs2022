#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
ListNode(int x, struct ListNode * next) : val(x), next(next) {}
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		ListNode* maxHead = NULL;
		ListNode* minHead = NULL;
		ListNode* maxCur = NULL;
		ListNode* minCur = NULL;

		ListNode* cur = head;

		while (cur != NULL) {
			if (cur->val < x) {
				if (minHead == NULL) {
					minHead = cur;
					minCur = cur;
				}
				else {
					minCur->next = cur;
					minCur = cur;
				}
			}
			else {
				if (maxHead == NULL) {
					maxHead = cur;
					maxCur = cur;
				}
				else {
					maxCur->next = cur;
					maxCur = cur;
				}
			}
			cur = cur->next;
		}
		if (minHead == NULL || maxHead == NULL) {
			return head;
		}
		else {
			maxCur->next = NULL;
			minCur->next = maxHead;
			return minHead;
		}
	}
};
int main()
{
	ListNode node1(8);
	ListNode node2(6);
	ListNode node3(5);
	ListNode node4(6);
	ListNode node5(7);
	ListNode node6(3);
	ListNode node7(4);
	ListNode node8(5);
	
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node6.next = &node7;
	node7.next = &node8;

	Solution p;
	p.partition(&node1, 6);


    system("pause");
    return 0;
}
