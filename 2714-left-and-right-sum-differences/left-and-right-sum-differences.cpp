class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;

        for (int x : nums)
            totalSum += x;

        int leftSum = 0;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            totalSum -= nums[i]; // right sum

            ans.push_back(abs(leftSum - totalSum));

            leftSum += nums[i];
        }

        return ans;
    }
};