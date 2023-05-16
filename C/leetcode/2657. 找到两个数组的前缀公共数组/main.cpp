class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int hashA[51] = {0};
        int hashB[51] = {0};
        vector<int> ans;
        for (int i = 0; i < A.size(); i++) {
            int cnt = 0;
            hashA[A[i]] = 1;
            hashB[B[i]] = 1;
            for (int j = 0; j < 51; j++)
                if (hashA[j] == 1 && hashB[j] == 1)
                    cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};