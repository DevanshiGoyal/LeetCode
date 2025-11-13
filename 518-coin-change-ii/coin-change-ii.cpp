class Solution {
public:
    int minCoins(int  ind , int target , vector<int>& coins , vector<vector<int>> &dp){
        // base condition
        if( ind == 0 ){
            if(target % coins[0] == 0) return 1 ;
            else return 0 ;
        }
        if(dp[ind][target] != -1) return dp[ind][target] ;

        // for infinite supply / multiple use 
        // pick will stand on the same ind 
        int notPick = minCoins(ind-1 , target , coins  , dp);
        int pick = 0 ;
        if(coins[ind] <= target) pick = minCoins(ind , target - coins[ind] , coins , dp) ;

        return dp[ind][target] = pick + notPick ;

    }

    int change(int amount, vector<int>& coins) {
        

        int n = coins.size() ;
        vector<vector<int>> dp(n , vector<int>(amount + 1 , -1)) ;

        int ans = minCoins(n - 1, amount, coins , dp);
        
        
        return ans;

    
    }
};