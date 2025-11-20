class Solution {
public:
    // Recursion ---> TLE 
    // Memoization 
    int lcsUtil(string& s1, string& s2, int ind1, int ind2 , vector<vector<int>> &dp) {
    // Base case 
    // index become -ve , return 0
    if (ind1 < 0 || ind2 < 0)
        return 0;

    //  if result for this pair of indices is already calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // If the char at the current indices *match*, increment the LCS length
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] =  1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1 , dp);
    else
        // If the characters don't match
        // then 2 condition ---> (ind1-1 , ind2 ) and  (ind1 , ind2 -1 )
        return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1, ind2 - 1 , dp), lcsUtil(s1, s2, ind1 - 1, ind2 , dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size() , n=text2.size();
        vector<vector<int>> dp(m , vector<int>(n , -1))  ;
        return lcsUtil(text1,text2,m-1,n-1 , dp );
        
        
    }
};