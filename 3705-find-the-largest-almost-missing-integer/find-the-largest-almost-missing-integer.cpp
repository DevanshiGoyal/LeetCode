class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;

        // Count in how many windows each number appears
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> f;

            for (int j = i; j < i + k; j++) {
                f[nums[j]]++;
            }

            // Each number should be counted only once
            // for this window
            for (auto it : f) {
                count[it.first]++;
            }
        }

        int ans = -1;

        for (auto it : count) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};