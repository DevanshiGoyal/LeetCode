class Solution {
public:
    //  TC-->O(N)    SC--->O(1) 
    bool isTrionic(vector<int>& nums) {

        int n = nums.size() ;
        // Phase 1 Up
        int i = 0 ;
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == 0 || i == n - 1) return false;
        
        int p = i;
        // Phase 2 Down
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        if (i == p || i == n - 1) return false;
        
        // Phase 3 Up
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        return i == n - 1;
    }
};