class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        int m = num.size();
        int maxProd = INT_MIN;

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int prod = (num[i] - '0') * (num[j] - '0');
                maxProd = max(maxProd, prod);
            }
        }

        return maxProd;
    }
};