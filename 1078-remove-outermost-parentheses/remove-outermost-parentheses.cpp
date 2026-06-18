class Solution {
public:
    string removeOuterParentheses(string s) {
        string output ;

        int op = 0;
        for(char c : s){
            if(c == '('){
                if(op>0){
                    output.push_back(c);
                }
                op++;
            }else{
                if(op>1){
                    output.push_back(c);
                }
                op--;
            }
        }

        return output ;
        
    }
};