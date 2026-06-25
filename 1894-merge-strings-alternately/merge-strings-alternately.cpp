class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int turn = 1;//1 means word1, 0 emans word2
        string ans;
        int i=0,j=0;
        int n = word1.size(), m= word2.size();
        while(i<n && j<m){
            if(turn){
                ans.push_back(word1[i++]);
            }else ans.push_back(word2[j++]);
            turn = !turn;
        }
        if(i<n) ans += word1.substr(i,n-i);
        if(j<m) ans += word2.substr(j,m-j);
        return ans;
    }
};