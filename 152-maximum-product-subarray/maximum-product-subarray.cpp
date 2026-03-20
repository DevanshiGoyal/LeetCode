class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //optimised appproach
        // based on observation 
        // all positive ---> then take all array 
        // even negatives --> then also take whole array 
        // odd negatives ---> remove one negative values ----> prefix and suufix prod 
        // using prefix and suffix product
        // TC--->O(N)  SC--->O(1)

        int n = nums.size();
        int pref = 1 , suff = 1 ;
        int ans = INT_MIN ;

        for(int i = 0 ; i<n ; i++){
            //Reset prefix and suffix to 1 if they become 0 (cases where product of  subarray becomes 0)
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;

            pref = pref*nums[i] ;
            suff = suff * nums[n-i-1] ;

            ans = max(ans , max(pref , suff));

        }
        return ans ;
        
    }
};