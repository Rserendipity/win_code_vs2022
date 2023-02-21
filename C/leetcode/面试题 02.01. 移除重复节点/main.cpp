/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeDuplicateNodes(ListNode *head)
    {
        unordered_set<int> hash;
        ListNode *phead = nullptr;
        ListNode *pcur = nullptr;
        for (ListNode *cur = head; cur; cur = cur->next)
        {
            if (hash.count(cur->val) == 0)
            {
                if (phead == nullptr)
                {
                    phead = pcur = cur;
                }
                else
                {
                    pcur->next = cur;
                    pcur = cur;
                }
                hash.insert(cur->val);
            }   
        }
        if (pcur)
            pcur->next = nullptr;
        return phead;
    }
};