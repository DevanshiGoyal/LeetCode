class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> vals;
        inorder(root, vals);  // get sorted BST values
        vector<vector<int>> ans;
        for (int q : queries) {
            int mini = -1, maxi = -1;
            // find first element >= q (successor)
            auto it = lower_bound(vals.begin(), vals.end(), q);
            if (it != vals.end() && *it == q) {
                // exact match
                mini = maxi = *it;
            } else {
                if (it != vals.begin()) mini = *(prev(it));  // largest smaller element
                if (it != vals.end()) maxi = *it;            // smallest greater element
            }
            ans.push_back({mini, maxi});
        }
        return ans;
    }
};