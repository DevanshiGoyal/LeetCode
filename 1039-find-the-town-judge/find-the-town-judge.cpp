class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if(trust.size() == 0 && n==1) return n ;

        vector<int> count(n+1);
        for(auto person : trust){
            int u = person[0];
            int v = person[1];

            count[v]++;
            count[u]--;

        }

        for(int i = 1 ; i<count.size() ; i++){
            if(count[i] ==  n-1) return i ;
        }
        return -1 ;
        
    }
};