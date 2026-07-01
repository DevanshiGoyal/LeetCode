class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // brute force 

        unordered_map<int , int> f ;
        int n = nums.size();
        // O(N) time
        for(int i = 0 ; i<n ; i++){
            f[nums[i]]++;

        }

        priority_queue<pair<int  , int>> pq ;

        for(auto e : f){
            pq.push({e.second , e.first});  // freq , element 
        }
        vector<int> ans ;
        while(k-- && !pq.empty()){

            ans.push_back(pq.top().second);
            pq.pop();
        }


        return ans ;
    }
};