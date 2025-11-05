class Solution {
public:
    // Recursivee approach ---> TLE
    
    //Time Complexity: O(2^(m+n))
    //Exponential — exploring all possible paths recursively
    //Space Complexity: O(m + n)
    //Recursion stack depth up to m + n
    int minCost(vector<vector<int>> &cost,int m, int n) { 
        if (n <0 || m <0) 
            return INT_MAX; 
        else if(m==0 && n==0) 
            return cost[m][n]; 
        
        return cost[m][n]+min(minCost(cost,m-1,n),minCost(cost,m,n-1)); 
    } 

    // Memoization
    //tc : O(n·m), Space: O(n·m + (n+m))
    int memoization(vector<vector<int>> &cost,int m, int n , vector<vector<int>>& dp){
        if (n <0 || m <0) 
            return INT_MAX; 
        else if(m==0 && n==0) 
            return cost[m][n]; 

            if(dp[m][n] != -1) return dp[m][n] ;
        
        return dp[m][n] = cost[m][n]+min(memoization(cost,m-1,n , dp),memoization(cost,m,n-1 , dp)); 

    }

    //Tc: O(n*m)
    //Sc: O(n*m)

    int  tabulation(vector<vector<int>> &cost,int m, int n , vector<vector<int>>& dp){

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == 0 && j == 0) dp[i][j] =cost[i][j] ;
                else{
                    int up = INT_MAX , left = INT_MAX ;
                    if(i>0) up = dp[i-1][j] ;
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = cost[i][j] + min(up  , left);
                    
                }
            }
        }
        return dp[m-1][n-1];
    }

    // tc---> O(n*m)
    // sc---O(n)

    int spaceopt(vector<vector<int>> &cost , int n, int m ){

        // Create 1D vector for previous row
        vector<int> prev(m, 0);
    
        // Loop through each row
        for (int i = 0; i < n; i++) {
        
            // Create curr vector for current row
            vector<int> curr(m, 0);
        
            // Loop through each column
            for (int j = 0; j < m; j++) {
            
                // If at the start cell
                if (i == 0 && j == 0)
                    curr[j] = cost[i][j];
                else {
                    
                    // Take up direction if valid
                    int up = cost[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;
                    
                    // Take left direction if valid
                    int left = cost[i][j];
                    if (j > 0)
                        left += curr[j - 1];
                    else
                        left += 1e9;
                    
                    // Take minimum of both directions
                    curr[j] = min(up, left);
                }
            }
    
            // Move current row to previous
            prev = curr;
        }
    
        // Return result at destination
        return prev[m - 1];

    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        //return minCost(grid,m-1,n-1);
        vector<vector<int>> dp(m , vector<int> (n , -1));
        //return memoization(grid,m-1,n-1 , dp);
        return tabulation(grid,m , n , dp);
        return spaceopt(grid  , m , n);
        
    }
};