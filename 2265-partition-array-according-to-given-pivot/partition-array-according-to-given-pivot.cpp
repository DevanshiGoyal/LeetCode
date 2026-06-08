class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int initialIndex = 0, lastIndex = n - 1;
        vector<int> ans(n);
        
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            if (nums[i] < pivot) ans[initialIndex++] = nums[i];
            if (nums[j] > pivot) ans[lastIndex--] = nums[j];
        }
        
        while (initialIndex <= lastIndex) ans[initialIndex++] = pivot;
        
        return ans;
    }
};