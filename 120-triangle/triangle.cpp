class Solution {
public:
    // recursive approach ---> TLE
    // tc ---> exponential
    // tc--- 2^(1+2+3+----+n) 
    // sc-->O(n)
    int recursion(int i , int  j , int n , vector<vector<int>>& triangle){
        //base condition ---> destination
        if(i == n-1) return triangle[n-1][j];

        int down = triangle[i][j] + recursion(i+1 , j , n , triangle);
        int diag = triangle[i][j] + recursion(i+1 , j+1 , n , triangle);

        return min(down , diag);
    }
    // sice there are overlapping subproblems ---> going to optimise it 
    // memoization ----> tle
    // tc---> O(n*n)
    // sc---> O(n)(recursive stack space) + O(n*n) 
int memo(int i , int j , int  n , vector<vector<int>>& triangle , vector<vector<int>>& dp ){
    //base condition ---> destination
    if(i == n-1) return triangle[n-1][j];

    if(dp[i][j] != -1) return dp[i][j] ;

    int down = triangle[i][j] + memo(i+1 , j , n , triangle , dp);
    int diag = triangle[i][j] + memo(i+1 , j+1 , n , triangle, dp);

    return dp[i][j] = min(down , diag); 

}
    // to optimise further 
    // tabulation (opp of rec. --> n-1 ---> 0)
    //TC:O(n*n), SC:O(n*n)
    int tabulation(int n , vector<vector<int>>& triangle , vector<vector<int>>& dp ){
        //  base case
        for(int j = 0 ; j<n ; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for( int i = n-2 ; i>=0 ; i--){
            for(int j = 0 ; j<=i ; j++ ){
                // go directly down
                int down = triangle[i][j] + dp[i+1][j] ;
                // go diagonally down
                int diag = triangle[i][j] + dp[i+1][j+1] ;

                dp[i][j] = min(down , diag) ;

            }
        }
        return dp[0][0] ;
    }

    // space optimization 
    //  instead of storing the triangle we need to store two rows --> front and curr rows

        int spaceOpt(int n , vector<vector<int>>& triangle , vector<vector<int>>& dp ){
        //  base case
        vector<int> front(n , 0) ; 
        for(int j = 0 ; j<n ; j++){
            front[j] = triangle[n-1][j];
        }
        vector<int> curr(n , 0) ;
        for( int i = n-2 ; i>=0 ; i--){
            for(int j = 0 ; j<=i ; j++ ){
                // go directly down
                int down = triangle[i][j] + front[j] ;
                // go diagonally down
                int diag = triangle[i][j] + front[j+1] ;

                curr[j] = min(down , diag) ;

            }
            front = curr ;
        }
        return front[0] ;
    }
    // tc--> O(n*n)
    //sc--> O(n)



    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp( n , vector<int>(n , -1));
        //return recursion( 0 , 0 , n , triangle)  ;  
        //return memo( 0 , 0 , n , triangle , dp)  ; 
        //return tabulation( n , triangle , dp)  ; 
        return spaceOpt( n , triangle , dp);


         
    }
};