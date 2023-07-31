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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *cur = head, *save = nullptr;
        while (cur) {
            save = cur->next;
            cur->next = prev;
            prev = cur;
            cur = save;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        // 快慢指针,找到一半的位置
        ListNode* fast = head, *slow = head, *prev = nullptr;
        while (fast  && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (prev == nullptr) {
            return;
        }

        // 1 -> 2 -> 3
        // 5 -> 4
        // 

        // 翻转后半部分
        ListNode* right = reverseList(slow->next);
        slow->next = nullptr;

        // 合并
        ListNode *cur = head;
        while(cur && right){
            ListNode *curSecond = right;
            right = right->next;
            ListNode *nextCur = cur->next;
            curSecond->next = cur->next;
            cur->next = curSecond;
            
            cur = nextCur;
        }
    }
};