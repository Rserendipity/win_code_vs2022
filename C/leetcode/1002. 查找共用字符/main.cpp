#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
// 解法1
//class Solution {
//public:
//    vector<string> commonChars(vector<string>& words) {
//        vector<string> ans;
//        int temp[26] = { 0 };
//        int min[26] = { 0 };
//        int vsize = words.size();
//
//        for (int i = 0; i < words[0].size(); i++) {
//            min[words[0][i] - 'a']++;
//        }
//
//        for (int i = 1; i < vsize; i++) {
//            memset(temp, 0, 26 * sizeof(int));
//            int ssize = (words[i]).size();
//            for (int j = 0; j < ssize; j++) {
//                temp[words[i][j] - 'a']++;
//            }
//            for (int j = 0; j < 26; j++) {
//                min[j] = std::min(temp[j], min[j]);
//            }
//        }
//
//        for (int i = 0; i < 26; i++) {
//            while (min[i]) {
//                string s;
//                s.append(1, i + 'a');
//                ans.push_back(s);
//                min[i]--;
//            }
//        }
//        return ans;
//    }
//};
// class Solution {
// public:
//     vector<string> commonChars(vector<string>& words) {
//         vector<string> ans;
//         int temp[26] = { 0 };
//         int min[26] = { 0 };
//         int vsize = words.size();

//         for (int i = 0; i < words[0].size(); i++) {
//             min[words[0][i] - 'a']++;
//         }

//         for (int i = 1; i < vsize; i++) {
//             memset(temp, 0, 26 * sizeof(int));
//             int ssize = (words[i]).size();
//             for (int j = 0; j < ssize; j++) {
//                 temp[words[i][j] - 'a']++;
//             }
//             for (int j = 0; j < 26; j++) {
//                 min[j] = std::min(temp[j], min[j]);
//             }
//         }

//         for (int i = 0; i < 26; i++) {
//             while (min[i]) {
//                 string s;
//                 s.append(1, i + 'a');
//                 ans.push_back(s);
//                 min[i]--;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int sz = words.size();
        int flag = 0; // 标记有没有找到相同的字符
        vector<string> ans;
        // 从 a ~ z 的循环
        for (int i = 'a'; i <= 'z'; i++) {
            flag = 0;

            // 如果都能找到相同的字符，flag不会被改
            for (int j = 0; j < sz; j++) {
                if (words[j].find(i) == words[j].npos) {
                    flag = 1;
                    break; // 找到一个字符串内不存在相同的字符则直接退出循环
                }
            }

            if (flag == 1) {
                // 有一个字符串没有找到当前 i 字符，啥也不做，让i++找下一个
            }
            else {
                // 所有字符串内找到了相同的字符，则加入到ans容器
                // 删除所有字符串里的i元素，再找一遍i字符，即把i--;
                string s(1, i);
                ans.push_back(s);
                // 删除所有字符串里的i
                for (int j = 0; j < sz; j++) {
                    auto pos = words[j].find(i); // 必定能找到
                    words[j].erase(words[j].begin() + pos, words[j].begin() + pos + 1);
                }
                i--;
            }
        }
        return ans;
    }
};



int main()
{
    vector<string> words = { "bella","label","roller" };
    Solution s;
    vector<string>ans = s.commonChars(words);

    for (auto& s : ans) {
        cout << s << endl;
    }

    return 0;
}
