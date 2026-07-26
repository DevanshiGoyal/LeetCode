class Solution {
public: 
    bool checkValidString(string s) {
        int minOpen = 0; 
        int maxOpen = 0;

        for(char ch : s){
            if (ch == '('){
                minOpen++;
                maxOpen++;
            }else if(ch == ')'){
                maxOpen--;
                minOpen--;
            }else{
                maxOpen++;
                minOpen--;
            }
            if(maxOpen < 0) return false;
            if(minOpen < 0) minOpen = 0;
        }
        return minOpen == 0;
    }
};