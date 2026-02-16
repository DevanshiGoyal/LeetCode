class Solution {
public:
    vector<vector<int>> dp;
    int memo(int i , int j, int m , int n){
        // base cases

        // out of grid
        if(i>=m && j>=n) return 0 ;

        // reached destination
        if(i==m-1 || j==n-1) return 1 ;

        if(dp[i][j] != -1) return dp[i][j];

        int down = memo(i+1 , j , m , n) ;
        int right = memo(i , j+1 , m , n) ;

        return dp[i][j] = down + right ;
    }

    int uniquePaths(int m, int n) {
        dp.resize(m , vector<int>(n,-1));
        return memo(0 , 0 , m , n) ;

        //return recursion(0 , 0 , m , n) ;
        
    }
};

// TC--> O(m*n)
// SC--> O(m*n)