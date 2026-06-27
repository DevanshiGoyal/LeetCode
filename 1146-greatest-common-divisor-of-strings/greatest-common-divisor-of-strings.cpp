class Solution {
public:

    string gcdOfStrings(string str1, string str2) {

        // If incompatible, no answer
        if (str1 + str2 != str2 + str1)
            return "";

        // gcd of lengths
        int gcdLength = gcd(str1.length(), str2.length());

        // return prefix of gcd length
        return str1.substr(0, gcdLength);
    }
};