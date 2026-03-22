class Solution {
public:
    // using recursion -->TLE
    //Memoization -->tle
    // overlapping subproblems
    // Bottom up approach 
    // TC---> O((m*n))  SC-->O(m*n) 
    
    int longestCommonSubsequence(string s1, string s2) {
       
        int  m = s1.length() ;
        int n = s2.length() ;

        vector<vector<int>>dp(m+1 , vector<int>(n+1)) ;
        
        for(int r = 0 ; r<m+1 ; r++){
            dp[r][0] = 0 ;
        }
        for(int c = 0 ; c<n+1 ; c++){
            dp[0][c] = 0 ;
        }

        for(int i = 1 ; i<m+1 ; i++){
            for(int j =1 ;j<n+1 ; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1] ;
                }
                else{
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]) ;
                }

            }
        }
        string lcs ="";
        int i = m , j= n ;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                lcs.push_back(s1[i-1]);
                i-- , j-- ;

            }
            else{
                if(dp[i-1][j]> dp[i][j-1]){
                    i--;
                }else j--;
            }
        }
        reverse(lcs.begin() , lcs.end());
        cout<<lcs<<endl;
        return dp[m][n];


        
    }
};