class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp ;

        for(int  i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int , int>> pq ;

        for(auto e : mp){
            pq.push({e.second , e.first}) ;
        }

        vector<int> ans ;

        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second) ;
            pq.pop() ;


        }
        return ans ;


        
    }
};