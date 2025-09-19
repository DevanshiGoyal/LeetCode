class Solution {
public:
    int maxElement(vector<int>& nums){

        int maxi = INT_MIN ;
        for(int i = 0 ; i< nums.size() ; i++){
            maxi = max(nums[i] , maxi );

        }
        return maxi ;
    }
    int getsum(vector<int>& nums, int divisor){
        int sum  =  0 ;
        for(int i =  0 ; i<nums.size() ; i++){
            sum += ceil((double)nums[i] /(double) divisor );
        }
        return sum ;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1 ;
        int e = maxElement(nums) ;
        int ans = e;

        while(s<=e){
            int mid = (s+e)/2 ;
            int sum = getsum(nums , mid);
            if(sum <= threshold ){
                ans = mid;
                e= mid-1 ;
            }else{
                s= mid+1 ;
            }
        }
        return ans ;
        
    }
};
//Time complexity--->O(log[max_ele] * N )

//Space complexity--->0(1) no extra memory space is used