class Solution {
    using ll = long long;
    int MOD = 1e9 + 7;

public:
    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        if (n == 1) return m;

        vector<ll> up(m + 1, 1);
        vector<ll> down(m + 1, 1);

        vector<ll> prefUp(m + 1);
        vector<ll> prefDown(m + 1);


        for (int len = 2; len <= n; len++) {

            vector<ll> currUp(m + 1);
            vector<ll> currDown(m + 1);

            prefUp[0] = 0;
            prefDown[0] = 0;

            for (int v = 1; v <= m; v++) {
                prefUp[v] = (prefUp[v - 1] + up[v]) % MOD;
                prefDown[v] = (prefDown[v - 1] + down[v]) % MOD;
            }

            ll totalDown = prefDown[m];

            for (int v = 1; v <= m; v++) {
                currUp[v] =
                    (totalDown - prefDown[v] + MOD) % MOD;

                currDown[v] =
                    prefUp[v - 1];
            }

            up=currUp;
            down= currDown;
        }

        ll ans = 0;

        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v]) % MOD;
            ans = (ans + down[v]) % MOD;
        }
        return (int)ans;
    }
};