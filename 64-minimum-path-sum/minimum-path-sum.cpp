class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<vector<int>>& grid , int i , int j, int m , int n ){
        if(i>=m || j>=n) return INT_MAX ;

        if(i==m-1 && j == n-1) return grid[i][j]; 
        if (dp[i][j] != -1) return dp[i][j];
        int down = rec(grid ,i+1 , j , m , n) ;
        int right = rec(grid , i , j+1 , m, n);

        return dp[i][j] = grid[i][j] + min(down , right);

        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.resize(m, vector<int>(n, -1));

        return rec(grid,0,0 , m , n);
        
    }
};