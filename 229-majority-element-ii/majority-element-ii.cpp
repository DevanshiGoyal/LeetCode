class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // brute force approach 
        // using hashmap 
        unordered_map<int , int> mp ;
        int n = nums.size() ;
        for(int i = 0 ; i<n ; i++){
            mp[nums[i]]++;
        }
        vector<int> ans ;
        n = n/3 ;
        for(auto e : mp){
            if(e.second > n ){
                ans.push_back(e.first);
            }

        }
        return ans ;
        
    }
};

//TC-->O(2*N)=O(N)  SC-->O(N)