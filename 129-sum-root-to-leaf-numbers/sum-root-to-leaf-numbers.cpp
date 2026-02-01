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
    int totalSum=0;
    void dfs(TreeNode* root, string path)
    {
        if(root == NULL) return;
        path = path + to_string(root->val);
        if(root->left==NULL && root->right==NULL) // leaf node 
        {
            totalSum = totalSum + stoi(path); // convert to int and add 
            return;
        }
        // continue dfs
        dfs(root->left, path);
        dfs(root->right, path);

    }
    int sumNumbers(TreeNode* root) {

    // Since the problem asks for root-to-leaf paths, we use DFS.
    
    // maintain a string that stores the current path digits.
    // When we reach a leaf, convert the string to an integer and add it to the total sum.

        dfs(root, "");
        return totalSum;
            
    }
};