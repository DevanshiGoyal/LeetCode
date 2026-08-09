class Solution {
public:
    int perimeter=0;
    void dfs(int r , int c , vector<vector<int>>& grid,int n , int m ){
        grid[r][c] = 2 ;

        int dr[4] = {-1 , 0 ,1 , 0};
        int dc[4] = {0 , 1, 0 , -1};

        for(int i = 0 ; i<4 ; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<0 || nr>=n || nc<0 || nc>=m){
                perimeter++;
            }
            else if(grid[nr][nc] == 0 ){
                perimeter++;
            }
            
            else if(grid[nr][nc] == 1 && nr>=0 && nr<n && nc<m && nc>=0 ){
                dfs(nr , nc , grid , n , m);
            }
        }
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j]==1){
                    dfs(i , j , grid , n, m);
                    break;
                }
            }
        }

        return perimeter ;
        
    }
};