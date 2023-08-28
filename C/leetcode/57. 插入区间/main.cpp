class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        vector<int> begin, end;
        for (auto& v : intervals) {
            begin.push_back(v[0]);
            end.push_back(v[1]);
        }
        sort(begin.begin(), begin.end());
        sort(end.begin(), end.end());
        int n = intervals.size();
        for(int i =0, j = 0; i< n; i++) {
            if(i == n-1 || begin[i + 1] > end[i]) {
                result.push_back({begin[j], end[i]});
                j = i + 1;
            }
        }

        return result;
    }
};