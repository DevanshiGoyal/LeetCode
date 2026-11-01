class Solution {
public:
    // optimal 
    // brute  tle  [1,1,1000000000]
    int minMoves(vector<int>& nums) {

        int mini = *min_element(nums.begin(), nums.end());

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            ans += nums[i] - mini;
        }

        return ans;
    }
};