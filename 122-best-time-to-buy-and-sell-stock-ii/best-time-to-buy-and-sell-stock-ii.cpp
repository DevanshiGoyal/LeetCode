class Solution {
public:
// memoization
    int dp_mem(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if(i == n) return 0;  // Base case: no more days
        
        if(dp[i][buy] != -1) return dp[i][buy];  // Already computed
        
        int profit = 0;
        if(buy) {
            // Can buy: choose between buying today or skipping
            // if bought -> sell(1) , else buy again (0)
            profit = max(-prices[i] + dp_mem(i+1, 0, prices, dp), 
                        dp_mem(i+1, 1, prices, dp));
        } else {
            // Can sell: choose between selling today or skipping  
            // if sold -> buy(1) , else sell again(0)
            profit = max(prices[i] + dp_mem(i+1, 1, prices, dp),
                        dp_mem(i+1, 0, prices, dp));
        }
        
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp(n , vector<int>(2, -1)) ;
        return dp_mem(0 , 1 , prices , dp) ;
        
    }
};
/*
Time Complexity: O(N*2). There are N*2 states therefore at max ‘N*2’ new problems will be solved and we are running a for loop for ‘N’ times to calculate the total sum

Space Complexity: O(N*2) + O(N). We are using a recursion stack space(O(N)) and a 2D array ( O(N*2)).
*/
