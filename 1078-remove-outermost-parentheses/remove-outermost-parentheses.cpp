class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack based approach 
        string ans ;
        stack<char> st ;

        for(auto e : s ){
            if(e == '('){
                if(!st.empty()){
                    
                    ans += '(' ;
                }
                st.push(e);
            }
            else{
                if(st.size() > 1){
                    ans+=')' ;
                }
                st.pop() ;
            }
        }

        return ans ;
        
    }
};