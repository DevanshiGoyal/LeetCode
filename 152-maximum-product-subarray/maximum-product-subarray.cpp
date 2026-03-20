class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // better approacj approach 
        /*
        I initialize max and min with first element

At each step, I decide whether to start fresh or extend

If number is negative, roles of max and min flip

Finally, I keep updating global answer
        */

        int n = nums.size() ;
        int maxProd = nums[0];   // max product till now
        int minProd = nums[0];   // min product till now
        int ans = nums[0];       // final answer
        
        for(int i = 1 ; i<n ; i++){
            // If current element is negative ->swap
            if(nums[i] < 0){
                swap(maxProd , minProd) ;
            }

            // either take current element OR extend subarray
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            

            ans = max(ans, maxProd);
        }

        return ans;
        
    }
};
/*
tc-->O(n)
sc-->o(n)
*/