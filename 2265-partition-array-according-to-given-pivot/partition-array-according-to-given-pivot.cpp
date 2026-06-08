class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int numsLessThanPivot = 0, numsEqualToPivot = 0, n = nums.size();
        for (auto val: nums) {
            if (val < pivot) numsLessThanPivot++;
            else if (val == pivot) numsEqualToPivot++;
        }
        
        int initialIndex = 0, equalIndex = numsLessThanPivot, finalIndex = numsLessThanPivot + numsEqualToPivot;
        vector<int> ans(n);
        
        for (auto val: nums) {
            if (val < pivot) ans[initialIndex++] = val;
            else if (val == pivot) ans[equalIndex++] = val;
            else ans[finalIndex++] = val;
        }
        return ans;
    }
};

// tc-->O(n)  sc-->O(n)

/*'
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        
        int left = 0;
        int right = n - 1;
        int i=0,j=n-1;
        
        while(i<n){
            if (nums[i] < pivot) {
                ans[left++] = nums[i];
            }
            
            if (nums[j] > pivot) {
                ans[right--] = nums[j];
            }

            i ++;
            j --;
        }
        
        //remaining indices will be filled with pivot
        while (left <= right) {
            ans[left++] = pivot;
        }
        
        return ans;
    }
};
*/