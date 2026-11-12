//approach 1: Brute Force
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc_ans=0,inc_dec=0;
        for(int i=0;i<nums.size();i++){
            int mx=1;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j-1]<nums[j])mx++;
                else break;
            }
            inc_ans=max(mx,inc_ans);
        }

        for(int i=0;i<nums.size()-1;i++){
            int mx=1;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j-1]>nums[j])mx++;
                else break;
            }
            inc_dec=max(mx,inc_dec);
        }
        return max(inc_ans,inc_dec);
    }
};


