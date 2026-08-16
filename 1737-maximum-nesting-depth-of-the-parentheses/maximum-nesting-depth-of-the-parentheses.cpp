class Solution {
public:
    int maxDepth(string s) {
        stack<char> st ;
        int maxcount = 0 ;
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] =='('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    maxcount = max(maxcount , (int)st.size());
                    st.pop();
                }
            }
        }
        return maxcount ;

        
    }
};