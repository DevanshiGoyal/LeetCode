class Solution {
public:
    int dfs(vector<vector<int>>& adj , vector<bool>& hasApple , int curr , int parent ){
        int time = 0 ;
        for(int neighbour : adj[curr]){
            if(neighbour == parent) continue ;
            int timeFromChild = dfs(adj , hasApple , neighbour ,curr) ;
            if(timeFromChild >0 || hasApple[neighbour]){
                time += timeFromChild + 2 ;
            }
            
        }
        return time ;
    }


    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        // build  the adjacency list 
        vector<vector<int>> adj(n) ;
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;

        }

        return dfs(adj , hasApple , 0 , -1) ;
        
    }
};