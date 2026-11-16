class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            int write_idx = 0;
            for (int i = 0; i < s.size(); i += k) {
                int sum = 0;
                for (int j = i; j < i + k && j < s.size(); j++) {
                    sum += s[j] - '0';
                }
                for (char c : to_string(sum)) {
                    s[write_idx++] = c;
                }
            }
            s.resize(write_idx);
        }
        return s;
    }
};