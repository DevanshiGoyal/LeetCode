int dp[100001][2];

class Solution {
public:
    bool f(int n, bool turn) {
        if(n == 0) {
            if(turn) return false;
            return true;
        }
        if(dp[n][turn] != -1) return dp[n][turn];
        bool alice = false;
        if(turn) {
            for(int i = 1; i*i <= n; i++) {
                alice |= f(n - i*i, false);
            }
        }
        else {
            alice = true;
            for(int i = 1; i*i <= n; i++) {
                bool bob = f(n - i*i, true);
                if(!bob) return dp[n][turn] = bob;
            }
        }
        return dp[n][turn] = alice;
    }
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n, true);
    }
};