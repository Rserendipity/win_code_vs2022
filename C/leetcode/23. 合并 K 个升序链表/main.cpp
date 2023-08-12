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
    struct Com {
        bool operator()(const ListNode* p1, const ListNode* p2) {
            if (!p1 || !p2)
                return true;
            return p1->val > p2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        
        ListNode phead(-1), *cur = &phead;
        priority_queue<ListNode*, vector<ListNode*>, Com> pq;

        for (auto& head : lists) {
            if (head)
                pq.push(head);
        }

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            if (top->next) {
                pq.push(top->next);
            }
        }
        return phead.next;
    }
};