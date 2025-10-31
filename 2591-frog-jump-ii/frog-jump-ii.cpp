class Solution {
public:
    int f(int ind,vector<int> &stones,vector<int> &dp){
        
        if(ind==0) return 0;
        if(ind==1) return abs(stones[ind]-stones[ind-1]);
        if(dp[ind]!=-1) return dp[ind];
        
        int curr=abs(stones[ind]-stones[ind-2]);
        int rem=f(ind-1,stones,dp);
        
        return dp[ind]=max(curr,rem);
    }

    int maxJump(vector<int>& stones) {
        
        int n=stones.size();
        vector<int> dp(n,-1);
        return f(n-1,stones,dp);
    }
    
};