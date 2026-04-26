class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> dist(r, vector<int>(c, -1));

        queue<pair<int,int>> q;

        // push all 0s into que
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {

                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < r && ny < c 
                   && dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;

                    q.push({nx, ny});
                }
            }
        }

        return dist;
    }
};
/*
Tc :O(m×n) - each cell in mat is processed once
Sc :O(m×n) - worst case, all cells added to que
*/