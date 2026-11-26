class Solution {
public:
    bool canAliceWin(int n) {
        bool AliceTurn = true;
        for(int i = 10; i > 0; i--){
            if(n - i < 0){
                return(!AliceTurn);
            }
            n-=i;
            AliceTurn = !AliceTurn;
        }
        return true;
    }
};