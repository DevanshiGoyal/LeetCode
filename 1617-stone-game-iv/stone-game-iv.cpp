bool dp[100001][2];

class Solution {
public:
    bool winnerSquareGame(int N) {
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int n = 1; n <= N; n++) {
            for(int turn = 0; turn <= 1; turn++) {
                bool alice = false;
                if(turn) {
                    for(int i = 1; i*i <= n; i++) {
                        alice |= dp[n - i*i][false];
                        if(alice) break;
                    }
                }
                else {
                    alice = true;
                    for(int i = 1; i*i <= n; i++) {
                        bool bob = dp[n - i*i][true];
                        if(!bob) {
                            alice = bob;
                            break;
                        }
                    }
                }
                dp[n][turn] = alice;
            }
        }
        return dp[N][true];
    }
};