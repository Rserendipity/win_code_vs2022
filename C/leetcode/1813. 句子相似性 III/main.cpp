class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int sz1 = sentence1.size() - 1;
        int sz2 = sentence2.size() - 1;

        if (sz1 > sz2) {
            sentence1.swap(sentence2);
            swap(sz1, sz2);
        }

        stringstream sin1(sentence1);
        stringstream sin2(sentence2);

        deque<string> Q1;
        deque<string> Q2;
        string tmp;

        while (sin1 >> tmp) {
            Q1.push_back(tmp);
        }
        while (sin2 >> tmp) {
            Q2.push_back(tmp);
        }

        // 头部去重
        while (!Q1.empty() && !Q2.empty() && Q1.front() == Q2.front()) {
            Q1.pop_front();
            Q2.pop_front();
        }
        // 尾巴去重
        while (!Q1.empty() && !Q2.empty() && Q1.back() == Q2.back()) {
            Q1.pop_back();
            Q2.pop_back();
        }
        // 头尾去重以后短的为长度0了，则另一个sentence要不就是重复、要不就是中间插入了句子
        return Q1.size() == 0;
    }
};