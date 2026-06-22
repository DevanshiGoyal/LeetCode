class Solution {
public:

    void dfs(int u, vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& nodes,
             int& edgeCount) {

        vis[u] = 1;
        nodes.push_back(u);

        edgeCount += adj[u].size();

        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis, nodes, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int complete = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                vector<int> nodes;
                int edgeCount = 0;

                dfs(i, adj, vis, nodes, edgeCount);

                int k = nodes.size();

                // divide by 2 because undirected edges counted twice
                edgeCount /= 2;

                if (edgeCount == (k * (k - 1)) / 2) {
                    complete++;
                }
            }
        }

        return complete;
    }
};
/*
DFS traversal: O(V + E)
Overall: O(n + edges.size())
*/