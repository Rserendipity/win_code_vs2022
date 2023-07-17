class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
            return lhs[1] - lhs[0] < rhs[1] - rhs[0];
        });

        vector<pair<int, int>> query;
        set<int> st;
        int n = queries.size();
        for (int i = 0; i < n; i++) {
            query.emplace_back(queries[i], i);
            st.insert(i);
        }
        sort(query.begin(), query.end());

        vector<int> res(n, -1);
        for (const auto& inter : intervals) {
            int L = inter[0], R = inter[1];
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (query[mid].first >= L) r = mid;
                else l = mid + 1;
            }
            if (query[r].first < L) continue;
            for (auto itr = st.lower_bound(r); itr != st.end() and query[*itr].first <= R; itr = st.erase(itr)) {
                res[query[*itr].second] = R - L + 1;
            }
        }

        return res;
    }
};