class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // brute force approach 
        // will take all subarrays 
        // try to find prod and then update max prod 

        int n = nums.size() ;
        int maxprod = INT_MIN ;
        for(int i = 0 ; i<n ; i++){
            int prod = 1 ;
            for(int j = i ; j<n ; j++){
                prod = prod*nums[j] ;
                maxprod = max(prod , maxprod) ;
                
            }

        }

        return maxprod ;
        
    }
};