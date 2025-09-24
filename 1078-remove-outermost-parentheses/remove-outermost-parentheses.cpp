class Solution {
public:
    string removeOuterParentheses(string s) {
        int left = 0, right = 0;
        string ans = "";
        int n = s.length(), cnt = 0;
        
        while (right < n) {
            if (s[right] == '(') {
                cnt++;
            } else {
                cnt--;
            }
            
            if (cnt == 0) {
                if (left <= right) {
                    ans += s.substr(left + 1, right - left - 1);
                    right++;
                    left = right;
                    continue;
                }
            }
            right++;
        }
        
        return ans;
    }
};