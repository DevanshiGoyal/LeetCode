class Solution {
public:
    // using recursion
    // TLE
    //TC--> O(2^(m+n))
    int recursion(int i , int j){
        // base case 
        if(i == 0  && j == 0) return 1 ;
        if(i<0 || j<0) return 0 ;

        int up = recursion(i-1 , j);
        int left = recursion(i , j-1) ;

        return up + left ;

    }

    int memoization(int i , int j  , vector<vector<int>> &dp ){

        // TC : O(M * N)
        // SC : O((M - 1) + (N - 1)) + O(M * N)

        if(i == 0  && j == 0) return 1 ;
        if(i<0 || j<0) return 0 ;

        if(dp[i][j] != -1) return dp[i][j];

        int up = memoization(i-1 , j , dp );
        int left = memoization(i , j-1 , dp ) ;

        return dp[i][j] = up + left ;

    }


    int uniquePaths(int m, int n) {

        //return recursion(m-1 , n-1) ;
        vector<vector<int>>dp(m , vector<int>(n , -1)) ;
        return memoization(m - 1, n - 1, dp);
        
    }
};