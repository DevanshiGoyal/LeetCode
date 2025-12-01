class Solution {
private:
    // memoization
    
    // Helper function to find the length of LIS
    int func(int i, int prevInd, vector<int> &arr, vector<vector<int>> &dp) {
        
        // base case
        if(i == arr.size() - 1) {
            if(prevInd == -1 || arr[prevInd] < arr[i]) return 1;
            return 0;
        }
        
        // If subproblem is already calculated
        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];
        
        // Not Take case
        int notTake = func(i+1, prevInd, arr, dp);
        
        int take = 0; // Take case
        
        // If no element is chosen till now
        if(prevInd == -1)
            take = func(i+1, i, arr, dp) + 1;
        
        /* Else the current element can be 
        taken if it is strictly increasing */
        else if(arr[i] > arr[prevInd])
            take = func(i+1, i, arr, dp) + 1;
        
        // Return the maximum length obtained from both cases
        return dp[i][prevInd + 1] = max(take, notTake);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        // DP array
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return func(0, -1, nums, dp);
        
    }
};