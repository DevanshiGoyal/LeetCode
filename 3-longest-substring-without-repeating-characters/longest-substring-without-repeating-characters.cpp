class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int l = 0, r = 0;
        int n = s.length();

        unordered_set<char> charSet;

        while (r < n) {
            if (charSet.find(s[r]) == charSet.end()) {
                // Character not seen before, expand window
                charSet.insert(s[r]);
                maxlen = max(maxlen, r - l + 1);
                r++;
            } else {
                // Duplicate found, shrink window from the left
                charSet.erase(s[l]);
                l++;
            }
        }

        return maxlen;
    }
};

//TC--->O(N)
//SC--->O(N)