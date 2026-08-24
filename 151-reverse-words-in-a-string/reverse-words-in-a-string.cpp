class Solution {
public:
    string reverseWords(string s) {
        string output = "";
        string temp = "";

        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] != ' ') {
                temp += s[i];
            }
            else {
                if (!temp.empty()) {
                    reverse(temp.begin(), temp.end());

                    if (!output.empty())
                        output += " ";

                    output += temp;
                    temp = "";
                }
            }
        }

        // Add the first word if it exists
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());

            if (!output.empty())
                output += " ";

            output += temp;
        }

        return output;
    }
};