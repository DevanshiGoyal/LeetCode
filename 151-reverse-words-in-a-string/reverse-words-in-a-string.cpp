class Solution {
public:
    string reverseWords(string s) {
        // using stack 
        // tc-->O(N)  sc--->O(N)
        stack<string> st;
        string tmp ="";
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] != ' ') tmp.push_back(s[i]);
            else{
                if(tmp!=""){
                    st.push(tmp);
                    tmp ="";
                }
            }

            if(i == s.length()-1){
                if(tmp != "") st.push(tmp);
            }
        }

        s = "";
        while(!st.empty()){
            s+=st.top();
            st.pop();
            if(!st.empty()){
                s+=' ';
            }
        }
        return s;
    }
};