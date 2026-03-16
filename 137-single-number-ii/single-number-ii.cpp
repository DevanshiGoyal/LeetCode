class Solution {
public:
// using hshmap 
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(int i = 0 ;i<nums.size() ; i++){
            mp[nums[i]]++;
        }

        for(auto ele : mp){
            if(ele.second != 3){
                return ele.first ;
            }
        }

        return -1 ;

        
    }
};