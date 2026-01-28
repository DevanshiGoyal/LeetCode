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
    bool preOrder(TreeNode* root , int targetSum , int sum){
        if(root== NULL){
            return false ;
        }

        sum+=root->val;

        // if we reached leaf node 
        if(!root->left && !root->right){
            if(sum == targetSum) return true ;
            else return false ;
        }

        bool leftSum = preOrder(root->left , targetSum , sum);
        bool rightSum = preOrder(root->right , targetSum , sum);

        return (leftSum || rightSum) ;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0 ;
        bool result = preOrder(root , targetSum , sum) ;        
        return result ;
    }
};