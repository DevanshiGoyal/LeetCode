class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int h = n / 2;

        vector<long long> arr;
        for (int x : nums) {
            arr.push_back(abs((long long)x));
        }

        sort(arr.begin(), arr.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (i < h ? -1LL : 1LL) * arr[i] * arr[i];
        }

        return ans;
    }
};