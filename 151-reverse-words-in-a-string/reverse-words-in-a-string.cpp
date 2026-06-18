class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;

        for(int i = 0; i < n; ) {

            while(i < n && s[i] == ' ')
                i++;

            if(i >= n) break;

            if(idx != 0)
                s[idx++] = ' ';

            int j = i;

            while(j < n && s[j] != ' ')
                j++;

            reverse(s.begin() + i, s.begin() + j);

            while(i < j)
                s[idx++] = s[i++];

            i = j;
        }

        s.resize(idx);
        return s;
    }
};