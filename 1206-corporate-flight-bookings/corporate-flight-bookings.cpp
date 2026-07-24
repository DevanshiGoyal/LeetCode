
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n + 2, 0);
        for (auto& e : bookings) {
            int start = e[0];
            int end = e[1];
            int value = e[2];
            ans[start] += value;
            ans[end + 1] -= value;
        }

        int sum = 0;
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            sum += ans[i];
            result.push_back(sum);
        }
        return result;
    }
};
