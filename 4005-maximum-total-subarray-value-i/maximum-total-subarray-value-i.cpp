class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX, maxi = INT_MIN;
        for (int x : nums) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }
        return (long long)(maxi - mini) * k;
    }
};
//tc O(n)     sc O(1)