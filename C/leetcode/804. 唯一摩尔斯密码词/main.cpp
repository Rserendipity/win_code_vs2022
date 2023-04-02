class Solution {
    const string alphe[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> hash;
        for (auto& s : words) {
            string tmp;
            for (char ch: s) {
                tmp += alphe[ch - 'a'];
            }
            hash.insert(tmp);
        }
        return hash.size();
    }
};