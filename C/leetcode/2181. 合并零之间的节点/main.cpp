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
    ListNode* mergeNodes(ListNode* head) {
        if (head == nullptr) 
            return nullptr;

        int flag = 0;
        ListNode* phead = nullptr, *pcur = nullptr;
        ListNode* cur = head->next;
        int sum = 0;
        while (cur) {
            if (cur->val != 0) {
                sum += cur->val;
            } else {
                if (phead == nullptr) {
                    phead = pcur = new ListNode(sum);
                } else {
                    pcur->next = new ListNode(sum);
                    pcur = pcur->next;
                }
                sum = 0;
            }
            cur = cur->next;
        }
        return phead;
    }
};
