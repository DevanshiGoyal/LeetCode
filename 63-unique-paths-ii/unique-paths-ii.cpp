class Solution {
public:
    //  Recursion---> TLE
    int  recursion(int i , int j , vector<vector<int>>& obstacleGrid){
        // base condition 
        
        if (i < 0 || j < 0) {
            return 0;
        }

        if(obstacleGrid[i][j] == 1) return 0 ;

        if (i == 0 && j == 0) {
            return 1;
        }
        

        int up = recursion(i-1 , j ,obstacleGrid );
        int left = recursion(i, j-1 ,obstacleGrid);

        return up + left ;

    }

    // Memoization 
    int  memoization(int i , int j , vector<vector<int>>& obstacleGrid , vector<vector<int>> &dp){
        // base condition 
        
        if (i < 0 || j < 0) {
            return 0;
        }

        if(obstacleGrid[i][j] == 1) {
            dp[i][j] = 0 ;
            return 0 ;
        }

        if (i == 0 && j == 0) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        

        int up = memoization(i-1 , j ,obstacleGrid , dp ) ;
        int left = memoization(i, j-1 ,obstacleGrid , dp);

        return dp[i][j] = up + left ;

    }

    // Tabulation
    int  tabulation(vector<vector<int>>& obstacleGrid , vector<vector<int>> &dp, int m , int n ){
        // base condition 

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0 ;
                }
                else if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else{
                    int up = 0 ; 
                    int left = 0 ;
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j > 0){
                        left = dp[i][j-1]; 
                    }
                    dp[i][j] = up + left;
        

                }
            }
        
        }
                
        return dp[m-1][n-1];

    } 

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m , vector<int>(n , -1)) ;
        //return recursion(m-1 , n-1 , obstacleGrid );

        //return memoization(m-1 , n-1 , obstacleGrid , dp );

        return tabulation(obstacleGrid , dp  , m ,n);


        
    }
};
//Recursive Approach

//Time Complexity: O(2^(m+n))
//Exponential — exploring all possible paths recursively

//Space Complexity: O(m + n)
//Recursion stack depth up to m + n

 

//Memoization (memo)

//Tc: O(m * n)
//Each subproblem (i, j) is solved once

//Sc: O(m * n)
//DP table + recursion stack

//Tabulation 

//Time Complexity: O(m * n)
//Iterates over full DP table

//Space Complexity: O(m * n)
//Full DP table