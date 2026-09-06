class Solution {
public:

    int dfs(string& s, string& t, int i, int j,
            vector<vector<int>>& memo) {

        if(j == 0)
            return 1;

        if(i == 0)
            return 0;

        if(memo[i][j] != -1)
            return memo[i][j];

        if(s[i - 1] == t[j - 1]) {

            memo[i][j] =
                dfs(s, t, i - 1, j - 1, memo) +
                dfs(s, t, i - 1, j, memo);

        } else {

            memo[i][j] =
                dfs(s, t, i - 1, j, memo);
        }

        return memo[i][j];
    }

    int numDistinct(string s, string t) {

        int m = s.size();
        int n = t.size();

        vector<vector<int>> memo(
            m + 1,
            vector<int>(n + 1, -1)
        );

        return dfs(s, t, m, n, memo);
    }
};