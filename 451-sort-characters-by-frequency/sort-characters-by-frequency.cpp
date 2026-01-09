class Solution {
public:
    string frequencySort(string s) {
        // approach using  hashmap and priority queue

        // count freq of each character 
        unordered_map<char,int> mp;
        for(auto x:s)
            mp[x]++;
        
        //max heap store pairs (freq, char) so that the char with highest freq on top
        priority_queue<pair<int,char>> pq;
        
        // pushing pairs into pq
        for(auto x: mp)
            pq.push(make_pair(x.second,x.first));
        
        // result string
        s = "";
        
        while(!pq.empty())
        {
            //get top char
            char c = pq.top().second;

            // repeated freq no of times
            for(int i = 0;i<pq.top().first;i++){
                // add to string
                s.push_back(c);

            }
            
            //pop top element 
            pq.pop();
        }

        return s;
    }
};

// TC : O(NlogK) N->length K-> unique char
//SC : O(K) for storing freq map and pq