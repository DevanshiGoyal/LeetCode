/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* startNode = nullptr;

    void addParent(TreeNode* root, TreeNode* par, int start) {
        if (!root) return;

        if (root->val == start) {
            startNode = root;
        }

        parent[root] = par;
        addParent(root->left, root, start);
        addParent(root->right, root, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        // build parent map + find start node
        addParent(root, nullptr, start);

        // BFS
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(startNode);
        visited.insert(startNode);

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool infected = false;

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                // left
                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                    infected = true;
                }

                // right
                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                    infected = true;
                }

                // parent
                if (parent[curr] && !visited.count(parent[curr])) {
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                    infected = true;
                }
            }

            if (infected) time++;
        }

        return time;
    }
};
