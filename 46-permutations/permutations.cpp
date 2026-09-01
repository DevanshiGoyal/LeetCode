class Solution {
public:
    void getPermutations(vector<int> &nums, vector<vector<int>> &ans, int idx)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            getPermutations(nums, ans, idx + 1);
            swap(nums[idx], nums[i]);
        } 
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        getPermutations(nums, ans, 0);
        return ans;
    }
};