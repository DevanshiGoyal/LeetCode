class Solution {
public:

    vector<vector<int>> dp;

    int recursion(int i , int j ,vector<vector<int>>& triangle,int m,int n){
        
        if(i>=m) return 0 ;
        if(j>i) return 0 ;
       

        //memoization
        if(dp[i][j] != INT_MAX) return dp[i][j] ;

        int down = triangle[i][j] + recursion(i+1 , j , triangle , m , n);
        int diagonal = triangle[i][j] + recursion(i+1 , j+1 , triangle , m , n);

        return dp[i][j] = min(down , diagonal);

    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        int maxCols = triangle[m-1].size();

        dp.resize(m , vector<int>(maxCols,INT_MAX));

        return recursion(0, 0, triangle, m , maxCols);
       

        
    }
};