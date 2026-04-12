class Solution {
public:
    void dfs(int node , vector<int> &vis , vector<vector<int>>& adjList){
        vis[node] = 1 ;
        for(auto &it : adjList[node]){
            if(!vis[it]){
                dfs(it , vis , adjList) ;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;  // rows
        int m = isConnected[0].size() ; // cols 

        // adlist
        vector<vector<int>> adjList(n) ;

        // visited array
        vector<int> visited(n, 0) ;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);  // neighbours
                }

            }
        }

        int count = 0 ;
        for(int i = 0 ;i<n ; i++){
            if(!visited[i]){  // agr not visted by any chance then different comp. not connected 
                count++;
                dfs(i , visited , adjList) ; // for other neigh
            }
        }

        return count ;
        
    }
};
//tc-->O(n^2)   sc-->O(n)