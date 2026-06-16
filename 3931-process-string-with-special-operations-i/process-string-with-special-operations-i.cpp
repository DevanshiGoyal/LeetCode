class Solution {
public:
    string processStr(string s) {

        string res ;
        for(char c : s){
            if(c>='a' && c<='z'){
                res.push_back(c) ;
            }
            else if(c=='#'){
                res+=res;
            }
            else if(c=='%'){
                reverse(res.begin() , res.end()) ;
            }
            else if(!res.empty() && c=='*'){
                res.pop_back() ;
            }
        }

        return res ;

        
    }
};

