class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {

        vis[node] = 1;

        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        // sabse pehle hum connected compnents find karrenge 
        // this too have two vays   --> dfs and dsu

        // using dfs traversal
        int n = stones.size();
        // graph   // O(n^2)
        vector<vector<int>> adj(n);
        // build edges

        for(int i = 0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                // any row same or col same 
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j) ;
                    adj[j].push_back(i) ;
                }
            }
        }

        vector<int> vis(n,0);
        int cmp = 0 ;

        for(int i = 0; i<n ; i++){
            if(!vis[i]){
                cmp++;
                dfs(i , adj , vis);  // O(V+E)
            }
        }

        return n - cmp;
        
    }
};

/*
If a connected component has
k stones

Then maximum removable stones are: k - 1

because

keep 1
remove all others

Then

answer = total stones - connected components
*/