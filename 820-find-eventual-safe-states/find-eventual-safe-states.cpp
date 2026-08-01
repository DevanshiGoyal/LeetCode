class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reversedGraph(n);
        vector<int> inDegree(n, 0);
        queue<int> q;

        // Step 1: Reverse graph & initialize indegrees
        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                reversedGraph[neighbor].push_back(i);
            }
            // Outdegree in original graph = Indegree in reversed graph
            inDegree[i] = graph[i].size(); 
            
            // Push terminal nodes (outdegree == 0) to queue
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        // Step 2: Kahn's Algorithm (Topological Sort)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : reversedGraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Sort result in ascending order
        sort(result.begin(), result.end());
        return result;
    }
};