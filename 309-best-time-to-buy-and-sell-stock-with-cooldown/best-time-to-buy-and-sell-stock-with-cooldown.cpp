class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {

            dp[ind][1] = max(
                dp[ind + 1][1],
                -prices[ind] + dp[ind + 1][0]
            );

            dp[ind][0] = max(
                dp[ind + 1][0],
                prices[ind] + dp[ind + 2][1]
            );
        }

        return dp[0][1];
    }
};

/*
Time Complexity: O(N * 2)
Reason: We iterate through N indices and 2 buy states.

Space Complexity: O(N * 2)
Reason: DP table of size (N+2) x 2.
*/