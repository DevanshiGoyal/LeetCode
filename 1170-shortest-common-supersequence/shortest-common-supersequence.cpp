class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int m = str1.size(), n = str2.size();
        // Create a DP table to store lengths of longest common subsequences.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Reconstruct the shortest common supersequence from the DP table
        string scs;
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs.push_back(str1[i - 1]);
                i--;
            } else {
                scs.push_back(str2[j - 1]);
                j--;
            }
        }

        // Add remaining characters of str1 and str2
        while (i > 0) {
            scs.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            scs.push_back(str2[j - 1]);
            j--;
        }

        // Reverse the constructed string since we've built it from the end
        reverse(scs.begin(), scs.end());
        return scs;
    }
};