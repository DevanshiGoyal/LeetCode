class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if(trust.size() == 0 && n==1) return n ;

        vector<int> out(n+1,0),in(n+1,0);
        for(auto p : trust){
            int u = p[0];
            int  v = p[1];

            in[v]++;
            out[u]++;
        }
        for(int i=1; i<=n; i++){
            if(out[i] == 0 && in[i] == n-1)
                return i;
        }
        return -1;
        
    }
};