class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Count the frequency of every word
        unordered_map<string, int> freq;
        for (string &word : words) {
            freq[word]++;
        }

        // bucket[i] stores all words that appear exactly i times
        vector<vector<string>> bucket(words.size() + 1);

        for (auto &entry : freq) {
            bucket[entry.second].push_back(entry.first);
        }

        vector<string> ans;

        // Traverse buckets from highest frequency to lowest
        for (int i = words.size(); i >= 1; i--) {

            if (bucket[i].empty())
                continue;

            // Words with the same frequency should be in lexicographical order
            sort(bucket[i].begin(), bucket[i].end());

            for (string &word : bucket[i]) {
                ans.push_back(word);

                // Stop after we have collected k words
                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};