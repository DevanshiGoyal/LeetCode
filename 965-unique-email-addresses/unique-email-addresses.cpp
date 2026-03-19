class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st ;  // avoid duplicates processed email 
        for(string &email : emails){
            string clean;
            for(char c : email){
                if(c=='+' || c=='@') break ; // stop at this 
                if(c=='.') continue ; // ignore .
                clean +=c ;  // processed email 
            }
            clean += email.substr(email.find('@'));   // takes ex:  @gmail.com 
            st.insert(clean);
        }
   
        return st.size();
    }
        
};
/*
Time	O(n * m)
Space	O(n)

(n = emails, m = len of string)
*/