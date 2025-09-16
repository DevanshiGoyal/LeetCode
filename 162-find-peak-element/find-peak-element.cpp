class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // edge cases 
        if(n==1) return 0 ;

        if(nums[0] > nums[1]) return 0 ;
        if(nums[n-1] > nums[n-2]) return n-1 ;

        int low = 1 , high = n-2 ;

        while(low<=high){
            int mid = low + (high - low)/2 ;
            if(nums[mid]> nums[mid-1] && nums[mid]> nums[mid+1]) return mid ;

            else if(nums[mid]> nums[mid-1]){
                // slope rising -> peak must be on right
                low =  mid + 1;
            }
            else{
                // slope falling -> peak must be on left
                high = mid -1 ;
            }


        }
        return low ; // by now low == high , so either works 

        
    }
};