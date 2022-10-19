#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
// �ⷨ1
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
        int flag = 0; // �����û���ҵ���ͬ���ַ�
        vector<string> ans;
        // �� a ~ z ��ѭ��
        for (int i = 'a'; i <= 'z'; i++) {
            flag = 0;

            // ��������ҵ���ͬ���ַ���flag���ᱻ��
            for (int j = 0; j < sz; j++) {
                if (words[j].find(i) == words[j].npos) {
                    flag = 1;
                    break; // �ҵ�һ���ַ����ڲ�������ͬ���ַ���ֱ���˳�ѭ��
                }
            }

            if (flag == 1) {
                // ��һ���ַ���û���ҵ���ǰ i �ַ���ɶҲ��������i++����һ��
            }
            else {
                // �����ַ������ҵ�����ͬ���ַ�������뵽ans����
                // ɾ�������ַ������iԪ�أ�����һ��i�ַ�������i--;
                string s(1, i);
                ans.push_back(s);
                // ɾ�������ַ������i
                for (int j = 0; j < sz; j++) {
                    auto pos = words[j].find(i); // �ض����ҵ�
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
