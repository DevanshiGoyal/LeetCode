class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        long long curr = 0;
        vector<long long> actualShifts(n);

        for (int i = n - 1; i >= 0; i--) {
            curr = (curr + shifts[i]) % 26;
            actualShifts[i] = curr;
        }

        for (int i = 0; i < n; i++) {
            s[i] = 'a' + (s[i] - 'a' + actualShifts[i]) % 26;
        }

        return s;
    }
};