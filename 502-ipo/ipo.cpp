class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size() ;

        vector<pair<int , int>> p;

        for(int i = 0 ; i<n ; i++){
            p.push_back({capital[i] , profits[i]}) ;  // m capital dekh rhi hu then basis pr max profit uthaungi 
        }

        sort(p.begin() , p.end()); //jitni capital h us according

        priority_queue<int> pq ; // max capital 

        int i = 0 ;
        while(k--){
            while(i<n && p[i].first <=w){
                pq.push(p[i].second); // max profit 
                i++;
            }

            if(pq.empty()){  // runtime error if k =1 , w=0  profits =[1,2,3] cap =[1,1,2]
                break;
            } 

            w+=pq.top();
            pq.pop();
        }
        return w;
        
    }
};