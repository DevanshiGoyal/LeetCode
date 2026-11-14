class Solution {
public:
// brute(n*r)
// optimal O(n)
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        //prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minSum = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r; len++) {
                int j = i + len;
                if (j > n)
                    break;

                int sum = prefix[j] - prefix[i];

                if (sum > 0) {
                    minSum = min(minSum, sum);
                }
            }
        }

        if(minSum == INT_MAX) return -1 ;
        return minSum;
    }
};