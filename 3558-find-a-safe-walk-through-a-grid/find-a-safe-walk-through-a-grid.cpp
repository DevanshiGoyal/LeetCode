class Solution {
public:
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size() ;

        vector<vector<int>> maxHealth(m , vector<int>(n , -1)); // maximum health remaining when reaching each cell

        queue<pair<int , pair<int , int>>> q ;  //remH , { r , c}

        int initialH = health - grid[0][0];
        if(initialH <= 0) return false ;

        q.push({initialH , {0 , 0}}) ;
        maxHealth[0][0] = initialH ;

        while(!q.empty()){
            
            auto [currH, pos] = q.front();
            q.pop();
            
            int r = pos.first;
            int c = pos.second ;

            if(r==m-1 && c == n-1) return true ;

            int dr[4] = {-1 , 0 , 1 , 0};
            int dc[4] = {0, 1, 0, -1};

            for(int i = 0 ; i<4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                int remH = currH - grid[nr][nc];
                if(remH <= 0 ) continue ;

                if(remH <= maxHealth[nr][nc]) continue ;

                maxHealth[nr][nc] = remH ;
                q.push({remH , {nr , nc}}) ;

            }

        }

        return false ;
        
    }
};
// tc --> O(m * n * health)   sc--> O(m*n)