class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // 1. Find the maximum cost to define the range
        int max_cost = 0;
        for (int cost : costs) {
            if (cost > max_cost) max_cost = cost;
        }
        
        // 2. Create frequency array (Counting Sort)
        vector<int> counts(max_cost + 1, 0);
        for (int cost : costs) {
            counts[cost]++;
        }
        
        int total_bars = 0;
        
        // 3. Greedily buy from cheapest to most expensive
        for (int price = 1; price <= max_cost; ++price) {
            if (counts[price] == 0) continue;
            
            // If we can't afford even one, we stop
            if (coins < price) break;
            
            // Buy as many as we can afford at this price
            int can_buy = min(counts[price], coins / price);
            
            // Update coins and total count
            coins -= (long long)can_buy * price;
            total_bars += can_buy;
        }
        
        return total_bars;
    }
};