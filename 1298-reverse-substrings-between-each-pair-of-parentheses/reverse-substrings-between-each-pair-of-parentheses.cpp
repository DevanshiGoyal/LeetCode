class Solution {
public:
    string reverseParentheses(string s) {
        int n = static_cast<int>(s.size());
        vector<int> pair(n);
        vector<int> openings;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                openings.push_back(i);
            } else if (s[i] == ')') {
                int j = openings.back();
                openings.pop_back();

                pair[i] = j;
                pair[j] = i;
            }
        }

        string answer;
        //answer.reserve(n);

        int i = 0;
        int direction = 1;

        while (i >= 0 && i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                direction = -direction;
            } else {
                answer.push_back(s[i]);
            }

            i += direction;
        }

        return answer;
    }
};