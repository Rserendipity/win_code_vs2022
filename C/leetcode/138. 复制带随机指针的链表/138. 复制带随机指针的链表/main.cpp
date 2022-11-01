#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};


class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL) {
			return NULL;
		}
		struct Node* cur = head;
		// ����
		while (cur) {
			struct Node* next = cur->next;
			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->val = cur->val;
			newNode->next = next;
			cur->next = newNode;
			cur = next;
		}

		cur = head;
		// ��������ڵ�
		while (cur) {
			struct Node* cpy = cur->next;
			struct Node* next = cpy->next;
			if (cur->random == NULL) {
				cpy->random = NULL;
			}
			else {
				cpy->random = cur->random->next;
			}
			cur = next;
		}

		// ��ֽڵ�
		cur = head;
		struct Node* ansHead = head->next;
		while (cur) {
			struct Node* cpy = cur->next;
			struct Node* next = cpy->next;
			if (next == NULL) {
				cpy->next = NULL;
				cur->next = NULL;
				break;
			}
			else {
				cpy->next = next->next;
				cur->next = next;
				cur = next;
			}
		}
		return ansHead;
	}
};
int main()
{

    system("pause");
    return 0;
}
