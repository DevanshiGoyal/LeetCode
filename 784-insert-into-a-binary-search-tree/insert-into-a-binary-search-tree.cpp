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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        
        TreeNode* curr = root;
        
        while(true){ // running an infinity loop, look for the place for new node to add
            if(curr->val < val){
                if(curr->right != nullptr) curr = curr->right; // update current on right
                else {
                    curr->right = new TreeNode(val); // otherwise add current of right to new value TreeNode
                    break; // breaking this infinity loop
                }
            }
            else{
                if(curr->left != nullptr) curr = curr->left; // update current on left
                else{
                    curr->left = new TreeNode(val); // otherwise add current of left to new value TreeNode
                    break; // breaking this infinity loop
                }
            }
        }
        return root;
        
    }
};