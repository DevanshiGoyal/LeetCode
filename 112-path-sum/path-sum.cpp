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

    void preOrder(TreeNode* root , bool& ans , int x , int sum){
        if(root==nullptr) return ;

        sum = sum+ root->val ;

        if(!root->left &&!root->right && sum==x){
            ans = true ;
            return ;
        }

        if(root->left){
            preOrder(root->left , ans , x , sum) ;
        }

        if(root->right){
            preOrder(root->right, ans , x , sum) ;
        }

    
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false ;
        bool ans = false ;

        int sum = 0 ;

        preOrder(root , ans , targetSum , sum) ;

        return ans ;

        
    }
};