class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), s=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int l=i+1, r=n-1;
            while(l < r){
                int t=nums[i]+nums[l]+nums[r];
                if(t == target)    return t;
                else if(t > target){
                    if(t-target < abs(s-target))
                        s = t;
                    r--;
                }else{
                    if(target-t < abs(s-target))
                        s = t;
                    l++;
                }
            }
        }
        return s;
    }
};