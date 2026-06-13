class Solution {
public:
    int solve(int ind, int buy,
              vector<int>& prices,
              int fee,
              vector<vector<int>>& dp) {

        if (ind == prices.size())
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy) {
            return dp[ind][buy] = max(
                solve(ind + 1, 1, prices, fee, dp),
                -prices[ind] + solve(ind + 1, 0, prices, fee, dp)
            );
        } else {
            return dp[ind][buy] = max(
                solve(ind + 1, 0, prices, fee, dp),
                prices[ind] - fee + solve(ind + 1, 1, prices, fee, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, fee, dp);
    }
};

/*
Time Complexity: O(N * 2)
Reason: N*2 states, each solved once.

Space Complexity: O(N * 2) + O(N)
Reason:
1. DP table uses O(N*2).
2. Recursion stack uses O(N).
*/