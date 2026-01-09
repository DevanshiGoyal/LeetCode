class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        string ans = "";
        // comparator function 
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);

        // iterating and counting freq of each char using unord map
        unordered_map<char , int> freq ;
        for (char c : s) {
            freq[c]++;
        }
        
        // using a priority q(max heap) to store pairs of char and their freq
        // sorted in decreasing order of freq

        for (const auto& entry : freq) {
            pq.push(make_pair(entry.first, entry.second));
        }
        string result = "";
        while (!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            result.append(p.second, p.first);
        }
        
        return result;



        

        
    }
};