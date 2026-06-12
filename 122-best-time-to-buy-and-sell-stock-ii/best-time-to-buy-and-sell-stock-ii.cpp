class Solution {
public:
// tabulation(bottom - up)
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(2, 0)) ;
        // Base case: no profit after last day
        dp[n][0] = dp[n][1] = 0;
        
        // Fill table backwards
        for(int day = n-1; day >= 0; day--) {
            for(int state = 0; state < 2; state++) {
                int profit = 0;
                if(state == 1) {  // Buy state
                    profit = max(-prices[day] + dp[day+1][0], dp[day+1][1]);
                } else {  // Sell state
                    profit = max(prices[day] + dp[day+1][1], dp[day+1][0]);
                }
                dp[day][state] = profit;
            }
        }
        
        return dp[0][1];  // Start in buy state
            
    }
};
/*
Time Complexity: O(N*2). Reason: There are two nested loops that account for O(N*2) complexity.

Space Complexity: O(N*2). We are using an external array of size ‘N*2’. Stack Space is eliminated.
*/
