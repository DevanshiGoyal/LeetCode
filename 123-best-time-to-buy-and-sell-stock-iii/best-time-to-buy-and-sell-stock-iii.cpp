class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for(int i = 0, n = prices.size(); i < n; ++i){
            const int p = prices[i];
            buy1 = max(buy1 , -p);
            sell1 = max(sell1 , p + buy1);
            buy2 = max(buy2 , sell1 - p);
            sell2 = max(sell2 , p + buy2);
        }
        return sell2;
    }
};