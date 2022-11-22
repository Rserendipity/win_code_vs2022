#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head != nullptr) {
            ans <<= 1;
            ans |= head->val;
            head = head->next;
        }
        return ans;
    }
};
int main()
{

    return 0;
}
