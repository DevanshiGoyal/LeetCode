class Solution {
public:
    int minElement(vector<int>& nums) {

        int mini = INT_MAX ;
        int n = nums.size() ;
        for(int i = 0 ; i<n ;i++){

            int num = nums[i] ;
            int sum = 0 ;
            while(num>0){
                int d = num%10 ;
                sum+=d ;
                num = num/10 ;

            }
            mini = min(mini , sum) ;

        }

        return mini ;
        
    }
};