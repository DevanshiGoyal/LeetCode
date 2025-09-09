class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int prod = 1 , maxprod = INT_MIN ;
        int n = nums.size();

        for (int i = 0; i < n ; i++) {
            prod = prod * nums[i];
            maxprod = max(maxprod , prod);

            if (prod==0){
                prod=1;
            }

        }

        prod = 1;

        for (int i = n - 1; i >= 0; i--) {
            prod = prod * nums[i];
            maxprod = max(maxprod , prod);
            if(prod == 0) {
                prod = 1;
            }      
        }
  

        return maxprod ;
        
    }
};