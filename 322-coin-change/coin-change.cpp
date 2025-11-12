class Solution {
public:
    // recursion approach ---> TLE
    // counting coins 
    //Tc---> exponential --> ( >>O(2^n) )
    //SC---> (>>O(n))

    // optimization 
    //memoization 
    // tc --- > O(N*T) 
    // Sc --- > O(N*T) + O(N) 


    int minCoins(int  ind , int target , vector<int>& coins , vector<vector<int>> &dp){
        // base condition
        if( ind == 0 ){
            if(target % coins[ind] == 0) return target / coins[ind] ;
            else return 1e9 ;
        }
        if(dp[ind][target] != -1) return dp[ind][target] ;

        // for infinite supply / multiple use 
        // pick will stand on the same ind 
        int notPick = 0 + minCoins(ind-1 , target , coins  , dp);
        int pick = INT_MAX ;
        if(coins[ind] <= target) pick = 1 + minCoins(ind , target - coins[ind] , coins , dp) ;

        return dp[ind][target] = min(pick , notPick) ;

    }

    // space optimisation 
     // tc---> O(N*amount)
     //sc--> O(amount)
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size() ;
        vector<int> prev(amount+1 , 0) , curr(amount + 1 , 0) ;

        for(int T = 0 ; T<=amount ; T++){
            if(T % coins[0] == 0) prev[T] =  T/coins[0] ;
            else prev[T] = 1e9;
        }

        for(int ind = 1 ; ind < n ; ind++){
            for(int T = 0 ; T <=amount ; T++){

                int notPick = 0 + prev[T] ;
                int pick = INT_MAX ;
                if(coins[ind] <= T) pick = 1 + curr[T - coins[ind]] ;

                curr[T] = min(pick , notPick) ;

            }
            prev = curr ;
        }

        
        //int ans = minCoins(n - 1, amount, coins , dp);
        int ans = prev[amount] ;
        if (ans >= 1e9) return -1;  // convert "impossible" to -1
        return ans;
        
    }
};