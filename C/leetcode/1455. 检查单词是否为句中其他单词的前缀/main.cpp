class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        int ans = -1;
        for (int i = 1; ss >> sentence; i++) {
            if (sentence.size() < searchWord.size())
                continue;
            int j = 0;
            for (; j < searchWord.size(); j++) {
                if (searchWord[j] == sentence[j]) 
                    continue;
                else
                    break;
            }
            if (j == searchWord.size() && ans == -1) {
                ans = i;
            }
        }
        return ans;
    }
};