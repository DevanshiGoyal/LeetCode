class Solution {
public:
    int bs(vector<int>& nums, int target , int left , int right){

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid; // Target found, return index
            } else if (nums[mid] < target) {
                left = mid + 1; // Move to the right half
            } else {
                right = mid - 1; // Move to the left half
            }
        }

        return -1; // Target not found

    }
    int search(vector<int>& nums, int target) {

        int start = 0 ;
        int end = nums.size()-1;
       

        while(start<=end){
            int mid = start + (end-start)/2 ;
            if(nums[mid] == target) return mid ;

            // Left half is sorted
            if (nums[start] <= nums[mid]) {
                if(nums[start] <= target && target < nums[mid]){
                    return bs(nums , target , start , mid-1  );
                }else {
                    start = mid + 1;
                }
            }
            // Right half is sorted
            else{
                if (nums[mid] < target && target <= nums[end]) {
                    return bs(nums, target, mid + 1, end);
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1 ;
        
    }
};