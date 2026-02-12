class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length() ;
        int cnt = 0 ;
        for(int i = 0 ; i<n ; i++){
            for(int j = i ; j<n ; j++){
                bool flag = true ;
                int l = i , r = j ;
                for(int k=i ; k<=j ; k++){
                    if(s[l]!=s[r]){
                        flag = false ;
                    }
                    l++;
                    r--;
                }
                if(flag) cnt++;

            }
        }

        return cnt ;
        
    }
};