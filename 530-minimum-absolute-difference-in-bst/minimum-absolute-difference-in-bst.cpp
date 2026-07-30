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
    vector<int>inorder ;
    void dfs(TreeNode* root){
        if(root == NULL) return ;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {

        dfs(root);
        int mini = INT_MAX ;

        for(int i = 0 ; i<inorder.size()-1 ; i++){
            mini = min(mini , inorder[i+1] - inorder[i]);
        }
        return mini ;
        
    }
};
// TC  o(N)   SC  O(N)