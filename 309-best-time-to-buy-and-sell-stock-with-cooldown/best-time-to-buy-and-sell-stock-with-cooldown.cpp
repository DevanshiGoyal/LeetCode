class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> front1(2, 0); // dp[ind+1]
        vector<int> front2(2, 0); // dp[ind+2]
        vector<int> curr(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {

            curr[1] = max(
                front1[1],
                -prices[ind] + front1[0]
            );

            curr[0] = max(
                front1[0],
                prices[ind] + front2[1]
            );

            front2 = front1;
            front1 = curr;
        }

        return front1[1];
    }
};

/*
Time Complexity: O(N * 2)
Reason: We process each day once.

Space Complexity: O(1)
Reason: Only three arrays of size 2 are used.
*/