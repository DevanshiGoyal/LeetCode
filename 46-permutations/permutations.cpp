class Solution {
public:
    void solve(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result){
        if(current.size()==nums.size()) {
            result.push_back(current);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            current.push_back(nums[i]);
            used[i] = true;
            solve(nums,current,used,result);
            used[i] = false;
            current.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        vector<bool> used(nums.size(),false);
        solve(nums,current,used,result);
        return result;
    }
};