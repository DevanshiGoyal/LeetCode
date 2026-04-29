class Solution {
private:
    void dfs(int row , int  col , vector<vector<int>> &vis , vector<vector<int>> &grid){
        vis[row][col] = 1 ;
        int n = grid.size() ;
        int m = grid[0].size() ;

        // check for 4 directions up , right , bottom , down 
        vector<vector<int>> directions = {{-1,0} ,{0,+1} , {+1,0} ,{0,-1}} ;
        for(int i = 0 ; i<4 ; i++){
            int nrow = row + directions[i][0] ;
            int ncol = col + directions[i][1] ;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow , ncol , vis , grid ) ;
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<int>> visited(n , vector<int>(m , 0)) ;
        // traverse first row and last row 
        for(int j = 0 ; j<m ; j++){
            if(grid[0][j] == 1 && visited[0][j] == 0 ){
                
                dfs(0 , j , visited , grid ) ;
            }
        
            if(grid[n-1][j] == 1 && visited[n-1][j] == 0 ){
                
                dfs(n-1 , j , visited , grid ) ;
            }
        }

        for(int i = 0;i<n;i++) {
            // check for unvisited Os in the boundary columns
            // first column 
            if(!visited[i][0] && grid[i][0] == 1 ) {
                dfs(i, 0, visited, grid); 
            }
            
            // last column
            if(!visited[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, visited, grid); 
            }
        }

        // if unvisited 1 , then count that land cell
        int enclave = 0 ;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    enclave ++ ;
                }
            }
        }
        return enclave ;
        
    }
};