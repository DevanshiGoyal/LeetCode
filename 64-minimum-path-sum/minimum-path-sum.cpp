class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // space optimised approach 
        
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);

        // initialize first cell
        dp[0] = grid[0][0];

        // first row
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        // remaining rows
        for (int i = 1; i < m; i++) {
            // first column
            dp[0] += grid[i][0];

            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};
