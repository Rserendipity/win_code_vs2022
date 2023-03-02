#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int index = 0;
        int sz = s.size();
        string ans;
        while (index < sz) {
            if (s[index] != ']') {
                st.push(s[index]);
            }
            else {
                char top = st.top();
                string tmp;
                while (top != '[') {
                    tmp += top;
                    st.pop();
                    top = st.top();
                }
                st.pop(); // '[' ³öÕ»
                top = st.top();
                reverse(tmp.begin(), tmp.end());
                string num;
                while (isdigit(top)) {
                    num += top;
                    st.pop();
                    if (st.empty())
                        break;
                    top = st.top();
                }
                int n = stoi(num);
                while (n--) {
                    ans += tmp;
                }
            }
            index++;
        }
        return ans;
    }
};
int main()
{
    cout << Solution().decodeString("3[a2[c]]");
    return 0;
}
