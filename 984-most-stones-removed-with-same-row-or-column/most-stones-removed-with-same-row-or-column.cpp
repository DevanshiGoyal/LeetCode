class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj  , vector<vector<int>>& stones , vector<int>& vis){
        vis[node] = 1 ;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it , adj , stones , vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<vector<int>>adj(n);

        vector<int> vis(n , 0);

        for(int i = 0 ; i<n ; i++){
            for(int j= i+1 ; j<n ; j++){

                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }

        int comp = 0 ;

        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                comp++;
                dfs(i , adj , stones , vis);
            }
        }

        return n - comp ;

    
        
    }
};