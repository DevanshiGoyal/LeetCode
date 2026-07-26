class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        return max(nums.back() * nums[n - 2] * nums[n - 3], nums.back() * nums[0] * nums[1]);
    }
};
//O(nlogn)