class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>>& adj , int node , vector<int> &color , int currcolor){

        queue<int> q ;

        q.push(node) ;

        color[node] = currcolor;

        while(!q.empty()){
            int u = q.front() ;
            q.pop() ;

            for(int& v : adj[u]){
                if(color[v] == color[u]){
                    return false ;
                }

                if(color[v] == -1){
                    color[v] = 1-color[u] ;
                    q.push(v) ;
                }
            }
        } 

        return true ;       
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // using bfs 

        int n = graph.size() ;

        vector<int> color(n , -1) ;

        // red = 1 
        // green = 0 

        for(int i = 0 ; i<n ; i++){
            if(color[i] == -1){
                if(checkBipartiteBFS(graph , i , color , 1 ) == false) return false ;
            }
        }

        return true ;
        
    }
};

/*

TC
BFS  O(V + E)
= O(V + E)

SC
color array + queue = O(V)
*/