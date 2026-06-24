class DSU {
public:

    vector<int> parent, size;

    DSU(int n) {

        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {

        if(node == parent[node]) {
            return node;
        }

        return parent[node] =
               findParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {

            parent[pu] = pv;
            size[pv] += size[pu];

        } else {

            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DSU dsu(n * n);

        vector<vector<int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        // STEP 1: connect all existing 1s
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 0)
                    continue;

                int node = r * n + c;

                for(auto d : dir) {

                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= 0 && nc >= 0 &&
                       nr < n && nc < n &&
                       grid[nr][nc] == 1) {

                        int adjNode =
                            nr * n + nc;

                        dsu.unionBySize(
                            node,
                            adjNode
                        );
                    }
                }
            }
        }

        int ans = 0;

        // STEP 2: try converting each 0
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 1)
                    continue;

                set<int> parents;

                for(auto d : dir) {

                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= 0 && nc >= 0 &&
                       nr < n && nc < n &&
                       grid[nr][nc] == 1) {

                        int adjNode =
                            nr * n + nc;

                        parents.insert(
                            dsu.findParent(adjNode)
                        );
                    }
                }

                int totalSize = 1;

                for(auto parent : parents) {
                    totalSize +=
                        dsu.size[parent];
                }

                ans = max(ans, totalSize);
            }
        }

        // STEP 3:
        // handle all-1s case
        for(int i = 0; i < n*n; i++) {

            ans = max(
                ans,
                dsu.size[
                    dsu.findParent(i)
                ]
            );
        }

        return ans;
    }
};