class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l = 0 , r = 0 ;
        int zc= 0 ;
        int maxlen = 0 ;

        while(r<nums.size()){
            if(nums[r] == 0){
                zc++ ;
            }

            while(zc>k){
                if(nums[l]==0){
                    zc--;
                }
                l++;
            }
            maxlen = max(maxlen , r-l+1) ;
            r++ ;
            

            
        }
        
        return maxlen ;
        

        
    }
};