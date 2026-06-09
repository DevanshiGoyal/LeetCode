/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* target,vector<TreeNode*>& path) {

        if (root == NULL)
            return false;

        path.push_back(root);

        if (root == target)
            return true;

        if (getPath(root->left, target, path) ||
            getPath(root->right, target, path))
            return true;

        path.pop_back(); // backtrack
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // brute intution
        vector<TreeNode*> path1, path2;

        getPath(root, p, path1);
        getPath(root, q, path2);

        TreeNode* lca = nullptr;

        int i = 0;
        while(i < path1.size() && i < path2.size()) {
            if(path1[i] == path2[i])
                lca = path1[i];
            else
                break;
            i++;
        }

        return lca;
        
    }
};
/*
Complexity
getPath() for p → O(N)
getPath() for q → O(N)
Comparing paths → O(H)

Overall:

Time  : O(N)
Space : O(H)

where H is the height of the tree.
*/