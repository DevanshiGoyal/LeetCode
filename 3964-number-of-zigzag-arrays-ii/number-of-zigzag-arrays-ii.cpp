class Solution {
public:
    static const int MOD = 1e9 + 7;

    using ll = long long;
    using Matrix = vector<vector<ll>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp > 0) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<ll> multiplyVector(
        const Matrix& A,
        const vector<ll>& v
    ) {
        int n = A.size();

        vector<ll> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] =
                    (res[i] + A[i][j] * v[j]) % MOD;
            }
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        // states:
        // (last_value, dir)
        // dir = 0 -> last move was DOWN
        // dir = 1 -> last move was UP

        int S = 2 * m;

        auto id = [&](int val, int dir) {
            return val * 2 + dir;
        };

        Matrix T(S, vector<ll>(S, 0));

        // transitions
        for (int prev = 0; prev < m; prev++) {

            // previous direction DOWN
            // next must go UP
            for (int nxt = prev + 1; nxt < m; nxt++) {
                T[id(nxt, 1)][id(prev, 0)] = 1;
            }

            // previous direction UP
            // next must go DOWN
            for (int nxt = 0; nxt < prev; nxt++) {
                T[id(nxt, 0)][id(prev, 1)] = 1;
            }
        }

        // base vector for length = 2
        vector<ll> base(S, 0);

        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {

                if (a < b) {
                    base[id(b, 1)]++;
                }
                else if (a > b) {
                    base[id(b, 0)]++;
                }
            }
        }

        if (n == 2) {
            ll ans = 0;

            for (ll x : base)
                ans = (ans + x) % MOD;

            return ans;
        }

        Matrix P = power(T, n - 2);

        vector<ll> finalState = multiplyVector(P, base);

        ll ans = 0;

        for (ll x : finalState)
            ans = (ans + x) % MOD;

        return ans;
    }
};