class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        // brute force approach 
        int n = nums.size();
        long long ans = 0 ;
        for(int i = 0 ; i<n ; i++){
            int targetcount = 0;
            for(int j = i ; j<n ; j++){
                if(nums[j]== target){
                    targetcount++;
                }

                int len = j-i+1;

                if(targetcount>len/2){
                    ans++;
                }
            }

        }
        return ans ;
        
    }
};

// tc-->O(n^2)    sc --->O(1)