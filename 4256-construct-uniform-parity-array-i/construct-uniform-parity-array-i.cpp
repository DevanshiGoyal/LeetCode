class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // return 1;
        int odd = 0;
        int even = 0;

        int n = nums1.size();

        for (int x : nums1) {
            if (x % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        if (even == n || odd == n) {
            return true;
        } else if (even >= 1 && odd >= 1) {
            return true;
        }

        return false;
    }
};