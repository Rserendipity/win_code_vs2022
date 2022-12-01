#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* minHead = nullptr;
        ListNode* maxHead = nullptr;
        ListNode* minMove = nullptr;
        ListNode* maxMove = nullptr;
        ListNode* cur = head;
        while (cur) {
            if (cur->val < x) {
                if (minHead == nullptr) {
                    minHead = minMove = cur;
                } else {
                    minMove->next = cur;
                    minMove = cur;
                }
            } else {
                if (maxHead == nullptr) {
                    maxHead = maxMove = cur;
                } else {
                    maxMove->next = cur;
                    maxMove = cur;
                }
            }
            cur = cur->next;
        }
        if (minHead) {
            minMove->next = maxHead;
            if (maxHead) {
                maxMove->next = nullptr;
            }
        } else {
            minHead = maxHead;
        }

        return minHead;
    }
};
int main()
{

    return 0;
}
