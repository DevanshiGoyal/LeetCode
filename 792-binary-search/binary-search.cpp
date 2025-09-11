class Solution {
public:
    int binarySearch(vector<int>& nums, int target , int low , int high ){
        // Recursive code 
        
        //Base case 
        if(low > high) return -1 ;
        int mid = low + (high - low)/2 ;

        if(target == nums[mid]) return mid ;

        else if(target > nums[mid]){
            return binarySearch(nums , target , mid+1 , high );
        }

        return binarySearch(nums , target , low ,  mid-1  );
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();

        return binarySearch(nums , target , 0 , n-1);
        
    }
};

// Tc---> O(log n)
//SC---> O(logn)