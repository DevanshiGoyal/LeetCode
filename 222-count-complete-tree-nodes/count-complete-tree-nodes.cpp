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
    int countNodes(TreeNode* root) {

        if (!root) return 0;
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;  // node , count
        q.push({root, 1});

        while (!q.empty()) {
            long long size = q.size();
            
            long long last;

            for (int i = 0; i < size; i++) {
                auto [node, cnt] = q.front();
                q.pop();

                if (i == size - 1) last = cnt;

                if (node->left)
                    q.push({node->left, 2*cnt});   
                if (node->right)
                    q.push({node->right, 2*cnt+1});
            }

            ans = last;
        }

        return ans;
   
        
    }
};