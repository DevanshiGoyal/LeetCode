class Solution {
public:
    // using recursion TLE
    // now memoization
    vector<int> dp;
    int solve(vector<int>& nums , int i){
        if(i>=nums.size()) return 0 ;
        if (dp[i] != -1) return dp[i];
        
        int steal = nums[i]+solve(nums , i+2);
        int skip = solve(nums, i+1);

        

        return dp[i] = max(steal , skip);
    }
    int rob(vector<int>& nums) {
    
        int n = nums.size();  
        dp.resize(n , -1)  ; 
        return solve(nums,0);
        
    }
};
/*
Time: O(n)
Space: O(n) — dp array + recursion stack
*/