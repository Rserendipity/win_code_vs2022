class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        //考虑n、m、q同阶的做法，不然很水.
        //考虑对度数种类的根号分治.即无向图本质不同的度数只有根号个,这是容易证明的.
        int m = edges.size();
        vector<int> de(n+1);
        unordered_map<int,int> mp;
        for(auto & x:edges)
        {
            de[x[0]]++;de[x[1]]++;
        }
        for(int i = 1;i<=n;i++) mp[de[i]]++;
        //注意到答案上界就是m.考虑d[u]+d[v] = i的点对数量.
        //虽然答案上界是m,但是暂存的数组是要2m的
        vector<int> ans(2*m+1);
        vector<pair<int,int>> freq(mp.begin(),mp.end());
        int sz = freq.size();
        for(int i = 0;i<sz;i++)
        {
            for(int j = 0;j<=i;j++)
            {
                if(j==i) ans[2*freq[i].first]+=(freq[i].second*(freq[i].second-1)/2);
                else ans[freq[i].first+freq[j].first]+=freq[i].second*freq[j].second;
            }
        }
        //考虑u、v之间的连边数,减去即可.由于umap不支持pair,所以压缩{u,v}为二进制数.
        unordered_map<int,int> egs;
        for(auto & x:edges)
        {
            int u = x[0],v = x[1];
            if(u>v) swap(u,v);
            egs[u*(n+1)+v]++;
        }
        for(auto & [k,cc]:egs)
        {
            int u = k/(n+1),v = k%(n+1);
            ans[de[u]+de[v]]--;//去掉这组点对,把它放到自己该放的地方喵
            ans[de[u]+de[v]-cc]++;
        }
        //原地做一次前缀和.
        for(int i = 1;i<=2*m;i++) ans[i]+=ans[i-1];
        int qsz = queries.size();
        vector<int> res(qsz);
        for(int i = 0;i<qsz;i++) res[i] = (n*(n-1)/2 - ans[queries[i]]);
        return res; 
    }
};