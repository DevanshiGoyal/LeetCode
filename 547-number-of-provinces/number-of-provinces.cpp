class Solution {
public:
    // using bfs
    void bfs(unordered_map<int , vector<int>> &adj, int u , vector<bool> &visited ){

        queue<int> q ;
        q.push(u) ;
        visited[u] = true ;

        while(!q.empty()){
            int u = q.front() ;
            q.pop() ;

            for(int &v : adj[u]){
                if(!visited[v]){
                    visited[v] = true ;
                    q.push(v) ;
                }
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
                bfs(adj , u ,visited) ;
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
queue -> O(V)
sc->  O(V+E)
*/