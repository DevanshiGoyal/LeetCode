class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // using two pointer method 
        int n = nums.size();
        int lp = 1, rp = 1;
        int res = nums[0];

        for (int i = 0; i < n; i++) {
            lp = lp == 0 ? 1 : lp;
            rp = rp == 0 ? 1 : rp;

            lp *= nums[i];
            rp *= nums[n - 1 - i];

            res = max(res, max(lp, rp));
        }

        return res;
        
    }
};