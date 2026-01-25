class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // TC--->O(N3)--->TLE
        // not efficient at all 
        // brute force making it into  O(N^2)
        int n = nums.size();
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int maxi = INT_MIN, mini = INT_MAX;
            for(int j = i; j < n; j++) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};
