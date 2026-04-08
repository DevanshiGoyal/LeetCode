class Solution {
public:
    const int mod = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<long long> mult(n, 1);

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for (int i = l; i <= r; i += k) {
                mult[i] = (mult[i] * v) % mod;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long val = (nums[i] * mult[i]) % mod;
            ans ^= val;
        }

        return ans;
    }
};
