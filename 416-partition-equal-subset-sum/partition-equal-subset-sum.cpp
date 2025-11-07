class Solution {
public:
    // space optimised
    //T(n): O(N * K)
    //S(n): O(K)
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<bool> prev(k + 1, false), curr(k + 1, false);
        prev[0] = true;
    
        if (arr[0] <= k)
            prev[arr[0]] = true;
    
        for (int i = 1; i < n; i++) {
            curr[0] = true;
            for (int target = 1; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (arr[i] <= target)
                    take = prev[target - arr[i]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
    
        return prev[k];
    
    }
    // tc---> O(n) 
    bool canPartition(vector<int>& nums) {
        int totSum = 0 ;
        int n = nums.size() ;
        for(int i = 0 ; i<nums.size() ; i++){
            totSum+= nums[i] ;

        }
        if(totSum % 2 !=0) return false ;
        
        int target = totSum / 2 ;

        return checkSubsequenceSum(n , nums , target) ;



        
    }
};