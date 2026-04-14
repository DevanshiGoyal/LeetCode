class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSumMap;
        int sum = 0, cnt = 0;

        preSumMap[0] = 1; // to count subarrays that start from index 0

        for (int num : nums) {
            sum += num;
            cnt += preSumMap[sum - k]; // how many times prefix sum occ
            preSumMap[sum]++;
        }

        return cnt;
    }
};
