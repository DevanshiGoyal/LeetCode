class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq ;
        for(int i = 0 ; i<stones.size() ; i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int el1 = pq.top();
            pq.pop();
            int el2 = pq.top();
            pq.pop();

            if(el1 != el2){
                pq.push(abs(el1-el2));
            }
            
        }
        if(pq.empty()) return 0 ;
        return pq.top();
        
    }
};