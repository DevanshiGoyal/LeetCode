class Solution {
public:
    void dfs(unordered_map<int , vector<int>> &adj, int u , vector<bool> &visited ){
        visited[u] = true ;

        for(int &v : adj[u]){
            if(!visited[v]){
                dfs(adj , v , visited) ;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
        //int c = isConnected[0].size() ;

        // build graph 
        unordered_map<int , vector<int>> adj ;
        // adjacency list
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j) ;  // isConnected[i][j] == isConnected[j][i]  constraint given
                    //adj[j].push_back(i) ;
                }
            }

        }

        vector<bool> visited(n , false);
        int province = 0 ;
        for(int u = 0 ; u<n ; u++){
            if(!visited[u]){
                province++;
                dfs(adj , u ,visited) ;
            }
        }
        return province ;
        
    }
};

/*

Tc
Building graph: O(V2)
DFS traversal: O(V+E)
tc-> O(V2)

sc

adj list -> O(V+E)
visited = O(V)
recursion stack -> O(V)
sc->  O(V+E)
*/
