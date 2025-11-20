class Solution {
public:
    // by shifting of index
    // Memoization
    int lcsUtil(string &s1, string &s2,int i,int j,vector<vector<int>> &memo) {
        if(i==0 || j==0){ // negative index
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(s1[i-1] == s2[j-1]){
            return memo[i][j]= 1+lcsUtil(s1,s2,i-1,j-1,memo);
        }else{
            return memo[i][j]= max(lcsUtil(s1,s2,i-1,j,memo) , lcsUtil(s1,s2,i,j-1,memo));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
      
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1))  ;
        return lcsUtil(text1,text2, m ,n, dp );
    }
};