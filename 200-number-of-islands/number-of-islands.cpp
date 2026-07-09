class Solution {
public:
    void dfs(int r , int c , vector<vector<char>>& grid ,vector<vector<int>> &vis ){

        int n = grid.size() ;
        int m = grid[0].size() ;
        vis[r][c] = 1 ;

        int dr[4] = {-1 , 0 , 1 , 0};
        int dc[4] = {0 , 1,0 , -1} ;

        for(int i = 0 ; i<4 ; i++){
            int nr = r+dr[i] ;
            int nc = c + dc[i] ;

            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == '1' && !vis[nr][nc] ){
                dfs(nr , nc , grid , vis) ;
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size() ;
        int m = grid[0].size() ;
        int islands = 0 ;
        vector<vector<int>> vis(n , vector<int>(m , 0)) ;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i , j , grid , vis) ;
                    islands++;
                }
            }
        }

        return islands ;
    }
};