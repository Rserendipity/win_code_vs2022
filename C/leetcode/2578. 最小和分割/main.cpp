class Solution
{
public:
    int splitNum(int num)
    {
        string s(to_string(num));
        sort(s.begin(), s.end());
        int i = 0;
        string a, b;
        while (i < s.size())
        {
            a.push_back(s[i++]);
            b.push_back(s[i++]);
        }
        return stoi(a) + stoi(b);
    }
};