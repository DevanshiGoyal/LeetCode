class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int gcdv = nums[i], lcmv = nums[i];
            long prod = 1;
            for (int j = i; j < n && prod <= INT_MAX; j++) {
                gcdv = __gcd(gcdv, nums[j]);
                lcmv = lcm(lcmv, nums[j]);
                prod *= nums[j];
                if (prod == lcmv * gcdv)
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
    
};