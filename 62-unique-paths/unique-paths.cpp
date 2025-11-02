class Solution {
public:
    // using recursion
    // TLE
    // TC--> O(2^(m+n))
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
    // Tabulation 
    // stack Optimisation
    int tabulation(int m , int n , vector<vector<int>> &dp ){

        // TC : O(M * N)
        // SC : O(M * N)
        
        for(int  i = 0 ; i< m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(i == 0  && j == 0) dp[i][j] = 1;
                else{

                    int up = 0, left = 0;
                    if (i > 0) up = dp[i - 1][j];
                    if (j > 0) left = dp[i][j - 1];
                    dp[i][j] = up + left;

                }
            }
        }
        
        return dp[m - 1][n - 1];

    }

    int tabulationSpaceOptimized(int m, int n) { 
        // TC : O(M * N)
        // SC : O(N)
        vector<int> prev(n , 0); //Prev row of size number of columns
        for (int i = 0; i < m; i++) {
            vector<int> curr(n , 0); // current row 
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) curr[j] = 1;
                else {
                    int up = 0, left = 0;
                    if (i > 0) up = prev[j];
                    if (j > 0) left = curr[j - 1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n - 1];

    }

    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m , vector<int>(n , -1)) ;
        //return recursion(m-1 , n-1) ;
        
        //return memoization(m - 1, n - 1, dp);
        //return tabulation(m, n, dp);
        return tabulationSpaceOptimized(m, n);
        
    }
};