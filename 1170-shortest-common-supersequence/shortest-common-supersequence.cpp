class Solution {
public:
    //T.C : O(m*n)
    //S.C : O(m*n)
    string shortestCommonSupersequence(string str1, string str2) {
        
        int m = str1.size(), n = str2.size();
        //  DP table to store len of longest common subsequences
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // fill DP table
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if( i==0 || j==0)  dp[i][j] = i+j;
                else if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1] ;
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // build the shortest common supersequence from  DP table
        string scs="";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs.push_back(str1[i - 1]);
                i--;
                j--;
            } else{ 
                if (dp[i - 1][j] < dp[i][j - 1]) { // moves toward shorter 
                    scs.push_back(str1[i - 1]);
                    i--;
                } else {
                    scs.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        //add remaining characters from both str1 and str2

        while (i > 0) {
            scs.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            scs.push_back(str2[j - 1]);
            j--;
        }

        // Reverse the  string since we built it from  end
        reverse(scs.begin(), scs.end());
        return scs;
    }
};