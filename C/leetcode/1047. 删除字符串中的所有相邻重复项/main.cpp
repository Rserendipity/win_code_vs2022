#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            if (!st.empty()) {
                if (st.top() == s[i]) {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
            else {
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{

    return 0;
}
