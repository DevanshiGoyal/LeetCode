class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        // using hash map ;
        int n = nums.size() ;
        unordered_map<int , int> mpp ;
        for(int i = 0 ; i<n ; i++){
            mpp[nums[i]]++ ;
            

        }
        for(int i = 0 ; i<n ; i++){
            if(nums[i]%2==0 && mpp[nums[i]]==1)return nums[i];
        }

        return -1 ;
        
    }
};