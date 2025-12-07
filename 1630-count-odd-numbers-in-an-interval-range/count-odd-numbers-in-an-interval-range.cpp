class Solution {
public:
    int countOdds(int low, int high) {
        //using maths trick 
        // tc--> O(1)
        // (x + 1) // 2   odd [1----- x]
        // [low , high]
        //odds up to high   −   odds up to (low - 1)
        int odds = (high + 1) / 2  - (low /2) ;
        return odds ;
        
    }
};