class Solution {
public:
    bool isAnagram(string s, string t) {
        //using String + Sorting
        if(s.length() != t.length()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t){
            return true;  
        }
        return false;
        
    }
};

/*

    Time Complexity : O(NlogN + MlogM), Sorting the String(s and t) costs O(NlogN + MlogM). 

    Space Complexity : O(1)

     

*/