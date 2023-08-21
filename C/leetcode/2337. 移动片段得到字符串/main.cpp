
class Solution {
public:
  bool canChange(string start, string target) {
    int n = start.size();
    // 双指针
    int i, j;
    // 两字符串都遍历完才结束
    for (i = 0, j = 0; i < n || j < n;) {
      // 遇到'_'就跳过
      if (start[i] == '_') {
        i++;
      } else if (target[j] == '_') {
        j++;
      } else {
        // 此时两个字符均不是'_'
        if (start[i] == target[j]) {
          // 如果此时两个字符为'L',i >=
          // j的话start[i]可以左移到和target[j]的相同位置
          if (start[i] == 'L') {
            if (i < j)
              return false;
          } else // 右侧同理
          {
            if (i > j)
              return false;
          }
          i++;
          j++;
        } else // 如果两个字符不相同就不能通过移动使得相同，两字符串的顺序需要一致
        {
          return false;
        }
      }
    }

    return true;
  }
};
