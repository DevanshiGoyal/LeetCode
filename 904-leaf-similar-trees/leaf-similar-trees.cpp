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

 
//T.C : O(n)
//S.C : O(n) (string s) - I am ignoring the recursion stack space here
class Solution {
public:
    
    void inOrder(TreeNode* root, string& s) {
        if(root == NULL) return;
        
        //leaf node
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val) + "_";
            return;
        }
        
        inOrder(root->left, s);
        inOrder(root->right, s);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";
        
        inOrder(root1, s1);
        inOrder(root2, s2);
        
        return s1==s2;
    }
};