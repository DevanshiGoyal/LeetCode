class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // brute force approach 
        // generating all the subarrays 
        // then finding the product ---> and then updating the maxProd 

        // three loops ---> TC---> O(N^3) -> high  SC--->O(1) --->TLE
        // need to optimise --->O(N^2)
        int n = nums.size();
        int maxProd = INT_MIN ;
        for(int i = 0 ; i<n ; i++){
            int prod = 1;
            for(int j = i ; j<n ; j++){
                
                prod*= nums[j];
                maxProd = max(prod , maxProd);

            }
            
        }

        return maxProd ;
        
    }
};