#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverse(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* next = NULL;
		while (cur != NULL) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		return pre;
	}
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return true;
		}
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}

		fast = reverse(slow->next);
		ListNode* vhead = head;

		while (fast) {
			if (fast->val != vhead->val) {
				return false;
			}
			vhead = vhead->next;
			fast = fast->next;
		}

		return true;
	}

};
int main()
{
	ListNode* head = new ListNode(1,
					new ListNode(2,
					new ListNode(3,
					new ListNode(3,
					new ListNode(2,
					new ListNode(1, NULL))))));
	Solution s;
	s.isPalindrome(head);
	system("pause");
	return 0;
}
