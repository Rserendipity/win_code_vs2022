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
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                if (head == nullptr) {
                    head = cur = list1;
                } else {
                    cur->next = list1;
                    cur = cur->next;
                }
                list1 = list1->next;
            } else {
                if (head == nullptr) {
                    head = cur = list2;
                } else {
                    cur->next = list2;
                    cur = cur->next;
                }
                list2 = list2->next;
            }
        }
        if (list1 == nullptr) {
            if (head == nullptr) {
                head = list2;
            } else {
                cur->next = list2;
            }
        } else {
            if (head == nullptr) {
                head = list1;
            } else {
                cur->next = list1;
            }
        }
        return head;
    }
};