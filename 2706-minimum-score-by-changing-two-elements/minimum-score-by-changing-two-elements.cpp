class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size()-1;
        int ans = INT_MAX;
        ans = min(ans , nums[n-1]-nums[1]);
        ans = min(ans, nums[n]-nums[2]);
        ans = min(ans, nums[n-2]-nums[0]);
        return ans;
    }
    
};