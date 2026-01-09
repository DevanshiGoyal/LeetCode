class Solution {
public:
    int maxDepth(string s) {
        // space optimised approach 
        // withou using stack using counter 
        int op = 0 ; // track the count of opening brackets 
        int maxi = 0 ;
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] == '(' ){
                op++;
                maxi = max(maxi , op);
            }else if(s[i] == ')') op-- ;
        }
        return maxi ;
        
        
    }
};

// TC-->O(N) SC-->O(1)