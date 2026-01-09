class Solution {
public:

    int priority(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
        return 0;
    }

    int romanToInt(string s) {
        int sol = 0;
        for(int i=1; i<s.size(); i++){
            // largest to smallest 
            if(priority(s[i-1])>=priority(s[i])) sol += priority(s[i-1]);
            else sol -= priority(s[i-1]);
        }  
        sol += priority(s[s.size()-1]);
        return sol;      
    }

    
};
//TC-->O(N)  SC-->O(1)