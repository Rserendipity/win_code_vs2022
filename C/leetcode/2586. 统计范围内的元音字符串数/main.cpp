class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0,arr[26] = {0};
        arr['a'-'a']=arr['e'-'a']=arr['i'-'a']=arr['o'-'a']=arr['u'-'a'] = 1;
        for (int i = left; i <= right; i++) {
            if (arr[words[i].front() - 'a'] + arr[words[i].back() - 'a'] == 2)
                ans++;
        }
        return ans;
    }
};