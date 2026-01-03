class Solution {
public:
    // Recursion---> TLE
    // Memoization

    int M = 1e9 + 7 ;
    vector<vector<int>> memo ;

    // 12 possible states of pattern for 1st row 
    string states[12] = {"RYG" , "RGY" ,"RYR" , "RGR",
                        "YRG" , "YGR" , "YRY" , "YGY" ,
                        "GRY" , "GYR" , "GYG" , "GRG"} ;

    int solve(int n , int prev){

        if(n==0) return 1 ; // we have found 1 way to paint N*3 grid

        if(memo[n][prev] != -1) return memo[n][prev] ;

        int result = 0 ;
        string last = states[prev]; 

        for(int curr = 0 ; curr < 12 ; curr++){
            if(curr == prev) continue ;

            string currPattern = states[curr];

            bool conflict = false ;

            for(int col = 0 ; col<3 ; col++){
                if(currPattern[col] == last[col]){
                    conflict = true ;
                    break ;
                }
            }
            if(!conflict){
                result = (result + solve(n-1, curr)) % M;
            }


        }
        return memo[n][prev] = result ;

    }

    int numOfWays(int n) {
        memo.resize(n , vector<int>(12 , -1)) ; // TC---> O(N)


        int result = 0 ;
        // choosing first row 
        for(int i = 0 ; i<12 ; i++){
            // now remaining n-1 rows painting 
            result = (result + solve(n-1, i)) % M;
        }

        return result ;
        

        
    }
};