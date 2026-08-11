class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize != 0) return false ;

        map<int , int> f ;

        for(int c : hand){
            f[c]++;
        }  
        while(!f.empty()){
            int smallest = f.begin()->first ;

            for(int j = 0; j<groupSize; j++){

                int c = smallest+j;

                if(f.find(c) == f.end()){
                    return false;
                }
                f[c]--;

                if(f[c] == 0){
                    f.erase(c);
                }
            }
        }
        return true ;

    }
};