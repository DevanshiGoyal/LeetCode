class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();
        unordered_set<string> s(nums.begin(), nums.end());

        for (int i = 0; i < (1 << n); ++i) {
            string candidate = "";
            for (int j = 0; j < n; ++j) {
                candidate += (i & (1 << j)) ? '1' : '0';
            }
            if (s.find(candidate) == s.end()) {
                return candidate;
            }
        }
        return "";        
    }
};