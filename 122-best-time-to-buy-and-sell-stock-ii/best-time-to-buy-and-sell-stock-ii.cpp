class Solution {
public:
// tabulation(bottom - up)
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<long> ahead(2, 0);
        vector<long> curr(2, 0);
        // Base condition: When there are no stocks left, the profit is 0.
        ahead[0] = ahead[1] = 0;
        
        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy < 2; buy++) {
                int profit = 0;
                if(buy == 1) {  // Buy state
                    profit = max(-prices[ind] + ahead[0], 0+ ahead[1]);
                } else {  // Sell state
                    profit = max(prices[ind] + ahead[1], 0+ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        
        return ahead[1];  
            
    }
};
/*
Time Complexity: O(N*2). Reason: There are two nested loops that account for O(N*2) complexity

Space Complexity: O(1). Reason: We are using an external array of size ‘2’.
*/
