class Solution {
public:
//Approach-3 (Space Optimized Bottom Up - Converting Approach-2)
    int rob(vector<int>& nums) {
        int n = nums.size();
        // no house : i=0
        int prev2 = 0;

        // 1 house ; i=1
        int prev1 = nums[0];
        

        for(int i = 2 ; i<=n ; i++){
            int steal = nums[i-1] + prev2;
            int skip = prev1;

            int curr = max(steal , skip);

            prev2 = prev1 ;
            prev1 = curr ;
        }

        return prev1 ;
        
    }
};