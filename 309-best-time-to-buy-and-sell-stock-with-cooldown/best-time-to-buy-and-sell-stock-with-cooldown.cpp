class Solution {
public:
    int solve(int ind, int buy,
              vector<int>& prices,
              vector<vector<int>>& dp) {

        if (ind >= prices.size())
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy) {
            return dp[ind][buy] = max(
                solve(ind + 1, 1, prices, dp),
                -prices[ind] + solve(ind + 1, 0, prices, dp)
            );
        } else {
            return dp[ind][buy] = max(
                solve(ind + 1, 0, prices, dp),
                prices[ind] + solve(ind + 2, 1, prices, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, dp);
    }
};

/*
Time Complexity: O(N * 2)
Reason: There are N*2 states and each state is solved once.

Space Complexity: O(N * 2) + O(N)
Reason:
1. DP array uses O(N*2).
2. Recursion stack uses O(N).
*/