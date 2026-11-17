class Solution {
public:
    const int INF = 1e9;

    // Precompute minimum cost of every substring
    vector<vector<int>> buildCost(string &s) {

        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int l = 0; l < n; l++) {

            for (int r = l + 1; r < n; r++) {

                int len = r - l + 1;

                // Try every proper divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0) continue;

                    int changes = 0;
                    int groupLen = len / d;

                    // Check every group
                    for (int offset = 0; offset < d; offset++) {

                        int left = l + offset;
                        int right = left + (groupLen - 1) * d;

                        // Check palindrome condition
                        while (left < right) {

                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        return cost;
    }

    int dfs(int start, int parts,
            int n,
            vector<vector<int>> &cost,
            vector<vector<int>> &dp) {

        if (parts == 0) {
            return (start == n) ? 0 : INF;
        }

        if (n - start < 2 * parts) {
            return INF;
        }

        if (dp[start][parts] != -1) {
            return dp[start][parts];
        }

        int ans = INF;

        // Leave at least 2 characters for every remaining part
        int maxEnd = n - 2 * (parts - 1) - 1;

        for (int end = start + 1; end <= maxEnd; end++) {

            int currentCost = cost[start][end];

            int remainingCost = dfs(end + 1, parts - 1, n, cost,  dp);

            if (remainingCost != INF) {
                ans = min(ans, currentCost + remainingCost);
            }
        }

        return dp[start][parts] = ans;
    }

    int minimumChanges(string s, int k) {

        int n = s.size();        
        vector<vector<int>> cost = buildCost(s);

        vector<vector<int>> dp(
            n + 1,
            vector<int>(k + 1, -1)
        );
        return dfs(0, k, n, cost, dp);
    }
};