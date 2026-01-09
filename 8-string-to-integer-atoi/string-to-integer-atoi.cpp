class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) return 0 ;

        const long long MAX_INT = INT_MAX;
        const long long MIN_INT = INT_MIN;

        int i = 0 ;
        int n = s.length();

        //skip leading whitespaces  --> tc-->o(k) k--> leading whitespace char
        while(i<n && s[i] == ' '){
            i++;
        }

        // we have reached end
        if(i == n ) return 0 ; // only whitespace

        // handling sign 
        int sign = 1 ;
        if(s[i] == '-'){
            sign = -1 ;
            i++;
        }else if(s[i] == '+'){
            i++ ;
        }

        // read the digits 
        long long res = 0 ;
        // Stop processing when non-digit char is there
        while(i<n && isdigit(s[i])){

            // process digit 

            int digit = s[i] -'0';
            res = res*10 + digit ;

            // handling overflow
            if(sign * res <= INT_MIN){
                return INT_MIN ;
            }

            if(sign * res >= INT_MAX){
                return INT_MAX ;
            }

            i++;
        }
        

        // return after applying sign 
        return static_cast<int>(res*sign);
    }
};

//tc-->o(n)  sc-->o(1)