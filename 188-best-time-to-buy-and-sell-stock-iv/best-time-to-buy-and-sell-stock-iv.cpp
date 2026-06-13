class Solution {
public:
    int solve(int ind, int buy, int cap,vector<int>& prices,vector<vector<vector<int>>>& dp) {

        if (ind == prices.size() || cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        if (buy) {
            return dp[ind][buy][cap] = max(solve(ind + 1, 1, cap, prices, dp),
                -prices[ind] + solve(ind + 1, 0, cap, prices, dp)
            );
        }
        else {
            return dp[ind][buy][cap] = max(solve(ind + 1, 0, cap, prices, dp),
                prices[ind] + solve(ind + 1, 1, cap - 1, prices, dp)
            );
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(k + 1, -1))
        );

        return solve(0, 1, k, prices, dp);
    }
};
/*
Time Complexity  O(N × 2 × K)

Space Complexity  DP array: O(N × 2 × K) + O(N) (recursion stack)
*/