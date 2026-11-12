//approach 2 comparing the adjacent ele in array
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc_len=1;
        int dec_len=1,inc_mx=1,dec_mx=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                inc_mx++;
            }
            else{
                inc_len=max(inc_len,inc_mx);
                inc_mx=1;
            }
            if(nums[i-1]>nums[i]){
                dec_mx++;
            }
            else{
                dec_len=max(dec_len,dec_mx);
                dec_mx=1;
            }
        }
        
        inc_len=max(inc_len,inc_mx);
        dec_len=max(dec_len,dec_mx);
        
        return max(inc_len,dec_len);
    }
};