class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        vector<int> minutes;

        for (string time : timePoints) {

            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));

            minutes.push_back(hour * 60 + minute);
        }

        sort(minutes.begin(), minutes.end());

        int ans = INT_MAX;

        for (int i = 1; i < minutes.size(); i++) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }

        // circular difference
        ans = min(ans, minutes[0] + 1440 - minutes.back());

        return ans;
    }
};