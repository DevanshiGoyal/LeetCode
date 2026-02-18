class Solution {
public:
    bool hasAlternatingBits(int n) {
            // brute force approach
        string s = convertToBinary(n);
        for(int i = 0 ;  i<s.length()-1 ; i++){
            if(s[i] == s[i+1]) return false ;

        }

        return true ;
        
    }
    string convertToBinary(int n){
        string res ="";

        while(n){
            int r = n % 2 ;
            res+=char(r+'0');
            n=n/2;
        }
        return res ;
    }
};