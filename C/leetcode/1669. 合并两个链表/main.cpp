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
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *prev = nullptr;
        ListNode *cur = list1;
        ListNode *head = list1;
        b -= a - 1;
        while (a--)
        {
            prev = cur;
            cur = cur->next;
        }
        if (prev == nullptr)
        {
            head = list2;
        }
        else
        {
            prev->next = list2;
        }
        while (b--)
        {
            ListNode *save = cur->next;
            delete cur;
            cur = save;
        }
        while (list2->next)
        {
            list2 = list2->next;
        }
        list2->next = cur;
        return head;
    }
};