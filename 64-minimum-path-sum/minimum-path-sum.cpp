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

    

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        //return minCost(grid,m-1,n-1);
        vector<vector<int>> dp(m , vector<int> (n , -1));
        return memoization(grid,m-1,n-1 , dp);
        
    }
};