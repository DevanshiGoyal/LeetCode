class Solution {
public:
    int reverseDegree(string s) {

        int sum =0 ; 
        for(int i = 1 ; i<=s.length() ; i++){
            char c = s[i-1];

            int revVal = 26 - (c-'a');
            cout<<revVal<<endl;
            int pos = i ;
            cout<<pos<<endl;
            sum+= revVal*pos;
        }

        return sum ;
        
    }
};