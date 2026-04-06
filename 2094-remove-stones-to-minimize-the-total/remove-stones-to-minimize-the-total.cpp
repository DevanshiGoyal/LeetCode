class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> mp ;

        for(int x : piles){
            mp.push(x);
        }

        while(k--){
            int top = mp.top();
            mp.pop();

            top -= top/2 ;// remove floor(top/2)

            mp.push(top);
        }

        int sum = 0 ;
        while(!mp.empty()){
            sum+=mp.top() ;
            mp.pop() ;
        }

        return sum ;
        
    }
};
//Tc - O((n + k) log n)   building heap - O(n)    each opern - O(log n)