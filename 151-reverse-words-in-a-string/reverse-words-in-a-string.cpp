class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == ' ') {
                if(!temp.empty()) {
                    st.push(temp);
                    temp = "";
                }
            }
            else {
                temp.push_back(s[i]);
            }
        }

        if(!temp.empty())
            st.push(temp);

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();

            if(!st.empty())
                ans += " ";
        }

        return ans;
    }
};