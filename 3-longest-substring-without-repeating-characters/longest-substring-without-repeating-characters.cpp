class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastIndex(256, -1);

        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {

            if (lastIndex[s[r]] >= l) {
                l = lastIndex[s[r]] + 1;
            }

            lastIndex[s[r]] = r;

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

//  O(n)    O(256)