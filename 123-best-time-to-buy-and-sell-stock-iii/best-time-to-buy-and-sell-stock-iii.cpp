class Solution {
public:
    int recursion(int ind , int buy , int cap, vector<int>& prices, vector<vector<vector<int>>>& memo){
        int n = prices.size();
        // base cases
        if(cap==0) return 0 ;
        if(ind == n) return 0 ;
        if(memo[ind][buy][cap] != -1) return  memo[ind][buy][cap];
        int profit = 0;
        if(buy){
            profit =  max(-prices[ind] + recursion(ind+1 , 0 , cap , prices, memo) , 0 + recursion(ind+1 , 1 , cap,prices , memo ));
        }else{
            profit =  max(prices[ind] + recursion(ind+1 , 1 , cap-1 , prices, memo) , 0 + recursion(ind+1 , 0 , cap, prices, memo ));
        }
        return memo[ind][buy][cap] = profit ;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n , vector<vector<int>>(2, vector<int>(3,-1)));  //size [n][2][3]
        return recursion(0 , 1 , 2 , prices , memo);
        
    }
};
/*
Time Complexity: O(N*2*3) , There are N*2*3 states therefore at max ‘N*2*3’ new problems will be solved.

Space Complexity: O(N*2*3) + O(N) , We are using a recursion stack space(O(N)) and a 3D array ( O(N*2*3)).
*/