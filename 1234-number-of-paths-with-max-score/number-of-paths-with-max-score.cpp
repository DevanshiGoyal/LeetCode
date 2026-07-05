class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        // Each entry is {score, ways}; score == -1 means unreachable.
        vector<pair<int,int>> below(n, {-1, 0}); // the row just below the current one (i+1)
        vector<pair<int,int>> cur  (n, {-1, 0}); // the row we are filling now (i)

        for (int i = n - 1; i >= 0; --i) {
            fill(cur.begin(), cur.end(), make_pair(-1, 0));   // clear the row we're about to fill
            for (int j = n - 1; j >= 0; --j) {
                if (i == n - 1 && j == n - 1) { cur[j] = {0, 1}; continue; } // S
                if (board[i][j] == 'X') continue;

                int best = -1;
                if (i + 1 < n)              best = max(best, below[j].first);
                if (j + 1 < n)              best = max(best, cur[j + 1].first);
                if (i + 1 < n && j + 1 < n) best = max(best, below[j + 1].first);
                if (best == -1) continue;

                long long cnt = 0;
                if (i + 1 < n              && below[j].first     == best) cnt += below[j].second;
                if (j + 1 < n              && cur[j + 1].first   == best) cnt += cur[j + 1].second;
                if (i + 1 < n && j + 1 < n && below[j + 1].first == best) cnt += below[j + 1].second;
                cnt %= MOD;

                int val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';
                cur[j] = {best + val, (int)cnt};
            }
            below = cur; // the row we just finished becomes "below" for the next row up
        }

        if (below[0].first == -1) return {0, 0};
        return {below[0].first, below[0].second};
    }
};