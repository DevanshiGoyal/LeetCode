class Solution {
public:
    // shifting of index by 1 
    // space optimization 
    // tc--->O(n*m)
    // sc--->O(m)
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // base cases
        for (int i = 0; i <= n; i++) {
            prev[0] = 0;
        }

        // fill in the DP table to calc the length of LCS
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    curr[ind2] = 1 + prev[ind2 - 1]; // Characters match, increment LCS length
                else
                    curr[ind2] = max(prev[ind2], curr[ind2 - 1]); // Characters don't match
            }
            prev = curr ;
        }

        return prev[m]; // Return the length of the Longest Common Subsequence
            
    }
};