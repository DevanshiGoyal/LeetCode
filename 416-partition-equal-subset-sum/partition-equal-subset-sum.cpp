class Solution {
public:
    bool recursion(int ind , int target , vector<int>&nums , vector<vector<int>>& dp){
        if(target==0) return true ;

        if(ind==0) return nums[0] == target;

        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = recursion(ind-1 , target , nums , dp);
        bool take = false ;
        if(nums[ind] <= target){
            take = recursion(ind-1 , target-nums[ind] , nums , dp);
        }

        return dp[ind][target] = notTake || take ;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0 ;
        
        for(int i = 0 ; i<n ; i++){
            sum+=nums[i];
        }

        
        if(sum%2 == 1) return false ;
        else{
            int target = sum/2 ;
            vector<vector<int>> dp (n , vector<int>(target+1 , -1));
        
            return recursion(n-1 , target , nums , dp);
    
        }
        
        
    }
};