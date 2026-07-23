class Solution {
public:
    int squareSum(int n){
        int ans=0;
        while(n>0){
            ans=ans+pow((n%10),2);
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        while(n>4){
            n=squareSum(n);
        }
        return (n == 1); 
    }
};