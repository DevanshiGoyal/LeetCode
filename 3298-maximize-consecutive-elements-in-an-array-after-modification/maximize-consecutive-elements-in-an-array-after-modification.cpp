
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {

            // Option 1 ---> increase curr ele by 1
            // Extend the sequence ending at x
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);

            // Option 2---> k eep curr ele unchanged
            // Extend the sequence ending at x - 1
            dp[x] = max(dp[x], dp[x - 1] + 1);

            ans = max(ans, max(dp[x], dp[x + 1]));
        }

        return ans;
    }
};
