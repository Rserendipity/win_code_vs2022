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
    ListNode* reverseLinkList(ListNode* head) {
        ListNode* cur = head, *prev = nullptr, *save = nullptr;
        while (cur) {
            save = cur->next;
            cur->next = prev;
            prev = cur;
            cur = save;
        }
        return prev;
    }

    // 第二题copy过来的
    ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode node;
        ListNode* cur = &node;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        return node.next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = _addTwoNumbers(reverseLinkList(l1), reverseLinkList(l2));
        return reverseLinkList(head);
    }
};