class Solution {
private:
    int dp[101][101][2];

    int f(int i, int m, bool turn, vector<int> &piles) {
        int n = piles.size();
        if(i == n) {
            return 0;
        }
        if(dp[i][m][turn] != -1) return dp[i][m][turn];
        
        int alice;
        if(turn) {
            alice = 0;
            int sum = 0;
            for(int ind = i; ind < i + 2*m; ind++) {
                if(ind == n) break;
                sum += piles[ind];
                int x = ind - i + 1;
                alice = max(alice, sum + f(ind + 1, max(x, m), false, piles));
            }
        }
        else {
            alice = INT_MAX;
            for(int ind = i; ind < i + 2*m; ind++) {
                if(ind == n) break;
                int x = ind - i + 1;
                alice = min(alice, f(ind + 1, max(x, m), true, piles));
            }
        }
        return dp[i][m][turn] = alice;
    }
public:
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return f(0, 1, true, piles);
    }
};