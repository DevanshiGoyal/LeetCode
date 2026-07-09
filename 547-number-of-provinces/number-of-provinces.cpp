class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj , vector<int>&vis){
        vis[node] = 1 ;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it , adj , vis) ;
            }
        }

    }

    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;

        // adj list 
        vector<vector<int>> adj(n) ;
        for(int u = 0 ; u<n ; u++){
            for(int v = 0 ; v<n ; v++){
                if(isConnected[u][v]==1 && u!=v){
                    adj[u].push_back(v) ;
                    adj[v].push_back(u) ;
                }
            }
           
        }
        int count = 0 ;
        vector<int> vis(n , 0) ;
        for(int i = 0  ; i<n ; i++){
            if(!vis[i]){
                count++;
                dfs(i , adj , vis);
                
            }
        }
        return count ;
    }
};

// sc  ---> O(n) + O(n)  (visited array + rescursion stack space)
// tc---->  O(n)  + o(v+2e) 
