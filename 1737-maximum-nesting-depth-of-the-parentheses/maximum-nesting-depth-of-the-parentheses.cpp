class Solution {
public:
    int maxDepth(string s) {
        // stack based approach 
        stack<char> st ;
        int maxcount = 0 ;
        
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                int x = st.size();
                maxcount = max(x , maxcount) ;
                st.pop() ;             
                
            }
            

        }
        return maxcount ;
        

        
    }
};
//TC-->O(N) SC-->O(N)