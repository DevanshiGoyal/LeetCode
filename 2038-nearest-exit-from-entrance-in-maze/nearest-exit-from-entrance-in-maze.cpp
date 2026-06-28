class Solution {
public:
    bool is_allowed(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        vector<pair<int,int>> directions = {
            {0,1},{0,-1},{1,0},{-1,0}
        };

        int m = maze.size();
        int n = maze[0].size();
        int sx = entrance[0];
        int sy = entrance[1];

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;

        q.push({sx, sy});
        visited[sx][sy] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                if ((x != sx || y != sy) &&
                    (x == 0 || x == m - 1 || y == 0 || y == n - 1)) {
                    return steps;
                }

                for (auto& d : directions) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if (is_allowed(nx, ny, m, n) &&
                        !visited[nx][ny] &&
                        maze[nx][ny] != '+') {

                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};