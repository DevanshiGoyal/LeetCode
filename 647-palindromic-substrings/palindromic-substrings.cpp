class Solution {
private:
    int count = 0;
public:
    int countSubstrings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        for (int i = 0; i < s.length(); i++) {
            help(s, i, i);
            help(s, i, i + 1);
        }
        return count;
    }
private:
    void help(string& s, int left, int right) {
        while (left >= 0 &&  s[left] == s[right] && right < s.size() ) {
            count++;
            left--;
            right++;
        }
    }
};