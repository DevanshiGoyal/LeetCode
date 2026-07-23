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
        int slow=n;
        int fast=n;
        while(n!=1&&fast!=1){
            slow=squareSum(slow);
            fast=squareSum(squareSum(fast));
            if(slow==fast&&fast!=1){
                return false;
            }
        }
        return true;
    }
};