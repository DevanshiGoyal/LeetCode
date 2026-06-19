class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length()!=goal.length()) return false ;
        string combine = s + s ;
        if(combine.find(goal) == string::npos) return false ;

        return true ;
        
    }
};