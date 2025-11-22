class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

        // base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        // fill in the DP table to calc the length of LCS
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match
            }
        }

        return dp[n][m]; // return the length of the Longest Common Subsequence
            
    }


    int minDistance(string word1, string word2){
        int n = word1.length() ;
        int m = word2.length() ;
        //int deletion = word1.length()-longestCommonSubsequence(word1 , word2);
        //int insertion = word2.length()-longestCommonSubsequence(word1 , word2);
        //return deletion+insertion;

        return n + m - 2 * longestCommonSubsequence(word1 , word2);
        
    }
};
