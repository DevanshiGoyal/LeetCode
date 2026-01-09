class Solution {
public:
    string frequencySort(string s) {
        //count
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        //Rank
        vector<pair<char, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](const pair<char, int> a, const pair<char, int> b) {
            return a.second > b.second;
        });
        //build
        string result = "";
        for (auto& p:v) {
            result.append(p.second, p.first);
        }
        return result;
    }
};
//Time complexity: O(N + Klog K)

//Space complexity: O(N + K)