class Solution {
public:
    string largestGoodInteger(string num) {
        string best = "";
        for(int i = 1 ; i<num.length()-1 ; i++){
            if(num[i-1] == num[i]  && num[i]== num[i+1]){
                best = max(best, num.substr(i-1, 3));
            }
        }

        return best ;
        
    }
};