class Solution {
public:
// tabulation(bottom - up)
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
    
        // Only need previous day's values
        int prevBuy = 0;   // Previous day's buy state profit
        int prevSell = 0;  // Previous day's sell state profit
        
        for(int day = n-1; day >= 0; day--) {
            int currBuy = max(-prices[day] + prevSell, prevBuy);
            int currSell = max(prices[day] + prevBuy, prevSell);
            
            prevBuy = currBuy;
            prevSell = currSell;
        }
        
        return prevBuy;  // Return profit starting in buy state
    }
};
/*
Time Complexity: O(N)

Space Complexity: O(1)
*/
