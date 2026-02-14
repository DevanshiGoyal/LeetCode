class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> bkt;

        for(char c : s){
            if(c=='('){
                bkt.push(c);
            }else{
                if(!bkt.empty() && bkt.top()=='(' ){
                    bkt.pop();
                }else{
                    bkt.push(c);
                }  

            }

        }

        return bkt.size();

        
    }
};