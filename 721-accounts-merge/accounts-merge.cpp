class DSU {
public:

    vector<int> parent, size;

    DSU(int n) {

        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {

        if (node == parent[node]) {
            return node;
        }

        return parent[node] =
               findParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {

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

    vector<vector<string>>
    accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DSU dsu(n);

        unordered_map<string,int> mailToNode;

        // STEP 1: UNION
        for (int i = 0; i < n; i++) {

            for (int j = 1;
                 j < accounts[i].size();
                 j++) {

                string mail = accounts[i][j];

                if (mailToNode.find(mail)
                    == mailToNode.end()) {

                    mailToNode[mail] = i;

                } else {

                    dsu.unionBySize(
                        i,
                        mailToNode[mail]
                    );
                }
            }
        }

        // STEP 2: GROUP MAILS
        vector<string> mergedMail[n];

        for (auto it : mailToNode) {

            string mail = it.first;
            int node = it.second;

            int parent =
                dsu.findParent(node);

            mergedMail[parent]
                .push_back(mail);
        }

        // STEP 3: BUILD ANSWER
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedMail[i].size() == 0)
                continue;

            sort(
                mergedMail[i].begin(),
                mergedMail[i].end()
            );

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};