class Solution {
public:
    int minAddToMakeValid(string s) {
        // optimal
        int op= 0, add = 0;

        for (char c : s) {
            if (c == '(') {
                op++;
            } else {
                if (op > 0) op--;
                else add++;
            }
        }

        return add + op;
    }
};
