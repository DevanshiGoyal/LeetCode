class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return hp_finder(dungeon,n,m,0,0,dp);
    }

    int hp_finder(vector<vector<int>>&arr,int n,int m,int row,int col,vector<vector<int>>&dp){
        if(row==n-1 && col==m-1){
            return max(1,1-arr[row][col]);
        }

        if(row>=n || col>=m){
            return INT_MAX;
        }

        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        int right=hp_finder(arr,n,m,row,col+1,dp);
        int down=hp_finder(arr,n,m,row+1,col,dp);

        dp[row][col]=min(right,down)-arr[row][col];

        dp[row][col]=max(1,dp[row][col]);

        return dp[row][col];
    }
};