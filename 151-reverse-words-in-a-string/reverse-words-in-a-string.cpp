class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        string ans = "";

        int i = 0;

        while(i < n) {

            while(i < n && s[i] == ' ')
                i++;

            if(i >= n) break;

            int j = i;

            while(j < n && s[j] != ' ')
                j++;

            string word = s.substr(i, j - i);
            reverse(word.begin(), word.end());

            if(!ans.empty())
                ans += " ";

            ans += word;

            i = j;
        }

        return ans;
    }
};