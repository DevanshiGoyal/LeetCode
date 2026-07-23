class Solution {
private:
    bool dfs(int r, int c, int index,
             vector<vector<char>>& board,
             string& word) {

        int n = board.size();
        int m = board[0].size();

        if (r < 0 || r >= n ||
            c < 0 || c >= m ||
            board[r][c] != word[index])
            return false;

        if (index == word.size() - 1)
            return true;

        char temp = board[r][c];
        board[r][c] = '#';

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int d = 0; d < 4; d++) {

            int nr = r + dx[d];
            int nc = c + dy[d];

            if (dfs(nr, nc, index + 1, board, word)) {
                board[r][c] = temp;
                return true;
            }
        }

        board[r][c] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs(i, j, 0, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};