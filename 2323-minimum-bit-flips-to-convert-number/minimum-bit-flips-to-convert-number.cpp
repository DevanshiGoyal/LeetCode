class Solution {
public:
// brute force 

    string conevrt2Binary(int a){
        string x  ;
        int d = 0 ;
        while(a>0){
            d=a%2;
            x.push_back(d+'0');
            a=a/2;
        }
        
        return x ;
    }
    int minBitFlips(int start, int goal) {
        string s = conevrt2Binary(start);
        string g = conevrt2Binary(goal);

        while(s.length() < g.length()) s.push_back('0');
        while (s.length() > g.length()) g.push_back('0');

        int cnt = 0 ;
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] != g[i]){
                s[i] = g[i];
                cnt++;
            }
        }
        return cnt;
        
    }
};