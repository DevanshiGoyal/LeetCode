class Solution {
public:

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& vis,queue<pair<int,int>>& q){
        int n = heights.size(), m = heights[0].size();
        int dr[4] = {-1 , 0 , 1 , 0};;
        int dc[4] = {0 , 1 , 0 , -1};

        while(!q.empty()){
            auto[r , c] = q.front();
            q.pop();

            for(int i = 0 ; i<4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    vis[nr][nc] = true ;
                    q.push({nr , nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n , vector<bool>(m , false));
        vector<vector<bool>> atlantic(n , vector<bool>(m , false));

        queue<pair<int , int>> q ;

        for(int i = 0 ; i<n ; i++){
            q.push({i, 0});
            pacific[i][0] = true ;
        }

        for(int j = 0 ; j<m ; j++){
            q.push({0 , j});
            pacific[0][j] = true ;
        }

        bfs(heights, pacific, q);

        // Atlantic Ocean (bottom row + right column)
        q = queue<pair<int,int>>();

        for(int i = 0; i < n; i++)
        {
            q.push({i, m - 1});
            atlantic[i][m - 1] = true;
        }

        for(int j = 0; j < m; j++)
        {
            q.push({n - 1, j});
            atlantic[n - 1][j] = true;
        }

        bfs(heights, atlantic, q);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;


        
    }
};