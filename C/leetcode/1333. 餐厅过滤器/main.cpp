class Solution
{
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        vector<int> result;
        sort(restaurants.begin(), restaurants.end(), [](vector<int> &v1, vector<int> &v2)
             {
            if (v1[1] == v2[1]) {
                return v1[0] > v2[0];
            } else {
                return v1[1] > v2[1];
            } });
        for (auto &v : restaurants)
        {
            if (veganFriendly == 1 && v[2] == 0)
            {
                continue;
            }
            if (maxPrice >= v[3] && maxDistance >= v[4])
            {
                result.push_back(v[0]);
            }
        }
        return result;
    }
};