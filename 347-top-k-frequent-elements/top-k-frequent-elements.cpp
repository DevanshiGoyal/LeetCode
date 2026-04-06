class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size() ;

        unordered_map<int , int> mp;

        for(int i = 0 ;i<n ; i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto it: mp){
            pq.push({it.second, it.first}); // freq, element
            if(pq.size()>k) pq.pop(); 
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};

/*
TC
Freq map O(n) + Heap operations O(n log k)
--> O(n log k)

SC
Hash map O(n) + Heap O(k)

--> O(n)
*/