class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force approach 
        int n = nums.size();
        int count = 0 ;
        for(int i = 0 ; i<n ; i++){
            int sum = nums[i] ;
            if(sum==k){
                count++;
            }
            for(int j = i+1 ; j<n ; j++){
                sum += nums[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count ;
        
    }
};
/*
Time Complexity --> O(n ^ 2) // where n is the size of the array
Space Complexity --> O(1) // we are not using anything extra from our side
It paases [ 85 / 89 ] in built test cases
*/