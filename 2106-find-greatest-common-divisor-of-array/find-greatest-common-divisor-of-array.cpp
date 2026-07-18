class Solution {
public:
    int gcd(int a , int b){
        if(b==0)return a ;
        return gcd(b , a%b);
    }
    int findGCD(vector<int>& nums) {
        int  maxi = 0 ;
        int mini = 1001 ;
        for(int e : nums){
            maxi = max(maxi , e);
            mini = min(mini ,e );
        }

        //return __gcd(mini , maxi);

        return gcd(mini , maxi);
        
    }
};