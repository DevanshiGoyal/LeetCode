class Solution {
public:
    int find(vector<int>& parent, int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
    }

    void Union(vector<int>& parent, vector<int>& rank, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if (a == b) return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        } else if (rank[a] > rank[b]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        // Initialize DSU
        vector<int> parent(n + 1), rank(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;

        // Map each email to the first account index it appears in
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (!mp.contains(accounts[i][j])) {
                    mp[accounts[i][j]] = i;
                } else {
                    // Same email found in two accounts → merge them
                    Union(parent, rank, i, mp[accounts[i][j]]);
                }
            }
        }

        // Group emails by root parent
        vector<vector<string>> groups(n);
        for (auto& [email, idx] : mp) {
            int par = find(parent, idx);
            groups[par].push_back(email);
        }

        // Build answer: sort emails and prepend name
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (groups[i].empty()) continue;

            sort(groups[i].begin(), groups[i].end());

            // Get name from the account that owns the first email in this group
            groups[i].insert(groups[i].begin(), accounts[mp[groups[i][0]]][0]);

            ans.push_back(groups[i]);
        }

        return ans;
    }
};