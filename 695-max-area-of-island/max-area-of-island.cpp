class Solution {
public:
    void dfs(int r , int c , vector<vector<int>>& grid , int n , int m , int &area){
        grid[r][c] = 2 ;
        area++;

        int dr[4] = {-1, 0 , 1 , 0};
        int dc[4] = {0 , 1 , 0 , -1};

        for(int i = 0 ;i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];


            if(nr< n && nc<m && nc>=0 && nr>=0 && grid[nr][nc] == 1){
                dfs(nr , nc , grid , n , m , area);
            }
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                int area = 0 ;
                if(grid[i][j] == 1){
                    dfs(i , j , grid , n , m , area);
                    maxArea = max(maxArea , area);
                }
            }
        }

        return maxArea;
        
    }
};