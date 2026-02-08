class Solution {
public:
    int climbStairs(int n) {

        if(n == 1 || n == 2) return n;

        //vector<int> dp(n + 1, -1);

        int prev2 = 0;
        int prev1 = 1;
        int curr = 2;
        int next ;

        for(int i = 3; i <= n; i++){
            next = curr + prev1 ; 
            prev1 = curr ;
            curr = next ;

        }

        return next ;
    }
};
