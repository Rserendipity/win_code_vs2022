/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pHead = nullptr, *cur = nullptr;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                if (pHead == nullptr) {
                    pHead = cur = new ListNode(list1->val);
                } else {
                    cur->next = new ListNode(list1->val);
                    cur = cur->next;
                }
                list1 = list1->next;
            } else {
                if (pHead == nullptr) {
                    pHead = cur = new ListNode(list2->val);
                } else {
                    cur->next = new ListNode(list2->val);
                    cur = cur->next;
                }
                list2 = list2->next;
            }
        }

        if (list1) {
            if (pHead == nullptr) {
                pHead = list1;
            } else {
                cur->next = list1;
            }
        }

        if (list2) {
            if (pHead == nullptr) {
                pHead = list2;
            } else {
                cur->next = list2;
            }
        }

        return pHead;
    }
};