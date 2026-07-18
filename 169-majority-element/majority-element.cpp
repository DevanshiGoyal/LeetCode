class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // brute force approach 
        // using hashmap

        int n = nums.size();
        unordered_map<int , int> mp ;  // num , count

        for(int i = 0  ; i<n ; i++){
            mp[nums[i]]++;
        }
        int ans ;
        for(auto e :mp){
            int f = e.second ;
            int num = e.first;
            if(f>n/2) ans = num ;

        }
        return ans ;
        
    }
};