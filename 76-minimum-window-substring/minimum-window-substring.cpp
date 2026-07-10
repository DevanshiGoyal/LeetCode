class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.length();
        int m = t.length();

        if (m > n)
            return "";

        vector<int> hash(256, 0);

        for (char ch : t)
            hash[ch]++;

        int l = 0, r = 0;
        int cnt = 0;

        int startIndex = -1;
        int mini = INT_MAX;

        while (r < n) {

            if (hash[s[r]] > 0)
                cnt++;

            hash[s[r]]--;

            while (cnt == m) {

                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    startIndex = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0)
                    cnt--;

                l++;
            }

            r++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, mini);
    }
};

/*
Time complexity: O(2n+m)
Space complexity: O(256)
*/