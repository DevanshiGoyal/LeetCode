class Solution {
public:
    int findGCD(vector<int>& nums) {
        int  maxi = 0 ;
        int mini = 1001 ;
        for(int e : nums){
            maxi = max(maxi , e);
            mini = min(mini ,e );
        }

        return __gcd(mini , maxi);
        
    }
};