class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);

        for(char c : s){
            count[c - 'a']++;
        }

        int ans = INT_MAX;
        vector<int> idxcount(26, 0);

        for(char c : target){
            idxcount[c - 'a']++;
        }

        for(char c : target){
            ans = min(ans, count[c - 'a'] / idxcount[c - 'a']);
        }

        return ans;
    }
};