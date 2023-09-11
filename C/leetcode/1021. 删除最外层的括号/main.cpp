class Solution {
public:
  string removeOuterParentheses(string s) {
    string ans;
    stack<char> st;

    int left = 0, right = 0;
    for (auto &ch : s) {
      st.push(ch);

      if (ch == '(') {
        left++;
      } else {
        right++;
      }

      // 匹配到一个原语
      if (left == right) {
        st.pop();
        string t;
        int n = st.size() - 1;
        while (n--) {
          t += st.top();
          st.pop();
        }
        st.pop();
        reverse(t.begin(), t.end());
        ans += t;
      }
    }
    return ans;
  }
};