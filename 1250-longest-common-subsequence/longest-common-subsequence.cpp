class Solution {
public:
    // using recursion -->TLE
    //Memoization -->tle
    // overlapping subproblems
    // Bottom up approach 
    // space optimised 1D optimised 
    // TC---> O((m*n))  SC-->O(n) 
    
    int longestCommonSubsequence(string s1, string s2) {
       
        int  n = s1.length() ;
        int m = s2.length() ;

       vector<int> prev(m + 1, 0), curr(m + 1, 0);

       // base cases
        for (int i = 0; i <= n; i++) {
            prev[0] = 0;
        }

        for(int i = 1 ; i<=n ; i++){
            for(int j =1 ;j<=m ; j++){
                
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1+ prev[j-1] ;
                }
                else{
                    curr[j] = max(curr[j-1] , prev[j]) ;
                }
                
            }
            prev = curr ;
        }
        return prev[m];
        
    }
};