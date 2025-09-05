class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using sliding window 
        int sum=0 ;
        int maxSum = INT_MIN;
        int len = 0;
        int start = 0;
        int n = nums.size() ;
        for(int i = 0 ; i<nums.size() ; i++){
            sum += nums[i];
            len++;
            if(len>0 && sum>maxSum) maxSum = sum ;

            while(sum<0){
                sum-=nums[start];
                start++;
                len--;
            }

            //if(len>0 && sum>maxSum) maxSum = sum ;
        }
        return maxSum ;
        
    }
};

//Time complexity:O(N)
//Space complexity:O(1)