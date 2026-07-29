class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp ;

        int size = nums.size();
         for(int i = 0 ; i<size ; i++){
            int complement = target - nums[i];
            if(mp.count(complement)){
                return{mp[complement] , i};
            }
            mp[nums[i]] = i ;
         }
         return{};


        
    }
};