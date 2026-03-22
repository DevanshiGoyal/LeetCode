class Solution {
public:
    // using recursion -->TLE
    //Memoization -->tle
    // overlapping subproblems
    // Bottom up approach 
    // space optimised 1D optimised 
    // TC---> O((m*n))  SC-->O(n) 
    
    int longestCommonSubsequence(string s1, string s2) {
       
        int  m = s1.length() ;
        int n = s2.length() ;

        vector<int>dp(n+1,0) ;

        for(int i = 1 ; i<m+1 ; i++){
            int prevdiag = 0 ;
            for(int j =1 ;j<n+1 ; j++){
                int temp = dp[j] ;
                if(s1[i-1]==s2[j-1]){
                    dp[j] = 1+ prevdiag ;
                }
                else{
                    dp[j] = max(dp[j-1] , dp[j]) ;
                }
                prevdiag = temp ;
            }
        }
        return dp[n];
        
    }
};