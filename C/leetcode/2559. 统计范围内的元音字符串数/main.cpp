class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int nw=words.size(),nq=queries.size();
        vector<int>ans(nq);
        vector<int>v(nw+1),w(26);
        w[0]=w['e'-'a']=w['i'-'a']=w['o'-'a']=w['u'-'a']=1;
        int sum=0,len;
        for(int i=0;i<nw;i++){
            len=words[i].size();
            if(w[words[i][0]-'a'] && w[words[i][len-1]-'a']){
                sum++;
            }
            v[i+1]=sum;
        }
        for(int i=0;i<nq;i++){
            ans[i]=v[queries[i][1]+1]-v[queries[i][0]];
        }
        return ans;
    }
};