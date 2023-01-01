class Solution
{
public:
    char repeatedCharacter(string s)
    {
        unordered_set<char> hash;
        for (auto ch : s)
        {
            if (hash.insert(ch).second == false)
            {
                return ch;
            }
        }
        return -1;
    }
};